#include <iostream>
#include <chrono>

constexpr int SCALE = 3; // 1 секунда = 3 минуты
constexpr int START_HOUR = 5;
constexpr int END_HOUR = 1;
constexpr int MINUTES_IN_DAY = 24 * 60;

int main() {
    auto start_real_time = std::chrono::steady_clock::now();
    int start_virtual_time = START_HOUR * 60; // 5:00 утра

    while (true) {
        auto now_real = std::chrono::steady_clock::now();
        auto elapsed_real_sec = std::chrono::duration_cast<std::chrono::seconds>(now_real - start_real_time).count();
        
        int current_time = start_virtual_time + elapsed_real_sec * SCALE;
        if (current_time >= MINUTES_IN_DAY + END_HOUR * 60) break; // Завершение в 1:00

        int hours = (current_time / 60) % 24;
        int minutes = current_time % 60;

        std::cout << "Текущее время: " << hours << ":" << (minutes < 10 ? "0" : "") << minutes << "\r" << std::flush;
    }

    return 0;
}

#include "metro.h"

std::mutex mtx_Cafar_Cabbarli;
std::mutex mtx_Xatai;

void chill_light_green(int id)
{
    std::ofstream file_light_green_line("output_light_green_line.txt", std::ios::app);
    file_light_green_line << id << " is chilling\n";
    std::this_thread::sleep_for(std::chrono::seconds(5));
}

void station_light_green(int id, const std::string &str, std::ofstream &faylik, const std::string &from)
{
    faylik << id << " in " << str << " station from " << from << "\n";
    std::this_thread::sleep_for(std::chrono::seconds(1));
}




void Cafar_Cabbarli(int id, const std::string &from, const std::string &movement)
{
    std::ofstream file_light_green_line("output_light_green_line.txt", std::ios::app);
    file_light_green_line << id << " in way Cafar Cabbarli from " << from << "\n";
    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::string str = "Cafar Cabbarli";
    std::unique_lock<std::mutex> lock(mtx_Cafar_Cabbarli);
    station_light_green(id, str, file_light_green_line, movement);
    lock.unlock();
}

void Xatai(int id, const std::string &from, const std::string &movement)
{
    std::ofstream file_light_green_line("output_light_green_line.txt", std::ios::app);
    file_light_green_line << id << " in way Xatai from " << from << "\n";
    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::string str = "Xatai";
    std::unique_lock<std::mutex> lock(mtx_Xatai);
    station_light_green(id, str, file_light_green_line, movement);
    lock.unlock();
}

void train_light_green(int id)
{
    int i = 0;
    chill_light_green(id);
    Xatai(id, "Depo", "Depo");
    while(i < 40)
    {
        Cafar_Cabbarli(id, "Xatai", "right");
        Xatai(id, "Cafar Cabbarli", "left");
        i++;
    }
}

void void_light_green_line()
{
    std::vector<std::thread> train_light_green_vec;

    int num;

    for(size_t i = 0; i != 2; i++)
    {
        std::srand(std::time(nullptr));

        num = rand() % 1000;
        num += 1259;
        num %= 1000;
        num += 1000;

        std::thread t_g_l(train_light_green, num);

        train_light_green_vec.push_back(std::move(t_g_l));
        
        std::this_thread::sleep_for(std::chrono::seconds(5));
    }

    for(auto &tr: train_light_green_vec)
    {
        tr.join();
    }
}
#include "metro.h"

int main()
{
    std::thread red_line(void_red_train);
    std::thread violet_line(void_violet_line);
    std::thread light_green_line(void_light_green_line);
    std::thread green_line(void_green_line);

    red_line.join();
    violet_line.join();
    light_green_line.join();
    green_line.join();

    return 0;
}
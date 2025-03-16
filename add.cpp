#include "metro.h"

void website()
{
    std::string str_mes;
    std::cout << "do you want to visit the website? (yes or !yes)\n";
    std::cin >> str_mes;
    if(str_mes == "yes")
    {   
        #ifdef _WIN32
        {
            system("start https://metro.gov.az/en/page/xetlerimiz/konseptual-sxem");
        }
        #elif __linux__
        {
            system("xdg-open https://metro.gov.az/en/page/xetlerimiz/konseptual-sxem");
        }
        #else
        std::cout << "Unsupported OS\n";
        #endif
    }
    else
    {
        std::cout << "then, let's go!\n";
    }
}
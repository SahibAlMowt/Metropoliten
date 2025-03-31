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

void map_pdf()
{
    std::string str_mes_pdf; 
    std::cout << "do you want to check map? (yes or !yes)\n";
    std::cin >> str_mes_pdf;

    if(str_mes_pdf == "yes")
    {   
        #ifdef _WIN32
        {
            system("start https://metro.gov.az/storage/files/file/6784/GrmgC0bDMeWpr1Y6amR3iTL76io1evDVWfywqkbr.pdf");
        }
        #elif __linux__
        {
            system("xdg-open https://metro.gov.az/storage/files/file/6784/GrmgC0bDMeWpr1Y6amR3iTL76io1evDVWfywqkbr.pdf");
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
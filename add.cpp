#include "metro.h"

void website()
{
    std::string str_mes;
    std::cout << "do you want to visit the website?\n";
    std::cin >> str_mes;
    if(str_mes == "yes")
    {
        system("start https://metro.gov.az/en/page/xetlerimiz/konseptual-sxem");
        system("xdg-open https://metro.gov.az/en/page/xetlerimiz/konseptual-sxem");
    }
    else
    {
        std::cout << "then, let's go!\n";
    }
}
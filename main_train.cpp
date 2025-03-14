#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <fstream>

std::mutex mtx_chill_red;
std::mutex mtx_chill_violet;
std::mutex mtx_chill_light_green;
std::mutex mtx_chill_green;

std::mutex mtx_station_red;
std::mutex mtx_station_violet;
std::mutex mtx_station_light_green;
std::mutex mtx_station_green;

std::mutex mtx_Icherisheher;
std::mutex mtx_Sahil;
std::mutex mtx_28_May;
std::mutex mtx_Ganjlik;
std::mutex mtx_Nariman_Narimanov;
std::mutex mtx_Bakmil;

std::mutex mtx_Xodjasan;
std::mutex mtx_Avtovogzal;
std::mutex mtx_Memar_Adjemi_violet;
std::mutex mtx_8_Noyabr;

std::mutex mtx_Ulduz;
std::mutex mtx_Koroglu;
std::mutex mtx_Gara_Garayev;
std::mutex mtx_Neftchiler;
std::mutex mtx_Xalqlar_Dostlugu;
std::mutex mtx_Ahmedli;
std::mutex mtx_Hazi_Aslanov;

std::mutex mtx_Cafar_Cabbarli;
std::mutex mtx_Xatai;

std::mutex mtx_Nizami;
std::mutex mtx_Elmler_Akademiyasi;
std::mutex mtx_Inshaatchilar;
std::mutex mtx_20_Yanvar;
std::mutex mtx_Memar_Adjemi_green;
std::mutex mtx_Nasimi;
std::mutex mtx_Azadliq_prospekti;
std::mutex mtx_Darnagul;

void chill_red(int id)
{
    std::lock_guard<std::mutex> lock(mtx_chill_red);
    std::ofstream file_red_line("output_red_line.txt", std::ios::app);
    file_red_line << id << " is chilling\n";
    std::this_thread::sleep_for(std::chrono::seconds(5));
}

void chill_violet(int id)
{
    std::lock_guard<std::mutex> lock(mtx_chill_violet);
    std::ofstream file_violet_line("output_violet_line.txt", std::ios::app);
    file_violet_line << id << " is chilling\n";
    std::this_thread::sleep_for(std::chrono::seconds(5));
}

void chill_light_green(int id)
{
    std::lock_guard<std::mutex> lock(mtx_chill_light_green);
    std::ofstream file_light_green_line("output_light_green_line.txt", std::ios::app);
    file_light_green_line << id << " is chilling\n";
    std::this_thread::sleep_for(std::chrono::seconds(5));
}


void chill_green(int id)
{
    std::lock_guard<std::mutex> lock(mtx_chill_green);
    std::ofstream file_green_line("output_green_line.txt", std::ios::app);
    file_green_line << id << " is chilling\n";
    std::this_thread::sleep_for(std::chrono::seconds(5));
}

//-----------------------------------------------------------------------------------

void station_red(int id, const std::string &str, std::ofstream &faylik, const std::string &from)
{
    std::lock_guard<std::mutex> lock(mtx_station_red);
    faylik << id << " in " << str << " station from " << from << "\n";
    std::this_thread::sleep_for(std::chrono::seconds(1));
}

void station_light_green(int id, const std::string &str, std::ofstream &faylik, const std::string &from)
{
    std::lock_guard<std::mutex> lock(mtx_station_light_green);
    faylik << id << " in " << str << " station from " << from << "\n";
    std::this_thread::sleep_for(std::chrono::seconds(1));
}

void station_violet(int id, const std::string &str, std::ofstream &faylik, const std::string &from)
{
    std::lock_guard<std::mutex> lock(mtx_station_violet);
    faylik << id << " in " << str << " station from " << from << "\n";
    std::this_thread::sleep_for(std::chrono::seconds(1));
}

void station_green(int id, const std::string &str, std::ofstream &faylik, const std::string &from)
{
    std::lock_guard<std::mutex> lock(mtx_station_green);
    faylik << id << " in " << str << " station from " << from << "\n";
    std::this_thread::sleep_for(std::chrono::seconds(1));
}

//-----------------------------------------------------------------------------
// red line 1

void Icherisheher(int id, const std::string &from, const std::string &movement)
{
    std::ofstream file_red_line("output_red_line.txt", std::ios::app);
    file_red_line << id << " in way Icherisheher from " << from << "\n";
    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::string str = "Icherisheher";
    std::unique_lock<std::mutex> lock(mtx_Icherisheher);
    station_red(id, str, file_red_line, movement);
    lock.unlock();
}

void Sahil(int id, const std::string &from, const std::string &movement)
{
    std::ofstream file_red_line("output_red_line.txt", std::ios::app);
    file_red_line << id << " in way Sahil from " << from << "\n";
    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::string str = "Sahil";
    std::unique_lock<std::mutex> lock(mtx_Sahil);
    station_red(id, str, file_red_line, movement);
    lock.unlock();
}

void May_28(int id, const std::string &from, const std::string &movement)
{
    std::ofstream file_red_line("output_red_line.txt", std::ios::app);
    file_red_line << id << " in way 28 May from " << from << "\n";
    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::string str = "28 May";
    std::unique_lock<std::mutex> lock(mtx_28_May);
    station_red(id, str, file_red_line, movement);
    lock.unlock();
}

void Ganjlik(int id, const std::string &from, const std::string &movement)
{
    std::ofstream file_red_line("output_red_line.txt", std::ios::app);
    file_red_line << id << " in way Ganjlik from " << from << "\n";
    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::string str = "Ganjlik";
    std::unique_lock<std::mutex> lock(mtx_Ganjlik);
    station_red(id, str, file_red_line, movement);
    lock.unlock();
}

void Nariman_Narimanov(int id, const std::string &from, const std::string &movement)
{
    std::ofstream file_red_line("output_red_line.txt", std::ios::app);
    file_red_line << id << " in way Nariman Narimanov from " << from << "\n";
    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::string str = "Nariman Narimanov";
    std::unique_lock<std::mutex> lock(mtx_Nariman_Narimanov);
    station_red(id, str, file_red_line, movement);
    lock.unlock();
}

void Bakmil(int id, const std::string &from, const std::string &movement)
{
    std::ofstream file_red_line("output_red_line.txt", std::ios::app);
    file_red_line << id << " in way Bakmil from " << from << "\n";
    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::string str = "Bakmil";
    std::unique_lock<std::mutex> lock(mtx_Bakmil);
    station_red(id, str, file_red_line, movement);
    lock.unlock();
}

//-------------------------------------------------------------------------
//  red line 2

void Ulduz(int id, const std::string &from, const std::string &movement)
{
    std::ofstream file_red_line("output_red_line.txt", std::ios::app);
    file_red_line << id << " in way Ulduz from " << from << "\n";
    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::string str = "Ulduz";
    std::unique_lock<std::mutex> lock(mtx_Ulduz);
    station_red(id, str, file_red_line, movement);
    lock.unlock();
}

void Koroglu(int id, const std::string &from, const std::string &movement)
{
    std::ofstream file_red_line("output_red_line.txt", std::ios::app);
    file_red_line << id << " in way Koroglu from " << from << "\n";
    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::string str = "Koroglu";
    std::unique_lock<std::mutex> lock(mtx_Koroglu);
    station_red(id, str, file_red_line, movement);
    lock.unlock();
}

void Gara_Garayev(int id, const std::string &from, const std::string &movement)
{
    std::ofstream file_red_line("output_red_line.txt", std::ios::app);
    file_red_line << id << " in way Gara Garayev from " << from << "\n";
    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::string str = "Gara Garayev";
    std::unique_lock<std::mutex> lock(mtx_Gara_Garayev);
    station_red(id, str, file_red_line, movement);
    lock.unlock();
}

void Neftchiler(int id, const std::string &from, const std::string &movement)
{
    std::ofstream file_red_line("output_red_line.txt", std::ios::app);
    file_red_line << id << " in way Neftchiler from " << from << "\n";
    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::string str = "Neftchiler";
    std::unique_lock<std::mutex> lock(mtx_Neftchiler);
    station_red(id, str, file_red_line, movement);
    lock.unlock();
}

void Xalqlar_Dostlugu(int id, const std::string &from, const std::string &movement)
{
    std::ofstream file_red_line("output_red_line.txt", std::ios::app);
    file_red_line << id << " in way Xalqlar Dostlugu from " << from << "\n";
    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::string str = "Xalqlar Dostlugu";
    std::unique_lock<std::mutex> lock(mtx_Xalqlar_Dostlugu);
    station_red(id, str, file_red_line, movement);
    lock.unlock();
}

void Ahmedli(int id, const std::string &from, const std::string &movement)
{
    std::ofstream file_red_line("output_red_line.txt", std::ios::app);
    file_red_line << id << " in way Ahmedli from " << from << "\n";
    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::string str = "Ahmedli";
    std::unique_lock<std::mutex> lock(mtx_Ahmedli);
    station_red(id, str, file_red_line, movement);
    lock.unlock();
}

void Hazi_Aslanov(int id, const std::string &from, const std::string &movement)
{
    std::ofstream file_red_line("output_red_line.txt", std::ios::app);
    file_red_line << id << " in way Hazi Aslanov from " << from << "\n";
    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::string str = "Hazi Aslanov";
    std::unique_lock<std::mutex> lock(mtx_Hazi_Aslanov);
    station_red(id, str, file_red_line, movement);
    lock.unlock();
}


//----------------------------------------------------------------------------
//  violet line

void Xodjasan(int id, const std::string &from, const std::string &movement)
{
    std::ofstream file_violet_line("output_violet_line.txt", std::ios::app);
    file_violet_line << id << " in way Xodjasan from " << from << "\n";
    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::string str = "Xodjasan";
    std::unique_lock<std::mutex> lock(mtx_Xodjasan);
    station_violet(id, str, file_violet_line, movement);
    lock.unlock();
}

void Avtovogzal(int id, const std::string &from, const std::string &movement)
{
    std::ofstream file_violet_line("output_violet_line.txt", std::ios::app);
    file_violet_line << id << " in way Avtovogzal from " << from << "\n";
    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::string str = "Avtovogzal";
    std::unique_lock<std::mutex> lock(mtx_Avtovogzal);
    station_violet(id, str, file_violet_line, movement);
    lock.unlock();
}

void Memar_Adjemi_violet(int id, const std::string &from, const std::string &movement)
{
    std::ofstream file_violet_line("output_violet_line.txt", std::ios::app);
    file_violet_line << id << " in way Memar Adjemi from " << from << "\n";
    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::string str = "Memar Adjemi";
    std::unique_lock<std::mutex> lock(mtx_Memar_Adjemi_violet);
    station_violet(id, str, file_violet_line, movement);
    lock.unlock();
}

void Noyabr_8(int id, const std::string &from, const std::string &movement)
{
    std::ofstream file_violet_line("output_violet_line.txt", std::ios::app);
    file_violet_line << id << " in way 8 Noyabr from " << from << "\n";
    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::string str = "8 Noyabr";
    std::unique_lock<std::mutex> lock(mtx_8_Noyabr);
    station_violet(id, str, file_violet_line, movement);
    lock.unlock();
}

//----------------------------------------------------------------------------------
//  light green line

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

//-----------------------------------------------------------------------
//  green line

void Nizami(int id, const std::string &from, const std::string &movement)
{
    std::ofstream file_green_line("output_green_line.txt", std::ios::app);
    file_green_line << id << " in way Nizami from " << from << "\n";
    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::string str = "Nizami";
    std::unique_lock<std::mutex> lock(mtx_Nizami);
    station_green(id, str, file_green_line, movement);
    lock.unlock();
}

void Elmler_Akademiyasi(int id, const std::string &from, const std::string &movement)
{
    std::ofstream file_green_line("output_green_line.txt", std::ios::app);
    file_green_line << id << " in way Elmler Akademiyasi from " << from << "\n";
    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::string str = "Elmler Akademiyasi";
    std::unique_lock<std::mutex> lock(mtx_Elmler_Akademiyasi);
    station_green(id, str, file_green_line, movement);
    lock.unlock();
}

void Inshaatchilar(int id, const std::string &from, const std::string &movement)
{
    std::ofstream file_green_line("output_green_line.txt", std::ios::app);
    file_green_line << id << " in way Inshaatchilar from " << from << "\n";
    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::string str = "Inshaatchilar";
    std::unique_lock<std::mutex> lock(mtx_Inshaatchilar);
    station_green(id, str, file_green_line, movement);
    lock.unlock();
}

void Yanvar_20(int id, const std::string &from, const std::string &movement)
{
    std::ofstream file_green_line("output_green_line.txt", std::ios::app);
    file_green_line << id << " in way 20 Yanvar from " << from << "\n";
    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::string str = "20 Yanvar";
    std::unique_lock<std::mutex> lock(mtx_20_Yanvar);
    station_green(id, str, file_green_line, movement);
    lock.unlock();
}

void Memar_Adjemi_green(int id, const std::string &from, const std::string &movement)
{
    std::ofstream file_green_line("output_green_line.txt", std::ios::app);
    file_green_line << id << " in way Memar Adjemi from " << from << "\n";
    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::string str = "Memar Adjemi";
    std::unique_lock<std::mutex> lock(mtx_Memar_Adjemi_green);
    station_green(id, str, file_green_line, movement);
    lock.unlock();
}

void Nasimi(int id, const std::string &from, const std::string &movement)
{
    std::ofstream file_green_line("output_green_line.txt", std::ios::app);
    file_green_line << id << " in way Nasimi from " << from << "\n";
    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::string str = "Nasimi";
    std::unique_lock<std::mutex> lock(mtx_Nasimi);
    station_green(id, str, file_green_line, movement);
    lock.unlock();
}

void Azadliq_Prospekti(int id, const std::string &from, const std::string &movement)
{
    std::ofstream file_green_line("output_green_line.txt", std::ios::app);
    file_green_line << id << " in way Azadliq Prospekti from " << from << "\n";
    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::string str = "Azadliq Prospekti";
    std::unique_lock<std::mutex> lock(mtx_Azadliq_prospekti);
    station_green(id, str, file_green_line, movement);
    lock.unlock();
}

void Darnagul(int id, const std::string &from, const std::string &movement)
{
    std::ofstream file_green_line("output_green_line.txt", std::ios::app);
    file_green_line << id << " in way Darnagul from " << from << "\n";
    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::string str = "Darnagul";
    std::unique_lock<std::mutex> lock(mtx_Darnagul);
    station_green(id, str, file_green_line, movement);
    lock.unlock();
}

//-----------------------------------------------------------------------

void train_green(int id)
{
    chill_green(id);
    Bakmil(id,"Depo", "Depo");
    int i = 0;
    while(i < 100)
    {
        Nariman_Narimanov(id, "Bakmil", "right");
        Ganjlik(id, "Nariman Narimanov", "right");
        May_28(id, "Ganjlik", "right");
        Nizami(id, "28 May", "right");
        Elmler_Akademiyasi(id, "Nizami", "right");
        Inshaatchilar(id, "Elmler Akademiyasi", "right");
        Yanvar_20(id, "Inshaatchilar", "right");
        Memar_Adjemi_green(id, "20 Yanvar", "right");
        Nasimi(id, "Memar Adjemi", "right");
        Azadliq_Prospekti(id, "Nasimi", "right");
        Darnagul(id, "Azadliq Prospekti", "right");
        chill_green(id);
        Azadliq_Prospekti(id, "Darnagul", "left");
        Nasimi(id, "Azadliq Prospekti", "left");

        
        i++;
    }
}


void train_red(int id)
{
    chill_red(id);
    Bakmil(id, "Depo", "Depo");
    int i = 0;
    while(i < 100)
    {
        Nariman_Narimanov(id, "Bakmil", "right");
        Ganjlik(id, "Nariman Narimanov", "right");
        May_28(id, "Ganjlik", "right");
        Sahil(id, "28 May", "right");
        Icherisheher(id, "Sahil", "right");
        chill_red(id);
        Sahil(id, "Icherisheher", "left");
        May_28(id, "Sahil", "left");
        Ganjlik(id, "28 May", "left");
        Nariman_Narimanov(id, "Ganjlik", "left");
        if(i % 10 == 0)
        { 
            Bakmil(id, "Nariman Narimanov", "left");
            chill_red(id);
            Nariman_Narimanov(id, "Bakmil", "right");
            Ganjlik(id, "Nariman Narimanov", "right");
            May_28(id, "Ganjlik", "right");
            Sahil(id, "28 May", "right");
            Icherisheher(id, "Sahil", "right");
            chill_red(id);
            continue;
        }
        Ulduz(id, "Nariman Narimanov", "left");
        Koroglu(id, "Ulduz", "left");
        Gara_Garayev(id, "Koroglu", "left");
        Neftchiler(id, "Gara Garayev", "left");
        Xalqlar_Dostlugu(id, "Neftchiler", "left");
        Ahmedli(id, "Xalqlar Dostlugu", "left");
        Hazi_Aslanov(id, "Ahmedli", "left");
        chill_red(id);
        Ahmedli(id, "Hazi Aslanov", "right");
        Xalqlar_Dostlugu(id, "Ahmedli", "right");
        Neftchiler(id, "Xalqlar Dostlugu", "right");
        Gara_Garayev(id, "Neftchiler", "right");
        Koroglu(id, "Gara Garayev", "right");
        Ulduz(id, "Koroglu", "right");
        Nariman_Narimanov(id, "Ulduz", "right");
        Ganjlik(id, "Nariman Narimanov", "right");
        May_28(id, "Ganjlik", "right");
        Sahil(id, "28 May", "right");
        Icherisheher(id, "Sahil", "right");
        chill_red(id);
        i++;
    }
}

void train_violet(int id)
{
    chill_violet(id);
    Xodjasan(id, "Depo", "Depo");
    int i = 0;
    while(i < 70)
    {
        Avtovogzal(id, "Xodjasan", "left");
        Memar_Adjemi_violet(id, "Avtovogzal", "left");
        Noyabr_8(id, "Memar_Adjemi", "left");
        chill_violet(id);
        Memar_Adjemi_violet(id, "8 Noyabr", "right");
        Avtovogzal(id, "Memar_Adjemi", "right");
        Xodjasan(id, "Avtovogzal", "right");
        chill_violet(id);
        i++;
    }
}

void train_light_green(int id)
{
    int i = 0;
    chill_light_green(id);
    Xatai(id, "Depo", "Depo"); // ??????????????????????????
    while(i < 40)
    {
        Cafar_Cabbarli(id, "Xatai", "right");
        Xatai(id, "Cafar Cabbarli", "left");
        i++;
    }
}

void void_red_train()
{
    std::vector<std::thread> train_red_vec;

    int num;

    for(size_t i = 0; i != 20; i++)
    {
        std::srand(std::time(nullptr));

        num = rand() % 1000;
        num += 1000;

        std::thread t_r(train_red, num);

        train_red_vec.push_back(std::move(t_r));
        
        std::this_thread::sleep_for(std::chrono::seconds(5));
    }

    for(auto &tr: train_red_vec)
    {
        tr.join();
    }
}

void void_violet_line()
{
    std::vector<std::thread> train_violet_vec;

    int num;

    for(size_t i = 0; i != 8; i++)
    {
        std::srand(std::time(nullptr));

        num = rand() % 1000;
        num += 1137;
        num %= 1000;
        num += 1000;

        std::thread t_v(train_violet, num);

        train_violet_vec.push_back(std::move(t_v));
        
        std::this_thread::sleep_for(std::chrono::seconds(5));
    }

    for(auto &tr: train_violet_vec)
    {
        tr.join();
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

void void_green_line()
{
    std::vector<std::thread> train_green_vec;

    int num;

    for(size_t i = 0; i != 20; i++)
    {
        std::srand(std::time(nullptr));

        num = rand() % 1000;
        num += 1456;
        num %= 1000;
        num += 1000;

        std::thread t_g(train_green, num);

        train_green_vec.push_back(std::move(t_g));

        std::this_thread::sleep_for(std::chrono::seconds(5));
    }

    for(auto &tr: train_green_vec)
    {
        tr.join();
    }
}

int main()
{
    std::thread red_line(void_red_train);
    std::thread violet_line(void_violet_line);
    std::thread light_green_line(void_light_green_line);

    red_line.join();
    violet_line.join();
    light_green_line.join();

    return 0;
}
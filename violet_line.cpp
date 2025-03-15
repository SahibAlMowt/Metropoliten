#include "metro.h"

std::mutex mtx_Xodjasan;
std::mutex mtx_Avtovogzal_left;
std::mutex mtx_Avtovogzal_right;
std::mutex mtx_Memar_Adjemi_violet_left;
std::mutex mtx_Memar_Adjemi_violet_right;
std::mutex mtx_8_Noyabr_left;
std::mutex mtx_8_Noyabr_right;

void chill_violet(int id)
{
    std::ofstream file_violet_line("output_violet_line.txt", std::ios::app);
    file_violet_line << id << " is chilling\n";
    std::this_thread::sleep_for(std::chrono::seconds(5));
}

void station_violet(int id, const std::string &str, std::ofstream &faylik, const std::string &from)
{
    faylik << id << " in " << str << " station from " << from << "\n";
    std::this_thread::sleep_for(std::chrono::seconds(1));
}




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
    if(movement == "left")
    {   
        std::unique_lock<std::mutex> lock(mtx_Avtovogzal_left);
        station_violet(id, str, file_violet_line, movement);
        lock.unlock();
    }
    else if(movement == "right")
    {
        std::unique_lock<std::mutex> lock(mtx_Avtovogzal_right);
        station_violet(id, str, file_violet_line, movement);
        lock.unlock();
    }
}

void Memar_Adjemi_violet(int id, const std::string &from, const std::string &movement)
{
    std::ofstream file_violet_line("output_violet_line.txt", std::ios::app);
    file_violet_line << id << " in way Memar Adjemi from " << from << "\n";
    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::string str = "Memar Adjemi";
    if(movement == "left")
    {
        std::unique_lock<std::mutex> lock(mtx_Memar_Adjemi_violet_left);
        station_violet(id, str, file_violet_line, movement);
        lock.unlock();
    }
    else if(movement == "right")
    {
        std::unique_lock<std::mutex> lock(mtx_Memar_Adjemi_violet_right);
        station_violet(id, str, file_violet_line, movement);
        lock.unlock();
    }
}

void Noyabr_8(int id, const std::string &from, const std::string &movement)
{
    std::ofstream file_violet_line("output_violet_line.txt", std::ios::app);
    file_violet_line << id << " in way 8 Noyabr from " << from << "\n";
    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::string str = "8 Noyabr";
    if(movement == "left")
    {
        std::unique_lock<std::mutex> lock(mtx_8_Noyabr_left);
        station_violet(id, str, file_violet_line, movement);
        lock.unlock();
    }
    else if(movement == "right")
    {
        std::unique_lock<std::mutex> lock(mtx_8_Noyabr_right);
        station_violet(id, str, file_violet_line, movement);
        lock.unlock();
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
        if(i == 68)
        {
            break;
        }
        Xodjasan(id, "Avtovogzal", "right");
        chill_violet(id);
        i++;
    }

    Xodjasan(id, "Avtovogzal", "right");
}

void void_violet_line()
{
    std::vector<std::thread> train_violet_vec;

    int num;

    for(size_t i = 0; i != 6; i++)
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
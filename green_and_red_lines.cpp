#include "metro.h"

std::mutex mtx_Nizami_left;
std::mutex mtx_Nizami_right;
std::mutex mtx_Elmler_Akademiyasi_left;
std::mutex mtx_Elmler_Akademiyasi_right;
std::mutex mtx_Inshaatchilar_left;
std::mutex mtx_Inshaatchilar_right;
std::mutex mtx_20_Yanvar_left;
std::mutex mtx_20_Yanvar_right;
std::mutex mtx_Memar_Adjemi_green_left;
std::mutex mtx_Memar_Adjemi_green_right;
std::mutex mtx_Nasimi_left;
std::mutex mtx_Nasimi_right;
std::mutex mtx_Azadliq_prospekti_left;
std::mutex mtx_Azadliq_prospekti_right;
std::mutex mtx_Darnagul_left;
std::mutex mtx_Darnagul_right;
std::mutex mtx_Ulduz_left;
std::mutex mtx_Ulduz_right;
std::mutex mtx_Koroglu_left;
std::mutex mtx_Koroglu_right;
std::mutex mtx_Gara_Garayev_left;
std::mutex mtx_Gara_Garayev_right; 
std::mutex mtx_Neftchiler_left;
std::mutex mtx_Neftchiler_right;
std::mutex mtx_Xalqlar_Dostlugu_left;
std::mutex mtx_Xalqlar_Dostlugu_right;
std::mutex mtx_Ahmedli_left;
std::mutex mtx_Ahmedli_right;
std::mutex mtx_Hazi_Aslanov_left;
std::mutex mtx_Hazi_Aslanov_right;
std::mutex mtx_Icherisheher_left;
std::mutex mtx_Icherisheher_right;
std::mutex mtx_Sahil_left;
std::mutex mtx_Sahil_right;
std::mutex mtx_28_May_left;
std::mutex mtx_28_May_right;
std::mutex mtx_Ganjlik_left;
std::mutex mtx_Ganjlik_right;
std::mutex mtx_Nariman_Narimanov_left;
std::mutex mtx_Nariman_Narimanov_right;
std::mutex mtx_Bakmil;

void chill_green(int id)
{
    std::ofstream file_green_line("output_green_line.txt", std::ios::app);
    file_green_line << id << " is chilling\n";
    std::this_thread::sleep_for(std::chrono::seconds(5));
}

void chill_red(int id)
{
    std::ofstream file_red_line("output_red_line.txt", std::ios::app);
    file_red_line << id << " is chilling\n";
    std::this_thread::sleep_for(std::chrono::seconds(5));
}

void station_red(int id, const std::string &str, std::ofstream &faylik, const std::string &from)
{
    faylik << id << " in " << str << " station from " << from << "\n";
    std::this_thread::sleep_for(std::chrono::seconds(1));
}

void station_green(int id, const std::string &str, std::ofstream &faylik, const std::string &from)
{
    faylik << id << " in " << str << " station from " << from << "\n";
    std::this_thread::sleep_for(std::chrono::seconds(1));
}

void Icherisheher(int id, const std::string &from, const std::string &movement)
{
    std::ofstream file_red_line("output_red_line.txt", std::ios::app);
    file_red_line << id << " in way Icherisheher from " << from << "\n";
    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::string str = "Icherisheher";
    if(movement == "left")
    {
        std::unique_lock<std::mutex> lock(mtx_Icherisheher_left);
        station_red(id, str, file_red_line, movement);
        lock.unlock();
    }
    else if(movement == "right")
    {
        std::unique_lock<std::mutex> lock(mtx_Icherisheher_right);
        station_red(id, str, file_red_line, movement);
        lock.unlock();
    }
}

void Sahil(int id, const std::string &from, const std::string &movement)
{
    std::ofstream file_red_line("output_red_line.txt", std::ios::app);
    file_red_line << id << " in way Sahil from " << from << "\n";
    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::string str = "Sahil";
    if(movement == "left")
    {
        std::unique_lock<std::mutex> lock(mtx_Sahil_left);
        station_red(id, str, file_red_line, movement);
        lock.unlock();
    }
    else if(movement == "right")
    {
        std::unique_lock<std::mutex> lock(mtx_Sahil_right);
        station_red(id, str, file_red_line, movement);
        lock.unlock();
    }
}

void May_28(int id, const std::string &from, const std::string &movement, const std::string &color)
{
    if(color == "red")
    {
        std::ofstream file_red_line("output_red_line.txt", std::ios::app);
        file_red_line << id << " in way 28 May from " << from << "\n";
        std::this_thread::sleep_for(std::chrono::seconds(3));
        std::string str = "28 May";
        if(movement == "right")
        {
            std::unique_lock<std::mutex> lock(mtx_28_May_right);
            station_red(id, str, file_red_line, movement);
            lock.unlock();
        }
        else if(movement == "left")
        {
            std::unique_lock<std::mutex> lock(mtx_28_May_left);
            station_red(id, str, file_red_line, movement);
            lock.unlock();
        }
    }
    else if(color == "green")
    {
        std::ofstream file_green_line("output_green_line.txt", std::ios::app);
        file_green_line << id << " in way 28 May from " << from << "\n";
        std::this_thread::sleep_for(std::chrono::seconds(3));
        std::string str = "28 May";
        if(movement == "left")
        {
            std::unique_lock<std::mutex> lock(mtx_28_May_left);
            station_green(id, str, file_green_line, movement);
            lock.unlock();
        }
        else if(movement == "right")
        {
            std::unique_lock<std::mutex> lock(mtx_28_May_right);
            station_red(id, str, file_green_line, movement);
            lock.unlock();
        }
    }
}

void Ganjlik(int id, const std::string &from, const std::string &movement, const std::string &color)
{
    if(color == "red")
    {
        std::ofstream file_red_line("output_red_line.txt", std::ios::app);
        file_red_line << id << " in way Ganjlik from " << from << "\n";
        std::this_thread::sleep_for(std::chrono::seconds(3));
        std::string str = "Ganjlik";
        if(movement == "left")
        {
            std::unique_lock<std::mutex> lock(mtx_Ganjlik_left);
            station_red(id, str, file_red_line, movement);
            lock.unlock();
        }
        else if(movement == "right")
        {
            std::unique_lock<std::mutex> lock(mtx_Ganjlik_right);
            station_red(id, str, file_red_line, movement);
            lock.unlock();
        }
    }
    else if(color == "green")
    {
        std::ofstream file_green_line("output_green_line.txt", std::ios::app);
        file_green_line << id << " in way Ganjlik from " << from << "\n";
        std::this_thread::sleep_for(std::chrono::seconds(3));
        std::string str = "Ganjlik";
        if(movement == "left")
        {
            std::unique_lock<std::mutex> lock(mtx_Ganjlik_left);
            station_green(id, str, file_green_line, movement);
            lock.unlock();
        }
        else if(movement == "right")
        {
            std::unique_lock<std::mutex> lock(mtx_Ganjlik_right);
            station_green(id, str, file_green_line, movement);
            lock.unlock();
        }
    }
}

void Nariman_Narimanov(int id, const std::string &from, const std::string &movement, const std::string &color)
{
    if(color == "red")
    {
        std::ofstream file_red_line("output_red_line.txt", std::ios::app);
        file_red_line << id << " in way Nariman Narimanov from " << from << "\n";
        std::this_thread::sleep_for(std::chrono::seconds(3));
        std::string str = "Nariman Narimanov";
        if(movement == "left")
        {
            std::unique_lock<std::mutex> lock(mtx_Nariman_Narimanov_left);
            station_red(id, str, file_red_line, movement);
            lock.unlock();
        }
        else if(movement == "right")
        {
            std::unique_lock<std::mutex> lock(mtx_Nariman_Narimanov_right);
            station_red(id, str, file_red_line, movement);
            lock.unlock();
        }
    }
    else if(color == "green")
    {
        std::ofstream file_green_line("output_green_line.txt", std::ios::app);
        file_green_line << id << " in way Nariman Narimanov from " << from << "\n";
        std::this_thread::sleep_for(std::chrono::seconds(3));
        std::string str = "Nariman Narimanov";
        if(movement == "left")
        {
            std::unique_lock<std::mutex> lock(mtx_Nariman_Narimanov_left);
            station_green(id, str, file_green_line, movement);
            lock.unlock();
        }
        else if(movement == "right")
        {
            std::unique_lock<std::mutex> lock(mtx_Nariman_Narimanov_right);
            station_green(id, str, file_green_line, movement);
            lock.unlock();
        }
    }
}

void Bakmil(int id, const std::string &from, const std::string &movement, const std::string &color)
{
    if(color == "red")
    {
        std::ofstream file_red_line("output_red_line.txt", std::ios::app);
        file_red_line << id << " in way Bakmil from " << from << "\n";
        std::this_thread::sleep_for(std::chrono::seconds(3));
        std::string str = "Bakmil";
        std::unique_lock<std::mutex> lock(mtx_Bakmil);
        station_red(id, str, file_red_line, movement);
        lock.unlock();
    }
    else if(color == "green")
    {
        std::ofstream file_green_line("output_green_line.txt", std::ios::app);
        file_green_line << id << " in way Bakmil from " << from << "\n";
        std::this_thread::sleep_for(std::chrono::seconds(3));
        std::string str = "Bakmil";
        std::unique_lock<std::mutex> lock(mtx_Bakmil);
        station_green(id, str, file_green_line, movement);
        lock.unlock();
    }
}

void Ulduz(int id, const std::string &from, const std::string &movement, const std::string &color)
{
    if(color == "red")
    {
        std::ofstream file_red_line("output_red_line.txt", std::ios::app);
        file_red_line << id << " in way Ulduz from " << from << "\n";
        std::this_thread::sleep_for(std::chrono::seconds(3));
        std::string str = "Ulduz";
        if(movement == "left")
        {
            std::unique_lock<std::mutex> lock(mtx_Ulduz_left);
            station_red(id, str, file_red_line, movement);
            lock.unlock();
        }
        else if(movement == "right")
        {
            std::unique_lock<std::mutex> lock(mtx_Ulduz_right);
            station_red(id, str, file_red_line, movement);
            lock.unlock();
        }
    }
    else if(color == "green")
    {
        std::ofstream file_green_line("output_green_line.txt", std::ios::app);
        file_green_line << id << " in way Ulduz from " << from << "\n";
        std::this_thread::sleep_for(std::chrono::seconds(3));
        std::string str = "Ulduz";
        if(movement == "left")
        {
            std::unique_lock<std::mutex> lock(mtx_Ulduz_left);
            station_green(id, str, file_green_line, movement);
            lock.unlock();
        }
        else if(movement == "right")
        {
            std::unique_lock<std::mutex> lock(mtx_Ulduz_right);
            station_green(id, str, file_green_line, movement);
            lock.unlock();
        }
    }
}

void Koroglu(int id, const std::string &from, const std::string &movement, const std::string &color)
{
    if(color == "red")
    {
        std::ofstream file_red_line("output_red_line.txt", std::ios::app);
        file_red_line << id << " in way Koroglu from " << from << "\n";
        std::this_thread::sleep_for(std::chrono::seconds(3));
        std::string str = "Koroglu";
        if(movement == "left")
        {
            std::unique_lock<std::mutex> lock(mtx_Koroglu_left);
            station_red(id, str, file_red_line, movement);
            lock.unlock();
        }
        else if(movement == "right")
        {
            std::unique_lock<std::mutex> lock(mtx_Koroglu_right);
            station_red(id, str, file_red_line, movement);
            lock.unlock();
        }
    }
    else if(color == "green")
    {
        std::ofstream file_green_line("output_green_line.txt", std::ios::app);
        file_green_line << id << " in way 28 May from " << from << "\n";
        std::this_thread::sleep_for(std::chrono::seconds(3));
        std::string str = "Koroglu";
        if(movement == "left")
        {
            std::unique_lock<std::mutex> lock(mtx_Koroglu_left);
            station_green(id, str, file_green_line, movement);
            lock.unlock();
        }
        else if(movement == "right")
        {
            std::unique_lock<std::mutex> lock(mtx_Koroglu_right);
            station_green(id, str, file_green_line, movement);
            lock.unlock();
        }
    }
}

void Gara_Garayev(int id, const std::string &from, const std::string &movement, const std::string &color)
{
    if(color == "red")
    {
        std::ofstream file_red_line("output_red_line.txt", std::ios::app);
        file_red_line << id << " in way Gara Garayev from " << from << "\n";
        std::this_thread::sleep_for(std::chrono::seconds(3));
        std::string str = "Gara Garayev";
        if(movement == "left")
        {
            std::unique_lock<std::mutex> lock(mtx_Gara_Garayev_left);
            station_red(id, str, file_red_line, movement);
            lock.unlock();
        }
        else if(movement == "right")
        {
            std::unique_lock<std::mutex> lock(mtx_Gara_Garayev_right);
            station_red(id, str, file_red_line, movement);
            lock.unlock();
        }
    }
    else if(color == "green")
    {
        std::ofstream file_green_line("output_green_line.txt", std::ios::app);
        file_green_line << id << " in way Gara Garayev from " << from << "\n";
        std::this_thread::sleep_for(std::chrono::seconds(3));
        std::string str = "Gara Garayev";
        if(movement == "left")
        {
            std::unique_lock<std::mutex> lock(mtx_Gara_Garayev_left);
            station_green(id, str, file_green_line, movement);
            lock.unlock();
        }
        else if(movement == "right")
        {
            std::unique_lock<std::mutex> lock(mtx_Gara_Garayev_right);
            station_green(id, str, file_green_line, movement);
            lock.unlock();
        }
    }
}

void Neftchiler(int id, const std::string &from, const std::string &movement, const std::string &color)
{
    if(color == "red")
    {
        std::ofstream file_red_line("output_red_line.txt", std::ios::app);
        file_red_line << id << " in way Neftchiler from " << from << "\n";
        std::this_thread::sleep_for(std::chrono::seconds(3));
        std::string str = "Neftchiler";
        if(movement == "left")
        {
            std::unique_lock<std::mutex> lock(mtx_Neftchiler_left);
            station_red(id, str, file_red_line, movement);
            lock.unlock();
        }
        else if(movement == "right")
        {
            std::unique_lock<std::mutex> lock(mtx_Neftchiler_right);
            station_red(id, str, file_red_line, movement);
            lock.unlock();
        }
    }
    else if(color == "green")
    {
        std::ofstream file_green_line("output_green_line.txt", std::ios::app);
        file_green_line << id << " in way Neftchiler from " << from << "\n";
        std::this_thread::sleep_for(std::chrono::seconds(3));
        std::string str = "Neftchiler";
        if(movement == "left")
        {
            std::unique_lock<std::mutex> lock(mtx_Neftchiler_left);
            station_green(id, str, file_green_line, movement);
            lock.unlock();
        }
        else if(movement == "right")
        {
            std::unique_lock<std::mutex> lock(mtx_Neftchiler_right);
            station_green(id, str, file_green_line, movement);
            lock.unlock();
        }
    }
}

void Xalqlar_Dostlugu(int id, const std::string &from, const std::string &movement, const std::string &color)
{
    if(color == "red")
    {
        std::ofstream file_red_line("output_red_line.txt", std::ios::app);
        file_red_line << id << " in way Xalqlar Dostlugu from " << from << "\n";
        std::this_thread::sleep_for(std::chrono::seconds(3));
        std::string str = "Xalqlar Dostlugu";
        if(movement == "left")
        {
            std::unique_lock<std::mutex> lock(mtx_Xalqlar_Dostlugu_left);
            station_red(id, str, file_red_line, movement);
            lock.unlock();
        }
        else if(movement == "right")
        {
            std::unique_lock<std::mutex> lock(mtx_Xalqlar_Dostlugu_right);
            station_red(id, str, file_red_line, movement);
            lock.unlock();
        }
    }
    else if(color == "green")
    {
        std::ofstream file_green_line("output_green_line.txt", std::ios::app);
        file_green_line << id << " in way Xalqlar Dostlugu from " << from << "\n";
        std::this_thread::sleep_for(std::chrono::seconds(3));
        std::string str = "Xalqlar Dostlugu";
        if(movement == "left")
        {
            std::unique_lock<std::mutex> lock(mtx_Xalqlar_Dostlugu_left);
            station_green(id, str, file_green_line, movement);
            lock.unlock();
        }
        else if(movement == "right")
        {
            std::unique_lock<std::mutex> lock(mtx_Xalqlar_Dostlugu_right);
            station_green(id, str, file_green_line, movement);
            lock.unlock();
        }
    }
}

void Ahmedli(int id, const std::string &from, const std::string &movement, const std::string &color)
{
    if(color == "red")
    {
        std::ofstream file_red_line("output_red_line.txt", std::ios::app);
        file_red_line << id << " in way Ahmedli from " << from << "\n";
        std::this_thread::sleep_for(std::chrono::seconds(3));
        std::string str = "Ahmedli";
        if(movement == "left")
        {
            std::unique_lock<std::mutex> lock(mtx_Ahmedli_left);
            station_red(id, str, file_red_line, movement);
            lock.unlock();
        }
        else if(movement == "right")
        {
            std::unique_lock<std::mutex> lock(mtx_Ahmedli_right);
            station_red(id, str, file_red_line, movement);
            lock.unlock();
        }
    }
    else
    {
        std::ofstream file_green_line("output_green_line.txt", std::ios::app);
        file_green_line << id << " in way Ahmedli from " << from << "\n";
        std::this_thread::sleep_for(std::chrono::seconds(3));
        std::string str = "Ahmedli";
        if(movement == "left")
        {
            std::unique_lock<std::mutex> lock(mtx_Ahmedli_left);
            station_green(id, str, file_green_line, movement);
            lock.unlock();
        }
        else if(movement == "right")
        {
            std::unique_lock<std::mutex> lock(mtx_Ahmedli_right);
            station_green(id, str, file_green_line, movement);
            lock.unlock();
        }
    }
}

void Hazi_Aslanov(int id, const std::string &from, const std::string &movement, const std::string &color)
{
    if(color == "red")
    {
        std::ofstream file_red_line("output_red_line.txt", std::ios::app);
        file_red_line << id << " in way Hazi Aslanov from " << from << "\n";
        std::this_thread::sleep_for(std::chrono::seconds(3));
        std::string str = "Hazi Aslanov";
        if(movement == "left")
        {
            std::unique_lock<std::mutex> lock(mtx_Hazi_Aslanov_left);
            station_red(id, str, file_red_line, movement);
            lock.unlock();
        }
        else if(movement == "right")
        {
            std::unique_lock<std::mutex> lock(mtx_Hazi_Aslanov_right);
            station_red(id, str, file_red_line, movement);
            lock.unlock();
        }
    }
    else if(color == "green")
    {
        std::ofstream file_green_line("output_green_line.txt", std::ios::app);
        file_green_line << id << " in way Hazi Aslanov from " << from << "\n";
        std::this_thread::sleep_for(std::chrono::seconds(3));
        std::string str = "Hazi Aslanov";
        if(movement == "left")
        {
            std::unique_lock<std::mutex> lock(mtx_Hazi_Aslanov_left);
            station_green(id, str, file_green_line, movement);
            lock.unlock();
        }
        else if(movement == "right")
        {
            std::unique_lock<std::mutex> lock(mtx_Hazi_Aslanov_right);
            station_green(id, str, file_green_line, movement);
            lock.unlock();
        }
    }
}

void Nizami(int id, const std::string &from, const std::string &movement)
{
    std::ofstream file_green_line("output_green_line.txt", std::ios::app);
    file_green_line << id << " in way Nizami from " << from << "\n";
    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::string str = "Nizami";
    if(movement == "left")
    {
        std::unique_lock<std::mutex> lock(mtx_Nizami_left);
        station_green(id, str, file_green_line, movement);
        lock.unlock();
    }
    else if(movement == "right")
    {
        std::unique_lock<std::mutex> lock(mtx_Nizami_right);
        station_green(id, str, file_green_line, movement);
        lock.unlock();
    }
}

void Elmler_Akademiyasi(int id, const std::string &from, const std::string &movement)
{
    std::ofstream file_green_line("output_green_line.txt", std::ios::app);
    file_green_line << id << " in way Elmler Akademiyasi from " << from << "\n";
    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::string str = "Elmler Akademiyasi";
    if(movement == "left")
    {
        std::unique_lock<std::mutex> lock(mtx_Elmler_Akademiyasi_left);
        station_green(id, str, file_green_line, movement);
        lock.unlock();
    }
    else if(movement == "right")
    {
        std::unique_lock<std::mutex> lock(mtx_Elmler_Akademiyasi_right);
        station_green(id, str, file_green_line, movement);
        lock.unlock();
    }

}

void Inshaatchilar(int id, const std::string &from, const std::string &movement)
{
    std::ofstream file_green_line("output_green_line.txt", std::ios::app);
    file_green_line << id << " in way Inshaatchilar from " << from << "\n";
    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::string str = "Inshaatchilar";
    if(movement == "left")
    {
        std::unique_lock<std::mutex> lock(mtx_Inshaatchilar_left);
        station_green(id, str, file_green_line, movement);
        lock.unlock();
    }
    else if(movement == "right")
    {
        std::unique_lock<std::mutex> lock(mtx_Inshaatchilar_right);
        station_green(id, str, file_green_line, movement);
        lock.unlock();
    }
}

void Yanvar_20(int id, const std::string &from, const std::string &movement)
{
    std::ofstream file_green_line("output_green_line.txt", std::ios::app);
    file_green_line << id << " in way 20 Yanvar from " << from << "\n";
    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::string str = "20 Yanvar";
    if(movement == "left")
    {
        std::unique_lock<std::mutex> lock(mtx_20_Yanvar_left);
        station_green(id, str, file_green_line, movement);
        lock.unlock();
    }
    else if(movement == "right")
    {
        std::unique_lock<std::mutex> lock(mtx_20_Yanvar_right);
        station_green(id, str, file_green_line, movement);
        lock.unlock();
    }
}

void Memar_Adjemi_green(int id, const std::string &from, const std::string &movement)
{
    std::ofstream file_green_line("output_green_line.txt", std::ios::app);
    file_green_line << id << " in way Memar Adjemi from " << from << "\n";
    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::string str = "Memar Adjemi";
    if(movement == "left")
    {
        std::unique_lock<std::mutex> lock(mtx_Memar_Adjemi_green_left);
        station_green(id, str, file_green_line, movement);
        lock.unlock();
    }
    else if(movement == "right")
    {
        std::unique_lock<std::mutex> lock(mtx_Memar_Adjemi_green_right);
        station_green(id, str, file_green_line, movement);
        lock.unlock();
    }
}

void Nasimi(int id, const std::string &from, const std::string &movement)
{
    std::ofstream file_green_line("output_green_line.txt", std::ios::app);
    file_green_line << id << " in way Nasimi from " << from << "\n";
    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::string str = "Nasimi";
    if(movement == "left")
    {
        std::unique_lock<std::mutex> lock(mtx_Nasimi_left);
        station_green(id, str, file_green_line, movement);
        lock.unlock();
    }
    else if(movement == "right")
    {
        std::unique_lock<std::mutex> lock(mtx_Nasimi_right);
        station_green(id, str, file_green_line, movement);
        lock.unlock();
    }
}

void Azadliq_Prospekti(int id, const std::string &from, const std::string &movement)
{
    std::ofstream file_green_line("output_green_line.txt", std::ios::app);
    file_green_line << id << " in way Azadliq Prospekti from " << from << "\n";
    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::string str = "Azadliq Prospekti";
    if(movement == "left")
    {   
        std::unique_lock<std::mutex> lock(mtx_Azadliq_prospekti_left);
        station_green(id, str, file_green_line, movement);
        lock.unlock();
    }
    else if(movement == "right")
    {
        std::unique_lock<std::mutex> lock(mtx_Azadliq_prospekti_right);
        station_green(id, str, file_green_line, movement);
        lock.unlock();
    }
}

void Darnagul(int id, const std::string &from, const std::string &movement)
{
    std::ofstream file_green_line("output_green_line.txt", std::ios::app);
    file_green_line << id << " in way Darnagul from " << from << "\n";
    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::string str = "Darnagul";
    if(movement == "left")
    {
        std::unique_lock<std::mutex> lock(mtx_Darnagul_left);
        station_green(id, str, file_green_line, movement);
        lock.unlock();
    }
    else if(movement == "right")
    {
        std::unique_lock<std::mutex> lock(mtx_Darnagul_right);
        station_green(id, str, file_green_line, movement);
        lock.unlock();
    }
}

void train_green(int id)
{
    chill_green(id);
    Bakmil(id,"Depo", "Depo", "green");
    int i = 0;
    while(i < 100)
    {
        Nariman_Narimanov(id, "Bakmil", "right", "green");
        if(i == 98)
        {
            break;
        }
        Ganjlik(id, "Nariman Narimanov", "right", "green");
        May_28(id, "Ganjlik", "right", "green");
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
        Memar_Adjemi_green(id, "Nasimi", "left");
        Yanvar_20(id, "Memar Adjemi", "left");
        Inshaatchilar(id, "20 Yanvar", "left");
        Elmler_Akademiyasi(id, "Inshaatchilar", "left");
        Nizami(id, "Elmler Akademiyasi", "left");
        May_28(id, "Nizami", "left", "green");
        Ganjlik(id, "28 May", "left", "green");
        Nariman_Narimanov(id, "Ganjlik", "left", "green");
        if(i % 10 == 0)
        { 
            Bakmil(id, "Nariman Narimanov", "left", "green");
            chill_green(id);
            continue;
        }
        Ulduz(id, "Nariman Narimanov", "left", "green");
        Koroglu(id, "Ulduz", "left", "green");
        Gara_Garayev(id, "Koroglu", "left", "green");
        Neftchiler(id, "Gara Garayev", "left", "green");
        Xalqlar_Dostlugu(id, "Neftchiler", "left", "green");
        Ahmedli(id, "Xalqlar Dostlugu", "left", "green");
        Hazi_Aslanov(id, "Ahmedli", "left", "green");
        chill_red(id);
        Ahmedli(id, "Hazi Aslanov", "right", "green");
        Xalqlar_Dostlugu(id, "Ahmedli", "right", "green");
        Neftchiler(id, "Xalqlar Dostlugu", "right", "green");
        Gara_Garayev(id, "Neftchiler", "right", "green");
        Koroglu(id, "Gara Garayev", "right", "green");
        Ulduz(id, "Koroglu", "right", "green");
        i++;
    }

    Bakmil(id,"Nariman Narimanov", "left", "green");
}

void train_red(int id)
{
    chill_red(id);
    Bakmil(id, "Depo", "Depo", "red");
    int i = 0;
    while(i < 100)
    {
        Nariman_Narimanov(id, "Bakmil", "right", "red");
        Ganjlik(id, "Nariman Narimanov", "right", "red");
        May_28(id, "Ganjlik", "right", "red");
        Sahil(id, "28 May", "right");
        Icherisheher(id, "Sahil", "right");
        chill_red(id);
        Sahil(id, "Icherisheher", "left");
        May_28(id, "Sahil", "left", "red");
        Ganjlik(id, "28 May", "left", "red");
        Nariman_Narimanov(id, "Ganjlik", "left", "red");
        if(i == 98)
        {
            break;
        }
        if(i % 10 == 0)
        { 
            Bakmil(id, "Nariman Narimanov", "left", "red");
            chill_red(id);
            continue;
        }
        Ulduz(id, "Nariman Narimanov", "left", "red");
        Koroglu(id, "Ulduz", "left", "red");
        Gara_Garayev(id, "Koroglu", "left", "red");
        Neftchiler(id, "Gara Garayev", "left", "red");
        Xalqlar_Dostlugu(id, "Neftchiler", "left", "red");
        Ahmedli(id, "Xalqlar Dostlugu", "left", "red");
        Hazi_Aslanov(id, "Ahmedli", "left", "red");
        chill_red(id);
        Ahmedli(id, "Hazi Aslanov", "right", "red");
        Xalqlar_Dostlugu(id, "Ahmedli", "right", "red");
        Neftchiler(id, "Xalqlar Dostlugu", "right", "red");
        Gara_Garayev(id, "Neftchiler", "right", "red");
        Koroglu(id, "Gara Garayev", "right", "red");
        Ulduz(id, "Koroglu", "right", "red");
        Nariman_Narimanov(id, "Ulduz", "right", "red");
        Ganjlik(id, "Nariman Narimanov", "right", "red");
        May_28(id, "Ganjlik", "right", "red");
        Sahil(id, "28 May", "right");
        Icherisheher(id, "Sahil", "right");
        chill_red(id);
        i++;
    }

    Bakmil(id, "Nariman Narimanov", "left", "red");
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
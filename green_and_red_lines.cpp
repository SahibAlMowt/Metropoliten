#include "metro.h"

#define MAKE_RED_COLOR(text) "<span style='color:red;'>" text "</span>"
#define MAKE_GREEN_COLOR(text) "<span style='color:green;'>" text "</span>"

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


std::mutex g_time_mutex;
int g_hours = 5;
int g_minutes = 0;

std::mutex r_time_mutex;
int r_hours = 5;
int r_minutes = 0;

void g_update_time(int add_minutes)
{
    std::lock_guard<std::mutex> lock(g_time_mutex);
    g_minutes += add_minutes;
    
    while (g_minutes >= 60) 
    {
        g_minutes -= 60;
        g_hours++;
    }
    
    if (g_hours >= 24)
    {
        g_hours -= 24; 
    } 
}

std::string g_get_time()
{
    std::lock_guard<std::mutex> lock(g_time_mutex);
    std::ostringstream oss;

    oss << std::setw(2) << std::setfill('0') << g_hours << ":"
        << std::setw(2) << std::setfill('0') << g_minutes;

    return oss.str();
}

void g_sleep(int sim_minutes)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(100 * sim_minutes));
    g_update_time(sim_minutes);
}


void r_update_time(int add_minutes)
{
    std::lock_guard<std::mutex> lock(r_time_mutex);
    r_minutes += add_minutes;
    
    while (r_minutes >= 60) 
    {
        r_minutes -= 60;
        r_hours++;
    }
    
    if (r_hours >= 24)
    {
        r_hours -= 24; 
    } 
}

std::string r_get_time()
{
    std::lock_guard<std::mutex> lock(r_time_mutex);
    std::ostringstream oss;

    oss << std::setw(2) << std::setfill('0') << r_hours << ":"
        << std::setw(2) << std::setfill('0') << r_minutes;

    return oss.str();
}

void r_sleep(int sim_minutes)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(100 * sim_minutes));
    r_update_time(sim_minutes);
}



void chill_green(int id)
{
    std::ofstream file_green_line("output_green_line.md", std::ios::app);
    file_green_line << id << " is chilling\n\n";
    g_sleep(5);
}

void chill_red(int id)
{
    std::ofstream file_red_line("output_red_line.md", std::ios::app);
    file_red_line << id << " is chilling\n\n";
    r_sleep(5);
}

void station_red(int id, const std::string &str, std::ofstream &faylik, const std::string &from)
{
    faylik << id << " in " << str << " station from " << from << " in " << r_get_time() << "\n\n";
    r_sleep(1);
}

void station_green(int id, const std::string &str, std::ofstream &faylik, const std::string &from)
{
    faylik << id << " in " << str << " station from " << from << " in " << g_get_time() << "\n\n" ;
    g_sleep(1);
}

void Icherisheher(int id, const std::string &from, const std::string &movement)
{
    std::ofstream file_red_line("output_red_line.md", std::ios::app);
    file_red_line << id << " in way " << MAKE_RED_COLOR("Icherisheher") << " from " << from << " in " << r_get_time() << "\n\n";
    r_sleep(3);
    std::string str = MAKE_RED_COLOR("Icherisheher");
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
    std::ofstream file_red_line("output_red_line.md", std::ios::app);
    file_red_line << id << " in way " << MAKE_RED_COLOR("Sahil") << " from " << from << " in " << r_get_time() << "\n\n";
    r_sleep(3);
    std::string str = MAKE_RED_COLOR("Sahil") ;
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
        std::ofstream file_red_line("output_red_line.md", std::ios::app);
        file_red_line << id << " in way " << MAKE_RED_COLOR("28 May") << " from " << from << " in " << r_get_time() << "\n\n";
        r_sleep(3);
        std::string str = MAKE_RED_COLOR("28 May");
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
        std::ofstream file_green_line("output_green_line.md", std::ios::app);
        file_green_line << id << " in way " << MAKE_GREEN_COLOR("28 May") << " from " << from << " in " << g_get_time() << "\n\n";
        g_sleep(3);
        std::string str = MAKE_GREEN_COLOR("28 May");
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
        std::ofstream file_red_line("output_red_line.md", std::ios::app);
        file_red_line << id << " in way " << MAKE_RED_COLOR("Ganjlik") << " from " << from << " in " << r_get_time() << "\n\n";
        r_sleep(3);
        std::string str = MAKE_RED_COLOR("Ganjlik");
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
        std::ofstream file_green_line("output_green_line.md", std::ios::app);
        file_green_line << id << " in way " << MAKE_GREEN_COLOR("Ganjlik") << " from " << from << " in " << g_get_time() << "\n\n";
        g_sleep(3);
        std::string str = MAKE_GREEN_COLOR("Ganjlik");
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
        std::ofstream file_red_line("output_red_line.md", std::ios::app);
        file_red_line << id << " in way " << MAKE_RED_COLOR("Nariman Narimanov") << " from " << from << " in " << r_get_time() << "\n\n";
        r_sleep(3);
        std::string str = MAKE_RED_COLOR("Nariman Narimanov");
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
        std::ofstream file_green_line("output_green_line.md", std::ios::app);
        file_green_line << id << " in way " << MAKE_GREEN_COLOR("Nariman Narimanov") << " from " << from << " in " << g_get_time() << "\n\n";
        g_sleep(3);
        std::string str = MAKE_GREEN_COLOR("Nariman Narimanov");
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
        std::ofstream file_red_line("output_red_line.md", std::ios::app);
        file_red_line << id << " in way " << MAKE_RED_COLOR("Bakmil") << " from " << from << " in " << r_get_time() << "\n\n";
        r_sleep(3);
        std::string str = MAKE_RED_COLOR("Bakmil");
        std::unique_lock<std::mutex> lock(mtx_Bakmil);
        station_red(id, str, file_red_line, movement);
        lock.unlock();
    }
    else if(color == "green")
    {
        std::ofstream file_green_line("output_green_line.md", std::ios::app);
        file_green_line << id << " in way " << MAKE_GREEN_COLOR("Bakmil") << " from " << from << " in " << g_get_time() <<  "\n\n";
        g_sleep(3);
        std::string str = MAKE_GREEN_COLOR("Bakmil");
        std::unique_lock<std::mutex> lock(mtx_Bakmil);
        station_green(id, str, file_green_line, movement);
        lock.unlock();
    }
}

void Ulduz(int id, const std::string &from, const std::string &movement, const std::string &color)
{
    if(color == "red")
    {
        std::ofstream file_red_line("output_red_line.md", std::ios::app);
        file_red_line << id << " in way " << MAKE_RED_COLOR("Ulduz") << " from " << from << " in " << r_get_time() << "\n\n";
        r_sleep(3);
        std::string str = MAKE_RED_COLOR("Ulduz");
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
        std::ofstream file_green_line("output_green_line.md", std::ios::app);
        file_green_line << id << " in way " << MAKE_GREEN_COLOR("Ulduz") << " from " << from << " in " << g_get_time() <<  "\n\n";
        g_sleep(3);
        std::string str = MAKE_GREEN_COLOR("Ulduz");
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
        std::ofstream file_red_line("output_red_line.md", std::ios::app);
        file_red_line << id << " in way " << MAKE_RED_COLOR("Koroglu") << " from " << from << " in " << r_get_time() <<  "\n\n";
        r_sleep(3);
        std::string str = MAKE_RED_COLOR("Koroglu");
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
        std::ofstream file_green_line("output_green_line.md", std::ios::app);
        file_green_line << id << " in way " << MAKE_GREEN_COLOR("Koroglu") << " from " << from << " in " << g_get_time() << "\n\n";
        g_sleep(3);
        std::string str = MAKE_GREEN_COLOR("Koroglu");
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
        std::ofstream file_red_line("output_red_line.md", std::ios::app);
        file_red_line << id << " in way " << MAKE_RED_COLOR("Gara Garayev") << " from " << from << " in " << r_get_time() <<  "\n\n";
        r_sleep(3);
        std::string str = MAKE_RED_COLOR("Gara Garayev");
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
        std::ofstream file_green_line("output_green_line.md", std::ios::app);
        file_green_line << id << " in way " << MAKE_GREEN_COLOR("Gara Garayev") << " from " << from << " in " << g_get_time() << "\n\n";
        g_sleep(3);
        std::string str = MAKE_GREEN_COLOR("Gara Garayev");
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
        std::ofstream file_red_line("output_red_line.md", std::ios::app);
        file_red_line << id << " in way " << MAKE_RED_COLOR("Neftchiler") << " from " << from << " in " << r_get_time() << "\n\n";
        r_sleep(3);
        std::string str = MAKE_RED_COLOR("Neftchiler");
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
        std::ofstream file_green_line("output_green_line.md", std::ios::app);
        file_green_line << id << " in way " << MAKE_GREEN_COLOR("Neftchiler") << " from " << from << " in " << g_get_time() << "\n\n";
        g_sleep(3);
        std::string str = MAKE_GREEN_COLOR("Neftchiler");
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
        std::ofstream file_red_line("output_red_line.md", std::ios::app);
        file_red_line << id << " in way " << MAKE_RED_COLOR("Xalqlar Dostlugu") << " from " << from << " in " << r_get_time() << "\n\n";
        r_sleep(3);
        std::string str = MAKE_RED_COLOR("Xalqlar Dostlugu");
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
        std::ofstream file_green_line("output_green_line.md", std::ios::app);
        file_green_line << id << " in way " << MAKE_GREEN_COLOR("Xalqlar Dostlugu") << " from " << from << " in " << g_get_time() <<  "\n\n";
        g_sleep(3);
        std::string str = MAKE_GREEN_COLOR("Xalqlar Dostlugu");
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
        std::ofstream file_red_line("output_red_line.md", std::ios::app);
        file_red_line << id << " in way " << MAKE_RED_COLOR("Ahmedli") << " from " << from << " in " << r_get_time() << "\n\n";
        r_sleep(3);
        std::string str = MAKE_RED_COLOR("Ahmedli");
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
    else if(color == "green")
    {
        std::ofstream file_green_line("output_green_line.md", std::ios::app);
        file_green_line << id << " in way " << MAKE_GREEN_COLOR("Ahmedli") << " from " << from << " in " << g_get_time() << "\n\n";
        g_sleep(3);
        std::string str = MAKE_GREEN_COLOR("Ahmedli");
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
        std::ofstream file_red_line("output_red_line.md", std::ios::app);
        file_red_line << id << " in way " << MAKE_RED_COLOR("Hazi Aslanov") << " from " << from << " in " << r_get_time() << "\n\n";
        r_sleep(3);
        std::string str = MAKE_RED_COLOR("Hazi Aslanov");
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
        std::ofstream file_green_line("output_green_line.md", std::ios::app);
        file_green_line << id << " in way " << MAKE_GREEN_COLOR("Hazi Aslanov") << " from " << from << " in " << g_get_time() << "\n\n";
        g_sleep(3);
        std::string str = MAKE_GREEN_COLOR("Hazi Aslanov");
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
    std::ofstream file_green_line("output_green_line.md", std::ios::app);
    file_green_line << id << " in way " << MAKE_GREEN_COLOR("Nizami") << " from " << from << " in " << g_get_time() << "\n\n";
    g_sleep(3);
    std::string str = MAKE_GREEN_COLOR("Nizami");
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
    std::ofstream file_green_line("output_green_line.md", std::ios::app);
    file_green_line << id << " in way " << MAKE_GREEN_COLOR("Elmlər Akademiyası") << " from " << from << " in " << g_get_time() << "\n\n";
    g_sleep(3);
    std::string str = MAKE_GREEN_COLOR("Elmler Akademiyasi");
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
    std::ofstream file_green_line("output_green_line.md", std::ios::app);
    file_green_line << id << " in way " << MAKE_GREEN_COLOR("Inshaatchilar") << " from " << from << " in " << g_get_time() << "\n\n";
    g_sleep(3);
    std::string str = MAKE_GREEN_COLOR("Inshaatchilar");
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
    std::ofstream file_green_line("output_green_line.md", std::ios::app);
    file_green_line << id << " in way " << MAKE_GREEN_COLOR("20 Yanvar") << " from " << from <<  " in " << r_get_time() << "\n\n";
    g_sleep(3);
    std::string str = MAKE_GREEN_COLOR("20 Yanvar");
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
    std::ofstream file_green_line("output_green_line.md", std::ios::app);
    file_green_line << id << " in way " << MAKE_GREEN_COLOR("Memar Adjemi") << " from " << from << " in " << g_get_time() << "\n\n";
    g_sleep(3);
    std::string str = MAKE_GREEN_COLOR("Memar Adjemi");
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
    std::ofstream file_green_line("output_green_line.md", std::ios::app);
    file_green_line << id << " in way " << MAKE_GREEN_COLOR("Nasimi") << " from " << from << " in " << g_get_time() << "\n\n";
    g_sleep(3);
    std::string str = MAKE_GREEN_COLOR("Nasimi");
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
    std::ofstream file_green_line("output_green_line.md", std::ios::app);
    file_green_line << id << " in way " << MAKE_GREEN_COLOR("Azadliq Prospekti") << " from " << from << " in " << g_get_time << "\n\n";
    g_sleep(3);
    std::string str = MAKE_GREEN_COLOR("Azadliq Prospekti");
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
    std::ofstream file_green_line("output_green_line.md", std::ios::app);
    file_green_line << id << " in way " << MAKE_GREEN_COLOR("Darnagul") << " from " << from << " in " << g_get_time() << "\n\n";
    g_sleep(3);
    std::string str = MAKE_GREEN_COLOR("Darnagul");
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
    while(i < 4)
    {
        Nariman_Narimanov(id, MAKE_GREEN_COLOR("Bakmil"), "right", "green");
        if(i == 3)
        {
            break;
        }
        Ganjlik(id, MAKE_GREEN_COLOR("Nariman Narimanov"), "right", "green");
        May_28(id, MAKE_GREEN_COLOR("Ganjlik"), "right", "green");
        Nizami(id, MAKE_GREEN_COLOR("28 May"), "right");
        Elmler_Akademiyasi(id, MAKE_GREEN_COLOR("Nizami"), "right");
        Inshaatchilar(id, MAKE_GREEN_COLOR("Elmler Akademiyasi"), "right");
        Yanvar_20(id, MAKE_GREEN_COLOR("Inshaatchilar"), "right");
        Memar_Adjemi_green(id, MAKE_GREEN_COLOR("20 Yanvar"), "right");
        Nasimi(id, MAKE_GREEN_COLOR("Memar Adjemi"), "right");
        Azadliq_Prospekti(id, MAKE_GREEN_COLOR("Nasimi"), "right");
        Darnagul(id, MAKE_GREEN_COLOR("Azadliq Prospekti"), "right");
        chill_green(id);
        Azadliq_Prospekti(id, MAKE_GREEN_COLOR("Darnagul"), "left");
        Nasimi(id, MAKE_GREEN_COLOR("Azadliq Prospekti"), "left");
        Memar_Adjemi_green(id, MAKE_GREEN_COLOR("Nasimi"), "left");
        Yanvar_20(id, MAKE_GREEN_COLOR("Memar Adjemi"), "left");
        Inshaatchilar(id, MAKE_GREEN_COLOR("20 Yanvar"), "left");
        Elmler_Akademiyasi(id, MAKE_GREEN_COLOR("Inshaatchilar"), "left");
        Nizami(id, MAKE_GREEN_COLOR("Elmler Akademiyasi"), "left");
        May_28(id, MAKE_GREEN_COLOR("Nizami"), "left", "green");
        Ganjlik(id, MAKE_GREEN_COLOR("May"), "left", "green");
        Nariman_Narimanov(id, MAKE_GREEN_COLOR("Ganjlik"), "left", "green");
        if(i == 1 && i < 1501)
        { 
            Bakmil(id, MAKE_GREEN_COLOR("Nariman Narimanov"), "left", "green");
            chill_green(id);
            continue;
        }
        Ulduz(id, MAKE_GREEN_COLOR("Nariman Narimanov"), "left", "green");
        Koroglu(id, MAKE_GREEN_COLOR("Ulduz"), "left", "green");
        Gara_Garayev(id, MAKE_GREEN_COLOR("Koroglu"), "left", "green");
        Neftchiler(id, MAKE_GREEN_COLOR("Gara Garayev"), "left", "green");
        Xalqlar_Dostlugu(id, MAKE_GREEN_COLOR("Neftchiler"), "left", "green");
        Ahmedli(id, MAKE_GREEN_COLOR("Xalqlar Dostlugu"), "left", "green");
        Hazi_Aslanov(id, MAKE_GREEN_COLOR("Ahmedli"), "left", "green");
        chill_red(id);
        Ahmedli(id, MAKE_GREEN_COLOR("Hazi Aslanov"), "right", "green");
        Xalqlar_Dostlugu(id, MAKE_GREEN_COLOR("Ahmedli"), "right", "green");
        Neftchiler(id, MAKE_GREEN_COLOR("Xalqlar Dostlugu"), "right", "green");
        Gara_Garayev(id, MAKE_GREEN_COLOR("Neftchiler"), "right", "green");
        Koroglu(id, MAKE_GREEN_COLOR("Gara Garayev"), "right", "green");
        Ulduz(id, MAKE_GREEN_COLOR("Koroglu"), "right", "green");
        i++;
    }

    Bakmil(id,MAKE_GREEN_COLOR("Nariman Narimanov"), "left", "green");
}

void train_red(int id)
{
    chill_red(id);
    Bakmil(id, "Depo", "Depo", "red");
    int i = 0;
    while(i < 3)
    {
        Nariman_Narimanov(id, MAKE_RED_COLOR("Bakmil"), "right", "red");
        Ganjlik(id, MAKE_RED_COLOR("Nariman Narimanov"), "right", "red");
        May_28(id, MAKE_RED_COLOR("Ganjlik"), "right", "red");
        Sahil(id, MAKE_RED_COLOR("28 May"), "right");
        Icherisheher(id, MAKE_RED_COLOR("Sahil"), "right");
        chill_red(id);
        Sahil(id, MAKE_RED_COLOR("Icherisheher"), "left");
        May_28(id, MAKE_RED_COLOR("Sahil"), "left", "red");
        Ganjlik(id, MAKE_RED_COLOR("28 May"), "left", "red");
        Nariman_Narimanov(id, MAKE_RED_COLOR("Ganjlik"), "left", "red");
        if(i == 2)
        {
            break;
        }
        if(i == 1 && id < 1501)
        { 
            Bakmil(id, MAKE_RED_COLOR("Nariman Narimanov"), "left", "red");
            chill_red(id);
            continue;
        }
        Ulduz(id, MAKE_RED_COLOR("Nariman Narimanov"), "left", "red");
        Koroglu(id, MAKE_RED_COLOR("Ulduz"), "left", "red");
        Gara_Garayev(id, MAKE_RED_COLOR("Koroglu"), "left", "red");
        Neftchiler(id, MAKE_RED_COLOR("Gara Garayev"), "left", "red");
        Xalqlar_Dostlugu(id, MAKE_RED_COLOR("Neftchiler"), "left", "red");
        Ahmedli(id, MAKE_RED_COLOR("Xalqlar Dostlugu"), "left", "red");
        Hazi_Aslanov(id, MAKE_RED_COLOR("Ahmedli"), "left", "red");
        chill_red(id);
        Ahmedli(id, MAKE_RED_COLOR("Hazi Aslanov"), "right", "red");
        Xalqlar_Dostlugu(id, MAKE_RED_COLOR("Ahmedli"), "right", "red");
        Neftchiler(id, MAKE_RED_COLOR("Xalqlar Dostlugu"), "right", "red");
        Gara_Garayev(id, MAKE_RED_COLOR("Neftchiler"), "right", "red");
        Koroglu(id, MAKE_RED_COLOR("Gara Garayev"), "right", "red");
        Ulduz(id, MAKE_RED_COLOR("Koroglu"), "right", "red");
        Nariman_Narimanov(id, MAKE_RED_COLOR("Ulduz"), "right", "red");
        Ganjlik(id, MAKE_RED_COLOR("Nariman Narimanov"), "right", "red");
        May_28(id, MAKE_RED_COLOR("Ganjlik"), "right", "red");
        Sahil(id, MAKE_RED_COLOR("28 May"), "right");
        Icherisheher(id, MAKE_RED_COLOR("Sahil"), "right");
        chill_red(id);
        i++;
    }

    Bakmil(id, MAKE_RED_COLOR("Nariman Narimanov"), "left", "red");
}

void void_red_train()
{
    std::vector<std::thread> train_red_vec;

    int num;

    std::srand(std::time(nullptr));

    for(size_t i = 0; i != 10; i++)
    {
        
        num = rand() % 1000;
        num += 1000;

        std::thread t_r(train_red, num);

        train_red_vec.push_back(std::move(t_r));
        
        r_sleep(5);
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

    std::srand(std::time(nullptr));

    for(size_t i = 0; i != 10; i++)
    {

        num = rand() % 1000;
        num += 1456;
        num %= 1000;
        num += 1000;

        std::thread t_g(train_green, num);

        train_green_vec.push_back(std::move(t_g));

        g_sleep(5);
    }

    for(auto &tr: train_green_vec)
    {
        tr.join();
    }
}
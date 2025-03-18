#include "metro.h"

// male header file !

#define MAKE_LIGHT_GREEN_COLOR(text) "<span style='color:#90EE90;'>" text "</span>"

std::mutex mtx_Cafar_Cabbarli;
std::mutex mtx_Xatai;

std::mutex l_g_time_mutex;
int l_g_hours = 5;
int l_g_minutes = 0;

void l_g_update_time(int add_minutes)
{
    std::lock_guard<std::mutex> lock(l_g_time_mutex);
    l_g_minutes += add_minutes;
    
    while (l_g_minutes >= 60) {
        l_g_minutes -= 60;
        l_g_hours++;
    }
    
    if (l_g_hours >= 24)
    {
        l_g_hours -= 24; 
    } 
}

std::string l_g_get_time()
{
    std::lock_guard<std::mutex> lock(l_g_time_mutex);
    std::ostringstream oss;
    oss << std::setw(2) << std::setfill('0') << l_g_hours << ":"
        << std::setw(2) << std::setfill('0') << l_g_minutes;
    return oss.str();
}

void l_g_sleep(int sim_minutes)
{
    std::this_thread::sleep_for(std::chrono::seconds(sim_minutes));
    l_g_update_time(sim_minutes);
}




void chill_light_green(int id)
{
    std::ofstream file_light_green_line("output_light_green_line.md", std::ios::app);
    file_light_green_line << id << " is chilling\n\n";
    l_g_sleep(5);
}

void station_light_green(int id, const std::string &str, std::ofstream &faylik, const std::string &from)
{
    faylik << id << " in " << str << " station from " << from << " in " << l_g_get_time() << "\n\n";
    l_g_sleep(1);
}




void Cafar_Cabbarli(int id, const std::string &from, const std::string &movement)
{
    std::ofstream file_light_green_line("output_light_green_line.md", std::ios::app);
    file_light_green_line << id << " in way " << MAKE_LIGHT_GREEN_COLOR("Cafar Cabbarli") << " from " << from << " in " << l_g_get_time() << "\n\n";
    l_g_sleep(3);
    std::string str = MAKE_LIGHT_GREEN_COLOR("Cafar Cabbarli");
    std::unique_lock<std::mutex> lock(mtx_Cafar_Cabbarli);
    station_light_green(id, str, file_light_green_line, movement);
    lock.unlock();
}

void Xatai(int id, const std::string &from, const std::string &movement)
{
    std::ofstream file_light_green_line("output_light_green_line.md", std::ios::app);
    file_light_green_line << id << " in way " << MAKE_LIGHT_GREEN_COLOR("Xatai") << " from " << from << " in " << l_g_get_time() << "\n\n";
    l_g_sleep(3);
    std::string str = MAKE_LIGHT_GREEN_COLOR("Xatai");
    std::unique_lock<std::mutex> lock(mtx_Xatai);
    station_light_green(id, str, file_light_green_line, movement);
    lock.unlock();
}

void train_light_green(int id)
{
    int i = 0;
    chill_light_green(id);
    Xatai(id, "Depo", "Depo");
    while(i < 70)
    {
        Cafar_Cabbarli(id, MAKE_LIGHT_GREEN_COLOR("Xatai"), "right");
        Xatai(id, MAKE_LIGHT_GREEN_COLOR("Cafar Cabbarli"), "left");
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
        
        l_g_sleep(5);
    }

    for(auto &tr: train_light_green_vec)
    {
        tr.join();
    }
}
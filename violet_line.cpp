#include "metro.h"

#define MAKE_VIOLET_COLOR(text) "<span style='color:purple;'>" text "</span>"

std::mutex mtx_Xodjasan;
std::mutex mtx_Avtovogzal_left;
std::mutex mtx_Avtovogzal_right;
std::mutex mtx_Memar_Adjemi_violet_left;
std::mutex mtx_Memar_Adjemi_violet_right;
std::mutex mtx_8_Noyabr_left;
std::mutex mtx_8_Noyabr_right;

std::mutex time_mutex;
int sim_hours = 5;
int sim_minutes = 0;

void update_time(int add_minutes)
{
    std::lock_guard<std::mutex> lock(time_mutex);
    sim_minutes += add_minutes;
    
    while (sim_minutes >= 60) {
        sim_minutes -= 60;
        sim_hours++;
    }
    
    if (sim_hours >= 24)
    {
        sim_hours -= 24; 
    } 
}

std::string get_time()
{
    std::lock_guard<std::mutex> lock(time_mutex);
    std::ostringstream oss;
    oss << std::setw(2) << std::setfill('0') << sim_hours << ":"
        << std::setw(2) << std::setfill('0') << sim_minutes;
    return oss.str();
}

void scaled_sleep(int sim_minutes)
{
    std::this_thread::sleep_for(std::chrono::seconds(sim_minutes));
    update_time(sim_minutes);
}



void chill_violet(int id)
{
    std::ofstream file_violet_line("output_violet_line.md", std::ios::app);
    file_violet_line << id << " is chilling\n\n";
    scaled_sleep(5);
}

void station_violet(int id, const std::string &str, std::ofstream &faylik, const std::string &from)
{
    faylik << id << " in " << str << " station from " << from << " in " << get_time() << "\n\n";
    scaled_sleep(1);
}




void Xodjasan(int id, const std::string &from, const std::string &movement)
{
    std::ofstream file_violet_line("output_violet_line.md", std::ios::app);
    file_violet_line << id << " in way " << MAKE_VIOLET_COLOR("Xodjasan") << " from " << from << " time " << get_time() << "\n\n";
    scaled_sleep(3);
    std::string str = MAKE_VIOLET_COLOR("Xodjasan");
    std::unique_lock<std::mutex> lock(mtx_Xodjasan);
    station_violet(id, str, file_violet_line, movement);
    lock.unlock();
}

void Avtovogzal(int id, const std::string &from, const std::string &movement)
{
    std::ofstream file_violet_line("output_violet_line.md", std::ios::app);
    file_violet_line << id << " in way " << MAKE_VIOLET_COLOR("Avtovogzal") << " from " << from << " time " << get_time() << "\n\n";
    scaled_sleep(3);
    std::string str = MAKE_VIOLET_COLOR("Avtovogzal");
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
    std::ofstream file_violet_line("output_violet_line.md", std::ios::app);
    file_violet_line << id << " in way " << MAKE_VIOLET_COLOR("Memar Adjemi") << " from " << from << " time " << get_time() << "\n\n";
    scaled_sleep(3);
    std::string str = MAKE_VIOLET_COLOR("Memar Adjemi");
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
    std::ofstream file_violet_line("output_violet_line.md", std::ios::app);
    file_violet_line << id << " in way " << MAKE_VIOLET_COLOR("8 Noyabr") << " from " << from << " time " << get_time() << "\n\n";
    scaled_sleep(3);
    std::string str = MAKE_VIOLET_COLOR("8 Noyabr");
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
        Avtovogzal(id, MAKE_VIOLET_COLOR("Xodjasan"), "left");
        Memar_Adjemi_violet(id, MAKE_VIOLET_COLOR("Avtovogzal"), "left");
        Noyabr_8(id, MAKE_VIOLET_COLOR("Memar Adjemi"), "left");
        chill_violet(id);
        Memar_Adjemi_violet(id, MAKE_VIOLET_COLOR("8 Noyabr"), "right");
        Avtovogzal(id, MAKE_VIOLET_COLOR("Memar Adjemi"), "right");
        if(i == 68)
        {
            break;
        }
        Xodjasan(id, MAKE_VIOLET_COLOR("Avtovogzal"), "right");
        chill_violet(id);
        i++;
    }

    Xodjasan(id, MAKE_VIOLET_COLOR("Avtovogzal"), "right");
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
        
        scaled_sleep(5);
    }

    for(auto &tr: train_violet_vec)
    {
        tr.join();
    }
}
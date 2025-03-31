#ifndef METRO_HPP
#define METRO_HPP

#include <iostream>
#include <fstream>
#include <thread>
#include <string>
#include <chrono>
#include <mutex>
#include <vector>
#include <map>
#include <iomanip>
#include <sstream>

namespace sam
{
    struct Station
    {
        std::string name;
        std::string next;
        std::string previous;
    };

    void fill_green_and_red_line(std::map<std::string, sam::Station> &stations);
    void get_mtx();

    extern std::map<std::string, std::mutex> gr_stations_mtx;

    namespace red_line
    {
        class Red_line
        {
        private:
            std::map<std::string, Station> stations;

            std::mutex time_mtx;
            std::mutex file_mtx;

            const int measure = 3;
            int hours = 5;
            int minutes = 0;

            std::ofstream filename;

            void update_time(const int &add_time);
            std::string get_time();
            void sleep(const int &add_time);


        public:
            Red_line();
            ~Red_line();
            void start();
            bool is_working_time();
            void fill_stations();
            void move_train(const size_t &train_id, const std::string &start_station);

            void write_to_file(const std::string &message); 
        };
    }

    namespace violet_line
    {
        class Violet_line
        {
        private:
            std::map<std::string, Station> stations;
            std::map<std::string, std::mutex> stations_mtx;

            std::mutex time_mtx;
            std::mutex file_mtx;

            const int measure = 3;
            const int start_hour = 5;
            const int end_hour = 1;

            std::ofstream filename;

        public:
            Violet_line();
            ~Violet_line();

            void start();
            bool is_working_time(const int &hour);
            void fill_stations();
            void move_train(const size_t &train_id, const std::string &start_station, int &virtual_hour, int &virtual_minutes);

            void write_to_file(const std::string &message);
        };
    }

    namespace light_green_line
    {
        class Light_green_line
        {
        private:

            std::map<std::string, Station> stations;
            std::map<std::string, std::mutex> stations_mtx;

            std::mutex time_mtx;
            std::mutex file_mtx;

            const int measure = 3;
            const int start_hour = 5;
            const int end_hour = 1;

            std::ofstream filename;

        public:
            
            Light_green_line();
            ~Light_green_line();

            void start();
            bool is_working_time(const int &hour);
            void fill_stations();
            void move_train(const size_t &train_id, const std::string &start_station, int &virtual_hour, int &virtual_minutes);

            void write_to_file(const std::string &message);
        };
    }

    namespace green_line
    {
        class Green_line
        {
        private:

            std::map<std::string, Station> stations;

            std::mutex time_mtx;
            std::mutex file_mtx;

            const int measure = 3;
            int hours = 5;
            int minutes = 0;

            std::ofstream filename;

            void update_time(const int &add_time);
            std::string get_time();
            void sleep(const int &add_time);

        public:
            
            Green_line();
            ~Green_line();

            void start();
            bool is_working_time();
            void fill_stations();
            void move_train(const size_t &train_id, const std::string &start_station);

            void write_to_file(const std::string &message);
        };
    }
}

#endif //METRO_HPP
#ifndef METRO_H
#define METRO_H

#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <fstream>

#include <iomanip>

//-----------------------------------------------
// add.cpp

void website();
void map_pdf();

//-------------------------------------------------
//  play with time

void l_g_update_time(int add_minutes);
std::string l_g_get_time();
void l_g_sleep(int sim_minutes);

void v_update_time(int add_minutes);
std::string v_get_time();
void v_sleep(int sim_minutes);

void g_update_time(int add_minutes);
std::string g_get_time();
void g_sleep(int sim_minutes);

void r_update_time(int add_minutes);
std::string r_get_time();
void r_sleep(int sim_minutes);


//-----------------------------------------------

//-----------------------------------------------
//  light_green_line.cpp

void chill_light_green(int id);
void station_light_green(int id, const std::string &str, std::ofstream &faylik, const std::string &from);

void Cafar_Cabbarli(int id, const std::string &from, const std::string &movement, std::ofstream &file_light_green_line);
void Xatai(int id, const std::string &from, const std::string &movement, std::ofstream &file_light_green_line);

void train_light_green(int id);
void void_light_green_line();

//-----------------------------------------------


//-----------------------------------------------
//  violet_line.cpp

void chill_violet(int id);
void station_violet(int id, const std::string &str, std::ofstream &faylik, const std::string &from);

void Xodjasan(int id, const std::string &from, const std::string &movement);
void Avtovogzal(int id, const std::string &from, const std::string &movement);
void Memar_Adjemi_violet(int id, const std::string &from, const std::string &movement);
void Noyabr_8(int id, const std::string &from, const std::string &movement);

void train_violet(int id);
void void_violet_line();

//-----------------------------------------------


//-----------------------------------------------
//  green_and_red_lines.cpp

void chill_red(int id);
void chill_green(int id);
void station_red(int id, const std::string &str, std::ofstream &faylik, const std::string &from);
void station_green(int id, const std::string &str, std::ofstream &faylik, const std::string &from);

void Bakmil(int id, const std::string &from, const std::string &movement, const std::string &color);
void Nariman_Narimanov(int id, const std::string &from, const std::string &movement, const std::string &color);
void Ganjlik(int id, const std::string &from, const std::string &movement, const std::string &color);
void May_28(int id, const std::string &from, const std::string &movement, const std::string &color);
void Sahil(int id, const std::string &from, const std::string &movement);
void Icherisheher(int id, const std::string &from, const std::string &movement);
void Ulduz(int id, const std::string &from, const std::string &movement, const std::string &color);
void Koroglu(int id, const std::string &from, const std::string &movement, const std::string &color);
void Gara_Garayev(int id, const std::string &from, const std::string &movement, const std::string &color);
void Neftchiler(int id, const std::string &from, const std::string &movement, const std::string &color);
void Xalqlar_Dostlugu(int id, const std::string &from, const std::string &movement, const std::string &color);
void Ahmedli(int id, const std::string &from, const std::string &movement, const std::string &color);
void Hazi_Aslanov(int id, const std::string &from, const std::string &movement, const std::string &color);
void Darnagul(int id, const std::string &from, const std::string &movement);
void Azadliq_Prospekti(int id, const std::string &from, const std::string &movement);
void Nasimi(int id, const std::string &from, const std::string &movement);
void Memar_Adjemi_green(int id, const std::string &from, const std::string &movement);
void Nizami(int id, const std::string &from, const std::string &movement);
void Elmler_Akademiyasi(int id, const std::string &from, const std::string &movement);
void Inshaatchilar(int id, const std::string &from, const std::string &movement);
void Yanvar_20(int id, const std::string &from, const std::string &movement);

void train_green(int id);
void train_red(int id);

void void_red_train();
void void_green_line();

//-----------------------------------------------

#endif //METRO_H
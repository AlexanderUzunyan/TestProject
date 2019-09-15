//============================================
//Programm "neuro" for weights computation
//neuro.hpp :: header-file
//Created by Alexander Uzunyan august 2019
//============================================
#ifndef neuro_hpp
#define neuro_hpp

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>


class pilot
{
  private:
   
    double height;
    double body_weight;
    int age;
    char e_color;
    char male_0;
    char eyes_color[4] = {'g'};
    //char eyes_color[4] = {'g', 'b', 'w', 's'};
    char male[2] = {'m', 'f'};
    

  public:
 
    int debug;
    int counter;
    time_t random_point;
    double weight;
    std::ofstream out;

    pilot(int debug, int counter);
    pilot();//dlia inicializacii massiva char
   
    void status_begin();
    void generator();
    void fill_parameters();  
    void probability_calculation();
    void print_parameters();
    void open_file();
    void input_file_stream();
    void close_file();

};

#endif 

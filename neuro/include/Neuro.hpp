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
#include <random>


class pilot
{
  private:
   
    double height;
    double body_weight;
    int age;
    int e_color;
    int e_all_color;
    int sex;

  public:
 
    int debug;
    int counter;
    time_t random_point;
    double weight;
    double weight1;
    std::ofstream out;
    std::ofstream out1;

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

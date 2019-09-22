//============================================
//Programm "neuro" for weights computation
//neuro.hpp :: header-file
//Created by Alexander Uzunyan august 2019
//For compile:g++ --std=c++11 -c neuro.hpp -o Neuro.o
//============================================
#define Neuro_cpp
#include "Neuro.hpp"
using namespace std;

pilot::pilot(int _debug, int _counter){

  debug = _debug;
  counter = _counter;
  random_point = time(NULL);
  
}
//======================================
//======================================
pilot::pilot(){
 
  // eyes_color = {'g', 'b', 'w'};
  //male = {'m', 'f'};

}
//======================================
//======================================
void pilot::status_begin(){

  cout << "Constructor succeed" << endl;

}
//======================================
//======================================
void pilot::generator(){

  srand(random_point);
  random_point++;

}
//======================================
//======================================
void pilot::fill_parameters(){

  height = rand() % 25 + 150;
  body_weight = rand() % 35 + 40;
  age = rand() % 20 + 25;
  e_color = rand() % 1;
  e_all_color = rand() %4;  
  sex =  rand() % 2;

}
//======================================
//======================================
void pilot::probability_calculation(){

  weight = 1*height + 2*body_weight + 2*age + 0.3*int(e_color) + 0.2*int(sex);
  if(e_color == 0) {weight = weight * 1.5;} 

}
//======================================
//======================================
void pilot::print_parameters(){

   cout << "Pilot`s parameters: " << 
     " " << "height:" << height <<
     " " << "Body_weight:" << body_weight <<
     " " << "Age:" << age << 
     " " << "Eyes_color:" << e_color << 
     " " << "Sex:" << sex << 
     " " << "Weight:" << weight <<  
   endl;
   
}
//======================================
//======================================
void pilot::open_file(){

  out.open("neuro_signal.dat");
  out1.open("neuro_back.dat");
  cout << "File is opened" << endl;

}
//======================================
//======================================
void pilot::input_file_stream(){
  
   if(out==NULL){
    cout << "File is not opend" << endl;
    exit(1);
    }else{
    out << height << 
      " " << body_weight <<
      " " << age <<
      " " << e_color << 
      " " << sex <<
      " " << weight <<
    endl;
   }

 if(out1==NULL){
    out1 << "File is not opend" << endl;
    exit(1);
    }else{
    out1 << height << 
      " " << body_weight <<
      " " << age <<
      " " << e_all_color << 
      " " << sex <<
      " " << weight <<
    endl;
   }
}
//======================================
//======================================
void pilot::close_file(){
  
  out.close();
  out1.close();
  cout << "File is closed" << endl;

}

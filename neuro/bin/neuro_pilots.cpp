//============================================
//Programm "neuro" for weights computation
//neuro.hpp :: header-file
//Created by Alexander Uzunyan august 2019
//For compile:g++ --std=c++11 neuro.cpp -L ./Neuro.o -o neuro
//============================================
#include "Neuro.hpp"
using namespace std;
//===============================================


int main(int argc, char** argv)
{
  if(argc < 3){
    cout << "Usage:: " << argv[0] << 
     " " << " Debug Counter " << 
    endl;
    cout << "Example: " << argv[0] << " 2 56 " << endl; 
    exit(1);
  }
  
  int debug = atoi(argv[1]);
  int counter = atoi(argv[2]);
  pilot p(debug, counter);

  p.status_begin();
  p.open_file();

   for(int i = 0; i < counter; i++){ 
     p.generator();
     p.fill_parameters();
     p.probability_calculation();
 
     if(debug == 2){
       p.print_parameters();
     }

     p.input_file_stream();
   }
  p.close_file();

 
}


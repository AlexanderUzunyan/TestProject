//============================================
//Programm "neuro" for weights computation
//neuro.hpp :: header-file
//Created by Alexander Uzunyan august 2019
//For compile:g++ --std=c++11 neuro.cpp -L ./Neuro.o -o neuro
//============================================
#include "neuro.hpp"
using namespace std;
//===============================================

// struct pilot_param{
//   double height;
//   double body_weight;
//   int age;
//   char e_color;
//   char male_0;
//   char eyes_color[4] = {'g', 'b', 'w', 's'};
//   char male[2] = {'m', 'f'};
// };

// void file_open(FILE* file);
// void file_close();
// void fill_tree();

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

//   pilot_param pilots;
//   FILE* fp = fopen("staff.dat", "r");
 
}
//===============================================

// void file_open(FILE* file);

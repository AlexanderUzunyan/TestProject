//============================================
//Programm "neuro" for weights computation and tree creation
//Neuro.hpp , Tree.hpp :: header-files
//Created by Alexander Uzunyan august 2019
//============================================
#include "Neuro.hpp"
#include "Tree.hpp"
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
  int N_records = atoi(argv[2]);
  pilot* sp = new pilot(debug, N_records, "signal", 0);
  sp->generator();
  delete sp;

  pilot* bp = new pilot(debug, N_records, "background", 1);
  bp->generator();
  delete bp;

}


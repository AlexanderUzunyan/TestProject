//============================================
//Programm "neuro" for weights computation
//neuro.hpp :: header-file
//Created by Alexander Uzunyan august 2019
//For compile:g++ --std=c++11 neuro.cpp -L ./Neuro.o -o neuro
//For compilation: g++ tree.cpp Tree.cpp --std=c++11  -L../lib  -lTreePlayer -lMinuit -lGui  $(root-config --libs) -lGpad  -lGX11 -lX3d  -o tree 

//============================================
//#include "neuro.hpp"
#include "Tree.hpp"
using namespace std;
//===============================================


int main(int argc, char** argv)
{
  if (argc < 2){
    cout << "debug: " << endl;
    cout << "Ex: " << argv[0] << " 1" << endl; 
    exit(1);
  }

  int debug = atoi(argv[1]);

  tree_pilot tree(debug);

  tree.file_dat_open();
  tree.file_root_open();
  tree.fill_tree();
  tree.file_close();

}
//===============================================


//============================================
//Programm "neuro" for weights computation
//tree.hpp :: header-file
//Created by Alexander Uzunyan september 2019
//For compilation:  g++ --std=c++11 -c Tree.cpp -o Tree.o 
//============================================
#define Tree_cpp
#include "Tree.hpp"
using namespace std;

tree_pilot::tree_pilot(int _debug){

  debug = _debug;
}
//======================================
//======================================
void tree_pilot::file_dat_open(){

  file1 = fopen("neuro_back.dat", "r");

  file1 = fopen("neuro_signal.dat", "r");


  if (debug == 2){
  cout << ":File_dat_open: " << endl;
  }

  if (file1 == NULL){
     cout << "File is not opened" << endl;
  }
}
//======================================
//======================================
void tree_pilot::fill_tree(){

   TTree* tree = new TTree("T", "neuro data from ascii file");
   tree1 = new TTree("T", "neuro data from ascii file");
  

   if (tree1 != NULL && tree != NULL){
     cout << "Trees are created" << endl;
   }

   tree->Branch("Pilot Death propobility",&pilot_param,"nr/I:age/I:e_color/I:sex/I:height/D:body_weight/D:death_propability/D");
   tree1->Branch("Pilot Death propobility",&pilot_param,"nr/I:age/I:e_color/I:sex/I:height/D:body_weight/D:death_propability/D");
 
   pilot_param.nr = 0;
   f = new TFile("neuro_back.root", "RECREATE");
   while(fgets(line,49,file)){
     sscanf(&line[0],"%lf %lf %d %d %d %lf",&pilot_param.height,&pilot_param.body_weight,&pilot_param.age,&pilot_param.eyes_color,&pilot_param.sex,&pilot_param.death_propability); 
     pilot_param.nr++;
     tree -> Fill();
   }
   tree->Write();

   pilot_param.nr = 0;
   f1 = new TFile("neuro_signal.root", "RECREATE");
   while(fgets(line,49,file1)){
     sscanf(&line[0],"%lf %lf %d %d %d %lf",&pilot_param.height,&pilot_param.body_weight,&pilot_param.age,&pilot_param.eyes_color,&pilot_param.sex,&pilot_param.death_propability); 
     pilot_param.nr++;
     tree1 -> Fill();
   }
   tree1->Write();
    
   cout << "passed fill " << endl;
   cout << "passed write " << endl;
   f->Close();
   f1->Close();
   cout << "passed close " << endl;
}

void tree_pilot::tree_print(){

  tree->Print();
  tree1->Print();
}
//======================================
//======================================
void tree_pilot::file_close(){
  
  fclose(file);
  fclose(file1);
}

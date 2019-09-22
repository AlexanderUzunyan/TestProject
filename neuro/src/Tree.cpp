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

  file = fopen("neuro_signal.dat", "r");

  file1 = fopen("neuro_back.dat", "r");


   
  if (debug == 2){
  cout << ":File_dat_open: " << endl;
  }

  if (file == NULL){
     cout << "File is not opened" << endl;
  }
}
//======================================
//======================================
void tree_pilot::file_root_open(){

   f = new TFile("neuro_signal.root", "RECREATE");

   f1 = new TFile("neuro_back.root", "RECREATE");
   
   if (debug == 2){
     cout << ":file_root_open: " << endl;
   }

   if (f == NULL){
     cout << "File is not opened" << endl;
   }

}
//======================================
//======================================
void tree_pilot::fill_tree(){

  tree = new TTree("T", "neuro data from ascii file");
  tree1 = new TTree("T", "neuro data from ascii file");
  

   if (tree != NULL){
     cout << "Tree is created" << endl;
   }

   tree->Branch("Pilot Death propobility",&pilot_param,"nr/I:age/I:e_color/I:sex/I:height/D:body_weight/D:death_propability/D");
   tree1->Branch("Pilot Death propobility",&pilot_param,"nr/I:age/I:e_color/I:sex/I:height/D:body_weight/D:death_propability/D");
   
   cout << "Branch is created" << endl;
   //  pilot_param.nr=0;
   // fgets(line,49,file);
   // cout << "line: " << endl;
   // sscanf(&line[0],"%lf %lf %d %d %d %lf",&pilot_param.height,&pilot_param.body_weight,&pilot_param.age,&pilot_param.eyes_color,&pilot_param.sex,&pilot_param.death_propability);
   // cout << "pilot_param.death_propability: " << pilot_param.death_propability << endl;
      
   // tree->Fill();
   //
 
  while(fgets(line,49,file)){
      sscanf(&line[0],"%lf %lf %d %d %d %lf",&pilot_param.height,&pilot_param.body_weight,&pilot_param.age,&pilot_param.eyes_color,&pilot_param.sex,&pilot_param.death_propability);
      cout << "pilot_param.death_propability: " << pilot_param.death_propability << endl;
      pilot_param.nr++;    
//     //sscanf(&line[0],"%f%f%d",&pilot_param.height,&pilot_param.body_weight,&pilot_param.age);
//     //sscanf(&line[40],"%d%d%f",&pilot_param.eyes_color,&pilot_param.male,&pilot_param.death_propability);
     tree -> Fill();
  }

    while(fgets(line,49,file1)){
      sscanf(&line[0],"%lf %lf %d %d %d %lf",&pilot_param.height,&pilot_param.body_weight,&pilot_param.age,&pilot_param.eyes_color,&pilot_param.sex,&pilot_param.death_propability);
      cout << "pilot_param.death_propability: " << pilot_param.death_propability << endl;
      pilot_param.nr++;    
//     //sscanf(&line[0],"%f%f%d",&pilot_param.height,&pilot_param.body_weight,&pilot_param.age);
//     //sscanf(&line[40],"%d%d%f",&pilot_param.eyes_color,&pilot_param.male,&pilot_param.death_propability);
     tree1 -> Fill();
  }


  //  if (debug == 2){
  //  cout << "Tree is filled: " << endl;
    
   cout << "passed fill " << endl;
   tree->Write();
   tree1->Write();
   cout << "passed write " << endl;
   f->Close();
   f1->Close();
   cout << "passed close " << endl;

  //}
}

void tree_pilot::tree_print(){

  tree->Print();
}
//======================================
//======================================
void tree_pilot::file_close(){
  
  fclose(file);
}

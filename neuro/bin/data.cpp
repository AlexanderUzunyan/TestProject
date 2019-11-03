//============================================
//Programm "neuro" for weights computation
//data.cpp :: program-file
//Created by Alexander Uzunyan november 2019
//============================================

#include "TRandom.h"
#include "TROOT.h"
#include "TMath.h"
#include "TTree.h"
#include "TArrayD.h"
#include "TStyle.h"
#include "TFile.h"
#include "TRandom.h"
#include "Riostream.h"
#include "TCanvas.h"
#include "TMatrixD.h"
#include "TH2F.h"
#include "TLegend.h"
#include "TBranch.h"

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <random>

void generator();  
void fill_record(); 
void print_record();  
void write_record();
void open_file();       
void close_file(); 
void print_record();    

struct PilotRecord{ //Pilot`s data
        float nr; //Record number
	float age;
	float eyecolor;
	float sex;
	float height;
	float weight;
        float record_weight;//record`s weight
    };

    int Nrecords;         
    std::string fnameASCII; 
    std::string fnameROOT; 
    int debug;            
    int datatype;         
    TRandom Rndm;         
    std::ofstream out;    
    std::ifstream in;     
    PilotRecord pilotRecord; 
    TFile* f;
    TTree* tree;
    std::string str;

using namespace std;

int main(int argc, char** argv)
{

  if(argc < 3){
    cout << "Usage:: " << argv[0] << 
     " " << " Level_debug Counter " << 
    endl;
    cout << "Example: " << argv[0] << " 2 56 " << endl; 
    exit(1);
  }

  debug = atoi(argv[1]);
  Nrecords = atoi(argv[2]); 
  fnameASCII = "ASCII_test.dat";
  fnameROOT = "signal_test.root";

  tree = new TTree("Tree", "neuro data from ASCII file");
  f = new TFile(fnameROOT.c_str(), "RECREATE");
  tree->Branch("pilotRecord", &pilotRecord.nr,"nr/F:age/F:eyecolor/F:sex/F:height/F:weight/F:record_weight/F");

  for(int i = 0; i < Nrecords; i++){ 
    open_file();
    fill_record();
    write_record();
    tree -> Fill();
    if(debug == 1){print_record();}
    }
   tree -> Write();
   f->Close();
   close_file();

}

//======================================
void fill_record(){

  pilotRecord.height = Rndm.Gaus(700, 100);
  pilotRecord.weight =  Rndm.Uniform(0,2);
  pilotRecord.age = Rndm.Gaus(32.5, 12.5);
  pilotRecord.eyecolor = Rndm.Gaus(400, 50);
  pilotRecord.sex = Rndm.Gaus(57.5,17.5);
  pilotRecord.record_weight =  Rndm.Gaus(10, 2);
  
}

void print_record(){

   cout << "Print record: " << 
     " " << "height:" << pilotRecord.height <<
     " " << "Body_weight:" << pilotRecord.weight <<
     " " << "Age:" << pilotRecord.age << 
     " " << "Eye_color:" << pilotRecord.eyecolor << 
     " " << "Sex:" << pilotRecord.sex << 
     " " << "Weight:" << pilotRecord.record_weight <<  
   endl;
     
}

void open_file(){

  out.open(fnameASCII);
   if(out==NULL){
     out << "I can`t open OutputFile " << fnameASCII << endl;
    exit(1);
   }else{
     cout << "OutputFile " << fnameASCII << " is opened" << endl;
   }

}

void write_record(){
  
  out << pilotRecord.height << 
      " " << pilotRecord.weight <<
      " " << pilotRecord.age <<
      " " << pilotRecord.eyecolor << 
      " " << pilotRecord.sex <<
      " " << pilotRecord.record_weight <<
    endl;

    if(debug > 1){
      print_record();
    }

}

void close_file(){
  
  out.close();
  cout << "OutputFile " << fnameASCII << " is closed" << endl;

}

void generator(){

  open_file();

   for(int i = 0; i < Nrecords; i++){ 
     fill_record();
     write_record();
     tree -> Fill();
     if(debug == 1){print_record();}
     // generate_rootfiles();
   }
   tree -> Write();
   f->Close();
   close_file();

}

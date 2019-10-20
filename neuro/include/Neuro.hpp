//============================================
//Programm "neuro" for weights computation
//neuro.hpp :: header-file
//Created by Alexander Uzunyan august 2019
//============================================
#ifndef neuro_hpp
#define neuro_hpp

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


struct PilotRecord{ //Pilot`s data
        int nr; //Record number
	int age;
	int eyecolor;
	double sex;
	double height;
	double weight;
        double record_weight;//record`s weight
    };

class pilot
{
  private:   
    int Nrecords;         //Numbers of records
    std::string fnameASCII; //Name of outpit file
    std::string fnameROOT;  //Name of output root file
    int debug;            //debug level
    int datatype;         //Type of data(signal or background)
    //Internal parameters
    TRandom Rndm;         //Random number generators
    std::ofstream out;    //ASCII output stream
    std::ifstream in;     //ASCII input stream
    //Output data
    PilotRecord pilotRecord; //Struct pilot record

    //RootTree
    TFile* f;
    TTree* tree;
    std::string str;

  public:
    //Constructor
    pilot(int debug, int Nrecords, std::string fnameASCII, int datatype);
   
    //Functions
    void SetDebug(int _debug){ debug = _debug;}
    std::string GetFname(){return fnameASCII;}
    void generator();        //Generate output files with N records
    void fill_record();      //Fils one record
    void record_weight();    //Calculates record`s weight
    void print_record();     //Prints record
    void write_record();     //Writes record
    void open_file();       //ASCII Files open
    void close_file();      //ASCII files close
    void test_func();       //Test rand() function;
    void generate_rootfiles(); //Rootfiles creation


};

#endif 

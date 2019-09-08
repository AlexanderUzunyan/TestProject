//============================================
//Programm "neuro" for weights computation
//tree.hpp :: header-file
//Created by Alexander Uzunyan september 2019
//============================================
#ifndef tree_hpp
#define tree_hpp

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <stdio.h>

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

class tree_pilot
{
  public:
    
    struct pilot_param_{
	double height;
	double body_weight;
	int age;
	int eyes_color; 
	int male;
	double death_propability;
    };
    pilot_param_ pilot_param;

    int debug;

    FILE* file;
    TFile* f;
    TTree* tree;
    char line[50];

    tree_pilot(int debug);

    void file_dat_open();
    void file_root_open();
    void fill_tree();
    void tree_print();
    void file_close();
   
};
#endif

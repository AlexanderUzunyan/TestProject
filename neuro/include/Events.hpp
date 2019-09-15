//============================================
//Programm "neuro" for weights computation
//tree.hpp :: header-file
//Created by Alexander Uzunyan september 2019
//============================================
#ifndef Tree_hpp
#define Tree_hpp

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

class pilot_parameters
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
    int level_debug;
    pilot_parameters(int level_debug);

  
   
};
#endif

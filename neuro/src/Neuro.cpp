//============================================
//Programm "neuro" for weights computation
//neuro.hpp :: header-file
//Created by Alexander Uzunyan august 2019
//For compile:g++ --std=c++11 -c neuro.hpp -o Neuro.o
//============================================
#define Neuro_cpp
#include "Neuro.hpp"
using namespace std;

pilot::pilot(int _debug, int _Nrecords, std::string _basename, int _datatype){

  debug = _debug;
  Nrecords = _Nrecords;
  unsigned int seconds = time(NULL);
  fnameASCII = _basename + ".dat";
  fnameROOT = _basename + ".root";
  datatype = _datatype;
  Rndm.SetSeed(seconds);
  if(datatype == 1){Rndm.SetSeed(seconds+1);}
  pilotRecord.nr = 0;

  tree = new TTree("Tree", "neuro data from ASCII file");
  f = new TFile(fnameROOT.c_str(), "RECREATE");
  tree->Branch("Pilot Death probability", &pilotRecord,"nr/I:age/I:eyecolor/I:sex/D:height/D:weight/D:record_weight/D");
  
}
//======================================
//======================================
void pilot::test_func(){

//   cout << Rndm.Integer(5) << endl;
//   cout << Rndm.Integer(5) << endl;
//   cout << Rndm.Gaus(0,1) << endl;
//   cout << Rndm.Gaus(0,1) << endl;
//   cout << Rndm.Uniform(1,3) << endl;
//   cout << Rndm.Uniform(1,3) << endl;
}
//======================================
//======================================
void pilot::fill_record(){

  double MeaneEyecolor = 460;
  if(datatype == 0){
    MeaneEyecolor = 580;
  }

  pilotRecord.height = Rndm.Gaus(162.5, 12.5);
  pilotRecord.weight = Rndm.Gaus(57.5,17.5);
  pilotRecord.age = Rndm.Gaus(32.5, 12.5);
  pilotRecord.eyecolor = Rndm.Gaus(MeaneEyecolor, 20);
  pilotRecord.sex = Rndm.Uniform(0,2);
  
}
//======================================
//======================================
void pilot::record_weight(){

  pilotRecord.record_weight = 1*pilotRecord.height + 2*pilotRecord.weight + 2*pilotRecord.age + 0.3*pilotRecord.eyecolor + 0.2*pilotRecord.sex;
  if(440 <= pilotRecord.eyecolor && pilotRecord.eyecolor <= 480) {pilotRecord.record_weight *= 1.5;} 
  cout << "record " << pilotRecord.record_weight << endl;
 
}
//======================================
//======================================
void pilot::print_record(){

   cout << "Print record: " << 
     " " << "height:" << pilotRecord.height <<
     " " << "Body_weight:" << pilotRecord.weight <<
     " " << "Age:" << pilotRecord.age << 
     " " << "Eye_color:" << pilotRecord.eyecolor << 
     " " << "Sex:" << pilotRecord.sex << 
     " " << "Weight:" << pilotRecord.record_weight <<  
   endl;
     
}
//======================================
//======================================
void pilot::open_file(){

  out.open(fnameASCII);
   if(out==NULL){
     out << "I can`t open OutputFile " << fnameASCII << endl;
    exit(1);
   }else{
     cout << "OutputFile " << fnameASCII << " is opened" << endl;
   }

}
//======================================
//======================================
void pilot::write_record(){
  
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
//======================================
//======================================
void pilot::close_file(){
  
  out.close();
  cout << "OutputFile " << fnameASCII << " is closed" << endl;

}
//======================================
//======================================
void pilot::generator(){

  open_file();

   for(int i = 0; i < Nrecords; i++){ 
     fill_record();
     record_weight();
     write_record();
     tree -> Fill();
     if(debug == 1){print_record();}
     // generate_rootfiles();
   }
   tree -> Write();
   f->Close();
   close_file();

}
//======================================
//======================================
void pilot::generate_rootfiles(){

//   getline(cin, str);
//   f << str << endl;
//   pilotRecord.nr++;
//   tree -> Fill();
//   tree -> Write();

//  TTree* tree = new TTree("Tree", "neuro data from ASCII file");

//   if (tree == NULL){
//     cout << "Tree are not created" << endl;
//   }

//   tree->Branch("Pilot Death probability", &pilotRecord,"nr/I:age/I:e_color/I:sex/I:height/D:weight/D:record_weight/D");

//   char line[50];
//   while(fgets(line,49, )){
//     sscanf(&line[0],"%lf %lf %d %d %d %lf",&pilotRecord.height,&pilotRecord.weight,&pilotRecord.age,&pilotRecord.eyecolor,&pilotRecord.sex,&pilotRecord.record_weight); 
//     pilotRecord.nr++;
//     tree -> Fill();
//    }
//    tree->Write();
//    f->Close();


}
//======================================
//======================================

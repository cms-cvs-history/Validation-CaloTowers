
#include <iostream.h>
#include "TFile.h"
#include "TTree.h"
#include "TText.h"

void hcaloval(const char* run = "HB", const char* noise = "noise", const char* drawhist = "none"){
  gROOT ->Reset();
  if (drawhist == "ps"){
    TCanvas *hcal = new TCanvas("Hcal","Hcal",0,0,707,500 );
    TString figure;
    figure = "figure";
    figure += run;
    figure += ".ps";
    ps = new TPostScript(figure , -112);
    ps->Range(29.7 , 21.0);
  }

  char name[50] ;
  char det[10] = run;
 
  TString PathToRef = "../data/";
  TString rfilename;
  rfilename = PathToRef+ "CaloTowersValidation" +run + noise + "_ref.root";
 

  TString sfilename= "";
  sfilename = sfilename +  "CaloTowersValidation" +run + noise + ".root";


  delete gROOT->GetListOfFiles()->FindObject(rfilename);
  delete gROOT->GetListOfFiles()->FindObject(sfilename);


  TFile * rfile = new TFile(rfilename);
  TFile * sfile = new TFile(sfilename);

  rfile->cd("DQMData/HcalRecHitTask");
  gDirectory->ls();

  sfile->cd("DQMData/HcalRecHitTask");
  gDirectory->ls();

  Char_t histo[200];

  gStyle->SetOptStat("n");

  gROOT->ProcessLine(".x HistoCompare.C");
  HistoCompare * myPV = new HistoCompare();
  TString hname;

 


    TH1* meOld;
    hname = "DQMData/HcalRecHitTask/CaloTowersTask_energy_ECAL";
    hname = hname + ";1";
    cout << "Processing: " <<  hname << endl;
    rfile->GetObject(hname  , meOld  );
 
    TH1* meNew;
    sfile->GetObject(hname ,  meNew );
    myPV->PVCompute(meOld ,meNew , "gif", noise, run);


    TH1* meOld;
    hname = "DQMData/HcalRecHitTask/CaloTowersTask_energy_HCAL";
    hname = hname + ";1";
    cout << "Processing: " <<  hname << endl;
    rfile->GetObject(hname  , meOld  );
 
    TH1* meNew;
    sfile->GetObject(hname ,  meNew );
    myPV->PVCompute(meOld ,meNew , "gif", noise, run);


    TH1* meOld;
    hname = "DQMData/HcalRecHitTask/CaloTowersTask_energy_HcalPlusEcalPlusHO";
    hname = hname + ";1";
    cout << "Processing: " <<  hname << endl;
    rfile->GetObject(hname  , meOld  );
 
    TH1* meNew;
    sfile->GetObject(hname ,  meNew );
    myPV->PVCompute(meOld ,meNew , "gif", noise, run);


   TH1* meOld;
    hname = "DQMData/HcalRecHitTask/CaloTowersTask_number_of_fired_towers";
    hname = hname + ";1";
    cout << "Processing: " <<  hname << endl;
    rfile->GetObject(hname  , meOld  );
 
    TH1* meNew;
    sfile->GetObject(hname ,  meNew );
    myPV->PVCompute(meOld ,meNew , "gif", noise, run);

} 

  

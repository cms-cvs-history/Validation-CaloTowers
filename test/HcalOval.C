#include <iostream>
// comparison of digi histograms with reference ones.
//  root -b -q hcaloval.C\(\"HB\"\) - just for PV comparison.
//  root -b -q hcaloval.C\(\"HB\",\"gif\"\) - PV comparison and creation of gif for each histo
//  root -b -q hcaloval.C\(\"HB\",\"ps\"\) - PV comparison and creation of ps file for each subdetector

#include "TFile.h"
#include "TTree.h"
#include "TText.h"
#include "TStyle.h"
#include "TPostScript.h"
#include "TString.h"

class HcalOval
{
public:
  HcalOval(const char* runtype, const char* drawhisto="none", string path2ref = "../data/", string path2data ="");
  ~HcalOval();

  void process(string name, string subdet);
  void runNoise();
  void runStandard();
  void runProfile();
  void runNone();
  void runAll();


private:
  string path2ref;
  string path2data;
  string run;
  string drawhist;
  bool isNoise;
  TFile * rfile;
  TFile * sfile;
  TCanvas * canvas;
  TPostScript * ps;
};


HcalOval::HcalOval(const char* runtype, const char* drawhisto, string path2ref, string path2data)
: run(runtype),
  drawhist(drawhisto),
  isNoise(runtype == "_noise"),
  rfile(0),
  sfile(0),
  canvas(0),
  ps(0)
{
  gROOT->Reset();
  if(drawhist == "ps"){
    canvas = new TCanvas("Hcal","Hcal",0,0,707,500 );
    string figure = "figure";
    figure += run;
    figure += ".ps";
    ps = new TPostScript(figure.c_str() , -112);
    ps->Range(29.7 , 21.0);
  }


  string rfilename;
  rfilename = path2ref+ "CaloTowersValidation" +run + "noise_ref.root";
  string sfilename;
  sfilename = path2data + "CaloTowersValidation" +run + "noise.root";



  cout << "Reference file : " << rfilename << endl;
   cout << "New file : " << sfilename << endl;
  delete gROOT->GetListOfFiles()->FindObject(rfilename.c_str());
  delete gROOT->GetListOfFiles()->FindObject(sfilename.c_str());

  // TText* te = new TText();
  // te->SetTextSize(0.1);
  rfile = new TFile(rfilename.c_str());
  sfile = new TFile(sfilename.c_str());
  rfile->cd("DQMData/HcalRecHitTask");
  gDirectory->ls();

  sfile->cd("DQMData/CaloTowersTask");
  gDirectory->ls();

  gStyle->SetOptStat("n");

  gROOT->ProcessLine(".x HistoCompare.C");

  runAll();

}

HcalOval::~HcalOval()
{
  if (drawhist == "ps") ps->Close();
}


void HcalOval::process(string histname, string subdet)
{
  TH1 * oldHist;
  TH1 * newHist;
  //  string tname = histname + "_"+ subdet + ";1";
  string tname = histname  + ";1";
  std::cout << "PROCESS " << tname << std::endl;

  rfile->GetObject(tname.c_str(), oldHist);
  sfile->GetObject(tname.c_str(), newHist); 
  HistoCompare comp;
  
  char * add = ("_"+run).c_str();
  comp.PVCompute(oldHist, newHist, drawhist.c_str(),add);
  if (drawhist == "ps") 
  { 
    canvas->Update(); 
    ps->NewPage();
  }
}


void HcalOval::runStandard()
{

  process("DQMData/CaloTowersTask/CaloTowersTask_energy_ECAL", run);
  process("DQMData/CaloTowersTask/CaloTowersTask_energy_HCAL", run);
  process("DQMData/CaloTowersTask/CaloTowersTask_energy_HcalPlusEcalPlusHO", run);
  process("DQMData/CaloTowersTask/CaloTowersTask_energy_OUTER", run);
  //  process("DQMData/CaloTowersTask/CaloTowersTask_energy_of_ECAL_component_of_tower",run);
  //  process("DQMData/CaloTowersTask/CaloTowersTask_energy_of_HCAL_component_of_tower",run);
  process("DQMData/CaloTowersTask/CaloTowersTask_number_of_fired_towers",run);
  // process("DQMData/CaloTowersTask/CaloTowersTask_sum_of_energy_HCAL_vs_ECAL",run);

}


void HcalOval::runAll()
{

    runStandard();

}



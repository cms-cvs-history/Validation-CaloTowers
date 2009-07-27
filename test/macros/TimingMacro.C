

void TimingMacro(TString ref_vers="218", TString val_vers="218", TString rfname, TString vfname){

  TCanvas *myc; 

  TFile ref_file(rfname); 
  TFile val_file(vfname); 

  TH2F* ref_hist2[4];
  TH2F* val_hist2[4];

  TProfile* ref_prof[4];
  TProfile* val_prof[4];

  ifstream timstr("InputTiming.txt");

  TString HistName1;
  TString HistName2;

  char xAxisTitle[200];
  TString OutLabel;

  string dump;

  int i;

  for (i = 0; i < 4; i++){
    timstr>>HistName1>>OutLabel;
    timstr.getline(xAxisTitle,200);
    
    timstr>>HistName2>>dump>>dump;
    
    myc = new TCanvas("myc","",800,600);
    
    ref_file.cd("DQMData/HcalRecHitsV/HcalRecHitTask");   

    ref_hist2[i] = (TH2F*) gDirectory->Get(HistName1);
    ref_prof[i]  = (TProfile*) gDirectory->Get(HistName2);

    val_file.cd("DQMData/HcalRecHitsV/HcalRecHitTask");   

    val_hist2[i] = (TH2F*) gDirectory->Get(HistName1);
    val_prof[i]  = (TProfile*) gDirectory->Get(HistName2);

    //Legend
    TLegend *leg = new TLegend(0.48, 0.91, 0.74, 0.99, "","brNDC");
    leg->SetBorderSize(2);
    leg->SetFillStyle(1001); 

    ref_hist2[i]->GetXaxis()->SetTitle(xAxisTitle);
    ref_hist2[i]->SetStats(kFALSE);

    ref_hist2[i]->SetMarkerColor(53); // rose
    ref_hist2[i]->Draw();
    ref_prof[i]->SetLineColor(41); 
    ref_prof[i]->Draw("same");
    
    val_hist2[i]->SetMarkerColor(42); 
    val_hist2[i]->Draw("same");
    val_prof[i]->SetLineColor(45); 
    val_prof[i]->Draw("same");
    
    leg->AddEntry(ref_prof[i],"CMSSW_"+ref_vers,"pl");
    leg->AddEntry(val_prof[i],"CMSSW_"+val_vers,"pl");   	     
    
    leg->Draw();
    
    myc->SaveAs(OutLabel);    
  }
  
}

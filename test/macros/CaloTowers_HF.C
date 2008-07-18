// Commands executed in a GLOBAL scope, e.g. created hitograms aren't erased...
{

   TCanvas *myc = new TCanvas("myc","",800,600);
      
   TFile f1("CaloTowersValidationHF_206.root");
   TFile f2("CaloTowersValidationHF_210pre6.root");

   
   // service variables
   //
   const int Nhist1 = 5;
   TH1F* f1_hist1[Nhist1];
   TH1F* f2_hist1[Nhist1];

   char *label1[Nhist1];

   label1[0] = &"HF_CaloTowers_MET.gif";
   label1[1] = &"HF_CaloTowers_SET.gif";
   label1[2] = &"HF_CaloTowers_Ntowers.gif";
   label1[3] = &"HF_CaloTowers_Energy_in_ECAL.gif"; 
   label1[4] = &"HF_CaloTowers_Energy_in_HCAL.gif"; 

   f1->cd("DQMData/CaloTowersV/CaloTowersTask");
   gDirectory->pwd();
   f1_hist1[0] = CaloTowersTask_MET;
   f1_hist1[1] = CaloTowersTask_SET;
   f1_hist1[2] = CaloTowersTask_number_of_fired_towers;
   f1_hist1[3] = CaloTowersTask_energy_ECAL;
   f1_hist1[4] = CaloTowersTask_energy_HCAL;


   f2->cd("DQMData/CaloTowersV/CaloTowersTask");
   gDirectory->pwd();
   f2_hist1[0] = CaloTowersTask_MET;
   f2_hist1[1] = CaloTowersTask_SET;
   f2_hist1[2] = CaloTowersTask_number_of_fired_towers;
   f2_hist1[3] = CaloTowersTask_energy_ECAL;
   f2_hist1[4] = CaloTowersTask_energy_HCAL;


   f1_hist1[0]->GetXaxis()->SetTitle("HF Calo MET (GeV)");
   f1_hist1[1]->GetXaxis()->SetTitle("HF Calo SET (GeV)");
   f1_hist1[2]->GetXaxis()->SetTitle("HF CaloTowers number");
   f1_hist1[3]->GetXaxis()->SetTitle("HF CaloTowers ECAL energy (GeV)");
   f1_hist1[4]->GetXaxis()->SetTitle("HF CaloTowers HCAL energy (GeV)");

   //   f1_hist1[1]->SetMaximum(400.);
   f1_hist1[0]->GetXaxis()->SetRangeUser(0.,60.);
   f1_hist1[1]->GetXaxis()->SetRangeUser(0.,100.);
   f1_hist1[2]->GetXaxis()->SetRangeUser(0.,30.);
   f1_hist1[3]->GetXaxis()->SetRangeUser(0.,50.);
   f1_hist1[4]->GetXaxis()->SetRangeUser(0.,50.);
   // f1_hist[7]->GetXaxis()->SetRangeUser(0.,160.);
   // hist1->GetXaxis()->SetNdivisions(-21);
   // hist1->GetYaxis()->SetNdivisions(-1003);


   //  1D-histo

   for (int i = 0; i < Nhist1; i++){

     if(i !=2 ) gPad->SetLogy();
     else gPad->SetLogy(0);

    f1_hist1[i]->SetStats(kFALSE);   
    f2_hist1[i]->SetStats(kFALSE); 
    
    f1_hist1[i]->SetTitle("");
    f2_hist1[i]->SetTitle("");

    f1_hist1[i]->SetLineWidth(2); 
    f2_hist1[i]->SetLineWidth(3); 
    
    // diffferent histo colors and styles
    f1_hist1[i]->SetLineColor(41);
    f1_hist1[i]->SetLineStyle(1); 
    
    f2_hist1[i]->SetLineColor(42);
    f2_hist1[i]->SetLineStyle(2);  


     //     if(i == 0 ) {
       TLegend *leg = new TLegend(0.68, 0.82, 0.98, 0.97, "","brNDC");
       //     }
       //     else {
       //       TLegend *leg = new TLegend(0.08, 0.6, 0.38, 0.85, "","brNDC");
       //     }

     leg->SetBorderSize(2);
     //  leg->SetFillColor(51); // see new color definition above
     leg->SetFillStyle(1001); //
     leg->AddEntry(f1_hist1[i],"CMSSW_206","l");
     leg->AddEntry(f2_hist1[i],"CMSSW_210pre6","l");


     f1_hist1[i]->Draw("hist");   
     f2_hist1[i]->Draw("hist same");   

     leg->Draw();   
     
     myc->SaveAs(label1[i]);
   }     


   // close ROOT files
   //
   f1.Close() ;  
   f2.Close() ;
   
   return ;  
     
}

// Commands executed in a GLOBAL scope, e.g. created hitograms aren't erased...
{

   TCanvas *myc = new TCanvas("myc","",800,600);
      
   TFile f1("HcalRecHitValidationHB_210pre6.root");
   TFile f2("HcalRecHitValidationHB_210pre9.root");

   
   // service variables
   //
   const int Nhist1 = 4;
   const int Nhist2 = 3;
   const int Nprof  = 3;
   TH1F* f1_hist1[Nhist1];
   TH1F* f2_hist1[Nhist1];

   TH2F*     f1_hist2[Nhist2];
   TProfile* f1_histp[Nprof];

   TH2F*     f2_hist2[Nhist2];
   TProfile* f2_histp[Nprof];

   char *label1[Nhist1];
   char *label2[Nhist2];

   label1[0] = &"HcalRecHitTask_energy_ecal_plus_hcal_in_cone_HB.gif";
   label1[1] = &"HcalRecHitTask_number_of_rechits_above_1GeV_HB.gif";
   label1[2] = &"HcalRecHitTask_number_of_rechits_in_cone_HB.gif";
   label1[3] = &"HcalRecHitTask_sum_of_rechits_energy_in_cone_HB.gif";

   label2[0] = &"HcalRecHitTask_energy_hcal_vs_ecal_HB.gif";
   label2[1] = &"HcalRecHitTask_energy_rechits_vs_simhits_HB.gif";
   label2[2] = &"HcalRecHitTask_timing_vs_energy_HB.gif";


   f1->cd("DQMData/HcalRecHitsV/HcalRecHitTask");
   gDirectory->pwd();
   f1_hist1[0] = HcalRecHitTask_energy_ecal_plus_hcal_in_cone_HB;
   f1_hist1[1] = HcalRecHitTask_number_of_rechits_above_1GeV_HB;
   f1_hist1[2] = HcalRecHitTask_number_of_rechits_in_cone_HB;
   f1_hist1[3] = HcalRecHitTask_sum_of_rechits_energy_in_cone_HB;

   f1_hist2[0] = HcalRecHitTask_energy_hcal_vs_ecal_HB;
   f1_hist2[1] = HcalRecHitTask_energy_rechits_vs_simhits_HB;
   f1_histp[1] = HcalRecHitTask_energy_rechits_vs_simhits_profile_HB; 
   f1_hist2[2] = HcalRecHitTask_timing_vs_energy_HB;

   f2->cd("DQMData/HcalRecHitsV/HcalRecHitTask");
   gDirectory->pwd();
   f2_hist1[0] = HcalRecHitTask_energy_ecal_plus_hcal_in_cone_HB;
   f2_hist1[1] = HcalRecHitTask_number_of_rechits_above_1GeV_HB;
   f2_hist1[2] = HcalRecHitTask_number_of_rechits_in_cone_HB;
   f2_hist1[3] = HcalRecHitTask_sum_of_rechits_energy_in_cone_HB;

   f2_hist2[0] = HcalRecHitTask_energy_hcal_vs_ecal_HB;
   f2_hist2[1] = HcalRecHitTask_energy_rechits_vs_simhits_HB;
   f2_histp[1] = HcalRecHitTask_energy_rechits_vs_simhits_profile_HB; 
   f2_hist2[2] = HcalRecHitTask_timing_vs_energy_HB;


   f1_hist1[0]->GetXaxis()->SetTitle("HB ecal+hcal energy in cone (GeV)");
   f1_hist1[1]->GetXaxis()->SetTitle("HB N_{rechits} > 1 GeV");
   f1_hist1[2]->GetXaxis()->SetTitle("HB N_{rechits} in cone");
   f1_hist1[3]->GetXaxis()->SetTitle("HB hcal energy in cone (GeV)");


   f1_hist2[0]->GetXaxis()->SetTitle("HB banana plot");
   f1_hist2[1]->GetXaxis()->SetTitle("HB RecHits energy vs SimHits energy (GeV)");
   f1_hist2[2]->GetXaxis()->SetTitle("HB timing vs energy");



   //   f1_hist1[1]->SetMaximum(400.);

    f1_hist1[0]->GetXaxis()->SetRangeUser(0.,100.);
    f1_hist1[3]->GetXaxis()->SetRangeUser(0.,100.);

    f1_hist2[0]->GetXaxis()->SetRangeUser(0.,100.);
    f1_hist2[0]->GetYaxis()->SetRangeUser(0.,100.);
    f1_hist2[1]->GetXaxis()->SetRangeUser(0.,1.);
    f1_hist2[1]->GetYaxis()->SetRangeUser(0.,100.);

   // f1_hist[7]->GetXaxis()->SetRangeUser(0.,160.);
   // hist1->GetXaxis()->SetNdivisions(-21);
   // hist1->GetYaxis()->SetNdivisions(-1003);


   //  1D-histo

   for (int i = 0; i < Nhist1; i++){

     if(i <= 4 )   f1_hist1[i]->SetStats(kTRUE);   // stat
     else  f1_hist1[i]->SetStats(kFALSE);
     

     
    f1_hist1[i]->SetTitle("");
    f2_hist1[i]->SetTitle("");

    f1_hist1[i]->SetLineWidth(2); 
    f2_hist1[i]->SetLineWidth(3); 
    
    // diffferent histo colors and styles
    f1_hist1[i]->SetLineColor(41);
    f1_hist1[i]->SetLineStyle(1); 
    
    f2_hist1[i]->SetLineColor(43);
    f2_hist1[i]->SetLineStyle(2);  


     //     if(i == 0 ) {
       TLegend *leg = new TLegend(0.58, 0.87, 0.84, 0.97, "","brNDC");
       //     }
       //     else {
       //       TLegend *leg = new TLegend(0.08, 0.6, 0.38, 0.85, "","brNDC");
       //     }

     leg->SetBorderSize(2);
     //  leg->SetFillColor(51); // see new color definition above
     leg->SetFillStyle(1001); //
     leg->AddEntry(f1_hist1[i],"CMSSW_210pre6","l");
     leg->AddEntry(f2_hist1[i],"CMSSW_210pre9","l");



     if (i<= 4) {
       TPaveStats *ptstats = new TPaveStats(0.85,0.86,0.98,0.98,"brNDC");
       ptstats->SetTextColor(41);
       f1_hist1[i]->GetListOfFunctions()->Add(ptstats);
       ptstats->SetParent(f1_hist1[i]->GetListOfFunctions());
       TPaveStats *ptstats = new TPaveStats(0.85,0.74,0.98,0.86,"brNDC");
       ptstats->SetTextColor(43);
       f2_hist1[i]->GetListOfFunctions()->Add(ptstats);
       ptstats->SetParent(f2_hist1[i]->GetListOfFunctions());

       f1_hist1[i]->Draw(""); // "stat"
       f2_hist1[i]->Draw("hist sames");
     }
     else {
       f1_hist1[i]->Draw(""); // "stat"
       f2_hist1[i]->Draw("hist same");
     }


     leg->Draw();   
     
     myc->SaveAs(label1[i]);
   }     


   //  2D-histo
  for (int i = 0; i < Nhist2; i++){

    f1_hist2[i]->SetStats(kFALSE);   
    f2_hist2[i]->SetStats(kFALSE); 
    
    f1_hist2[i]->SetTitle("");
    f2_hist2[i]->SetTitle("");

    f1_hist2[i]->SetLineColor(2);
    f1_hist2[i]->SetLineWidth(2); 
    f1_hist2[i]->SetMarkerColor(41);
    f1_hist2[i]->SetMarkerStyle(20);
    f1_hist2[i]->SetMarkerSize(0.4);  
    if(i == 1) f1_hist2[i]->SetMarkerSize(0.05);  


    f2_hist2[i]->SetLineColor(3);
    f2_hist2[i]->SetLineWidth(3); 
    f2_hist2[i]->SetMarkerColor(42);
    f2_hist2[i]->SetMarkerStyle(22);
    f2_hist2[i]->SetMarkerSize(0.5);  
    if(i == 1) f2_hist2[i]->SetMarkerSize(0.05);  

    f1_hist2[i]->Draw("P");   
    f2_hist2[i]->Draw("PSAME");   

    if(i == 1) { // rechits vs simhits 
      f1_histp[i]->SetLineColor(2);
      f1_histp[i]->SetLineStyle(1);     
      f1_histp[i]->SetLineWidth(2); 
      
      f1_histp[i]->Draw("e same");
      
      f2_histp[i]->SetLineColor(3);
      f2_histp[i]->SetLineStyle(1);     
      f2_histp[i]->SetLineWidth(2);
 
      f2_histp[i]->Draw("e same");
    }
    
    TLegend *leg = new TLegend(0.38, 0.82, 0.68, 0.97, "","brNDC");    
     leg->SetBorderSize(2);
     leg->SetFillStyle(1001); 
     leg->AddEntry(f1_hist2[i],"CMSSW_210pre6","l");
     leg->AddEntry(f2_hist2[i],"CMSSW_210pre9","l");

     leg->Draw();   
     
     myc->SaveAs(label2[i]);

  }

   // close ROOT files
   //
   f1.Close() ;  
   f2.Close() ;
   
   return ;  
     
}

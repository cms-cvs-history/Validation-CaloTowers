// Commands executed in a GLOBAL scope, e.g. created hitograms aren't erased...
{


   TFile f1("HcalRecHitValidation_noise_NZS_206.root");
   TFile f2("HcalRecHitValidation_noise_NZS_210pre6.root");

   
   // service variables
   //
   const int Nhist1 = 17;
   const int Nhist2 = 1;
   const int Nprof  = 8;
   TH1F* f1_hist1[Nhist1];
   TH1F* f2_hist1[Nhist1];
   TH2F* f1_hist2[Nhist2];
   TH2F* f2_hist2[Nhist2];
   TProfile* f1_prof[Nprof];
   TProfile* f2_prof[Nprof];

   char *label1[Nhist1];
   char *label2[Nhist2];
   char *labelp[Nprof];

   label1[0] = &"HcalRecHits_noise_HB.gif";
   label1[1] = &"HcalRecHits_noise_HE.gif";
   label1[2] = &"HcalRecHits_noise_HO.gif";
   label1[3] = &"HcalRecHits_noise_HFL.gif";
   label1[4] = &"HcalRecHits_noise_HFS.gif";

   label1[5]  = &"N_HB.gif";
   label1[6]  = &"N_HE.gif";
   label1[7]  = &"N_HO.gif";
   label1[8]  = &"N_HF.gif";

   label1[9]   = &"HcalRecHits_occupancy_vs_ieta_HB1.gif";
   label1[10]  = &"HcalRecHits_occupancy_vs_ieta_HB2.gif";
   label1[11]  = &"HcalRecHits_occupancy_vs_ieta_HE1.gif";
   label1[12]  = &"HcalRecHits_occupancy_vs_ieta_HE2.gif";
   label1[13]  = &"HcalRecHits_occupancy_vs_ieta_HE3.gif";
   label1[14]  = &"HcalRecHits_occupancy_vs_ieta_HO.gif";
   label1[15]  = &"HcalRecHits_occupancy_vs_ieta_HF1.gif";
   label1[16]  = &"HcalRecHits_occupancy_vs_ieta_HF2.gif";

   labelp[0]  = &"HcalRecHits_Emean_seq_HB1.gif";
   labelp[1]  = &"HcalRecHits_Emean_seq_HB2.gif";
   labelp[2]  = &"HcalRecHits_Emean_seq_HE1.gif";
   labelp[3]  = &"HcalRecHits_Emean_seq_HE2.gif";
   labelp[4]  = &"HcalRecHits_Emean_seq_HE3.gif";
   labelp[5]  = &"HcalRecHits_Emean_seq_HO.gif";
   labelp[6]  = &"HcalRecHits_Emean_seq_HF1.gif";
   labelp[7]  = &"HcalRecHits_Emean_seq_HF2.gif";

   f1->cd("DQMData/HcalRecHitsV/HcalRecHitTask");
   gDirectory->pwd();
   f1_hist1[0] = e_hb;
   f1_hist1[1] = e_he;
   f1_hist1[2] = e_ho;
   f1_hist1[3] = e_hfl;
   f1_hist1[4] = e_hfs;

   f1_hist1[5] = N_HB;
   f1_hist1[6] = N_HE;
   f1_hist1[7] = N_HO;
   f1_hist1[8] = N_HF;

   f1_hist1[9]  = occupancy_vs_ieta_HB1;
   f1_hist1[10] = occupancy_vs_ieta_HB2;
   f1_hist1[11] = occupancy_vs_ieta_HE1;
   f1_hist1[12] = occupancy_vs_ieta_HE2;
   f1_hist1[13] = occupancy_vs_ieta_HE3;
   f1_hist1[14] = occupancy_vs_ieta_HO;
   f1_hist1[15] = occupancy_vs_ieta_HF1;
   f1_hist1[16] = occupancy_vs_ieta_HF2;

   f1_prof[0] = emean_seq_HB1;
   f1_prof[1] = emean_seq_HB2;
   f1_prof[2] = emean_seq_HE1;
   f1_prof[3] = emean_seq_HE2;
   f1_prof[4] = emean_seq_HE3;
   f1_prof[5] = emean_seq_HO;
   f1_prof[6] = emean_seq_HF1;
   f1_prof[7] = emean_seq_HF2;


   //   f1_hist2[0] = HcalDigiTask_amplitude_vs_simhits_depth1_HE;


   f2->cd("DQMData/HcalRecHitsV/HcalRecHitTask");
   gDirectory->pwd();
   f2_hist1[0] = e_hb;
   f2_hist1[1] = e_he;
   f2_hist1[2] = e_ho;
   f2_hist1[3] = e_hfl;
   f2_hist1[4] = e_hfs;

   f2_hist1[5] = N_HB;
   f2_hist1[6] = N_HE;
   f2_hist1[7] = N_HO;
   f2_hist1[8] = N_HF;

   f2_hist1[9]  = occupancy_vs_ieta_HB1;
   f2_hist1[10] = occupancy_vs_ieta_HB2;
   f2_hist1[11] = occupancy_vs_ieta_HE1;
   f2_hist1[12] = occupancy_vs_ieta_HE2;
   f2_hist1[13] = occupancy_vs_ieta_HE3;
   f2_hist1[14] = occupancy_vs_ieta_HO;
   f2_hist1[15] = occupancy_vs_ieta_HF1;
   f2_hist1[16] = occupancy_vs_ieta_HF2;

   f2_prof[0] = emean_seq_HB1;
   f2_prof[1] = emean_seq_HB2;
   f2_prof[2] = emean_seq_HE1;
   f2_prof[3] = emean_seq_HE2;
   f2_prof[4] = emean_seq_HE3;
   f2_prof[5] = emean_seq_HO;
   f2_prof[6] = emean_seq_HF1;
   f2_prof[7] = emean_seq_HF2;


   // Axis

   f1_hist1[0]->GetXaxis()->SetTitle("HB Noise RecHits Energy (GeV)");
   f1_hist1[1]->GetXaxis()->SetTitle("HE Noise RecHits Energy (GeV)");
   f1_hist1[2]->GetXaxis()->SetTitle("HO Noise RecHits Energy (GeV)");
   f1_hist1[3]->GetXaxis()->SetTitle("HFL Noise RecHits Energy (GeV)");
   f1_hist1[4]->GetXaxis()->SetTitle("HFS Noise RecHits Energy (GeV)");

   f1_hist1[5]->GetXaxis()->SetTitle("Number or RecHits in HB");
   f1_hist1[6]->GetXaxis()->SetTitle("Number or RecHits in HE");
   f1_hist1[7]->GetXaxis()->SetTitle("Number or RecHits in HO");
   f1_hist1[8]->GetXaxis()->SetTitle("Number or RecHits in HF");

   f1_hist1[9]->GetXaxis()->SetTitle("Occupancy vs i#eta HB1");
   f1_hist1[10]->GetXaxis()->SetTitle("Occupancy vs i#eta HB2");
   f1_hist1[11]->GetXaxis()->SetTitle("Occupancy vs i#eta HE1");
   f1_hist1[12]->GetXaxis()->SetTitle("Occupancy vs i#eta HE2");
   f1_hist1[13]->GetXaxis()->SetTitle("Occupancy vs i#eta HE3");
   f1_hist1[14]->GetXaxis()->SetTitle("Occupancy vs i#eta HO");
   f1_hist1[15]->GetXaxis()->SetTitle("Occupancy vs i#eta HF1");
   f1_hist1[16]->GetXaxis()->SetTitle("Occupancy vs i#eta HF2");

   f1_prof[0]->SetXTitle("HB1 Emean with RMS errors (GeV) in all channels"); 
   f1_prof[1]->SetXTitle("HB2 Emean with RMS errors (GeV) in all channels");
   f1_prof[2]->SetXTitle("HE1 Emean with RMS errors (GeV) in all channels");
   f1_prof[3]->SetXTitle("HE2 Emean with RMS errors (GeV) in all channels");
   f1_prof[4]->SetXTitle("HE3 Emean with RMS errors (GeV) in all channels");
   f1_prof[5]->SetXTitle("HO Emean with RMS errors (GeV) in all channels");
   f1_prof[6]->SetXTitle("HF1 Emean with RMS errors (GeV) in all channels");
   f1_prof[7]->SetXTitle("HF2 Emean with RMS errors (GeV) in all channels");

   //  1D-histo

   for (int i = 0; i < Nhist1; i++){

     TCanvas *myc = new TCanvas("myc","",800,600);
     gStyle->SetOptStat(1111);
     
     if(i <= 4 )  gPad->SetLogy(1);
     else gPad->SetLogy(0);
     
     
     if(i <= 8 )   f1_hist1[i]->SetStats(kTRUE);   // stat box  
     else  f1_hist1[i]->SetStats(kFALSE);
     
     f1_hist1[i]->SetTitle("");
     f2_hist1[i]->SetTitle("");
     
     f1_hist1[i]->SetLineWidth(2); 
     f2_hist1[i]->SetLineWidth(1); 
     
     // diffferent histo colors and styles
     f1_hist1[i]->SetLineColor(41);
     f1_hist1[i]->SetLineStyle(1); 
     
     f2_hist1[i]->SetLineColor(43);
     f2_hist1[i]->SetLineStyle(2);  
     

     if(i >=9 && i<=16) 
       TLegend *leg = new TLegend(0.4, 0.82, 0.6, 0.97, "","brNDC");
       else TLegend *leg = new TLegend(0.58, 0.82, 0.76, 0.97, "","brNDC");
     leg->SetBorderSize(2);
     //  leg->SetFillColor(51); // see new color definition above
     leg->SetFillStyle(1001); //
     leg->AddEntry(f1_hist1[i],"CMSSW_206","l");
     leg->AddEntry(f2_hist1[i],"CMSSW_210pre6","l");


     if (i <= 8) {
       TPaveStats *ptstats = new TPaveStats(0.8,0.8,0.99,1.0,"brNDC");
       ptstats->SetTextColor(41);
       f1_hist1[i]->GetListOfFunctions()->Add(ptstats);
       ptstats->SetParent(f1_hist1[i]->GetListOfFunctions());
       TPaveStats *ptstats = new TPaveStats(0.8,0.6,0.99,0.8,"brNDC");
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


     //     myc->Modified();
     
     myc->SaveAs(label1[i]);
   }     


   //  Profiles

   for (int i = 0; i < Nprof; i++){

     gStyle->SetPadLeftMargin(0.07);
     gStyle->SetPadRightMargin(0.02);

     TCanvas *myc = new TCanvas("myc","",1200,600);
     myc->SetGrid();
     
     f1_prof[i]->SetStats(kFALSE);   
     f2_prof[i]->SetStats(kFALSE); 
     
     f1_prof[i]->SetTitle("");
     f2_prof[i]->SetTitle("");
   
     
     f1_prof[i]->SetLineWidth(1); 
     f1_prof[i]->SetLineColor(5);
     f1_prof[i]->SetLineStyle(1); 
     f1_prof[i]->SetMarkerColor(2);
     f1_prof[i]->SetMarkerStyle(20);
     f1_prof[i]->SetMarkerSize(0.5);
   
     f2_prof[i]->SetLineWidth(1); 
     f2_prof[i]->SetLineColor(45);
     f2_prof[i]->SetLineStyle(2);  
     f2_prof[i]->SetMarkerColor(4);
     f2_prof[i]->SetMarkerStyle(22);
     f2_prof[i]->SetMarkerSize(0.5);


     TLegend *leg = new TLegend(0.75, 0.88, 0.95, 0.98, "","brNDC");
     leg->SetBorderSize(2);
     leg->SetFillStyle(1001); //
     leg->AddEntry(f1_prof[i],"CMSSW_206","lp");
     leg->AddEntry(f2_prof[i],"CMSSW_210pre6","lp");


     f1_prof[i]->Draw("histep");   
     f2_prof[i]->Draw("phiste same");   

     leg->Draw();   
     
     myc->SaveAs(labelp[i]);
   }     

   // close ROOT files
   //
   f1.Close() ;  
   f2.Close() ;
   
   return ;  
}     


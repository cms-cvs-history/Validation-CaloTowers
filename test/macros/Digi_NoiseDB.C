// Commands executed in a GLOBAL scope, e.g. created hitograms aren't erased...
{
#include "TPaveStats.h"

   TCanvas *myc = new TCanvas("myc","",800,600);


   //   TPaveStats *st = new TPaveStats(0.4, 0.4, 0.98, 0.98,"brNDC");
      
   //...current Pad  parameters 
   //   gPad->SetLogy(1);
   //   gStyle->SetOptStat(111111);


   TFile f1("HcalRecHitValidation_noise_206.root");
   TFile f2("HcalRecHitValidation_noise_210pre6.root");

   
   // service variables
   //
   const int Nhist1 = 40; // 8 gains (3 HB, 3 He, 2 HF)
                          // 16 pedestals (4 CapID, 4 subdet)
                          // 16 ped_width ( idem)  
   const int Nhist2 = 1;
   TH1F* f1_hist1[Nhist1];
   TH1F* f2_hist1[Nhist1];
   TH2F* f1_hist2[Nhist2];
   TH2F* f2_hist2[Nhist2];

   char *label1[Nhist1];
   char *label2[Nhist2];

   label1[0] = &"HBHE_gain_depth1.gif";
   label1[1] = &"HBHE_gain_depth2.gif";
   label1[2] = &"HBHE_gain_depth3.gif";
   /*
   label1[3] = &"HE_gain_depth1.gif";
   label1[4] = &"HE_gain_depth2.gif";
   label1[5] = &"HE_gain_depth3.gif";
   */
   label1[6] = &"HF_gain_depth1.gif";
   label1[7] = &"HF_gain_depth2.gif";
 
   label1[8]  = &"HBHE_ped_cap1.gif";
   label1[9]  = &"HBHE_ped_cap2.gif";
   label1[10] = &"HBHE_ped_cap3.gif";
   label1[11] = &"HBHE_ped_cap4.gif";
   /*
   label1[12] = &"HE_ped_cap1.gif";
   label1[13] = &"HE_ped_cap2.gif";
   label1[14] = &"HE_ped_cap3.gif";
   label1[15] = &"HE_ped_cap4.gif";
   */
   label1[16] = &"HO_ped_cap1.gif";
   label1[17] = &"HO_ped_cap2.gif";
   label1[18] = &"HO_ped_cap3.gif";
   label1[19] = &"HO_ped_cap4.gif";
   label1[20] = &"HF_ped_cap1.gif";
   label1[21] = &"HF_ped_cap2.gif";
   label1[22] = &"HF_ped_cap3.gif";
   label1[23] = &"HF_ped_cap4.gif";

   label1[24] = &"HBHE_pedwid_cap1.gif";
   label1[25] = &"HBHE_pedwid_cap2.gif";
   label1[26] = &"HBHE_pedwid_cap3.gif";
   label1[27] = &"HBHE_pedwid_cap4.gif";
   /*
   label1[28] = &"HE_pedwid_cap1.gif";
   label1[29] = &"HE_pedwid_cap2.gif";
   label1[30] = &"HE_pedwid_cap3.gif";
   label1[31] = &"HE_pedwid_cap4.gif";
   */
   label1[32] = &"HO_pedwid_cap1.gif";
   label1[33] = &"HO_pedwid_cap2.gif";
   label1[34] = &"HO_pedwid_cap3.gif";
   label1[35] = &"HO_pedwid_cap4.gif";
   label1[36] = &"HF_pedwid_cap1.gif";
   label1[37] = &"HF_pedwid_cap2.gif";
   label1[38] = &"HF_pedwid_cap3.gif";
   label1[39] = &"HF_pedwid_cap4.gif";

   //   label2[0] = &"HcalRecHits_noise_HB.gif";


   f1->cd("DQMData/HcalDigisV/HcalDigiTask");
   gDirectory->pwd();
   f1_hist1[0] = HcalDigiTask_gain_Depth1_HB;
   f1_hist1[1] = HcalDigiTask_gain_Depth2_HB;
   f1_hist1[2] = HcalDigiTask_gain_Depth3_HB;

   /*
   f1_hist1[3] = HcalDigiTask_gain_Depth1_HE;
   f1_hist1[4] = HcalDigiTask_gain_Depth2_HE;
   f1_hist1[5] = HcalDigiTask_gain_Depth3_HE;
   */

   f1_hist1[6] = HcalDigiTask_gain_Depth1_HF;
   f1_hist1[7] = HcalDigiTask_gain_Depth2_HF;

   f1_hist1[8]  = HcalDigiTask_pedestal_capId0_HB;
   f1_hist1[9]  = HcalDigiTask_pedestal_capId1_HB;
   f1_hist1[10] = HcalDigiTask_pedestal_capId2_HB;
   f1_hist1[11] = HcalDigiTask_pedestal_capId3_HB;

   /*
   f1_hist1[12] = HcalDigiTask_pedestal_capId0_HE;
   f1_hist1[13] = HcalDigiTask_pedestal_capId1_HE;
   f1_hist1[14] = HcalDigiTask_pedestal_capId2_HE;
   f1_hist1[15] = HcalDigiTask_pedestal_capId3_HE;
   */

   f1_hist1[16] = HcalDigiTask_pedestal_capId0_HO;
   f1_hist1[17] = HcalDigiTask_pedestal_capId1_HO;
   f1_hist1[18] = HcalDigiTask_pedestal_capId2_HO;
   f1_hist1[19] = HcalDigiTask_pedestal_capId3_HO;

   f1_hist1[20] = HcalDigiTask_pedestal_capId0_HF;
   f1_hist1[21] = HcalDigiTask_pedestal_capId1_HF;
   f1_hist1[22] = HcalDigiTask_pedestal_capId2_HF;
   f1_hist1[23] = HcalDigiTask_pedestal_capId3_HF;

   f1_hist1[24] = HcalDigiTask_pedestal_width_capId0_HB;
   f1_hist1[25] = HcalDigiTask_pedestal_width_capId1_HB;
   f1_hist1[26] = HcalDigiTask_pedestal_width_capId2_HB;
   f1_hist1[27] = HcalDigiTask_pedestal_width_capId3_HB;

   /*
   f1_hist1[28] = HcalDigiTask_pedestal_width_capId0_HE;
   f1_hist1[29] = HcalDigiTask_pedestal_width_capId1_HE;
   f1_hist1[30] = HcalDigiTask_pedestal_width_capId2_HE;
   f1_hist1[31] = HcalDigiTask_pedestal_width_capId3_HE;
   */

   f1_hist1[32] = HcalDigiTask_pedestal_width_capId0_HO;
   f1_hist1[33] = HcalDigiTask_pedestal_width_capId1_HO;
   f1_hist1[34] = HcalDigiTask_pedestal_width_capId2_HO;
   f1_hist1[35] = HcalDigiTask_pedestal_width_capId3_HO;

   f1_hist1[36] = HcalDigiTask_pedestal_width_capId0_HF;
   f1_hist1[37] = HcalDigiTask_pedestal_width_capId1_HF;
   f1_hist1[38] = HcalDigiTask_pedestal_width_capId2_HF;
   f1_hist1[39] = HcalDigiTask_pedestal_width_capId3_HF;


   //   f1_hist2[0] = HcalDigiTask_amplitude_vs_simhits_depth1_HE;


   f2->cd("DQMData/HcalDigisV/HcalDigiTask");
   gDirectory->pwd();
   f2_hist1[0] = HcalDigiTask_gain_Depth1_HB;
   f2_hist1[1] = HcalDigiTask_gain_Depth2_HB;
   f2_hist1[2] = HcalDigiTask_gain_Depth3_HB;

   /*
   f2_hist1[3] = HcalDigiTask_gain_Depth1_HE;
   f2_hist1[4] = HcalDigiTask_gain_Depth2_HE;
   f2_hist1[5] = HcalDigiTask_gain_Depth3_HE;
   */

   f2_hist1[6] = HcalDigiTask_gain_Depth1_HF;
   f2_hist1[7] = HcalDigiTask_gain_Depth2_HF;

   f2_hist1[8]  = HcalDigiTask_pedestal_capId0_HB;
   f2_hist1[9]  = HcalDigiTask_pedestal_capId1_HB;
   f2_hist1[10] = HcalDigiTask_pedestal_capId2_HB;
   f2_hist1[11] = HcalDigiTask_pedestal_capId3_HB;

   /*
   f2_hist1[12] = HcalDigiTask_pedestal_capId0_HE;
   f2_hist1[13] = HcalDigiTask_pedestal_capId1_HE;
   f2_hist1[14] = HcalDigiTask_pedestal_capId2_HE;
   f2_hist1[15] = HcalDigiTask_pedestal_capId3_HE;
   */

   f2_hist1[16] = HcalDigiTask_pedestal_capId0_HO;
   f2_hist1[17] = HcalDigiTask_pedestal_capId1_HO;
   f2_hist1[18] = HcalDigiTask_pedestal_capId2_HO;
   f2_hist1[19] = HcalDigiTask_pedestal_capId3_HO;

   f2_hist1[20] = HcalDigiTask_pedestal_capId0_HF;
   f2_hist1[21] = HcalDigiTask_pedestal_capId1_HF;
   f2_hist1[22] = HcalDigiTask_pedestal_capId2_HF;
   f2_hist1[23] = HcalDigiTask_pedestal_capId3_HF;

   f2_hist1[24] = HcalDigiTask_pedestal_width_capId0_HB;
   f2_hist1[25] = HcalDigiTask_pedestal_width_capId1_HB;
   f2_hist1[26] = HcalDigiTask_pedestal_width_capId2_HB;
   f2_hist1[27] = HcalDigiTask_pedestal_width_capId3_HB;

   /*
   f2_hist1[28] = HcalDigiTask_pedestal_width_capId0_HE;
   f2_hist1[29] = HcalDigiTask_pedestal_width_capId1_HE;
   f2_hist1[30] = HcalDigiTask_pedestal_width_capId2_HE;
   f2_hist1[31] = HcalDigiTask_pedestal_width_capId3_HE;
   */

   f2_hist1[32] = HcalDigiTask_pedestal_width_capId0_HO;
   f2_hist1[33] = HcalDigiTask_pedestal_width_capId1_HO;
   f2_hist1[34] = HcalDigiTask_pedestal_width_capId2_HO;
   f2_hist1[35] = HcalDigiTask_pedestal_width_capId3_HO;

   f2_hist1[36] = HcalDigiTask_pedestal_width_capId0_HF;
   f2_hist1[37] = HcalDigiTask_pedestal_width_capId1_HF;
   f2_hist1[38] = HcalDigiTask_pedestal_width_capId2_HF;
   f2_hist1[39] = HcalDigiTask_pedestal_width_capId3_HF;


   //  1D-histo

   for (int i = 0; i < Nhist1; i++){
     // allowed histos
     if(i<3 || (i > 5 && i < 12) || (i > 15 && i < 28) || (i > 31)) {

       f1_hist1[i]->SetStats(kFALSE);   
       f2_hist1[i]->SetStats(kFALSE); 
       
       /*
	 f1_hist1[i]->SetTitle("");
	 f2_hist1[i]->SetTitle("");
       */
       
       f1_hist1[i]->SetLineWidth(2); 
       f2_hist1[i]->SetLineWidth(3); 
       
       // diffferent histo colors and styles
       f1_hist1[i]->SetLineColor(41);
       f1_hist1[i]->SetLineStyle(1); 
       
       f2_hist1[i]->SetLineColor(42);
       f2_hist1[i]->SetLineStyle(2);  
       
       
       //     if(i == 0 ) {
       TLegend *leg = new TLegend(0.75, 0.87, 0.98, 0.97, "","brNDC");
       //     }
       //     else {
       //        TLegend *leg = new TLegend(0.08, 0.6, 0.38, 0.85, "","brNDC");
       //     }
       
       leg->SetBorderSize(2);
       //  leg->SetFillColor(51); // see new color definition above
       leg->SetFillStyle(1001); //
       leg->AddEntry(f1_hist1[i],"CMSSW_206","l");
       leg->AddEntry(f2_hist1[i],"CMSSW_210pre6","l");
       
       
       f1_hist1[i]->Draw("hist");   
       f2_hist1[i]->Draw("hist same");   
       
       leg->Draw();   
       
       
       //     myc->Modified();
       
       myc->SaveAs(label1[i]);
       
     }
   }     
     

   // close ROOT files
   //
   f1.Close() ;  
   f2.Close() ;
   
   return ;  
}     


// Commands executed in a GLOBAL scope, e.g. created hitograms aren't erased...
{
#include "TPaveStats.h"

   TCanvas *myc = new TCanvas("myc","",800,600);


   //   TPaveStats *st = new TPaveStats(0.4, 0.4, 0.98, 0.98,"brNDC");
      
   //...current Pad  parameters 
   //   gPad->SetLogy(1);
   //   gStyle->SetOptStat(111111);


   TFile f1("HcalDigisValidation_noise.root");
   TFile f2("HcalDigisValidation_noise.root");

   
   // service variables
   //
   const int Nhist1 = 72; 

   const int Nhist2 = 1;
   TH1F* f1_hist1[Nhist1];
   TH1F* f2_hist1[Nhist1];
   TH2F* f1_hist2[Nhist2];
   TH2F* f2_hist2[Nhist2];

   char *label1[Nhist1];
   char *label2[Nhist2];

   label1[0] = &"HB_gain_depth1.gif";
   label1[1] = &"HB_gain_depth2.gif";
   label1[2] = &"HE_gain_depth1.gif";
   label1[3] = &"HE_gain_depth2.gif";
   label1[4] = &"HE_gain_depth3.gif";
   label1[5] = &"HO_gain_depth3.gif";
   label1[6] = &"HF_gain_depth1.gif";
   label1[7] = &"HF_gain_depth2.gif";
 
   label1[8]  = &"HB_ped_cap0_depth1.gif";
   label1[9]  = &"HB_ped_cap1_depth1.gif";
   label1[10] = &"HB_ped_cap2_depth1.gif";
   label1[11] = &"HB_ped_cap3_depth1.gif";
   label1[12] = &"HB_ped_cap0_depth2.gif";
   label1[13] = &"HB_ped_cap1_depth2.gif";
   label1[14] = &"HB_ped_cap2_depth2.gif";
   label1[15] = &"HB_ped_cap3_depth2.gif";

   label1[16] = &"HE_ped_cap0_depth1.gif";
   label1[17] = &"HE_ped_cap1_depth1.gif";
   label1[18] = &"HE_ped_cap2_depth1.gif";
   label1[19] = &"HE_ped_cap3_depth1.gif";
   label1[20] = &"HE_ped_cap0_depth2.gif";
   label1[21] = &"HE_ped_cap1_depth2.gif";
   label1[22] = &"HE_ped_cap2_depth2.gif";
   label1[23] = &"HE_ped_cap3_depth2.gif";
   label1[24] = &"HE_ped_cap0_depth3.gif";
   label1[25] = &"HE_ped_cap1_depth3.gif";
   label1[26] = &"HE_ped_cap2_depth3.gif";
   label1[27] = &"HE_ped_cap3_depth3.gif";

   label1[28] = &"HO_ped_cap0.gif";
   label1[29] = &"HO_ped_cap1.gif";
   label1[30] = &"HO_ped_cap2.gif";
   label1[31] = &"HO_ped_cap3.gif";

   label1[32] = &"HF_ped_cap0_depth1.gif";
   label1[33] = &"HF_ped_cap1_depth1.gif";
   label1[34] = &"HF_ped_cap2_depth1.gif";
   label1[35] = &"HF_ped_cap3_depth1.gif";
   label1[36] = &"HF_ped_cap0_depth2.gif";
   label1[37] = &"HF_ped_cap1_depth2.gif";
   label1[38] = &"HF_ped_cap2_depth2.gif";
   label1[39] = &"HF_ped_cap3_depth2.gif";


   // widths 
   label1[40] = &"HB_pedwidth_cap0_depth1.gif";
   label1[41] = &"HB_pedwidth_cap1_depth1.gif";
   label1[42] = &"HB_pedwidth_cap2_depth1.gif";
   label1[43] = &"HB_pedwidth_cap3_depth1.gif";
   label1[44] = &"HB_pedwidth_cap0_depth2.gif";
   label1[45] = &"HB_pedwidth_cap1_depth2.gif";
   label1[46] = &"HB_pedwidth_cap2_depth2.gif";
   label1[47] = &"HB_pedwidth_cap3_depth2.gif";

   label1[48] = &"HE_pedwidth_cap0_depth1.gif";
   label1[49] = &"HE_pedwidth_cap1_depth1.gif";
   label1[50] = &"HE_pedwidth_cap2_depth1.gif";
   label1[51] = &"HE_pedwidth_cap3_depth1.gif";
   label1[52] = &"HE_pedwidth_cap0_depth2.gif";
   label1[53] = &"HE_pedwidth_cap1_depth2.gif";
   label1[54] = &"HE_pedwidth_cap2_depth2.gif";
   label1[55] = &"HE_pedwidth_cap3_depth2.gif";
   label1[56] = &"HE_pedwidth_cap0_depth3.gif";
   label1[57] = &"HE_pedwidth_cap1_depth3.gif";
   label1[58] = &"HE_pedwidth_cap2_depth3.gif";
   label1[59] = &"HE_pedwidth_cap3_depth3.gif";

   label1[60] = &"HO_pedwidth_cap0.gif";
   label1[61] = &"HO_pedwidth_cap1.gif";
   label1[62] = &"HO_pedwidth_cap2.gif";
   label1[63] = &"HO_pedwidth_cap3.gif";

   label1[64] = &"HF_pedwidth_cap0_depth1.gif";
   label1[65] = &"HF_pedwidth_cap1_depth1.gif";
   label1[66] = &"HF_pedwidth_cap2_depth1.gif";
   label1[67] = &"HF_pedwidth_cap3_depth1.gif";
   label1[68] = &"HF_pedwidth_cap0_depth2.gif";
   label1[69] = &"HF_pedwidth_cap1_depth2.gif";
   label1[70] = &"HF_pedwidth_cap2_depth2.gif";
   label1[71] = &"HF_pedwidth_cap3_depth2.gif";

  //   label2[0] = &"HcalRecHits_noise_HB.gif";


   f1->cd("DQMData/HcalDigisV/HcalDigiTask");
   gDirectory->pwd();
   f1_hist1[0] = HcalDigiTask_gain_capId0_Depth1_HB;
   f1_hist1[1] = HcalDigiTask_gain_capId0_Depth2_HB;
   f1_hist1[2] = HcalDigiTask_gain_capId0_Depth1_HE;
   f1_hist1[3] = HcalDigiTask_gain_capId0_Depth2_HE;
   f1_hist1[4] = HcalDigiTask_gain_capId0_Depth3_HE;
   f1_hist1[5] = HcalDigiTask_gain_capId0_Depth4_HO;
   f1_hist1[6] = HcalDigiTask_gain_capId0_Depth1_HF;
   f1_hist1[7] = HcalDigiTask_gain_capId0_Depth2_HF;

   f1_hist1[8]  = HcalDigiTask_pedestal_capId0_Depth1_HB;
   f1_hist1[9]  = HcalDigiTask_pedestal_capId1_Depth1_HB;
   f1_hist1[10] = HcalDigiTask_pedestal_capId2_Depth1_HB;
   f1_hist1[11] = HcalDigiTask_pedestal_capId3_Depth1_HB;
   f1_hist1[12] = HcalDigiTask_pedestal_capId0_Depth2_HB;
   f1_hist1[13] = HcalDigiTask_pedestal_capId1_Depth2_HB;
   f1_hist1[14] = HcalDigiTask_pedestal_capId2_Depth2_HB;
   f1_hist1[15] = HcalDigiTask_pedestal_capId3_Depth2_HB;

   f1_hist1[16] = HcalDigiTask_pedestal_capId0_Depth1_HE;
   f1_hist1[17] = HcalDigiTask_pedestal_capId1_Depth1_HE;
   f1_hist1[18] = HcalDigiTask_pedestal_capId2_Depth1_HE;
   f1_hist1[19] = HcalDigiTask_pedestal_capId3_Depth1_HE;
   f1_hist1[20] = HcalDigiTask_pedestal_capId0_Depth2_HE;
   f1_hist1[21] = HcalDigiTask_pedestal_capId1_Depth2_HE;
   f1_hist1[22] = HcalDigiTask_pedestal_capId2_Depth2_HE;
   f1_hist1[23] = HcalDigiTask_pedestal_capId3_Depth2_HE;
   f1_hist1[24] = HcalDigiTask_pedestal_capId0_Depth3_HE;
   f1_hist1[25] = HcalDigiTask_pedestal_capId1_Depth3_HE;
   f1_hist1[26] = HcalDigiTask_pedestal_capId2_Depth3_HE;
   f1_hist1[27] = HcalDigiTask_pedestal_capId3_Depth3_HE;

   f1_hist1[28] = HcalDigiTask_pedestal_capId0_Depth4_HO;
   f1_hist1[29] = HcalDigiTask_pedestal_capId1_Depth4_HO;
   f1_hist1[30] = HcalDigiTask_pedestal_capId2_Depth4_HO;
   f1_hist1[31] = HcalDigiTask_pedestal_capId3_Depth4_HO;

   f1_hist1[32] = HcalDigiTask_pedestal_capId0_Depth1_HF;
   f1_hist1[33] = HcalDigiTask_pedestal_capId1_Depth1_HF;
   f1_hist1[34] = HcalDigiTask_pedestal_capId2_Depth1_HF;
   f1_hist1[35] = HcalDigiTask_pedestal_capId3_Depth1_HF;
   f1_hist1[36] = HcalDigiTask_pedestal_capId0_Depth2_HF;
   f1_hist1[37] = HcalDigiTask_pedestal_capId1_Depth2_HF;
   f1_hist1[38] = HcalDigiTask_pedestal_capId2_Depth2_HF;
   f1_hist1[39] = HcalDigiTask_pedestal_capId3_Depth2_HF;


   f1_hist1[40] = HcalDigiTask_pedestal_width_capId0_Depth1_HB;
   f1_hist1[41] = HcalDigiTask_pedestal_width_capId1_Depth1_HB;
   f1_hist1[42] = HcalDigiTask_pedestal_width_capId2_Depth1_HB;
   f1_hist1[43] = HcalDigiTask_pedestal_width_capId3_Depth1_HB;
   f1_hist1[44] = HcalDigiTask_pedestal_width_capId0_Depth2_HB;
   f1_hist1[45] = HcalDigiTask_pedestal_width_capId1_Depth2_HB;
   f1_hist1[46] = HcalDigiTask_pedestal_width_capId2_Depth2_HB;
   f1_hist1[47] = HcalDigiTask_pedestal_width_capId3_Depth2_HB;

   f1_hist1[48] = HcalDigiTask_pedestal_width_capId0_Depth1_HE;
   f1_hist1[49] = HcalDigiTask_pedestal_width_capId1_Depth1_HE;
   f1_hist1[50] = HcalDigiTask_pedestal_width_capId2_Depth1_HE;
   f1_hist1[51] = HcalDigiTask_pedestal_width_capId3_Depth1_HE;
   f1_hist1[52] = HcalDigiTask_pedestal_width_capId0_Depth2_HE;
   f1_hist1[53] = HcalDigiTask_pedestal_width_capId1_Depth2_HE;
   f1_hist1[54] = HcalDigiTask_pedestal_width_capId2_Depth2_HE;
   f1_hist1[55] = HcalDigiTask_pedestal_width_capId3_Depth2_HE;
   f1_hist1[56] = HcalDigiTask_pedestal_width_capId0_Depth3_HE;
   f1_hist1[57] = HcalDigiTask_pedestal_width_capId1_Depth3_HE;
   f1_hist1[58] = HcalDigiTask_pedestal_width_capId2_Depth3_HE;
   f1_hist1[59] = HcalDigiTask_pedestal_width_capId3_Depth3_HE;

   f1_hist1[60] = HcalDigiTask_pedestal_width_capId0_Depth4_HO;
   f1_hist1[61] = HcalDigiTask_pedestal_width_capId1_Depth4_HO;
   f1_hist1[62] = HcalDigiTask_pedestal_width_capId2_Depth4_HO;
   f1_hist1[63] = HcalDigiTask_pedestal_width_capId3_Depth4_HO;

   f1_hist1[64] = HcalDigiTask_pedestal_width_capId0_Depth1_HF;
   f1_hist1[65] = HcalDigiTask_pedestal_width_capId1_Depth1_HF;
   f1_hist1[66] = HcalDigiTask_pedestal_width_capId2_Depth1_HF;
   f1_hist1[67] = HcalDigiTask_pedestal_width_capId3_Depth1_HF;
   f1_hist1[68] = HcalDigiTask_pedestal_width_capId0_Depth2_HF;
   f1_hist1[69] = HcalDigiTask_pedestal_width_capId1_Depth2_HF;
   f1_hist1[70] = HcalDigiTask_pedestal_width_capId2_Depth2_HF;
   f1_hist1[71] = HcalDigiTask_pedestal_width_capId3_Depth2_HF;

   //   f1_hist2[0] = HcalDigiTask_amplitude_vs_simhits_depth1_HE;


   f2->cd("DQMData/HcalDigisV/HcalDigiTask");
   gDirectory->pwd();
   f2_hist1[0] = HcalDigiTask_gain_capId0_Depth1_HB;
   f2_hist1[1] = HcalDigiTask_gain_capId0_Depth2_HB;
   f2_hist1[2] = HcalDigiTask_gain_capId0_Depth1_HE;
   f2_hist1[3] = HcalDigiTask_gain_capId0_Depth2_HE;
   f2_hist1[4] = HcalDigiTask_gain_capId0_Depth3_HE;
   f2_hist1[5] = HcalDigiTask_gain_capId0_Depth4_HO;
   f2_hist1[6] = HcalDigiTask_gain_capId0_Depth1_HF;
   f2_hist1[7] = HcalDigiTask_gain_capId0_Depth2_HF;

   f2_hist1[8]  = HcalDigiTask_pedestal_capId0_Depth1_HB;
   f2_hist1[9]  = HcalDigiTask_pedestal_capId1_Depth1_HB;
   f2_hist1[10] = HcalDigiTask_pedestal_capId2_Depth1_HB;
   f2_hist1[11] = HcalDigiTask_pedestal_capId3_Depth1_HB;
   f2_hist1[12] = HcalDigiTask_pedestal_capId0_Depth2_HB;
   f2_hist1[13] = HcalDigiTask_pedestal_capId1_Depth2_HB;
   f2_hist1[14] = HcalDigiTask_pedestal_capId2_Depth2_HB;
   f2_hist1[15] = HcalDigiTask_pedestal_capId3_Depth2_HB;

   f2_hist1[16] = HcalDigiTask_pedestal_capId0_Depth1_HE;
   f2_hist1[17] = HcalDigiTask_pedestal_capId1_Depth1_HE;
   f2_hist1[18] = HcalDigiTask_pedestal_capId2_Depth1_HE;
   f2_hist1[19] = HcalDigiTask_pedestal_capId3_Depth1_HE;
   f2_hist1[20] = HcalDigiTask_pedestal_capId0_Depth2_HE;
   f2_hist1[21] = HcalDigiTask_pedestal_capId1_Depth2_HE;
   f2_hist1[22] = HcalDigiTask_pedestal_capId2_Depth2_HE;
   f2_hist1[23] = HcalDigiTask_pedestal_capId3_Depth2_HE;
   f2_hist1[24] = HcalDigiTask_pedestal_capId0_Depth3_HE;
   f2_hist1[25] = HcalDigiTask_pedestal_capId1_Depth3_HE;
   f2_hist1[26] = HcalDigiTask_pedestal_capId2_Depth3_HE;
   f2_hist1[27] = HcalDigiTask_pedestal_capId3_Depth3_HE;

   f2_hist1[28] = HcalDigiTask_pedestal_capId0_Depth4_HO;
   f2_hist1[29] = HcalDigiTask_pedestal_capId1_Depth4_HO;
   f2_hist1[30] = HcalDigiTask_pedestal_capId2_Depth4_HO;
   f2_hist1[31] = HcalDigiTask_pedestal_capId3_Depth4_HO;

   f2_hist1[32] = HcalDigiTask_pedestal_capId0_Depth1_HF;
   f2_hist1[33] = HcalDigiTask_pedestal_capId1_Depth1_HF;
   f2_hist1[34] = HcalDigiTask_pedestal_capId2_Depth1_HF;
   f2_hist1[35] = HcalDigiTask_pedestal_capId3_Depth1_HF;
   f2_hist1[36] = HcalDigiTask_pedestal_capId0_Depth2_HF;
   f2_hist1[37] = HcalDigiTask_pedestal_capId1_Depth2_HF;
   f2_hist1[38] = HcalDigiTask_pedestal_capId2_Depth2_HF;
   f2_hist1[39] = HcalDigiTask_pedestal_capId3_Depth2_HF;


   f2_hist1[40] = HcalDigiTask_pedestal_width_capId0_Depth1_HB;
   f2_hist1[41] = HcalDigiTask_pedestal_width_capId1_Depth1_HB;
   f2_hist1[42] = HcalDigiTask_pedestal_width_capId2_Depth1_HB;
   f2_hist1[43] = HcalDigiTask_pedestal_width_capId3_Depth1_HB;
   f2_hist1[44] = HcalDigiTask_pedestal_width_capId0_Depth2_HB;
   f2_hist1[45] = HcalDigiTask_pedestal_width_capId1_Depth2_HB;
   f2_hist1[46] = HcalDigiTask_pedestal_width_capId2_Depth2_HB;
   f2_hist1[47] = HcalDigiTask_pedestal_width_capId3_Depth2_HB;

   f2_hist1[48] = HcalDigiTask_pedestal_width_capId0_Depth1_HE;
   f2_hist1[49] = HcalDigiTask_pedestal_width_capId1_Depth1_HE;
   f2_hist1[50] = HcalDigiTask_pedestal_width_capId2_Depth1_HE;
   f2_hist1[51] = HcalDigiTask_pedestal_width_capId3_Depth1_HE;
   f2_hist1[52] = HcalDigiTask_pedestal_width_capId0_Depth2_HE;
   f2_hist1[53] = HcalDigiTask_pedestal_width_capId1_Depth2_HE;
   f2_hist1[54] = HcalDigiTask_pedestal_width_capId2_Depth2_HE;
   f2_hist1[55] = HcalDigiTask_pedestal_width_capId3_Depth2_HE;
   f2_hist1[56] = HcalDigiTask_pedestal_width_capId0_Depth3_HE;
   f2_hist1[57] = HcalDigiTask_pedestal_width_capId1_Depth3_HE;
   f2_hist1[58] = HcalDigiTask_pedestal_width_capId2_Depth3_HE;
   f2_hist1[59] = HcalDigiTask_pedestal_width_capId3_Depth3_HE;

   f2_hist1[60] = HcalDigiTask_pedestal_width_capId0_Depth4_HO;
   f2_hist1[61] = HcalDigiTask_pedestal_width_capId1_Depth4_HO;
   f2_hist1[62] = HcalDigiTask_pedestal_width_capId2_Depth4_HO;
   f2_hist1[63] = HcalDigiTask_pedestal_width_capId3_Depth4_HO;

   f2_hist1[64] = HcalDigiTask_pedestal_width_capId0_Depth1_HF;
   f2_hist1[65] = HcalDigiTask_pedestal_width_capId1_Depth1_HF;
   f2_hist1[66] = HcalDigiTask_pedestal_width_capId2_Depth1_HF;
   f2_hist1[67] = HcalDigiTask_pedestal_width_capId3_Depth1_HF;
   f2_hist1[68] = HcalDigiTask_pedestal_width_capId0_Depth2_HF;
   f2_hist1[69] = HcalDigiTask_pedestal_width_capId1_Depth2_HF;
   f2_hist1[70] = HcalDigiTask_pedestal_width_capId2_Depth2_HF;
   f2_hist1[71] = HcalDigiTask_pedestal_width_capId3_Depth2_HF;


   //  1D-histo

   for (int i = 0; i < Nhist1; i++){
     // "allowed" histos
     if(i<72) {

       f1_hist1[i]->SetStats(kTRUE);   
       f2_hist1[i]->SetStats(kTRUE); 
       
       /*
	 f1_hist1[i]->SetTitle("");
	 f2_hist1[i]->SetTitle("");
       */
       
       f1_hist1[i]->SetLineWidth(2); 
       f2_hist1[i]->SetLineWidth(3); 
       
       // diffferent histo colors and styles
       f1_hist1[i]->SetLineColor(41);
       f1_hist1[i]->SetLineStyle(1); 
       
       f2_hist1[i]->SetLineColor(43);
       f2_hist1[i]->SetLineStyle(2);  
       
       
       //     if(i == 0 ) {
       TLegend *leg = new TLegend(0.58, 0.91, 0.84, 0.99, "","brNDC");
       //     }
       //     else {
       //        TLegend *leg = new TLegend(0.08, 0.6, 0.38, 0.85, "","brNDC");
       //     }
       
       leg->SetBorderSize(2);
       //  leg->SetFillColor(51); // see new color definition above
       leg->SetFillStyle(1001); //
       leg->AddEntry(f1_hist1[i],"CMSSW_210pre9","l");
       leg->AddEntry(f2_hist1[i],"CMSSW_210pre9","l");
       
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


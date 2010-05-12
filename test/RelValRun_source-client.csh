#!/bin/tcsh

nohup cmsRun run_onRelVal_TTbar_MC_source-client_cfg.py      >& mcttb.txt &
nohup cmsRun run_onRelVal_TTbar_Startup_source-client_cfg.py >& stttb.txt &
nohup cmsRun run_onRelVal_QCD_MC_source-client_cfg.py        >& mcqcd.txt &
nohup cmsRun run_onRelVal_QCD_Startup_source-client_cfg.py   >& stqcd.txt &
nohup cmsRun run_onRelVal_HighPtQCD_MC_source-client_cfg.py  >& hptqc.txt &

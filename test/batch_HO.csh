#!/bin/csh
setenv name runHO
setenv MYWORKDIR /afs/cern.ch/cms/CAF/CMSALCA/ALCA_HCALCALIB/data/data_Validation/CMSSW_2_1_0_pre9/src/Validation/CaloTowers/test
setenv MYOUT ${MYWORKDIR} 
#----------------
cd ${MYWORKDIR}
cp ${MYWORKDIR}/runHOvalid_simhits_digis_rechits_towers_cfg.py   ${WORKDIR}/run.py
eval `scramv1 runtime -csh`
#
cd ${WORKDIR}
echo ${WORKDIR}

cmsRun run.py > & ${name}.log
#---------------------------------------------------------------
 rfcp   ${name}.log                  ${MYWORKDIR}/.
 rfcp   HcalRecHitValidationHO.root  ${MYOUT}/.

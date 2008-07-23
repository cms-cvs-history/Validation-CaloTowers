#!/bin/csh
setenv name runHF
setenv MYWORKDIR /afs/cern.ch/cms/CAF/CMSALCA/ALCA_HCALCALIB/data/data_Validation/CMSSW_2_1_0_pre9/src/Validation/CaloTowers/test
setenv MYOUT /castor/cern.ch/user/a/abdullin/validation_210pre9
#----------------
cd ${MYWORKDIR}
cp ${MYWORKDIR}/runHFvalid_simhits_digis_rechits_towers_cfg.py   ${WORKDIR}/run.py
eval `scramv1 runtime -csh`
#
cd ${WORKDIR}
echo ${WORKDIR}

cmsRun run.py > & ${name}.log
#---------------------------------------------------------------
 rfcp   ${name}.log                  ${MYWORKDIR}/.
 rfcp   HcalRecHitValidationHF.root  ${MYOUT}/.

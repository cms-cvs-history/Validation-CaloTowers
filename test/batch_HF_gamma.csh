#!/bin/csh
setenv name runHF_gamma
setenv MYWORKDIR /afs/cern.ch/cms/CAF/CMSALCA/ALCA_HCALCALIB/data/data_Validation/CMSSW_2_1_0_pre9/src/Validation/CaloTowers/test
setenv MYOUT ${MYWORKDIR}  #/castor/cern.ch/user/a/abdullin/validation_210pre9
#----------------
cd ${MYWORKDIR}
cp ${MYWORKDIR}/runHF_gamma_valid_simhits_digis_rechits_towers_cfg.py   ${WORKDIR}/run.py
eval `scramv1 runtime -csh`
#
cd ${WORKDIR}
echo ${WORKDIR}

cmsRun run.py > & ${name}.log
#---------------------------------------------------------------
 rfcp   ${name}.log                  ${MYWORKDIR}/.
 rfcp   HcalRecHitValidationHF_gamma.root  ${MYOUT}/.

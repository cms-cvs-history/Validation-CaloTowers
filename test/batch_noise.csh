#!/bin/csh
setenv name noise
setenv MYWORKDIR /afs/cern.ch/cms/CAF/CMSALCA/ALCA_HCALCALIB/data/data_Validation/CMSSW_2_1_0_pre9/src/Validation/CaloTowers/test
setenv MYOUT /castor/cern.ch/user/a/abdullin/validation_210pre9
#----------------
cd ${MYWORKDIR}
cp ${MYWORKDIR}/runNoise_valid_simhits_digis_rechits_cfg.py   ${WORKDIR}/run.py
eval `scramv1 runtime -csh`
#
cd ${WORKDIR}
echo ${WORKDIR}

cmsRun run.py > & ${name}.log
#---------------------------------------------------------------
 rfcp   ${name}.log                  ${MYWORKDIR}/.
 rfcp   HcalRecHitValidation_noise.root'  ${MYOUT}/.

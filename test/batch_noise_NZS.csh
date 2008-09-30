#!/bin/csh
setenv name noise_NZS
setenv MYWORKDIR /afs/cern.ch/cms/CAF/CMSALCA/ALCA_HCALCALIB/data/data_Validation/CMSSW_2_1_0/src/Validation/CaloTowers/test
setenv MYOUT ${MYWORKDIR}
#----------------
cd ${MYWORKDIR}
cp ${MYWORKDIR}/runNoise_valid_simhits_digis_rechits_NZS_cfg.py   ${WORKDIR}/run.py
eval `scramv1 runtime -csh`
#
cd   ${WORKDIR}
echo ${WORKDIR}

cmsRun run.py > & ${name}.log
#---------------------------------------------------------------
 rfcp   ${name}.log                          ${MYWORKDIR}/.
 rfcp   HcalRecHitValidation_noise_NZS.root  ${MYOUT}/.

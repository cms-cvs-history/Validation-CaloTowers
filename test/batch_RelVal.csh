#!/bin/csh
setenv name runRelVal
setenv MYWORKDIR /afs/cern.ch/cms/CAF/CMSALCA/ALCA_HCALCALIB/data/data_Validation/CMSSW_2_1_0/src/Validation/CaloTowers/test

setenv MYOUT  ${MYWORKDIR}  #/castor/cern.ch/user/a/abdullin/validation_210
#----------------
cd ${MYWORKDIR}
cp ${MYWORKDIR}/run_onRelVal_cfg.py   ${WORKDIR}/run.py
eval `scramv1 runtime -csh`
#
cd   ${WORKDIR}
echo ${WORKDIR}

cmsRun run.py > & ${name}.log
#---------------------------------------------------------------
 rfcp   ${name}.log                   ${MYWORKDIR}/.
 rfcp   HcalRecHitValidationALL.root  ${MYOUT}/.

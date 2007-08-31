#!/bin/csh

    eval `scramv1 ru -csh`
    SealPluginRefresh
        
    rm *.xml*
    if ( -e outputCaloTowersHB.log ) rm outputCaloTowersHB.log

    if ( -e outputCaloTowersHE.log ) rm outputCaloTowersHE.log

    if ( -e outputCaloTowersHF.log ) rm outputCaloTowersHF.log

    if ( -e outputCaloTowersHF_gamma.log ) rm outputCaloTowersHF_gamma.log

    if ( -e outputCaloTowersHO.log ) rm outputCaloTowersHO.log

    if ( -e outputCaloTowersALL.log ) rm outputCaloTowersALL.log

    cmsRun --parameter-set runHB.cfg >& outputCaloTowersHB.log &

    cmsRun --parameter-set runHE.cfg >& outputCaloTowersHE.log &

    cmsRun --parameter-set runHF.cfg >& outputCaloTowersHF.log &

    cmsRun --parameter-set runHF_gamma.cfg >& outputCaloTowersHF_gamma.log &

    cmsRun --parameter-set runHO.cfg >& outputCaloTowersHO.log &

    cmsRun --parameter-set runALL.cfg >& outputCaloTowersALL.log &

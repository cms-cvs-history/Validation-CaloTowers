#!/bin/csh

    eval `scramv1 ru -csh`
    SealPluginRefresh
        
    rm *.xml*
    if ( -e outputCaloTowersHBnoise.log ) rm outputCaloTowersHBnoise.log

    if ( -e outputCaloTowersHEnoise.log ) rm outputCaloTowersHEnoise.log

    if ( -e outputCaloTowersHFnoise.log ) rm outputCaloTowersHFnoise.log

    cmsRun --parameter-set runHBnoise.cfg >& outputCaloTowersHBnoise.log

    cmsRun --parameter-set runHEnoise.cfg >& outputCaloTowersHEnoise.log

    cmsRun --parameter-set runHFnoise.cfg >& outputCaloTowersHFnoise.log

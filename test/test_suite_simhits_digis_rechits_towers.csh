#!/bin/csh

    eval `scramv1 ru -csh`
    SealPluginRefresh
        
    rm *.xml*
    if ( -e outputCaloTowersHB_chain.log ) rm outputCaloTowersHB_chain.log

    if ( -e outputCaloTowersHE_chain.log ) rm outputCaloTowersHE_chain.log

    if ( -e outputCaloTowersHF_chain.log ) rm outputCaloTowersHF_chain.log

    if ( -e outputCaloTowersHF_gamma_chain.log ) rm outputCaloTowersHF_gamma_chain.log

    if ( -e outputCaloTowersHO_chain.log ) rm outputCaloTowersHO_chain.log

    if ( -e outputCaloTowersALL_chain.log ) rm outputCaloTowersALL_chain.log

    if ( -e outputCaloTowersNoise_chain.log ) rm outputCaloTowersNoise_chain.log

    cmsRun --parameter-set runHvalid_simhits_digis_rechits_towers.cfg >& outputCaloTowersHB_chain.log &

    cmsRun --parameter-set runHEvalid_simhits_digis_rechits_towers.cfg >& outputCaloTowersHE_chain.log &

    cmsRun --parameter-set runHFvalid_simhits_digis_rechits_towers.cfg >& outputCaloTowersHF_chain.log &

    cmsRun --parameter-set runHF_gamma_valid_simhits_digis_rechits_towers.cfg >& outputCaloTowersHF_gamma_chain.log &

    cmsRun --parameter-set runHOvalid_simhits_digis_rechits_towers.cfg >& outputCaloTowersHO_chain.log &

    cmsRun --parameter-set runALLvalid_simhits_digis_rechits_towers.cfg >& outputCaloTowersALL_chain.log &

    cmsRun --parameter-set runNoise_valid_simhits_digis_rechits.cfg >& outputCaloTowersNoise_chain.log &
 

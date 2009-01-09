import FWCore.ParameterSet.Config as cms

process = cms.Process("FULLPROD")
process.load("Validation.CaloTowers.Production_noecal_cfi")

process.load("Configuration.StandardSequences.GeometryHCAL_cff")
process.load("Configuration.StandardSequences.MagneticField_cff")
process.g4SimHits.UseMagneticField = False

process.USER = cms.OutputModule("PoolOutputModule",
    outputCommands = cms.untracked.vstring('keep *', 
        'drop EBDataFramesSorted_*_*_*', 
        'drop EEDataFramesSorted_*_*_*', 
        'drop ESDataFramesSorted_*_*_*', 
        'drop EBSrFlagsSorted_*_*_*', 
        'drop EESrFlagsSorted_*_*_*', 
        'drop EcalTriggerPrimitiveDigisSorted_*_*_*', 
        'drop CrossingFrame_*_*_*', 
        'drop HBHEDataFramesSorted_*_*_*', 
        'drop HFDataFramesSorted_*_*_*', 
        'drop HODataFramesSorted_*_*_*', 
        'drop ZDCDataFramesSorted_*_*_*', 
        'drop HcalTriggerPrimitiveDigisSorted_*_*_*', 
        'drop PSimHits_*_*_*', 
        'drop PSimHitCrossingFrame_*_*_*', 
        'drop PCaloHitCrossingFrame_*_*_*', 
        'drop SimTracks_*_*_*', 
        'drop SimTrackCrossingFrame_*_*_*', 
        'drop SimVertexs_*_*_*', 
        'drop SimVertexCrossingFrame_*_*_*', 
        'drop edmHepMCProductCrossingFrame_*_*_*', 
        'drop CrossingFramePlaybackInfo_*__*', 
        'drop edmTriggerResults_*_*_*'),
    fileName = cms.untracked.string('validation_ALL.root')
)

process.p = cms.Path(process.VtxSmeared*process.g4SimHits*process.mix*process.simHcalUnsuppressedDigis*process.simHcalDigis*process.hbhereco*process.hfreco*process.horeco)
process.outpath = cms.EndPath(process.USER)
process.PoolSource.fileNames = ['file:/afs/cern.ch/cms/data/CMSSW/Validation/HcalHits/data/1_4_x/mc_pi50_eta05.root']



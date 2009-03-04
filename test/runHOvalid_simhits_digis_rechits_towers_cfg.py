import FWCore.ParameterSet.Config as cms

process = cms.Process("VALID")
process.load("Validation.CaloTowers.Validation_hcalonly_cfi")

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(-1)
)

process.load("Configuration.StandardSequences.GeometryHCAL_cff")
process.load("Configuration.StandardSequences.MagneticField_cff")
process.g4SimHits.UseMagneticField = False

process.PoolSource.fileNames = ['file:/afs/cern.ch/cms/data/CMSSW/Validation/HcalHits/data/3_1_X/mc_pi+500_ho.root']

process.hcalDigiAnalyzer.outputFile = 'HcalDigisValidationHO.root'
process.hcalDigiAnalyzer.hcalselector = 'HO'

process.hcalRecoAnalyzer.outputFile = 'HcalRecHitValidationHO.root'
process.hcalRecoAnalyzer.hcalselector = 'HO'
process.hcalRecoAnalyzer.ecalselector = 'no'
process.hcalRecoAnalyzer.eventype = 'single'

process.p = cms.Path(process.VtxSmeared*process.g4SimHits*process.mix*process.simHcalUnsuppressedDigis*process.simHcalDigis*process.hbhereco*process.horeco*process.hfreco*process.hcalDigiAnalyzer*process.hcalRecoAnalyzer)


import FWCore.ParameterSet.Config as cms

process = cms.Process("VALID")
process.load("Validation.CaloTowers.Validation_hcalonly_cfi")

process.load("Configuration.StandardSequences.GeometryHCAL_cff")
process.load("Configuration.StandardSequences.MagneticField_cff")
process.g4SimHits.UseMagneticField = False

process.PoolSource.fileNames = ['file:/afs/cern.ch/cms/data/CMSSW/Validation/HcalHits/data/1_4_x/mc_pi50_eta05.root']

process.hcalRecoAnalyzer.outputFile = 'HcalRecHitValidationALL.root'
process.hcalRecoAnalyzer.hcalselector = 'all'
process.hcalRecoAnalyzer.ecalselector = 'no'
process.hcalRecoAnalyzer.eventype = 'single'

process.p = cms.Path(process.VtxSmeared*process.g4SimHits*process.mix*process.simHcalUnsuppressedDigis*process.simHcalDigis*process.hbhereco*process.horeco*process.hfreco*process.hcalRecoAnalyzer)

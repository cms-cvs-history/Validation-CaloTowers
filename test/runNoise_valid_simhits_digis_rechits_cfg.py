import FWCore.ParameterSet.Config as cms

process = cms.Process("VALID")
process.load("Validation.CaloTowers.Validation_hcalonly_cfi")

process.PoolSource.fileNames = ['file:/afs/cern.ch/cms/data/CMSSW/Validation/HcalHits/data/1_4_x/mc_nue.root']

process.hcalDigiAnalyzer.outputFile = 'HcalDigisValidation_noise.root'
process.hcalDigiAnalyzer.hcalselector = 'noise'

process.hcalRecoAnalyzer.outputFile = 'HcalRecHitValidation_noise.root'
process.hcalRecoAnalyzer.hcalselector = 'noise'
process.hcalRecoAnalyzer.ecalselector = 'no'
process.hcalRecoAnalyzer.eventype = 'single'

process.p = cms.Path(process.VtxSmeared*process.g4SimHits*process.mix*process.simHcalUnsuppressedDigis*process.simHcalDigis*process.hbhereco*process.horeco*process.hfreco*process.hcalDigiAnalyzer*process.hcalRecoAnalyzer)

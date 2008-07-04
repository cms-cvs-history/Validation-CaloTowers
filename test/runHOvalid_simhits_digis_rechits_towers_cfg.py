import FWCore.ParameterSet.Config as cms

process = cms.Process("VALID")
process.load("Validation.CaloTowers.Validation_hcalonly_cfi")

process.PoolSource.fileNames = ['file:/afs/cern.ch/cms/data/CMSSW/Validation/HcalHits/data/1_4_x/mc_pi+500_ho.root']

process.hcalDigiAnalyzer.outputFile = 'HcalDigisValidationHO.root'
process.hcalDigiAnalyzer.hcalselector = 'HO'

process.hcalRecoAnalyzer.outputFile = 'HcalRecHitValidationHO.root'
process.hcalRecoAnalyzer.hcalselector = 'HO'
process.hcalRecoAnalyzer.ecalselector = 'no'
process.hcalRecoAnalyzer.eventype = 'single'

process.p = cms.Path(process.VtxSmeared*process.g4SimHits*process.mix*process.simHcalUnsuppressedDigis*process.simHcalDigis*process.hbhereco*process.horeco*process.hfreco*process.hcalDigiAnalyzer*process.hcalRecoAnalyzer)


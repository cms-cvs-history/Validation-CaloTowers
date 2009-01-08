import FWCore.ParameterSet.Config as cms

process = cms.Process("VALID")
process.load("Validation.CaloTowers.Validation_hcalonly_cfi")

process.PoolSource.fileNames = ['file:/afs/cern.ch/cms/data/CMSSW/Validation/HcalHits/data/1_4_x/mc_gamma50_hf-.root', 'file:/afs/cern.ch/cms/data/CMSSW/Validation/HcalHits/data/1_4_x/mc_gamma50_hf+.root']

process.hcalRecoAnalyzer.outputFile = 'HcalRecHitValidationHF_gamma.root'
process.hcalRecoAnalyzer.hcalselector = 'HF'
process.hcalRecoAnalyzer.ecalselector = 'no'
process.hcalRecoAnalyzer.eventype = 'single'

#process.p = cms.Path(process.VtxSmeared*process.g4SimHits*process.mix*process.calDigi*process.calolocalreco*process.caloTowersRec*process.hcalDigiAnalyzer*process.hcalRecoAnalyzer*process.hcalTowerAnalyzer)

process.p = cms.Path(process.VtxSmeared * process.g4SimHits * process.mix * process.simHcalUnsuppressedDigis * process.simHcalDigis * process.hbhereco* process.horeco * process.hfreco * process.hcalRecoAnalyzer)


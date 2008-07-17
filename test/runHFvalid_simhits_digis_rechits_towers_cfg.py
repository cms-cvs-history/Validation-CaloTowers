import FWCore.ParameterSet.Config as cms

process = cms.Process("VALID")
process.load("Validation.CaloTowers.Validation_cfi")

process.PoolSource.fileNames = ['file:/afs/cern.ch/cms/data/CMSSW/Validation/HcalHits/data/1_4_x/mc_pi50_etaphi-344.root', 'file:/afs/cern.ch/cms/data/CMSSW/Validation/HcalHits/data/1_4_x/mc_pi50_etaphi+344.root']

process.hcalDigiAnalyzer.outputFile = 'HcalDigisValidationHF.root'
process.hcalDigiAnalyzer.hcalselector = 'HF'

process.hcalRecoAnalyzer.outputFile = 'HcalRecHitValidationHF.root'
process.hcalRecoAnalyzer.hcalselector = 'HF'
process.hcalRecoAnalyzer.ecalselector = 'yes'
process.hcalRecoAnalyzer.eventype = 'single'

process.hcalTowerAnalyzer.outputFile = 'CaloTowersValidationHF.root'
process.hcalTowerAnalyzer.hcalselector = 'HF'

process.p = cms.Path(process.VtxSmeared*process.g4SimHits*process.mix*process.calDigi*process.calolocalreco*process.caloTowersRec*process.hcalDigiAnalyzer*process.hcalRecoAnalyzer*process.hcalTowerAnalyzer)
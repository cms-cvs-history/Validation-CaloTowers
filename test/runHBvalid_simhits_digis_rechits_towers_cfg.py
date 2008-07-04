import FWCore.ParameterSet.Config as cms

process = cms.Process("VALID")

process.load("Validation.CaloTowers.Validation_cfi")

process.PoolSource.fileNames = ['file:/afs/cern.ch/cms/data/CMSSW/Validation/HcalHits/data/1_4_x/mc_pi50_etaphi-44.root', 'file:/afs/cern.ch/cms/data/CMSSW/Validation/HcalHits/data/1_4_x/mc_pi50_etaphi+44.root']

process.hcalDigiAnalyzer.outputFile = 'HcalDigisValidationHB.root'
process.hcalDigiAnalyzer.hcalselector = 'HB'

process.hcalRecoAnalyzer.outputFile = 'HcalRecHitValidationHB.root'
process.hcalRecoAnalyzer.hcalselector = 'HB'
process.hcalRecoAnalyzer.ecalselector = 'yes'
process.hcalRecoAnalyzer.eventype = 'single'

process.hcalTowerAnalyzer.outputFile = 'CaloTowersValidationHB.root'
process.hcalTowerAnalyzer.hcalselector = 'HB'

process.p = cms.Path(process.VtxSmeared*process.g4SimHits*process.mix*process.calDigi*process.calolocalreco*process.caloTowersRec*process.hcalDigiAnalyzer*process.hcalRecoAnalyzer*process.hcalTowerAnalyzer)

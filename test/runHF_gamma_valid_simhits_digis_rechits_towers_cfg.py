import FWCore.ParameterSet.Config as cms

process = cms.Process("VALID")
process.load("Validation.CaloTowers.Validation_cfi")

process.load("Configuration.StandardSequences.GeometryECALHCAL_cff")
process.load("Configuration.StandardSequences.MagneticField_cff")
process.g4SimHits.UseMagneticField = False

process.PoolSource.fileNames = ['file:/afs/cern.ch/cms/data/CMSSW/Validation/HcalHits/data/1_4_x/mc_gamma50_hf-.root', 'file:/afs/cern.ch/cms/data/CMSSW/Validation/HcalHits/data/1_4_x/mc_gamma50_hf+.root']

process.hcalDigiAnalyzer.outputFile = 'HcalDigisValidationHF_gamma.root'
process.hcalDigiAnalyzer.hcalselector = 'HF'

process.hcalRecoAnalyzer.outputFile = 'HcalRecHitValidationHF_gamma.root'
process.hcalRecoAnalyzer.hcalselector = 'HF'
process.hcalRecoAnalyzer.ecalselector = 'yes'
process.hcalRecoAnalyzer.eventype = 'single'

process.hcalTowerAnalyzer.outputFile = 'CaloTowersValidationHF.root'
process.hcalTowerAnalyzer.hcalselector = 'HF'

process.p = cms.Path(process.VtxSmeared*process.g4SimHits*process.mix*process.calDigi*process.calolocalreco*process.caloTowersRec*process.hcalDigiAnalyzer*process.hcalRecoAnalyzer*process.hcalTowerAnalyzer)



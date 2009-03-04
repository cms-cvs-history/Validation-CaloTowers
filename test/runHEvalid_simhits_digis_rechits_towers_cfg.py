import FWCore.ParameterSet.Config as cms

process = cms.Process("VALID")
process.load("Validation.CaloTowers.Validation_cfi")

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(-1)
)

process.load("Configuration.StandardSequences.GeometryECALHCAL_cff")
process.load("Configuration.StandardSequences.MagneticField_cff")
process.g4SimHits.UseMagneticField = False

process.PoolSource.fileNames = ['file:/afs/cern.ch/cms/data/CMSSW/Validation/HcalHits/data/3_1_X/mc_pi50_etaphi-244.root', 'file:/afs/cern.ch/cms/data/CMSSW/Validation/HcalHits/data/3_1_X/mc_pi50_etaphi+244.root']

process.hcalDigiAnalyzer.outputFile = 'HcalDigisValidationHE.root'
process.hcalDigiAnalyzer.hcalselector = 'HE'

process.hcalRecoAnalyzer.outputFile = 'HcalRecHitValidationHE.root'
process.hcalRecoAnalyzer.hcalselector = 'HE'
process.hcalRecoAnalyzer.ecalselector = 'yes'
process.hcalRecoAnalyzer.eventype = 'single'

process.hcalTowerAnalyzer.outputFile = 'CaloTowersValidationHE.root'
process.hcalTowerAnalyzer.hcalselector = 'HE'

process.p = cms.Path(process.VtxSmeared*process.g4SimHits*process.mix* process.calDigi *  process.ecalLocalRecoSequence *  process.hbhereco*process.horeco*process.hfreco * process.caloTowersRec*process.hcalDigiAnalyzer*process.hcalRecoAnalyzer*process.hcalTowerAnalyzer)



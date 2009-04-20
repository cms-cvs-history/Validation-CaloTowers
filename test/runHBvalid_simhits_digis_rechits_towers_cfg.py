import FWCore.ParameterSet.Config as cms

process = cms.Process("VALID")
process.load("Validation.CaloTowers.Validation_cfi")

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(-1)
)

process.load("Configuration.StandardSequences.GeometryECALHCAL_cff")
process.load("Configuration.StandardSequences.MagneticField_cff")
process.g4SimHits.UseMagneticField = False


process.PoolSource.fileNames = ['file:/afs/cern.ch/cms/data/CMSSW/Validation/HcalHits/data/3_1_X/mc_pi50_etaphi-44.root', 'file:/afs/cern.ch/cms/data/CMSSW/Validation/HcalHits/data/3_1_X/mc_pi50_etaphi+44.root']

process.hcalDigiAnalyzer.outputFile = 'HcalDigisValidationHB.root'
process.hcalDigiAnalyzer.hcalselector = 'HB'

process.hcalRecoAnalyzer.outputFile = 'HcalRecHitValidationHB.root'
process.hcalRecoAnalyzer.hcalselector = 'HB'
process.hcalRecoAnalyzer.ecalselector = 'yes'
process.hcalRecoAnalyzer.eventype = 'single'

process.hcalTowerAnalyzer.outputFile = 'CaloTowersValidationHB.root'
process.hcalTowerAnalyzer.hcalselector = 'HB'

#process.USER = cms.OutputModule("PoolOutputModule",
#    fileName = cms.untracked.string('output.root'),
#    dataset = cms.untracked.PSet(
#        dataTier = cms.untracked.string('GEN-SIM-RECO'),
#        filterName = cms.untracked.string('')
#    )
#)


process.p = cms.Path(
 process.VtxSmeared * process.g4SimHits * process.mix *
 process.calDigi * 
 process.ecalPacker * process.hcalRawData *
 process.ecalDigis * process.hcalDigis *
 process.ecalGlobalUncalibRecHit * process.ecalDetIdToBeRecovered * process.ecalRecHit *
 process.hbhereco * process.horeco * process.hfreco *
 process.caloTowersRec *
 process.hcalDigiAnalyzer *
 process.hcalRecoAnalyzer *
 process.hcalTowerAnalyzer ) 

### process.outpath = cms.EndPath(process.USER)

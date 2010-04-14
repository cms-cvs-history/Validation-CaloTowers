#################################################################
# Remaking HCAL RecHits and CaloTowers from RAW for validation  #
#################################################################

import FWCore.ParameterSet.Config as cms

process = cms.Process("RelValValidation")
process.load("Configuration.StandardSequences.Geometry_cff")
process.load('Configuration.StandardSequences.RawToDigi_cff')
process.load("Configuration.StandardSequences.Reconstruction_cff")

process.load("Configuration.StandardSequences.FrontierConditions_GlobalTag_cff")
#--- automatic GlobalTag setting -------------------------------------------
#--- to set it manually: - comment the following 2 lines
#--- and uncomment the 3d one with the actual tag to be set properly
from Configuration.PyReleaseValidation.autoCond import autoCond
process.GlobalTag.globaltag = autoCond['startup']
#--process.GlobalTag.globaltag = 'MC_36Y_V4::All'



process.load("DQMServices.Core.DQM_cfg")
process.DQM.collectorHost = ''

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(10)
)

#######################################################################
#--- TWO-file approach, as both RAW  (for HCAL re-reco)    and
#                               RECO (for unchanged ECAL)  are required 
#######################################################################
process.source = cms.Source("PoolSource",
noEventSort = cms.untracked.bool(True),
duplicateCheckMode = cms.untracked.string('noDuplicateCheck'),   
    #--- full set of GEN-SIM-RECO RelVal files ----------------------------
    fileNames = cms.untracked.vstring(

     ),
    #--- full set of GEN-SIM-DIGI-RAW(-HLTDEBUG) RelVal files -------------
    secondaryFileNames = cms.untracked.vstring(   

     )
)


process.hcalTowerAnalyzer = cms.EDAnalyzer("CaloTowersValidation",
    outputFile               = cms.untracked.string('CaloTowersValidationRelVal.root'),
    CaloTowerCollectionLabel = cms.untracked.InputTag('newtowerMaker'),
    hcalselector             = cms.untracked.string('all'),
    mc                       = cms.untracked.string('no')
)

process.hcalNoiseRates = cms.EDAnalyzer('NoiseRates',
    outputFile   = cms.untracked.string('NoiseRatesRelVal.root'),
    rbxCollName  = cms.untracked.InputTag('newhcalnoise'),
    minRBXEnergy = cms.untracked.double(20.0),
    minHitEnergy = cms.untracked.double(1.5)
)

process.hcalRecoAnalyzer = cms.EDAnalyzer("HcalRecHitsValidation",
    outputFile                = cms.untracked.string('HcalRecHitValidationRelVal.root'),

    HBHERecHitCollectionLabel = cms.untracked.InputTag("newhbhereco"),
    HFRecHitCollectionLabel   = cms.untracked.InputTag("newhfreco"),
    HORecHitCollectionLabel   = cms.untracked.InputTag("newhoreco"),
    eventype                  = cms.untracked.string('multi'),
    ecalselector              = cms.untracked.string('yes'),
    hcalselector              = cms.untracked.string('all'),
    mc                        = cms.untracked.string('no')
)

#-----------------------------------------------------------------------------
#                        HCAL re-reco 4-step procedure preparation
#-----------------------------------------------------------------------------
#--- In case of DATA (re-reco) 
#--- one might need to add some parameters replacements
#--- similar to what is in the reference RECO config
#--- used for the original reconstruction !


#(1) -------------------------- to get hcalDigis (on the fly) from existing RAW
#
from EventFilter.HcalRawToDigi.HcalRawToDigi_cfi import *

#(2) -------------------------- to get (NEW) HCAL RecHits 
#
from RecoLocalCalo.HcalRecProducers.HcalHitReconstructor_hbhe_cfi import *
from RecoLocalCalo.HcalRecProducers.HcalHitReconstructor_ho_cfi import *
from RecoLocalCalo.HcalRecProducers.HcalHitReconstructor_hf_cfi import *
process.newhbhereco = hbhereco.clone()
process.newhoreco   = horeco.clone()
process.newhfreco   = hfreco.clone()
process.newhcalLocalRecoSequence = cms.Sequence(process.newhbhereco+process.newhfreco+process.newhoreco)

#(3) -------------------------- to get (NEW) CaloTowers 
#
from RecoLocalCalo.CaloTowersCreator.calotowermaker_cfi import *
process.newtowerMaker = calotowermaker.clone()
process.newtowerMaker.hfInput = cms.InputTag("newhfreco")
process.newtowerMaker.hbheInput = cms.InputTag("newhbhereco")
process.newtowerMaker.hoInput = cms.InputTag("newhoreco")

#(4) -------------------------  to get (NEW) RBX noise 
# 
from RecoMET.METProducers.hcalnoiseinfoproducer_cfi import *
process.newhcalnoise = hcalnoise.clone()
process.newhcalnoise.recHitCollName = "newhbhereco"
process.newhcalnoise.caloTowerCollName = "newtowerMaker"

#--- Making re-reco and analysing
#--- first 4 producers: HCAL+CaloTowers(+RBX noise) re-reco. 
#
process.p = cms.Path(
process.hcalDigis *
process.newhcalLocalRecoSequence *
process.newtowerMaker *
process.newhcalnoise *
#---
process.hcalTowerAnalyzer * 
process.hcalNoiseRates * 
process.hcalRecoAnalyzer)

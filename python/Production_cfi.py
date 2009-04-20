import FWCore.ParameterSet.Config as cms

from Configuration.StandardSequences.SimulationRandomNumberGeneratorSeeds_cff import *
from Configuration.StandardSequences.VtxSmearedGauss_cff import *
from Configuration.StandardSequences.Simulation_cff import *
from Configuration.StandardSequences.MixingNoPileUp_cff import *
from Configuration.StandardSequences.FrontierConditions_GlobalTag_cff import *
GlobalTag.globaltag = 'IDEAL_31X::All'
from Configuration.StandardSequences.Reconstruction_cff import *

maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(-1)
)
MessageLogger = cms.Service("MessageLogger")

source = cms.Source("PoolSource",
    debugFlag = cms.untracked.bool(True),
    debugVebosity = cms.untracked.uint32(10),
    fileNames = cms.untracked.vstring('file:/afs/cern.ch/cms/data/CMSSW/Validation/HcalHits/data/1_4_x/mc_pi+100_etaphi44.root')
)

VtxSmeared.SigmaX = 0.00001
VtxSmeared.SigmaY = 0.00001
VtxSmeared.SigmaZ = 0.00001

#--- DigiToRaw
from Configuration.StandardSequences.DigiToRaw_cff import *
ecalPacker.Label = 'simEcalDigis'
ecalPacker.InstanceEB = 'ebDigis'
ecalPacker.InstanceEE = 'eeDigis'
ecalPacker.labelEBSRFlags = "simEcalDigis:ebSrFlags"
ecalPacker.labelEESRFlags = "simEcalDigis:eeSrFlags"
#--- RawToDigi
from Configuration.StandardSequences.RawToDigi_cff  import *
hcalDigis.InputLabel = 'hcalRawData'
ecalDigis.InputLabel = 'ecalPacker'


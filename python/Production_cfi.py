import FWCore.ParameterSet.Config as cms

from Configuration.StandardSequences.SimulationRandomNumberGeneratorSeeds_cff import *
from Configuration.StandardSequences.VtxSmearedGauss_cff import *
from Configuration.StandardSequences.Simulation_cff import *
from Configuration.StandardSequences.Geometry_cff import *
from Configuration.StandardSequences.Digi_cff import *
from Configuration.StandardSequences.MagneticField_cff import *
from Configuration.StandardSequences.MixingNoPileUp_cff import *
from Configuration.StandardSequences.FakeConditions_cff import *
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

XMLIdealGeometryESSource.geomXMLFiles = cms.vstring(
    "Geometry/CMSCommonData/data/materials.xml",
    "Geometry/CMSCommonData/data/rotations.xml",
    "Geometry/HcalCommonData/data/hcalrotations.xml",
    "Geometry/HcalCommonData/data/hcalforwardmaterial.xml",
    "Geometry/TrackerCommonData/data/trackermaterial.xml",
    "Geometry/CMSCommonData/data/normal/cmsextent.xml",
    "Geometry/CMSCommonData/data/cms.xml",
    "Geometry/CMSCommonData/data/cmsMother.xml",
    "Geometry/CMSCommonData/data/muonBase.xml",
    "Geometry/CMSCommonData/data/cmsMuon.xml",
    "Geometry/CMSCommonData/data/mgnt.xml",
    "Geometry/CMSCommonData/data/muonMagnet.xml",
    "Geometry/CMSCommonData/data/muonMB.xml",
    "Geometry/CMSCommonData/data/caloBase.xml",
    "Geometry/CMSCommonData/data/cmsCalo.xml",
    "Geometry/HcalCommonData/data/hcalalgo.xml",
    "Geometry/EcalCommonData/data/eregalgo.xml",
    "Geometry/EcalCommonData/data/ebalgo.xml",
    "Geometry/EcalCommonData/data/ebcon.xml",
    "Geometry/EcalCommonData/data/ebrot.xml",
    "Geometry/EcalCommonData/data/eecon.xml",
    "Geometry/EcalCommonData/data/escon.xml",
    "Geometry/EcalCommonData/data/eefixed.xml",
    "Geometry/EcalCommonData/data/eehier.xml",
    "Geometry/EcalCommonData/data/eealgo.xml",
    "Geometry/EcalCommonData/data/esalgo.xml",
    "Geometry/EcalCommonData/data/eeF.xml",
    "Geometry/EcalCommonData/data/eeB.xml",
    "Geometry/HcalCommonData/data/hcalbarrelalgo.xml",
    "Geometry/HcalCommonData/data/hcalendcapalgo.xml",
    "Geometry/HcalCommonData/data/hcalouteralgo.xml",
    "Geometry/HcalCommonData/data/hcalforwardalgo.xml",
    "Geometry/HcalCommonData/data/hcalforwardfibre.xml",
    "Geometry/EcalSimData/data/ecalsens.xml",
    "Geometry/HcalCommonData/data/hcalsens.xml",
    "Geometry/HcalSimData/data/CaloUtil.xml",
    "Geometry/EcalSimData/data/EcalProdCuts.xml",
    "Geometry/HcalSimData/data/HcalProdCuts.xml",
    "Geometry/CMSCommonData/data/FieldParameters.xml"
)


VtxSmeared.SigmaX = 0.00001
VtxSmeared.SigmaY = 0.00001
VtxSmeared.SigmaZ = 0.00001
g4SimHits.UseMagneticField = False
hbhereco.digiLabel = 'simHcalDigis'
horeco.digiLabel = 'simHcalDigis'
hfreco.digiLabel = 'simHcalDigis'
ecalPreshowerRecHit.ESdigiCollection = 'simEcalPreshowerDigis'
ecalWeightUncalibRecHit.EBdigiCollection = 'simEcalDigis:ebDigis'
ecalWeightUncalibRecHit.EEdigiCollection = 'simEcalDigis:eeDigis'

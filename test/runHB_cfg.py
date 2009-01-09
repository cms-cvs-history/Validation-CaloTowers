import FWCore.ParameterSet.Config as cms

process = cms.Process("CALOTOWERS")
process.load("Validation.CaloTowers.CaloTowersValidation_cfi")
process.load("Configuration.StandardSequences.Geometry_cff")

process.PoolSource.fileNames = ['file:/afs/cern.ch/cms/data/CMSSW/Validation/HcalDigis/data/2_0_0/simhits_pi50_etaphi44.root']
process.myanalyzer.outputFile = 'CaloTowersValidationHB.root'
process.myanalyzer.hcalselector = 'HB'



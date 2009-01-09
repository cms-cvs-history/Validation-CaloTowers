import FWCore.ParameterSet.Config as cms

process = cms.Process("CALOTOWERS")
process.load("Validation.CaloTowers.CaloTowersValidation_cfi")
process.load("Configuration.StandardSequences.Geometry_cff")

process.PoolSource.fileNames = ['file:/afs/cern.ch/cms/data/CMSSW/Validation/HcalDigis/data/1_8_0/simhits_pi50_etaphi244.root']
process.myanalyzer.outputFile = 'CaloTowersValidationHE.root'
process.myanalyzer.hcalselector = 'HE'



#ifndef CaloTowersValidation_H
#define CaloTowersValidation_H
 

#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/EventSetup.h"
#include "FWCore/Framework/interface/ESHandle.h"
#include "FWCore/Framework/interface/MakerMacros.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/MessageLogger/interface/MessageLogger.h"

#include "DQMServices/Core/interface/DQMStore.h"
#include "FWCore/ServiceRegistry/interface/Service.h"

#include "DataFormats/DetId/interface/DetId.h"
#include "DataFormats/CaloTowers/interface/CaloTowerDetId.h"
#include "DataFormats/Math/interface/Vector3D.h"

#include <vector>
#include <utility>
#include <ostream>
#include <string>
#include <algorithm>
#include <cmath>
#include "DQMServices/Core/interface/MonitorElement.h"


class CaloTowersValidation : public edm::EDAnalyzer {
 public:
   CaloTowersValidation(edm::ParameterSet const& conf);
  ~CaloTowersValidation();
  virtual void analyze(edm::Event const& e, edm::EventSetup const& c);
  virtual void beginJob(const edm::EventSetup&) ;
  virtual void endJob() ;

 private:
  
  DQMStore* dbe_;
  std::string outputFile_;
  std::string hcalselector_;

  typedef math::RhoEtaPhiVector Vector;

  std::string theCaloTowerCollectionLabel;

  // eta limits to calcualte MET, SET (not to include HF if not needed)
  double etaMax;
  double etaMin;

  MonitorElement* meEnergyHcalvsEcal;
  MonitorElement* meEnergyHO; 
  MonitorElement* meEnergyEcal; 
  MonitorElement* meEnergyHcal; 
  MonitorElement* meNumFiredTowers;

  MonitorElement* meEnergyEcalTower;
  MonitorElement* meEnergyHcalTower;
  MonitorElement* meTotEnergy;

  MonitorElement* mapEnergy;
  MonitorElement* mapEnergyEcal;
  MonitorElement* mapEnergyHcal;
  MonitorElement* MET;
  MonitorElement* SET;
  MonitorElement* phiMET;


};

#endif

#include "FWCore/PluginManager/interface/ModuleDef.h"
#include "FWCore/Framework/interface/MakerMacros.h"

#include "Validation/CaloTowers/interface/CaloTowersClient.h"

DEFINE_SEAL_MODULE();
DEFINE_ANOTHER_FWK_MODULE(CaloTowersClient);

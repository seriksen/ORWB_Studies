#include "ORWB_Studies.h"
#include "ConfigSvc.h"
#include <string>

int main(int argc, char* argv[]) {
  // Crate config svc to read from unique config file
  string alpacaTopDir = std::getenv("ALPACA_TOPDIR");
  string analysisName("ORWB_Studies");
  string configFile("config/ORWB_Studies.config");
  string configFileFullPath = alpacaTopDir + "/modules/" + analysisName + "/" + configFile;

  ConfigSvc* config = ConfigSvc::Instance(argc, argv, analysisName, alpacaTopDir, configFileFullPath);

  // Create analysis code and run
  Analysis* ana;
  if(config->configFileVarMap["whichAna"]==0){
    ana = new ORWB_Studies();
    ana->Run(config->FileList, config->OutName, config->FileListTruth);
  }

  // Clean up
  delete ana;
  delete config;

  return 0;
}

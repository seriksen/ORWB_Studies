#ifndef ORWB_Studies_H
#define ORWB_Studies_H

#include "Analysis.h"

#include "CutsORWB_Studies.h"
#include "EventBase.h"

#include <TTreeReader.h>
#include <string>

class SkimSvc;

class ORWB_Studies : public Analysis {

public:
    ORWB_Studies();
    ~ORWB_Studies();

    void Initialize();
    void Execute();
    void Finalize();

protected:
    CutsORWB_Studies* m_cutsORWB_Studies;
    ConfigSvc* m_conf;
};

#endif

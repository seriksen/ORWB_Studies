#ifndef CutsORWB_Studies_H
#define CutsORWB_Studies_H

#include "EventBase.h"

class CutsORWB_Studies {

public:
    CutsORWB_Studies(EventBase* eventBase);
    ~CutsORWB_Studies();
    bool ORWB_StudiesCutsOK();

private:
    EventBase* m_event;
};

#endif

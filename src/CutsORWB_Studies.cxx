#include "CutsORWB_Studies.h"
#include "ConfigSvc.h"

CutsORWB_Studies::CutsORWB_Studies(EventBase* eventBase)
{
    m_event = eventBase;
}

CutsORWB_Studies::~CutsORWB_Studies()
{
}

// Function that lists all of the common cuts for this Analysis
bool CutsORWB_Studies::ORWB_StudiesCutsOK()
{
    // List of common cuts for this analysis into one cut
    return true;
}

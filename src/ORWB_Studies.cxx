#include "ORWB_Studies.h"
#include "Analysis.h"
#include "ConfigSvc.h"
#include "CutsBase.h"
#include "CutsORWB_Studies.h"
#include "EventBase.h"
#include "HistSvc.h"
#include "Logger.h"
#include "SkimSvc.h"
#include "SparseSvc.h"

// Constructor
ORWB_Studies::ORWB_Studies()
    : Analysis()
{
    // Set up the expected event structure, include branches required for analysis.
    // List the branches required below, see full list here https://luxzeplin.gitlab.io/docs/softwaredocs/analysis/analysiswithrqs/rqlist.html
    // Load in the Single Scatters Branch
    m_event->IncludeBranch("ss");
    m_event->Initialize();
    ////////

    // Setup logging
    logging::set_program_name("ORWB_Studies Analysis");

    // Setup the analysis specific cuts.
    m_cutsORWB_Studies = new CutsORWB_Studies(m_event);

    // Setup config service so it can be used to get config variables
    m_conf = ConfigSvc::Instance();
}

// Destructor
ORWB_Studies::~ORWB_Studies()
{
    delete m_cutsORWB_Studies;
}

/////////////////////////////////////////////////////////////////
// Start of main analysis code block
//
// Initialize() -  Called once before the event loop.
void ORWB_Studies::Initialize()
{
    INFO("Initializing ORWB_Studies Analysis");
}

// Execute() - Called once per event.
void ORWB_Studies::Execute()
{

    // Make a variable from the contents of the data
    //  prevents having to write full ' (*event->Branch)->variableName ' structure many times in the analysis
    int numSS = (*m_event->m_singleScatter)->nSingleScatters;

    // if there is a single scatter in the event then plot the S1 pulse area
    if (numSS > 0) {
        m_hists->BookFillHist("SingleScatters", 300, 0., 3000., (*m_event->m_singleScatter)->s1Area_phd);
    }
}

// Finalize() - Called once after event loop.
void ORWB_Studies::Finalize()
{
    INFO("Finalizing ORWB_Studies Analysis");
}

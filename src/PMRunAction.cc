#include "PMRunAction.hh"
#include "G4RunManager.hh"
#include "Randomize.hh"
#include <ctime>
#include <random>

PMRunAction::PMRunAction() {
    G4AnalysisManager *analysisManager = G4AnalysisManager::Instance();

    analysisManager->CreateNtuple("START", "START");
    analysisManager->CreateNtupleDColumn("ENERGY_PMT");
    analysisManager->CreateNtupleIColumn("DECAY");
    analysisManager->FinishNtuple(0);
}

PMRunAction::~PMRunAction() {}

void PMRunAction::BeginOfRunAction(const G4Run *run) {
    G4AnalysisManager *analysisManager = G4AnalysisManager::Instance();
    G4int runID = run->GetRunID();
    G4long seed = time(NULL) + runID; // oppure una combinazione che garantisca unicit�
    G4Random::setTheSeed(seed);
    G4cout << "Inizio run " << runID << " con seme " << seed << G4endl;

    std::stringstream strRunID;
    strRunID << runID;

    analysisManager->OpenFile("output" + strRunID.str() + ".root");
    //analysisManager->OpenFile("output.root");
}

void PMRunAction::EndOfRunAction(const G4Run *run) {
    G4AnalysisManager *analysisManager = G4AnalysisManager::Instance();

    analysisManager->Write();

    analysisManager->CloseFile();

    G4int runID = run->GetRunID();
}

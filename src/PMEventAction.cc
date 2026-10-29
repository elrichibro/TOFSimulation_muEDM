#include "PMEventAction.hh"

#include "G4RunManager.hh"
#include "G4AnalysisManager.hh"
#include "PMPrimaryGenerator.hh"
#include "G4SystemOfUnits.hh"
#include "G4Run.hh"


PMEventAction::PMEventAction(PMPrimaryGenerator* primaryGen): fPrimaryGenerator(primaryGen), fEventID(0), fPrimaryEnergy(0.), fTheta(0.), fPhi(0.) {}

PMEventAction::~PMEventAction() {}

void PMEventAction::BeginOfEventAction(const G4Event* evt) {}

void PMEventAction::EndOfEventAction(const G4Event*) {}

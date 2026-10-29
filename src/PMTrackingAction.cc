#include "PMTrackingAction.hh"

#include "G4Track.hh"
#include "G4VProcess.hh"
#include "G4RunManager.hh"
#include "G4EventManager.hh"
#include "G4UnitsTable.hh"

// Constructor -> when you have ereditarieta da una classe madre -> nel costruttore devi chiamare
// prima il costruttore della classe madre e poi quello della classe figlia. 
PMTrackingAction::PMTrackingAction() : G4UserTrackingAction() {}
// Destructor -> Does the mother destructor call automatically
PMTrackingAction::~PMTrackingAction() {}

void PMTrackingAction::PreUserTrackingAction(const G4Track* track) {}

void PMTrackingAction::PostUserTrackingAction(const G4Track* track) {}

#ifndef PMEVENTACTION_HH
#define PMEVENTACTION_HH

#include "G4UserEventAction.hh"
#include "G4Event.hh"
#include "G4ThreeVector.hh"
#include "PMPrimaryGenerator.hh"


class PMRunAction;

class PMEventAction : public G4UserEventAction
{
public:
    PMEventAction(PMRunAction*);
    virtual ~PMEventAction();

    virtual void BeginOfEventAction(const G4Event*) override;
    virtual void EndOfEventAction(const G4Event*) override;

    PMEventAction(PMPrimaryGenerator* primaryGen);

    G4int GetEventID() const { return fEventID; }
    G4double GetPrimaryEnergy() const { return fPrimaryEnergy; }
    G4double GetTheta() const { return fTheta; }
    G4double GetPhi()   const { return fPhi; }

private:
    G4int    fEventID;
    G4double fPrimaryEnergy;
    G4double fTheta;
    G4double fPhi;

    const PMPrimaryGenerator* fPrimaryGenerator;
};
#endif // PMEVENTACTION_HH

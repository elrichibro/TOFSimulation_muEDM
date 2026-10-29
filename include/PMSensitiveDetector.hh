#ifndef PMSENSITIVEDETECTOR_HH
#define PMSENSITIVEDETECTOR_HH

#include "G4VSensitiveDetector.hh"

#include "G4RunManager.hh"
#include "G4AnalysisManager.hh"
#include "G4SystemOfUnits.hh"
#include "G4UnitsTable.hh"
#include "PMPrimaryGenerator.hh"

class PMSensitiveDetector : public G4VSensitiveDetector {
    public:
        // Constructor
        PMSensitiveDetector(G4String);
        // Destructor
        ~PMSensitiveDetector();

    private:
        virtual G4bool ProcessHits(G4Step *, G4TouchableHistory *);

        virtual void Initialize(G4HCofThisEvent*) override;
        virtual void EndOfEvent(G4HCofThisEvent *) override;

        G4double fTotalEnergyDeposited;

        G4bool hitPMT7;
        G4bool hitPMT4;
        G4bool hitPMT2;
        G4bool hitPMT1;
        G4bool hitDECAY;

        G4int eventID;
        G4int Decay_event;

        G4double decayTime;


};

#endif

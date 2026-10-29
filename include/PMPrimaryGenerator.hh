#ifndef PMPRIMARYGENERATOR_HH
#define PMPRIMARYGENERATOR_HH

// Mother class G4VUserPrimaryGeneratorAction for the our custom class: PMPrimaryGenerator  
#include "G4VUserPrimaryGeneratorAction.hh"

#include "G4ParticleDefinition.hh"
#include "G4ParticleGun.hh"

// Take particles from this
#include "G4ParticleTable.hh"

// Usefull for units
#include "G4SystemOfUnits.hh"

class PMPrimaryGenerator : public G4VUserPrimaryGeneratorAction {
    public:
        // Construcor
        PMPrimaryGenerator();
        // Destructor
        ~PMPrimaryGenerator();

        // Main method of the class
        virtual void GeneratePrimaries(G4Event *);

        // Use "const" when you want read-only methods -> they are called GETTERS
        G4double GetPrimaryEnergy() const { return fPrimaryEnergy; }
        G4double GetTheta() const { return fTheta; }
        G4double GetPhi() const { return fPhi; }

        // Setters -> used to set the wanted value
        void SetPrimaryEnergy(G4double value) { fPrimaryEnergy = value; }
        void SetTheta(G4double value) {fTheta = value; }
        void SetPhi(G4double value) { fPhi = value; }

    private:
        G4ParticleGun *fParticleGun;

        // Quantities at GENERATOR LEVEL -> by us
        // Energy of the generated particle
        G4double fPrimaryEnergy;
        // Theta of the generated particle
        G4double fTheta;
        // Phi of the generated particle
        G4double fPhi;
};

#endif

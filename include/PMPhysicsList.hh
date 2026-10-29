#ifndef PMPHYSICSLISTS_HH
#define PMPHYSICSLISTS_HH

// Mother class G4VModularPhysicsList of out custom class: PMPhysicsList 
#include "G4VModularPhysicsList.hh"

// Additional physics packets
#include "G4EmStandardPhysics.hh"
#include "G4DecayPhysics.hh"

class PMPhysicsList : public G4VModularPhysicsList {
    public:
        // Constructor
        PMPhysicsList();
        // Destructor
        ~PMPhysicsList();
};

#endif

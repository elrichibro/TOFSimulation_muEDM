#ifndef PMDETECTORCONSTRUCTION_HH
#define PMDETECTORCONSTRUCTION_HH

// Mother class of PMDetectorConstruction
#include "G4VUserDetectorConstruction.hh"

#include "G4Box.hh"

#include "G4LogicalVolume.hh"
#include "G4VPhysicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4Material.hh"

#include "G4NistManager.hh"
#include "G4SystemOfUnits.hh"
#include "G4UnitsTable.hh"

#include "G4VisAttributes.hh"
#include "G4Color.hh"
#include "G4SDManager.hh"

// Program class
#include "PMSensitiveDetector.hh"

// Definition and Inheritance from G4VUserDetectorConstruction
class PMDetectorConstruction : public G4VUserDetectorConstruction {
    public:
        // Constructor
        PMDetectorConstruction();
        // Destructor
        virtual ~PMDetectorConstruction();

        // Method -> returns a pointer of type G4VPhysicalVolume 
        virtual G4VPhysicalVolume* Construct();
    
    private:
        // Logic volume of the SiPM
        G4LogicalVolume* logicSiPM;
        // Logic volume of the TOF scintillator
        G4LogicalVolume* logicScintillator;

        // Fundamental method
        virtual void ConstructSDandField();
};

#endif
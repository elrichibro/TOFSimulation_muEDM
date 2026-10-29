#include "PMDetectorConstruction.hh"

// Constructor
PMDetectorConstruction::PMDetectorConstruction() {}

// Destructor
PMDetectorConstruction::~PMDetectorConstruction() {}

// Defining Construct
G4VPhysicalVolume* PMDetectorConstruction::Construct() {
    G4bool checkOverlaps = true;

    // For material construction 
    G4NistManager* nist  = G4NistManager::Instance();
    G4Material* worldMat = nist->FindOrBuildMaterial("G4_AIR");
    G4Material* Polistirene = nist->FindOrBuildMaterial("G4_POLYSTYRENE");

    // Definition of the world dimensions
    G4double xWorld = 5 * cm;
    G4double yWorld = 5 * cm;
    G4double zWorld = 5 * cm;

    // Definition of the World -> SOLID -> LOGICAL -> PHYSICAL
    G4Box* solidWorld = new G4Box("solidWorld", xWorld, yWorld, zWorld);
    G4LogicalVolume* logicWorld = new G4LogicalVolume(solidWorld, worldMat, "logicalWorld");
    G4VPhysicalVolume* physWorld = new G4PVPlacement(0, G4ThreeVector(0., 0., 0.), logicWorld, "physWorld", 0, false, 0, checkOverlaps);

    // Scintillator dimensions
    G4double Scintillator_xSize = 10.0 * mm;
    G4double Scintillator_ySize = 10.0 * mm;
    G4double Scintillator_zSize = 25.0 * um;

    // SiPM dimensions
    G4double SiPM_xSize = 0.65 * mm;
    G4double SiPM_ySize = 0.65 * mm;
    G4double SiPM_zSize = 25.0 * um;

    G4Box* solidScintillator = new G4Box("solidScintillator", Scintillator_xSize, Scintillator_ySize, Scintillator_zSize);
    logicScintillator = new G4LogicalVolume(solidScintillator, Polistirene, "logicScintillator");
    G4VPhysicalVolume* physScintillator = new G4PVPlacement(0, G4ThreeVector(0., 0., 0.), logicScintillator, "physScintillator", logicWorld, false, 1, true);

    G4Box* solidSiPM = new G4Box("solidSiPM", SiPM_xSize, SiPM_ySize, SiPM_zSize);
    logicSiPM = new G4LogicalVolume(solidSiPM, Polistirene, "logicSiPM");
    G4VPhysicalVolume* physSiPM = new G4PVPlacement(0, G4ThreeVector(6.0*mm, 6.0*mm, 50.0*um), logicSiPM, "physSiPM", logicWorld, false, 2, true);

    // Returns the pointer to the Physical world object
    return physWorld;
}

void PMDetectorConstruction::ConstructSDandField() {

    PMSensitiveDetector *sensDet = new PMSensitiveDetector("SensitveDetector");
    
    logicScintillator->SetSensitiveDetector(sensDet);
    logicSiPM->SetSensitiveDetector(sensDet);

    G4SDManager::GetSDMpointer()->AddNewDetector(sensDet);
}
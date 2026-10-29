// Header file for the class PMPrimaryGenerator 
#include "PMPrimaryGenerator.hh"

// Geant4 Class
#include "G4PhysicalConstants.hh"

#include "Randomize.hh"
#include <ctime>
#include <random>

PMPrimaryGenerator::PMPrimaryGenerator() {
    fParticleGun = new G4ParticleGun(1);
}

PMPrimaryGenerator::~PMPrimaryGenerator() {
    delete fParticleGun;
}

void generateCosmicRay(G4double &x0, G4double &y0, G4double &phi, G4double &theta) {
    x0 = -0.25*m + G4UniformRand() * (0.5*m);
    y0 = -0.15*m + G4UniformRand() * (0.3*m);

    phi = G4UniformRand() * 2 * CLHEP::pi;
    G4double u = G4UniformRand();
    theta = acos(pow(1 - u, 1.0 / 3.0));
}

void PMPrimaryGenerator::GeneratePrimaries(G4Event * anEvent) {
    G4ParticleTable *particleTable = G4ParticleTable::GetParticleTable();
    G4ParticleDefinition *particle = nullptr;

    G4double randomVal = G4UniformRand();
    if(randomVal < 0.5) {
        particle = particleTable->FindParticle("mu+");
    } else {
        particle = particleTable->FindParticle("mu-");
    }
    /**/

    //particle = particleTable->FindParticle("mu-");
    //particle = particleTable->FindParticle("mu+");


    // Imposta la geometria dell'evento
    G4double x0, y0, phi, theta;
    generateCosmicRay(x0, y0, phi, theta);

    G4double E_rand = G4UniformRand() * (1000.*MeV - 1.*MeV) + 1.*MeV;
    G4double muon_mass = particle->GetPDGMass();
    G4double momentum = sqrt((E_rand * E_rand) - (muon_mass * muon_mass));

    G4double mom_x = sin(theta) * cos(phi);
    G4double mom_y = sin(theta) * sin(phi);
    G4double mom_z = -cos(theta);

    G4ThreeVector pos(x0, y0, 1.0*m);
    G4ThreeVector mom(mom_x, mom_y, mom_z);

    fPrimaryEnergy = E_rand;
    fTheta = theta;
    fPhi = phi;

    //G4cout << "Energia iniziale: " << fPrimaryEnergy << " ,Theta: " << fTheta << " ,Phi: " << fPhi << G4endl;

    fParticleGun->SetParticlePosition(pos);
    fParticleGun->SetParticleMomentumDirection(mom);
    fParticleGun->SetParticleMomentum(momentum);
    fParticleGun->SetParticleDefinition(particle);
    fParticleGun->GeneratePrimaryVertex(anEvent);
}



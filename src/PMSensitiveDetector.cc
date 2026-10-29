#include "PMSensitiveDetector.hh"
#include "G4Track.hh"
#include "G4ParticleDefinition.hh"

PMSensitiveDetector::PMSensitiveDetector(G4String name) : G4VSensitiveDetector(name)
{
    fTotalEnergyDeposited = 0.;

    hitDECAY = false;
    hitPMT7 = false;
    hitPMT4 = false;
    hitPMT2 = false;
    hitPMT1 = false;
    Decay_event = 0;

    decayTime = 0;
}

PMSensitiveDetector::~PMSensitiveDetector()
{
}

void PMSensitiveDetector::Initialize(G4HCofThisEvent *)
{
    fTotalEnergyDeposited = 0.;

    Decay_event = 0;

    hitDECAY = false;
    hitPMT7 = false;
    hitPMT4 = false;
    hitPMT2 = false;
    hitPMT1 = false;

    decayTime = -1;
}

G4bool PMSensitiveDetector::ProcessHits(G4Step *aStep, G4TouchableHistory *)
{

    const G4Track* track = aStep->GetTrack();
    G4int particlePDG = track->GetDefinition()->GetPDGEncoding();

    G4AnalysisManager *analysisManager = G4AnalysisManager::Instance();

    G4int eventID = G4RunManager::GetRunManager()->GetCurrentEvent()->GetEventID();

    G4StepPoint *preStepPoint = aStep->GetPreStepPoint();
    G4StepPoint *postStepPoint = aStep->GetPostStepPoint();

    G4double energyDeposited = aStep->GetTotalEnergyDeposit();
    G4int stepNumber = aStep->GetTrack()->GetCurrentStepNumber();

    G4TouchableHandle touchable = preStepPoint->GetTouchableHandle();
    G4String physVolName = touchable->GetVolume()->GetName();
    G4int copyNumber = touchable->GetCopyNumber();

    G4double fPreTime = preStepPoint->GetGlobalTime();
    G4double fPostTime = postStepPoint->GetGlobalTime();


    G4ThreeVector posMuon = preStepPoint->GetPosition();
    G4int trackID = aStep->GetTrack()->GetTrackID();

    G4double V_soglia = 0.001 *MeV;
    G4double T_soglia = 5.0 *ns;

    const G4VProcess* proc = postStepPoint->GetProcessDefinedStep();
    G4String process = proc->GetProcessName();

    if(track->GetParentID() == 0){
    //if(hitDECAY == false){
        if(copyNumber == 7 && energyDeposited > V_soglia){
            hitPMT7 = true;
        }
        if(copyNumber == 4 && energyDeposited > V_soglia){
            hitPMT4 = true;
        }
        if(copyNumber == 2 && energyDeposited > V_soglia){
            hitPMT2 = true;
        }
        if(copyNumber == 1 && energyDeposited > V_soglia){
            hitPMT1 = true;
        }
        if(copyNumber == 8){
            fTotalEnergyDeposited += energyDeposited;
        }
        if(copyNumber == 9){
            fTotalEnergyDeposited += energyDeposited;
        }
        if(copyNumber == 10){
            fTotalEnergyDeposited += energyDeposited;
        }
        if(copyNumber == 11){
            fTotalEnergyDeposited += energyDeposited;
        }

        //if(decayTime < 0 && (copyNumber == 8 || copyNumber == 9 || copyNumber == 10 || copyNumber == 11)){fTotalEnergyDeposited += energyDeposited;}
        //G4cout<< "energia PRE DECAY PMT: " << energyDeposited << "MeV" << G4endl;

/*

        }
    else{
        if(fPreTime < decayTime){fTotalEnergyDeposited += energyDeposited;}
        }
    //}
        if(track->GetParentID() == 0 && proc && process == "Decay" && (copyNumber == 8 || copyNumber == 9 || copyNumber == 10 || copyNumber == 11)){
            decayTime = fPostTime;
            hitDECAY = true;
            Decay_event = 1;
            G4cout << "|---------------------------------------------------------------------------------------------------|"<< G4endl;
            G4cout << "| Decadimento del primary (TrackID=1) rilevato nel PMT: "<< copyNumber << " e al tempo: " <<
            G4BestUnit(postStepPoint->GetGlobalTime(), "Time") << G4endl;
            G4cout << "|---------------------------------------------------------------------------------------------------|"<< G4endl;
            }

        //if(decayTime > 0 && fPreTime > decayTime && (copyNumber == 8 || copyNumber == 9 || copyNumber == 10 || copyNumber == 11)){
            //fTotalEnergyDeposited += energyDeposited;
            //G4cout<< "energia POST_DECAY PMT: " << energyDeposited << "MeV" << G4endl;
        //}
*/
}
    return true;
}

void PMSensitiveDetector::EndOfEvent(G4HCofThisEvent *)
{
    G4AnalysisManager *analysisManager = G4AnalysisManager::Instance();

    //G4cout<< "energia PMT: " << fTotalEnergyDeposited << "MeV" <<G4endl;

    if(hitPMT7 && hitPMT4 && hitPMT2 && hitPMT1){
        analysisManager->FillNtupleDColumn(0, 0, fTotalEnergyDeposited);
        analysisManager->FillNtupleIColumn(0, 1, Decay_event);
        analysisManager->AddNtupleRow(0);
    }
    //G4cout << "Deposited energy: " << fTotalEnergyDeposited << " MeV" << G4endl;

}

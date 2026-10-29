#ifndef PMTRACKINGACTION_HH
#define PMTRACKINGACTION_HH

#include "G4UserTrackingAction.hh"

class PMTrackingAction : public G4UserTrackingAction {
    public:
        // Constructor
        PMTrackingAction();
        // Destructor
        virtual ~PMTrackingAction();

        virtual void PreUserTrackingAction(const G4Track*);
        virtual void PostUserTrackingAction(const G4Track*);
};

#endif

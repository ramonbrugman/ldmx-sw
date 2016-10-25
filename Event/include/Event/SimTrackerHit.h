/**
 *
 * @file SimTrackerHit.h
 * @brief Class used to encapsulate information from a hit in a
 *        simulated tracking detector.
 * @author Omar Moreno, SLAC National Accelerator Laboratory
 * @author Jeremy McCormick, SLAC National Accelerator Laboratory
 */

#ifndef Event_SimTrackerHit_h
#define Event_SimTrackerHit_h

// C++ StdLib
#include <iostream>
#include <bitset>

// ROOT
#include "TObject.h"
#include "TRef.h"

// LDMX
#include "Event/SimParticle.h"

namespace event {

class SimTrackerHit: public TObject {

    public:

        /** Constructor */
        SimTrackerHit();

        /** Destructor */
        virtual ~SimTrackerHit();

        /** Print a description of this object. */
        void Print(Option_t *option = "") const;

        /** Reset the SimTrackerHit object. */
        void Clear(Option_t *option = "");

        /** Return the ID of the hit. */
        int getID() const { return id; };

        /**
         * Get the geometric layer ID of the hit.
         */
        int getLayerID() const { return layer_id; };

        /** Return the position of the hit in mm. */
        std::vector<float> getPosition() const { return {x, y, z}; };

        /** Return the energy deposited on the hit in GeV. */
        float getEdep() const { return edep; };

        /** Return the time of the hit in ns. */
        float getTime() const { return time; };

        /**
         * Return the path length between the start and end points of the
         * hit in mm.
         */
        float getPathLength() const { return path_length; };

        /**
         * Return the momentum in GeV of the particle at the position at which
         * the hit took place.
         */
        std::vector<double> getMomentum() const { return {px, py, pz}; };

        /** Return the Monte Carlo particle that created the hit. */
        SimParticle* getSimParticle() const;

        /** Set the ID of the hit. */
        void setID(const long id) { this->id = id; };

        /** Set the position of the hit in mm. */
        void setPosition(const float x, const float y, const float z);

        /** Set the energy deposited on the hit in GeV. */
        void setEdep(const float edep) { this->edep = edep; };

        /** Set the time of the hit in ns. */
        void setTime(const float time) { this->time = time; };

        /**
         * Set the path length of the hit in mm.
         */
        void setPathLength(const float path_length) { this->path_length = path_length; };

        /**
         * Set the momentum in GeV of the particle at the position at which
         * the hit took place.
         */
        void setMomentum(const float px, const float py, const float pz);

        /**
         * Set the geometric layer ID of the hit.
         */
        void setLayerID(const int layer_id) { this->layer_id = layer_id; };

        /** Set the Monte Carlo particle that created the hit. */
        void setSimParticle(SimParticle* simParticle) { this->simParticle.SetObject(simParticle); };

    private:

        /** */
        TRef simParticle{nullptr};

        /** */
        int id{0};

        /** */
        int layer_id{0};

        /** */
        float edep{0};

        /** */
        float time{0};

        /** */
        float px{0};

        /** */
        float py{0};

        /** */
        float pz{0};

        /** */
        float x{0};

        /** */
        float y{0};

        /** */
        float z{0};

        /** */
        float path_length{0};

        ClassDef(SimTrackerHit, 1);

}; // SimTrackerHit
}

#endif // Event_SimTrackerHit_h

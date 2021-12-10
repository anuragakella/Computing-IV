#ifndef UNIVERSE_H
#define UNIVERSE_H

#include "CelestialBody.h"

class Universe {
    public:

        int numberOfPlanets;
        void setRadius(float radius);
        void setNumPlanets(int n);
        float getRadius();
        int getNumPlanets();

        void step(double);

        std::vector<CelestialBody> getBodies();
        void addBody(CelestialBody* body);
        Universe(int, float);
        std::vector<CelestialBody> bodies;

    private:
        float radius;
};

#endif
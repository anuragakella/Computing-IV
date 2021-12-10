#include "Universe.h"

float Universe::getRadius() {
    return radius;
}

std::vector<CelestialBody> Universe::getBodies() {
    return bodies;
}

void Universe::setRadius(float radius) {
    Universe::radius = radius;
} 

void Universe::addBody(CelestialBody *body) {
    bodies.push_back(*body);
}

Universe::Universe(int n, float r){
    numberOfPlanets = n;
    radius = r;
}


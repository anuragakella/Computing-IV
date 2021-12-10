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

void Universe::step(double seconds) {
    std::vector<CelestialBody>::iterator it;
    for(it = bodies.begin(); it != bodies.end(); it++){

        double acx = it -> xforce / it -> getMass();
        double acy = it -> yforce / it -> getMass();

        it -> setVelX(it -> getVelX() + (acx * seconds));
        it -> setVelY(it -> getVelY() + (acy * seconds));

        it -> setX(it -> getX() + (it -> getVelX() * seconds));
        it -> setY(it -> getY() + (it -> getVelY() * seconds));
    }
}

void Universe::addBody(CelestialBody *body) {
    bodies.push_back(*body);
}

Universe::Universe(int n, float r){
    numberOfPlanets = n;
    radius = r;
}


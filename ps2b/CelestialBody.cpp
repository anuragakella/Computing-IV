#include "CelestialBody.h"
#include <iostream>
#include <math.h>

CelestialBody::CelestialBody(double x, double y, double vx, double vy,
       double mass, double r, std::string filename) {
    CelestialBody::x = x;
    CelestialBody::y = y;
    CelestialBody::vx = vx;
    CelestialBody::vy = vy;
    CelestialBody::mass = mass;
    CelestialBody::radius = r;
    CelestialBody::filename = filename;
}

CelestialBody::CelestialBody() {
    return;
}

double CelestialBody::getX() {
    return x;
}

double CelestialBody::getY() {
    return y;
}

void CelestialBody::setX(double x) {
    CelestialBody::x = x;
}

void CelestialBody::setY(double y) {
    CelestialBody::y = y;
}

double CelestialBody::getMass() {
    return mass;
}

std::string CelestialBody::getFilename() {
    return filename;
}

double CelestialBody::getVelX() {
    return vx;
}

double CelestialBody::getVelY() {
    return vy;
}

void CelestialBody::setVelX(double vx) {
    CelestialBody::vx = vx;
}

void CelestialBody::setVelY(double vy) {
    CelestialBody::vy = vy;
}

void CelestialBody::resetForce() {
    xforce = 0.0;
    yforce = 0.0;
}

void CelestialBody::force(CelestialBody &body) {
    
// removing verbose calculations to increase fps
//    std::cout << "--" << std::endl;
//    std::cout << "Gravity for: " << filename << ", " << body.getFilename() << std::endl;
//    std::cout << "Masses: " << mass << ", " << body.getMass() << std::endl;

   double delx = body.getX() - x;
   double dely = body.getY() - y;
   double rsq = delx * delx + dely * dely; 

   double v2force = (G * mass * body.getMass()) / rsq; 

   xforce += v2force * (delx / sqrt(rsq));
   yforce += v2force * (dely / sqrt(rsq));

//    std::cout << "Force, X Component: " << xforce << std::endl;
//    std::cout << "Force, Y Component: " << yforce << std::endl;
   
}


std::istream& operator>> (std::istream &data, CelestialBody &body) {

    data >> body.x >> body.y >> body.vx >> body.vy >> body.mass >> body.filename;

    if (!body.image.loadFromFile(body.filename))
        return data;

    body.calculatePosition();

    body.texture.loadFromImage(body.image);
    body.sprite.setTexture(body.texture);

    body.sprite.setPosition(body.ry, body.rx);

    return data;

}

void CelestialBody::setSpritePos() {
    calculatePosition();
    sprite.setPosition(ry, rx);
}


void CelestialBody::draw (sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(sprite);

}

void CelestialBody::setUniverseRadius(float urad) {
    univRadius = urad;
}

std::ostream& operator<< (std::ostream &outstream, CelestialBody &body){

  outstream << "CelestialBody : [x:" << body.x << " y:";
  outstream << body.y << " velx:" << body.vx << " vely:";
  outstream << body.vy << " mass:" << body.mass << "]";
  outstream << " {x:" << body.rx << " " << body.ry << "}" << " " << body.filename << std::endl;

  return outstream;
}

void CelestialBody::prettyPrint() {
    std::cout << x << " " << y << " " << vx << " " << vy << " " << mass << " " << filename << std::endl;
}

void CelestialBody::calculatePosition() {
    rx = ((x/univRadius) * (screenw / 2)) + (screenw/2);
    ry = ((y/univRadius) * (screenh / 2)) + (screenh/2);

}
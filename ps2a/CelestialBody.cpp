#include "CelestialBody.h"
#include <iostream>

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

std::istream& operator>> (std::istream &data, CelestialBody &body) {

    data >> body.x >> body.y >> body.vx >> body.vy >> body.mass >> body.filename;

    if (!body.image.loadFromFile(body.filename))
        return data;

    body.calculatePosition();

    body.texture.loadFromImage(body.image);
    body.sprite.setTexture(body.texture);

    body.sprite.setPosition(body.rx, body.ry);

    return data;

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

void CelestialBody::calculatePosition() {
    rx = ((x/univRadius) * (screenw / 2)) + (screenw/2);
    ry = ((y/univRadius) * (screenh / 2)) + (screenh/2);

}
#ifndef CELESTIALBODY_H
#define CELESTIALBODY_H

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class CelestialBody: public sf::Drawable {

    public:
        CelestialBody();
        CelestialBody(double x, double y, double vx, double vy,
        double mass, double r, std::string filename);

        int screenw, screenh;

        float univRadius;
        void setRadius(double new_rad);

        void setUniverseRadius(float);

        friend std::istream& operator>> (std::istream &input, CelestialBody &cBody);

        friend std::ostream& operator<< (std::ostream &output, CelestialBody &cBody);

    private:
        
        void draw (sf::RenderTarget &target, sf::RenderStates states) const;
        void calculatePosition(void);

        double x, y, rx, ry, vx, vy, mass, radius;
        std::string filename;

        sf::Image image;
        sf::Sprite sprite;
        sf::Texture texture;

};

#endif
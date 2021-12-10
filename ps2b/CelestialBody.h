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

        const double G = 6.674e-11;

        int screenw, screenh;

        float univRadius;
        void setRadius(double new_rad);

        void force(CelestialBody &body);

        void setSpritePos();

        void setUniverseRadius(float);

        std::string getFilename();

        double getMass();

        double getX();
        double getY();

        void resetForce();

        void setX(double);
        void setY(double);

        double getVelX();
        double getVelY();

        void setVelX(double);
        void setVelY(double);

        double xforce, yforce;

        void prettyPrint();
        
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
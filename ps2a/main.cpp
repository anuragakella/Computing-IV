#include <iostream>
#include "CelestialBody.h"
#include "Universe.h"

int max_height = 768, max_width = 1366;

int main() {

    sf::RenderWindow window(sf::VideoMode(max_width, max_height), "Computing IV: PS2a");
    window.setFramerateLimit(60);

    sf::RectangleShape rect(sf::Vector2f(20, 20));
    rect.setPosition(100, 100);
    
    std::string num, rad;

    std::cin >> num;
    std::cin >> rad;

    Universe universe(atoi(num.c_str()), atof(rad.c_str()));

    sf::Image bcgimg;
    if(!(bcgimg.loadFromFile("bcg.png")))
        std::cout << "couldn't load bg image" << std::endl;
    
    sf::Texture bcgtexture;
    bcgtexture.loadFromImage(bcgimg);
    sf::Sprite bcgSprite;
    bcgSprite.setTexture(bcgtexture);

    bcgSprite.setScale(
    max_width / bcgSprite.getLocalBounds().width, 
    max_height / bcgSprite.getLocalBounds().height);

    bcgSprite.setPosition(0, 0);

    std::cout << "Trying to render " << num << " planets..." << std::endl;

    for(int i = 0; i < universe.numberOfPlanets; i++) {
        CelestialBody* body = new CelestialBody();
        
        body -> screenh = max_height;
        body -> screenw = max_width;
        body -> setUniverseRadius(universe.getRadius());
        
        std::cin >> *body;

        universe.addBody(body);

        std::cout << *body;
    }

    while (window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.draw(bcgSprite);

        std::vector<CelestialBody>::iterator it;

        for(it = universe.bodies.begin(); it != universe.bodies.end(); it++)
            window.draw(*it);
    

        window.display();
    }
    return 0;
}
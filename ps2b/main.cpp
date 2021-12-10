#include <iostream>
#include "CelestialBody.h"
#include "Universe.h"
#include <SFML/Audio.hpp>

int max_height = 1000, max_width = 1000;

int main(int argc, char** argv) {

    // ./NBody 157788000.0 25000.0 < planets.txt
    if(argc != 3) {
        std::cout << "Bad arguments, terminating." << std::endl;
        return 1;
    }

    float delta = atof(argv[2]);
    float simtime = atof(argv[1]);
    float time = 0;

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

    sf::Font font;
    font.loadFromFile("arial.ttf");

    sf::Text elapsedText;
    elapsedText.setFont(font);

    elapsedText.setCharacterSize(20);
    elapsedText.setFillColor(sf::Color::White);
    elapsedText.setPosition(10, 10);

    elapsedText.setString("Elapsed Time: " + std::to_string(time));

    sf::Music music;
    if (!music.openFromFile("bgm.wav"))
        return -1; // error
    music.play();

    std::cout << "Trying to render " << num << " planets..." << std::endl;

    std::vector<CelestialBody>::iterator planetx, planety;

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
        window.draw(elapsedText);

        planetx = universe.bodies.begin();

        for(int i = 0; i < universe.numberOfPlanets; i++){

            planety = universe.bodies.begin();
            planetx -> resetForce();
            
            for(int j = 0; j < universe.numberOfPlanets; j++) {
                if(planetx != planety)
                    planetx -> force(*planety);
                planety++;
            }
            planetx++;
        }

        universe.step(delta);

        std::vector<CelestialBody>::iterator it;

        for(it = universe.bodies.begin(); it != universe.bodies.end(); it++){
            window.draw(*it);
            it -> setSpritePos();
        }

        elapsedText.setString("Elapsed Time: " + std::to_string(time));

        if(time < simtime)
            time += delta;
        else 
            break;

        window.display();
    }

    std::cout << "Final values:" << std::endl;

    std::vector<CelestialBody>::iterator it;

        for(it = universe.bodies.begin(); it != universe.bodies.end(); it++){
            it -> prettyPrint();
        }

    return 0;
}
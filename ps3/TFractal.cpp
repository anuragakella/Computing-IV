#include "Triangle.h"
#include <vector>
#include <iostream>

#include <random>

#define WIN_H 1000
#define WIN_W 1000

#define PYT 0.867

void fTree(Triangle trg, int depth, int len, sf::RenderWindow *window) {
    if(depth <= 0)
        return;
    
    std::cout << "calculating triangles for - depth: " << depth << std::endl;

    trg.bottom = new Triangle(sf::Vector2f(trg.a3.x - len, trg.a3.y), trg.a3, sf::Vector2f(trg.a3.x - len/2, trg.a3.y + (len * PYT)));
    trg.left = new Triangle(sf::Vector2f(trg.a1.x - len/2, trg.a1.y - len), sf::Vector2f(trg.a1.x + len/2, trg.a1.y - len), trg.a1);
    trg.right = new Triangle(trg.a2, sf::Vector2f(trg.a2.x + len, trg.a2.y), sf::Vector2f(trg.a2.x + len/2, trg.a2.y + len));

    window -> draw(*trg.bottom);
    window -> draw(*trg.left);
    window -> draw(*trg.right);

    depth--;

    fTree(*trg.left, depth, len/2, window);
    fTree(*trg.right, depth, len/2, window);
    fTree(*trg.bottom, depth, len/2, window);
}

int main(int argc, char* argv[]) {

    if (argc!= 3) {
        std::cout << "Bad Arguments.\nUsage: ./executable [length] [depth]\n";
        return -1;
    }

    sf::RenderWindow window(sf::VideoMode(WIN_W, WIN_H), "Computing IV: PS3");
    window.setFramerateLimit(60);

    int len = atoi(argv[1]);
    int depth = atoi(argv[2]);

    float x = WIN_W/2 - len/2;
    float y = WIN_H/2 - len/2;


    Triangle initialTriangle(sf::Vector2f(x, y), sf::Vector2f(x + len, y), sf::Vector2f(x + len/2, y + (len * PYT)));

    window.draw(initialTriangle);
    fTree(initialTriangle, depth, len/2, &window);

    std::cout << "Done rendering." << std::endl;

    sf::Vector2u windowSize = window.getSize();
    sf::Texture texture;
    texture.create(windowSize.x, windowSize.y);
    texture.update(window);
    sf::Image capture = texture.copyToImage();

    sf::Texture fraxture;
    fraxture.loadFromImage(capture);
    sf::Sprite fracrite;
    fracrite.setTexture(fraxture);

    int frames = 0;
    bool flip = false;
    
    while (window.isOpen()){

        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        
        frames++;

        if (frames % 50 == 0) {
            flip = !flip;
        } 
        
        // if (flip)
        //     fracrite.rotate(0.5);
        // else
        //     fracrite.rotate(-0.5);

        if (frames % 10 == 0)   
            fracrite.setColor(sf::Color(rand() % 255, rand() % 255, rand() % 255));

        window.draw(fracrite);

        window.display();
    }
}
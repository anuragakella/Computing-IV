#include "Triangle.h"

Triangle::Triangle(sf::Vector2f a, sf::Vector2f b, sf::Vector2f c) {
    a1 = a;
    a2 = b;
    a3 = c;

    bottom = NULL;
    left = NULL;
    right = NULL;
}

void Triangle::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    sf::Vertex line[] = {
        sf::Vertex(a1),
        sf::Vertex(a2)
    };
    
    target.draw(line, 2, sf::Lines);

    line[0] = sf::Vertex(a2);
    line[1] = sf::Vertex(a3);
    target.draw(line, 2, sf::Lines);

    line[0] = sf::Vertex(a1);
    line[1] = sf::Vertex(a3);
    target.draw(line, 2, sf::Lines);
}
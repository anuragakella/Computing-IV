#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Triangle: public sf::Drawable {
    public:
    Triangle(sf::Vector2f, sf::Vector2f, sf::Vector2f);
    sf::Vector2f a1, a2, a3;
    Triangle *left, *right, *bottom;
    int len;
    
    private:
    void draw (sf::RenderTarget &target, sf::RenderStates states) const;
};
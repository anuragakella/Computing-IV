/*
*  Computing IV - Assignment - PS0
*  Instructor: Prof. Yelena Rykalova
*  
*  Due Date: 13th September 2021
*
*  Author: Anurag Akella (ID 01990503)
*
*  Description: This program uses basic SFML concepts to draw a sprite on screen, from an image (png) file. 
*               It also listens for arrow key strokes to move the sprite on screen.
*               Additional Feature: 1. the sprite shoots a straight projectile in the last moved direction when the spacebar key is pressed.
                2. Disco Mode: the background cycles through multiple colors when the 'D' key is pressed. to disable this mode, the user can press 'F' on the 
                keyboard.
*/

#include <SFML/Graphics.hpp>

// bullet class, handles movement logic for the projectile
class Bullet {
    private:
    float x, y, velocity; 
    int direction, screen_width, screen_height;
    public:
    float getPosX();
    float getPosY();
    void setPosX(float);
    void setPosY(float);
    void setDirection(int);
    void update();
    bool inFrame();
    Bullet(float, float, int, int, int);
};

// constructor
Bullet::Bullet(float x, float y, int direction, int screen_width, int screen_height) {
    Bullet::velocity = 10.f;
    Bullet::x = x;
    Bullet::y = y;
    Bullet::direction = direction;
    Bullet::screen_width = screen_width;
    Bullet::screen_height = screen_height;
}

// update function, updates velocity based on direction
void Bullet::update(){
    switch(direction) {
        case 0: y += velocity; break; 
        case 2: y -= velocity; break; 
        case 1: x += velocity; break; 
        case 3: x -= velocity; break; 
    }
}

// checks if the bullet is in frame
bool Bullet::inFrame(){
    if (x <=0 || x >= screen_width) {
        return false;
    }
    if (y <= 0 || y >= screen_height){
        return false;
    }
    return true;
}

// sets direction of the bullet
void Bullet::setDirection(int d){
    Bullet::direction = d;
}

// setters and getters
// gets live X posiion
float Bullet::getPosX(){
    return Bullet::x;
}

// gets live Y position
float Bullet::getPosY(){
    return Bullet::y;
}

// set X position
void Bullet::setPosX(float x){
    Bullet::x = x;
}

// set Y position
void Bullet::setPosY(float y){
    Bullet::y = y;
}

int main(){
    // max screen height
    int max_height = 768, max_width = 1024;
    int direction = 0;
    int i = 0, j = 0, k = 0;
    bool discoMode = false;

    // create a window
    sf::RenderWindow window(sf::VideoMode(max_width, max_height), "Computing IV: PS0");
    window.setFramerateLimit(60);
    
    // create a texture
    sf::Texture texture;
    if (!texture.loadFromFile("sprite.png"))
        return EXIT_FAILURE;

    // create a sprite from the texture
    sf::Sprite sprite(texture);
    sprite.setPosition(100.f, 100.f);

    // one instance of the bullet class - used for the whole app - instead of despawning, change position when needed
    sf::RectangleShape bcg(sf::Vector2f(max_width, max_height));
    bcg.setPosition(0, 0);

    sf::RectangleShape bulletRect(sf::Vector2f(20, 20));
    bulletRect.setPosition(-100, -100);
    Bullet bullet(-100.f, -100.f, 1, max_width, max_height);

    // main game loop
    while (window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // update bullet x,y only if its in frame
        if (bullet.inFrame()){
            bulletRect.setPosition(bullet.getPosX(), bullet.getPosY()); 
            bullet.update();
        } else {
            bulletRect.setPosition(-100, -100);
        }
        
        // listen for keystrokes
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
            direction = 3;
            if(!(sprite.getPosition().x <= 0))
            sprite.move(sf::Vector2f(-10.f, 0.f));
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
            direction = 1;
            if(!(sprite.getPosition().x >= (max_width-sprite.getGlobalBounds().width)))
            sprite.move(sf::Vector2f(10.f, 0.f));
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
            direction = 2;
            if(!(sprite.getPosition().y <= 0))
            sprite.move(sf::Vector2f(0.f, -10.f));
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
            direction = 0;
            if(!(sprite.getPosition().y >= (max_height-sprite.getGlobalBounds().height)))
            sprite.move(sf::Vector2f(0.f, 10.f));
        }

        // launch a bullet if space is pressed
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
            if (!bullet.inFrame()){
                bullet.setDirection(direction);
                bullet.setPosX(sprite.getPosition().x + 50);
                bullet.setPosY(sprite.getPosition().y + 50);
                bulletRect.setPosition(bullet.getPosX(), bullet.getPosY());  
            }        
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            discoMode = true;
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
            discoMode = false;

        // draw everything
        window.clear();
        if (discoMode) {
            if (i > 254) i = 0;
            if (j > 254) j = 0;
            if (k > 254) j = 0;
            bcg.setFillColor(sf::Color(i, j, k));
            i += 10;
            j++;
            k += 30;
            window.draw(bcg);
        }
        window.draw(bulletRect);
        window.draw(sprite);
        window.display();
    }
    return 0;
}

#ifndef HEADER_CAT
#define HEADER_CAT
#include <SFML/Graphics.hpp>
#include "Settings.h"
class Cat{
    private:
        sf::Texture texture;
        float velocityY;

    public: 
        sf::Sprite sprite;

        Cat() {
            texture.loadFromFile("build/assets/cat.png");
            sprite.setTexture(texture);
            // Scale the sprite to match the target size
            sf::Vector2u textureSize = texture.getSize();
            float scaleX = Settings::CAT_WIDTH/ textureSize.x;
            float scaleY = Settings::CAT_HEIGHT/ textureSize.y;
            sprite.setScale(scaleX, scaleY);
            sprite.setPosition(200, Settings::WINDOW_HEIGHT / 2);
            velocityY = 0;
        }
        void update() {
            velocityY += Settings::GRAVITY;
            sprite.move(0, velocityY);
            // Prevent bird from falling off-screen
            if (sprite.getPosition().y + sprite.getGlobalBounds().height > Settings::WINDOW_HEIGHT) {
                sprite.setPosition(sprite.getPosition().x, Settings::WINDOW_HEIGHT - sprite.getGlobalBounds().height);
                velocityY = 0;
            }
        }
       void jump() {
            velocityY = Settings::JUMP_STRENGTH;
        }
};
#endif

#include <SFML/Graphics.hpp>
class Character {

    public:
        sf::Sprite sprite;
        sf::Texture texture;
        int x;
        int y;

    public:
        // Constructor
        Character(int initialX = 0, int initialY = 0) : x(initialX), y(initialY) {
            texture.loadFromFile("/home/kairat/GitHub/PixelBird/src/assets/bird.jpg");
            sprite.setTexture(texture);
        }

        // Getter for x
        int getX() const {
            return x;
        }

        // Setter for x
        void setX(int newX) {
            x = newX;
        }

        // Getter for y
        int getY() const {
            return y;
        }

        // Setter for y
        void setY(int newY) {
            y = newY;
        }
        void moveDx(int dx){
            setX(x + dx);
        }

        void moveDy(int dy){
            setY(y + dy);
        }

        const sf::Sprite & getSprite(){return sprite;}

        void jump(){
            moveDy(20);
            moveDx(10);
            sprite.setPosition(x,y);
        }
};

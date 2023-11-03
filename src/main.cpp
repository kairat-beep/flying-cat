#include <SFML/Graphics.hpp>
#include <iostream>
#include "Bird.cpp"

int main()
{
    auto window = sf::RenderWindow{ { 1920u, 1080u }, "Fly birdy fly" };
    window.setFramerateLimit(144);
    sf::Time sec = sf::seconds(1.f);
    sf::Clock clock;//start the clock
    double dt = 0;
    sf::Time start = clock.getElapsedTime();
    Character bird;
    while (window.isOpen())
    {
        sf::Time newTime = clock.getElapsedTime();
        window.clear();
        for (auto event = sf::Event{}; window.pollEvent(event);)
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }

            if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Up){
                bird.jump();
            }
        }
        window.draw(bird.getSprite());
        window.display();
    }
}

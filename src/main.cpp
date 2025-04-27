#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "Cat.cpp"
#include "Pipe.cpp"
#include "Settings.h"
#include "GravityBar.cpp"

int main() {
    srand(static_cast<unsigned>(time(0)));
    sf::RenderWindow window(sf::VideoMode(Settings::WINDOW_WIDTH, Settings::WINDOW_HEIGHT), "Flappy Cat");
    window.setFramerateLimit(60);
    sf::Clock clock;

    GravityBar gravityBar(0.1f, 2.0f);

    Cat cat;
    std::vector<Pipe> pipes;
    pipes.emplace_back(Settings::WINDOW_WIDTH);
    bool gameOver = false;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            //Too long to append. Need to create a  class for a joystick and keyboard together
            if (sf::Joystick::isConnected(0) && (sf::Joystick::getAxisPosition(0,sf::Joystick::Y)<-20 || sf::Joystick::isButtonPressed(0,3))
                || event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space)
                cat.jump();
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::R || (sf::Joystick::isConnected(0) && (sf::Joystick::isButtonPressed(0,9)))){
                pipes.clear();
                pipes.emplace_back(Settings::WINDOW_WIDTH);
                gameOver = false;
            }

            //Keep for debugging and locating buttions
            for (unsigned int i = 0; i < sf::Joystick::getButtonCount(0); ++i) {
                if (sf::Joystick::isButtonPressed(0, i)) {
                    std::cout << "Button " << i << " is pressed\n";
                }
            }
        }

        if (!gameOver) {
            cat.update();

            for (auto& pipe : pipes) {
                pipe.update();

                if (pipe.topPipe.getGlobalBounds().intersects(cat.sprite.getGlobalBounds()) ||
                    pipe.bottomPipe.getGlobalBounds().intersects(cat.sprite.getGlobalBounds())) {
                    gameOver = true;
                }
            }

            if (pipes.back().topPipe.getPosition().x < Settings::WINDOW_WIDTH - 300) {
                pipes.emplace_back(Settings::WINDOW_WIDTH);
            }
        }
        // Delta time for smoother movement
        sf::Time dt = clock.restart();
        float deltaTime = dt.asSeconds();

        sf::RectangleShape debugCatBox;
        debugCatBox.setSize(sf::Vector2f(cat.sprite.getGlobalBounds().width, cat.sprite.getGlobalBounds().height));
        debugCatBox.setPosition(cat.sprite.getPosition());
        debugCatBox.setFillColor(sf::Color(255, 0, 0, 100)); // Red transparent box
        window.draw(debugCatBox);

        window.clear(sf::Color(135, 206, 235));
        window.draw(cat.sprite);
        for (auto& pipe : pipes) {
            window.draw(pipe.topPipe);
            window.draw(pipe.bottomPipe);
        }
        gravityBar.draw(window);
        window.display();
    }
    return 0;
}


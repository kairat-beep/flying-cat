#ifndef HEADER_GRAVITY_BAR
#define HEADER_GRAVITY_BAR
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Settings.h"
class GravityBar {
public:
    sf::RectangleShape bar, slider;
    float minGravity, maxGravity;

    GravityBar(float minG, float maxG) : minGravity(minG), maxGravity(maxG) {
        bar.setSize(sf::Vector2f(200, 10));
        bar.setPosition(50, Settings::WINDOW_HEIGHT - 50);
        bar.setFillColor(sf::Color::White);

        slider.setSize(sf::Vector2f(10, 20));
        slider.setPosition(50, Settings::WINDOW_HEIGHT - 55);
        slider.setFillColor(sf::Color::Red);
    }

    void update(sf::RenderWindow &window, sf::Event event) {
        if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                float mouseX = event.mouseButton.x;
                if (mouseX >= 50 && mouseX <= 250) {
                    slider.setPosition(mouseX, slider.getPosition().y);
                    float newGravity = minGravity + ((mouseX - 50) / 200.0f) * (maxGravity - minGravity);
                    Settings::GRAVITY = newGravity;
                }
            }
        }
    }

    void draw(sf::RenderWindow &window) {
        window.draw(bar);
        window.draw(slider);
    }
};
#endif

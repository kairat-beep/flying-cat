#ifndef HEADER_PIPE
#define HEADER_PIPE

#include <SFML/Graphics.hpp>
#include "Settings.h"
class Pipe {
public:
    sf::RectangleShape topPipe, bottomPipe;

    Pipe(float x) {
        float height = rand() % (Settings::WINDOW_HEIGHT - Settings::PIPE_GAP - 100) + 50;
        
        topPipe.setSize(sf::Vector2f(Settings::PIPE_WIDTH, height));
        topPipe.setPosition(x, 0);
        topPipe.setFillColor(sf::Color::Green);

        bottomPipe.setSize(sf::Vector2f(Settings::PIPE_WIDTH, Settings::WINDOW_HEIGHT - height - Settings::PIPE_GAP));
        bottomPipe.setPosition(x, height + Settings::PIPE_GAP);
        bottomPipe.setFillColor(sf::Color::Green);
    }

    void update() {
        topPipe.move(-Settings::SPEED, 0);
        bottomPipe.move(-Settings::SPEED, 0);
    }
};
#endif

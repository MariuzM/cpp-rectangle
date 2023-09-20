#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

// Function to handle events
void handleEvents(sf::RenderWindow& window) {
    sf::Event event;

    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            window.close();
        }

        if (event.type == sf::Event::Resized) {
            sf::Vector2u windowSize = window.getSize();
            cout << "Window Size: " << windowSize.x << "x" << windowSize.y << endl;

            sf::View view(sf::FloatRect(0, 0, windowSize.x, windowSize.y));
            window.setView(view);
        }
    }
}

// Function to update game state
void updateGameState(sf::RectangleShape& rect, sf::Vector2f& rectPos, int& xVelocity, int& yVelocity, int rectSizeX, int rectSizeY, sf::RenderWindow& window) {
    if (rectPos.x < 0 || rectPos.x > window.getSize().x - rectSizeX) {
        xVelocity *= -1;
    }

    if (rectPos.y < 0 || rectPos.y > window.getSize().y - rectSizeY) {
        yVelocity *= -1;
    }

    rectPos.x += xVelocity;
    rectPos.y += yVelocity;
    rect.setPosition(rectPos);
}

int main() {
    sf::RenderWindow window(sf::VideoMode(550, 500), "Rectangle");
    window.setFramerateLimit(60);

    int rectSizeX = 50;
    int rectSizeY = 50;

    sf::RectangleShape rect;
    sf::Vector2f rectPos(100, 100);

    rect.setPosition(rectPos);
    rect.setSize(sf::Vector2f(rectSizeX, rectSizeY));

    int xVelocity = 7;
    int yVelocity = 7;

    while (window.isOpen()) {
        handleEvents(window);

        updateGameState(rect, rectPos, xVelocity, yVelocity, rectSizeX, rectSizeY, window);

        window.clear();
        window.draw(rect);
        window.display();
    }

    return 0;
}

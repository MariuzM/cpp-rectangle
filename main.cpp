#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

class Box {
   public:
    Box(int x, int y, int width, int height) {
        this->x = x;
        this->y = y;
        this->width = width;
        this->height = height;
    }
    sf::RectangleShape getRect() {
        sf::RectangleShape box;
        box.setPosition(sf::Vector2f(this->x, this->y));
        box.setSize(sf::Vector2f(this->width, this->height));
        return box;
    }

   private:
    int x;
    int y;
    int width;
    int height;
};

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
void updateGameState(sf::RectangleShape& box, sf::Vector2f& boxPos, int& xVelocity, int& yVelocity, int& boxSizeX, int& boxSizeY, sf::RenderWindow& window) {
    if (boxPos.x < 0 || boxPos.x > window.getSize().x - boxSizeX) {
        xVelocity *= -1;
    }

    if (boxPos.y < 0 || boxPos.y > window.getSize().y - boxSizeY) {
        yVelocity *= -1;
    }

    boxPos.x += xVelocity;
    boxPos.y += yVelocity;
    box.setPosition(boxPos);
}

int main() {
    sf::RenderWindow window(sf::VideoMode(550, 500), "Box");
    window.setFramerateLimit(60);

    int boxSizeX = 50;
    int boxSizeY = 50;

    Box box_1(200, 200, 50, 50);

    sf::RectangleShape box_2;
    sf::Vector2f boxPos(100, 100);

    box_2.setPosition(boxPos);
    box_2.setSize(sf::Vector2f(boxSizeX, boxSizeY));

    int xVelocity = 7;
    int yVelocity = 7;

    while (window.isOpen()) {
        handleEvents(window);

        updateGameState(box_2, boxPos, xVelocity, yVelocity, boxSizeX, boxSizeY, window);

        window.clear();
        window.draw(box_1.getRect());
        window.draw(box_2);
        window.display();
    }

    return 0;
}

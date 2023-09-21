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

// // Function to update game state
// void updateGameState(Box& box, int& xVelocity, int& yVelocity, int& boxSizeX, int& boxSizeY, sf::RenderWindow& window) {
//     if (box.getPosX() < 0 || box.getPosX() > window.getSize().x - boxSizeX) {
//         xVelocity *= -1;
//     }

//     if (box.getPosY() < 0 || box.getPosY() > window.getSize().y - boxSizeY) {
//         yVelocity *= -1;
//     }

//     box.setPosX(xVelocity);
//     box.setPosY(yVelocity);
// }

class Box {
   private:
    int x;
    int y;
    int w;
    int h;

   public:
    explicit Box(int _x, int _y, int _w, int _h) : x(_x), y(_y), w(_w), h(_h) {}

    sf::RectangleShape getRect() {
        sf::RectangleShape rect;
        rect.setPosition(sf::Vector2f(x, y));
        rect.setSize(sf::Vector2f(w, h));
        return rect;
    }

    sf::Vector2f getPosition() {
        return sf::Vector2f(x, y);
    }

    void setPosition(int _x, int _y) {
        x = _x;
        y = _y;
    }
};

void handleKeyboardEvents(Box& box) {
    int val = 5;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        box.setPosition(box.getPosition().x - val, box.getPosition().y);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        box.setPosition(box.getPosition().x + val, box.getPosition().y);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        box.setPosition(box.getPosition().x, box.getPosition().y - val);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        box.setPosition(box.getPosition().x, box.getPosition().y + val);
    }
}

int main() {
    sf::RenderWindow window(sf::VideoMode(700, 500), "Box");
    window.setFramerateLimit(60);

    Box box(200, 200, 50, 50);

    // int xVelocity = 7;
    // int yVelocity = 7;
    // int boxSizeX = 50;
    // int boxSizeY = 50;

    while (window.isOpen()) {
        handleEvents(window);
        handleKeyboardEvents(box);

        // updateGameState(box, xVelocity, yVelocity, boxSizeX, boxSizeY, window);

        window.clear();
        window.draw(box.getRect());
        window.display();
    }

    return 0;
}

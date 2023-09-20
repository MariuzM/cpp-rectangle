#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

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
    sf::Event event;

    // if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
    //   sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    //   std::cout << "X: " << mousePos.x << " Y: " << mousePos.y << std::endl;
    // }

    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }

      if (event.type == sf::Event::Resized) {
        sf::Vector2u windowSize = window.getSize();
        cout << "Window Size: " << windowSize.x << "x" << windowSize.y << endl;

        sf::View view(sf::FloatRect(0, 0, windowSize.x, windowSize.y));
        window.setView(view);
      }

      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
        window.close();
      }
    }

    if (rectPos.x < 0 || rectPos.x > window.getSize().x - rectSizeX) {
      xVelocity *= -1;
    }
    if (rectPos.y < 0 || rectPos.y > window.getSize().y - rectSizeY) {
      yVelocity *= -1;
    }

    rectPos.x += xVelocity;
    rectPos.y += yVelocity;
    rect.setPosition(rectPos);

    window.clear();
    window.draw(rect);
    window.display();
  }

  return 0;
}

#include<iostream>
#include<SFML/Graphics.hpp> // NEED TO INSTALL GLFW
#include"char.h"

int main()
{
  sf::Window window(
    sf::VideoMode(640, 480),
    "Hello");
  while (window.isOpen())
  {
    sf::Event event;
    while (window.pollEvent(event))
      if (event.type ==
          sf::Event::Closed)
          window.close();

  }
  return 0;
}
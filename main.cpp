#include<iostream>
#include<SFML/Graphics.hpp> 
#include"char.h"

int main()
{
  const int winWidth = 640;
  const int winHeight = 480;  
  sf::RenderWindow window(sf::VideoMode(winWidth, winHeight), "Hello");
  // window.setFramerateLimit(60);   
  sf::Texture skateTexture;
  skateTexture.loadFromFile("dexPack.png");
  sf::Sprite skate(skateTexture);
  sf::Vector2u size = skateTexture.getSize();
  skate.setOrigin(size.x /2, size.y / 2);


  sf::CircleShape circle(50);
  circle.setFillColor(sf::Color::Magenta);
  circle.setPosition(300.0f, 300.0f);

  // sf::Font myFont;
  // if (!myFont.loadFromFile("fonts/tech.ttf"))
  // {
  //   std::cerr << "Can't load font\n";
  //   exit(-1);
  // }

  // Keep window open
  while (window.isOpen())
  {
    // Event Handling
    sf::Event event;
    while (window.pollEvent(event))
    {
      // Trigger window closing when window is closed
      if (event.type == sf::Event::Closed)
      {
        std::cout << "Closing window" << std::endl;
        window.close();
      }

      // Key press event
      if (event.type == sf::Event::KeyPressed)
      {
        // std::cout << "Key pressed: " << event.key.code << std::endl;
        if (event.key.code == sf::Keyboard::W)
        {
          skate.move({0.f,-5.f});
        }
        if (event.key.code == sf::Keyboard::A)
        {
          skate.move({-5.f,0.f});
        }
        if (event.key.code == sf::Keyboard::S)
        {
          skate.move({0.f,5.f});
        }
        if (event.key.code == sf::Keyboard::D)
        {
          skate.move({5.f,0.f});
        }
      }
    }

      // float circleMoveSpeedX = 0.01f;
      // float circleMoveSpeedY = 0.01f;
      // circle.setPosition(circle.getPosition().x + circleMoveSpeedX, circle.getPosition().y + circleMoveSpeedY);

      window.clear();
      window.draw(skate);
      // window.draw(text);
      window.display();
  }

  return 0;
}
#include <iostream>
#include <SFML/Graphics.hpp>
#include "TextureManager.h"
#include "Button.h"
#include "StartScreen.h"


void LoadTextures() {
    // Start Screen
    TextureManager::LoadTexture("backgroundImage");
    TextureManager::LoadTexture("title");
    TextureManager::LoadTexture("newGame");
    TextureManager::LoadTexture("continue");
}

int main()
{
    // Creates window to fill current screen
    sf::RenderWindow window;
    window.create(sf::VideoMode(1920,1080), "The Apartment");
    // Moves window left 13 pixels to fill screen
    window.setPosition(sf::Vector2i(-13, 0));
    // Load all textures
    LoadTextures();
    // Create StartScreen
    StartScreen startScreen;

    while (window.isOpen())
    {
        if (!startScreen.GameStarted()) {
            startScreen.Display(window);
        }
        // Getting mouse position
        sf::Mouse mouse;
        auto pos = sf::Mouse::getPosition(window);
        if (!startScreen.GameStarted()) {
            startScreen.Hover(pos.x, pos.y);
        }


        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseButtonPressed) {
                // LMB
                if (event.mouseButton.button == sf::Mouse::Left) {
                    // Get mouse position
                    auto pos = sf::Mouse::getPosition(window);
                    // If on starting screen
                    if(!startScreen.GameStarted())
                        startScreen.LeftClick(pos.x, pos.y);
                }
            }
        }
        window.display();
        window.clear();
  
    }

    return 0;
}
#include <iostream>
#include <SFML/Graphics.hpp>
#include <zLib\zlib.h>
#include <tmx/MapLoader.hpp>
#include "TextureManager.h"
#include "Button.h"
#include "StartScreen.h"


void LoadTextures() {
    // Start Screen
    TextureManager::LoadTexture("backgroundImage");
    TextureManager::LoadTexture("title");
    TextureManager::LoadTexture("newGame");
    TextureManager::LoadTexture("newGameI");
    // Tiles
    TextureManager::LoadTexture("grassCenter");
    TextureManager::LoadTexture("grassMid");
    // Gray House
    TextureManager::LoadTexture("houseGray");
    TextureManager::LoadTexture("houseGrayBottomLeft");
    TextureManager::LoadTexture("houseGrayBottomRight");
    TextureManager::LoadTexture("houseGrayBottomMid");
    TextureManager::LoadTexture("houseGrayMidLeft");
    TextureManager::LoadTexture("houseGrayMidRight");
    TextureManager::LoadTexture("houseGrayTopLeft");
    TextureManager::LoadTexture("houseGrayTopMid");
    TextureManager::LoadTexture("houseGrayTopRight");
    TextureManager::LoadTexture("houseGrayAlt2");
    TextureManager::LoadTexture("roofGreyMid");
    TextureManager::LoadTexture("windowCheckered");
    TextureManager::LoadTexture("doorKnob");
    TextureManager::LoadTexture("doorTop");
    // Characters
    TextureManager::LoadTexture("chooseYourCharacter");
    TextureManager::LoadTexture("curran_front"); TextureManager::LoadTexture("curran_stand");
    TextureManager::LoadTexture("peterman_front"); TextureManager::LoadTexture("peterman_stand");
    TextureManager::LoadTexture("wyatt_front"); TextureManager::LoadTexture("wyatt_stand");
    TextureManager::LoadTexture("egan_front"); TextureManager::LoadTexture("egan_stand");
    TextureManager::LoadTexture("Curran"); TextureManager::LoadTexture("peterman"); TextureManager::LoadTexture("wyatt"); TextureManager::LoadTexture("egan");
    // Curran walk
    TextureManager::LoadTexture("p1_walk01"); TextureManager::LoadTexture("p1_walk03");
    //Peterman walk
    TextureManager::LoadTexture("p4_walk01"); TextureManager::LoadTexture("p4_walk03");
    // Wyatt walk
    TextureManager::LoadTexture("p3_walk01"); TextureManager::LoadTexture("p3_walk03");
    // Egan walk
    TextureManager::LoadTexture("p2_walk01"); TextureManager::LoadTexture("p2_walk03");
}

int main()
{
    // Creates window to fill current screen
    sf::RenderWindow window;
    window.create(sf::VideoMode(1920,1080), "The Apartment");
    // Moves window left 13 pixels to fill screen
    window.setPosition(sf::Vector2i(-7, 0));
    // Load all textures
    LoadTextures();
    // Create StartScreen
    StartScreen startScreen;
    // Load map
    tmx::MapLoader ml("maps");
    ml.load("test.tmx");
    
    while (window.isOpen())
    {
        // =================== Start Screen/Character Selection ===================
        if (!startScreen.GameStarted()) {
            startScreen.Display(window);
            // Check if mouse is hovering over buttons
            sf::Mouse mouse;
            auto pos = sf::Mouse::getPosition(window);  // Gets mouse position (x and y)
            startScreen.Hover(pos.x, pos.y, window);
            // Check for clicks on buttons
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
                        if (!startScreen.GameStarted())
                            startScreen.LeftClick(pos.x, pos.y, window);
                    }
                }
            }
            window.display();
            window.clear();
        }
        // =================== Game Started ===================
        if (startScreen.GameStarted()) {
            window.draw(ml);
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
                    }
                }
            }
            window.display();
            window.clear();
        }
    }

    return 0;
}
#include <iostream>
#include <SFML/Graphics.hpp>
#include <zLib\zlib.h>
#include <tmx/MapLoader.hpp>
#include "TextureManager.h"
#include "Button.h"
#include "StartScreen.h"
#include "Player.h"


void LoadTextures() {
    // Start Screen
    TextureManager::LoadTexture("backgroundImage");
    TextureManager::LoadTexture("title");
    TextureManager::LoadTexture("newGame");
    TextureManager::LoadTexture("newGameI");
    // Characters
    TextureManager::LoadTexture("chooseYourCharacter");
    TextureManager::LoadTexture("curran_front"); 
    TextureManager::LoadTexture("peterman_front");
    TextureManager::LoadTexture("wyatt_front"); 
    TextureManager::LoadTexture("egan_front");
    TextureManager::LoadTexture("Curran"); TextureManager::LoadTexture("peterman"); TextureManager::LoadTexture("wyatt"); TextureManager::LoadTexture("egan");
    // Curran walk
    TextureManager::LoadTexture("curran_walk01"); TextureManager::LoadTexture("curran_walk03");
    TextureManager::LoadTexture("curran_walk01l"); TextureManager::LoadTexture("curran_walk03l");
    //Peterman walk
    TextureManager::LoadTexture("peterman_walk01"); TextureManager::LoadTexture("peterman_walk03");
    TextureManager::LoadTexture("peterman_walk01l"); TextureManager::LoadTexture("peterman_walk03l");
    // Wyatt walk
    TextureManager::LoadTexture("wyatt_walk01"); TextureManager::LoadTexture("wyatt_walk03");
    TextureManager::LoadTexture("wyatt_walk01l"); TextureManager::LoadTexture("wyatt_walk03l");
    // Egan walk
    TextureManager::LoadTexture("egan_walk01"); TextureManager::LoadTexture("egan_walk03");
    TextureManager::LoadTexture("egan_walk01l"); TextureManager::LoadTexture("egan_walk03l");
}

int main()
{
    sf::Sprite bg;
    // Creates window to fill current screen
    sf::RenderWindow window;
    window.create(sf::VideoMode(1920,1080), "The Apartment");
    window.setFramerateLimit(70);
    // Moves window left 13 pixels to fill screen
    window.setPosition(sf::Vector2i(-7, 0));
    // Load all textures
    LoadTextures();
    // Create StartScreen
    StartScreen startScreen;
    // Load map/bg
    bg.setTexture(TextureManager::GetTexture("backgroundImage"));
    tmx::MapLoader* level0 = new tmx::MapLoader("maps");
    level0->load("level0.tmx");
    sf::Event event;
    // Level switching and player creation
    string playerName;
    Player player;
    bool playerCreated = false;
    bool levelSwitched = false; bool levelBeaten = false;
    int levelNum = 1;
    string currentLevel = "level";
    // Create MapLoader for levels and vector for layers
    tmx::MapLoader ml("maps");
    std::vector<tmx::MapLayer> layers;

    while (window.isOpen())
    {
        // =================== Start Screen/Character Selection ===================
        if (!startScreen.GameStarted()) {
            window.draw(bg);
            window.draw(*level0);
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
            if (!levelSwitched) { // Load new level
                delete level0;
                currentLevel += std::to_string(levelNum) + ".tmx";
                ml.load(currentLevel);
                layers = ml.getLayers(); // Get vector for layers
                player.SetMap(layers); // Send layer vector to player for collisions
                levelSwitched = true;
                currentLevel = "level";
            } if (!playerCreated) {
                playerName = startScreen.GetPlayerName();
                player.Create(playerName);
                playerCreated = true;
            }
            // Draw elements
            window.draw(ml);
            player.Display(window);
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
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                player.Walk('r');
            } 
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                player.Walk('l');
            }
            window.display();
            window.clear();
        }
    }

    return 0;
}
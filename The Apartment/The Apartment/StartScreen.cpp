#include "StartScreen.h"

// Initializes StartScreen
StartScreen::StartScreen() {
	// Set texture on bg and title sprites
	background.setTexture(TextureManager::GetTexture("backgroundImage"));
	title.setTexture(TextureManager::GetTexture("title"));
	// Set texture on newGame button
	newGame.SetImage("newGame");
	// Set position of sprites and buttons 
	title.setPosition(450, 30);
	newGame.SetPosition(700, 400);
	// Initialize ground tile positions/textures
	for (int i = 0; i < 28; i++) {
		sf::Sprite* tile = new sf::Sprite;
		tile->setTexture(TextureManager::GetTexture("grassMid"));
		tile->setPosition(i * 70, 800);
		grassTiles[i] = tile;
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 28; j++) {
			sf::Sprite* tile = new sf::Sprite;
			tile->setTexture(TextureManager::GetTexture("grassCenter"));
			tile->setPosition(j * 70, 1080 - (i * 70));
			if (i == 0)
				dirtTiles[j] = tile;
			if (i == 1)
				dirtTiles[j + 28] = tile;
			if (i == 2)
				dirtTiles[j + 56] = tile;
			if(i == 3)
				dirtTiles[j + 84] = tile;
		}
	}
	// Building
	CreateBuilding();

	// Character buttons
	curran.SetImage("curran_front"); curran.SetPosition(200, 710);
	peterman.SetImage("peterman_front"); peterman.SetPosition(400, 710);
	wyatt.SetImage("wyatt_front"); wyatt.SetPosition(600, 710);
	egan.SetImage("egan_front"); egan.SetPosition(800, 710);

	// Choose your character
	chooseYourCharacter.setTexture(TextureManager::GetTexture("chooseYourCharacter"));
	chooseYourCharacter.setPosition(175, 30);
}

void StartScreen::CreateBuilding() {
	// Initialize building tiles
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 5; j++) {
			sf::Sprite* tile = new sf::Sprite;
			building[i][j] = tile;
		}
	}
	for (int i = 1; i < 4; i++)
		building[0][i]->setTexture(TextureManager::GetTexture("houseGrayTopMid"));
	for (int i = 1; i < 5; i++) {
		building[1][i]->setTexture(TextureManager::GetTexture("houseGray"));
		building[2][i]->setTexture(TextureManager::GetTexture("houseGray"));
		building[3][i]->setTexture(TextureManager::GetTexture("houseGray"));
		building[4][i]->setTexture(TextureManager::GetTexture("houseGray"));
		building[5][i]->setTexture(TextureManager::GetTexture("houseGray"));
	}
	building[0][0]->setTexture(TextureManager::GetTexture("houseGrayTopLeft"));
	building[0][4]->setTexture(TextureManager::GetTexture("houseGrayTopRight"));
	building[2][4]->setTexture(TextureManager::GetTexture("houseGrayTopRight"));
	building[1][0]->setTexture(TextureManager::GetTexture("houseGrayMidLeft"));
	building[2][0]->setTexture(TextureManager::GetTexture("houseGrayMidLeft"));
	building[3][0]->setTexture(TextureManager::GetTexture("houseGrayMidLeft"));
	building[4][0]->setTexture(TextureManager::GetTexture("houseGrayMidLeft"));
	building[5][0]->setTexture(TextureManager::GetTexture("houseGrayMidLeft"));
	building[1][4]->setTexture(TextureManager::GetTexture("houseGrayMidRight"));
	building[2][4]->setTexture(TextureManager::GetTexture("houseGrayMidRight"));
	building[3][4]->setTexture(TextureManager::GetTexture("houseGrayMidRight"));
	building[4][4]->setTexture(TextureManager::GetTexture("houseGrayMidRight"));
	building[5][4]->setTexture(TextureManager::GetTexture("houseGrayMidRight"));
	building[6][0]->setTexture(TextureManager::GetTexture("houseGrayBottomLeft"));
	building[6][1]->setTexture(TextureManager::GetTexture("houseGrayBottomMid"));
	building[6][2]->setTexture(TextureManager::GetTexture("doorKnob"));
	building[6][3]->setTexture(TextureManager::GetTexture("houseGrayBottomMid"));
	building[6][4]->setTexture(TextureManager::GetTexture("houseGrayBottomRight"));

	// Set buildling position
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 5; j++) {
			building[i][j]->setPosition((1360 + (j * 70)), (310 + (i * 70)));
		}
	}

	// Set windows/door top
	sf::Sprite window1; window1.setTexture(TextureManager::GetTexture("windowCheckered")); window1.setPosition(1430, 380); windows[0] = window1;
	sf::Sprite window2; window2.setTexture(TextureManager::GetTexture("windowCheckered")); window2.setPosition(1430, 550); windows[1] = window2;
	sf::Sprite window3; window3.setTexture(TextureManager::GetTexture("windowCheckered")); window3.setPosition(1570, 380); windows[2] = window3;
	sf::Sprite window4; window4.setTexture(TextureManager::GetTexture("windowCheckered")); window4.setPosition(1570, 550); windows[3] = window4;
	doorTop.setTexture(TextureManager::GetTexture("doorTop")); doorTop.setPosition(1500, 660);
}

void StartScreen::Display(sf::RenderWindow& window) {
	// ========== Always displayed ==========
	// Draw bg
	window.draw(background);

	// Display ground tiles
	for (int i = 0; i < 28; i++) {
		window.draw(*grassTiles[i]);
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 28; j++) {
			if (i == 0)
				window.draw(*dirtTiles[j]);
			if (i == 1)
				window.draw(*dirtTiles[j + 28]);
			if (i == 2)
				window.draw(*dirtTiles[j + 56]);
			if (i == 3)
				window.draw(*dirtTiles[j + 84]);
		}
	}
	// Display building
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 5; j++) {
			window.draw(*building[i][j]);
		}
	}
	// Dipsplay windows/door top
	for (int i = 0; i < 4; i++) {
		window.draw(windows[i]);
	}
	window.draw(doorTop);
	// Display characters
	curran.Display(window);
	peterman.Display(window);
	wyatt.Display(window);
	egan.Display(window);
	// ========================================

	// Draw title and new game button if it hasn't been clicked yet
	if (!newGameClicked) {
		window.draw(title);
		// Update newGame and continue buttons
		newGame.Display(window);
	}
	if (newGameClicked) {
		window.draw(chooseYourCharacter);
	}
}

void StartScreen::LeftClick(int xPos, int yPos) {
	// If player clicks on New Game button
	if (newGame.GetSprite().getGlobalBounds().contains(sf::Vector2f(xPos, yPos))) { // If button's sprite is in pos of click
		newGameClicked = true;
	}
}

void StartScreen::Hover(int xPos, int yPos, sf::RenderWindow& window) {
	// Check New Game button
	if (newGame.GetSprite().getGlobalBounds().contains(sf::Vector2f(xPos, yPos))) {
		newGame.Illuminate();
}
	else if (!newGame.GetSprite().getGlobalBounds().contains(sf::Vector2f(xPos, yPos))) {
		newGame.Deluminate();
	}
	// Check curran sprite
	if (curran.GetSprite().getGlobalBounds().contains(sf::Vector2f(xPos, yPos))) {
		ShowCharacterName("curran", window);
	}
	// Check peterman sprite
	if (peterman.GetSprite().getGlobalBounds().contains(sf::Vector2f(xPos, yPos))) {
		ShowCharacterName("peterman", window);
	}
	// Check wyatt sprite
	if (wyatt.GetSprite().getGlobalBounds().contains(sf::Vector2f(xPos, yPos))) {
		ShowCharacterName("wyatt", window);
	}
	// Check egan sprite
	if (egan.GetSprite().getGlobalBounds().contains(sf::Vector2f(xPos, yPos))) {
		ShowCharacterName("egan", window);
	}
}

void StartScreen::ShowCharacterName(string character, sf::RenderWindow& window) {
	if (character == "curran" && newGameClicked) {
		sf::Sprite curranName;
		curranName.setTexture(TextureManager::GetTexture("Curran"));
		curranName.setPosition(157, 610);
		window.draw(curranName);
	} 	if (character == "peterman" && newGameClicked) {
		sf::Sprite petermanName;
		petermanName.setTexture(TextureManager::GetTexture("peterman"));
		petermanName.setPosition(345, 610);
		window.draw(petermanName);
	}	if (character == "wyatt" && newGameClicked) {
		sf::Sprite wyattName;
		wyattName.setTexture(TextureManager::GetTexture("wyatt"));
		wyattName.setPosition(555, 610);
		window.draw(wyattName);
	}	if (character == "egan" && newGameClicked) {
		sf::Sprite eganName;
		eganName.setTexture(TextureManager::GetTexture("egan"));
		eganName.setPosition(750, 610);
		window.draw(eganName);
	}
}

bool StartScreen::GameStarted() {
	if (newGameClicked && enteredBuilding) {
		gameStarted = true;
		return gameStarted;
	}
	return gameStarted;
}

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
	// Character buttons
	curran.SetImage("curran_front"); curran.SetPosition(200, 710);
	peterman.SetImage("peterman_front"); peterman.SetPosition(400, 710);
	wyatt.SetImage("wyatt_front"); wyatt.SetPosition(600, 710);
	egan.SetImage("egan_front"); egan.SetPosition(800, 710);
	// Choose your character
	chooseYourCharacter.setTexture(TextureManager::GetTexture("chooseYourCharacter"));
	chooseYourCharacter.setPosition(175, 30);
}


void StartScreen::Display(sf::RenderWindow& window) {
	//Check condition to stop showing startScreen
	if (selectedCharacter.GetSprite().getPosition().x >= 1500) { // If selected character is at doors
		enteredBuilding = true;
	}
	// ========== Always displayed ==========
	// Draw bg
	window.draw(background);

	// Display characters
	if (!characterSelected) {
		curran.Display(window);
		peterman.Display(window);
		wyatt.Display(window);
		egan.Display(window);
	}
	if (characterAssigned) { // Once a character has been chose, assign walking textures and make character move to door
		selectedCharacter.Display(window);
		sf::Time elapsed;
		sf::Clock clock;
		elapsed = clock.getElapsedTime();
		if (selectedCharacter.GetSprite().getPosition().x < 1500) {
			if (frameCount % 400 == 0) {
				if (spriteChange % 2 == 0) {
					if(curranSelected) { selectedCharacter.SetImage("p1_walk03"); }
					if(petermanSelected) { selectedCharacter.SetImage("p4_walk03"); }
					if (wyattSelected) { selectedCharacter.SetImage("p3_walk03"); }
					if (eganSelected) { selectedCharacter.SetImage("p2_walk03"); }
					spriteChange++;
				}
				else {
					if (curranSelected) { selectedCharacter.SetImage("p1_walk01"); }
					if (petermanSelected) { selectedCharacter.SetImage("p4_walk01"); }
					if (wyattSelected) { selectedCharacter.SetImage("p3_walk01"); }
					if (eganSelected) { selectedCharacter.SetImage("p2_walk01"); }
					spriteChange++;
				}
			}
			selectedCharacter.GetSprite().move(400000 * elapsed.asSeconds(), 0);
			clock.restart();
			frameCount++;
		}
	}
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

void StartScreen::LeftClick(int xPos, int yPos, sf::RenderWindow& window) {
	// If player clicks on New Game button
	if (newGame.GetSprite().getGlobalBounds().contains(sf::Vector2f(xPos, yPos))) { // If button's sprite is in pos of click
		newGameClicked = true;
	}
	// If player selects curran
	if (curran.GetSprite().getGlobalBounds().contains(sf::Vector2f(xPos, yPos)) && newGameClicked) { // If button's sprite is in pos of click
		characterSelected = true;
		curranSelected = true;
		selectedCharacter = curran;
		characterAssigned = true;
	} // If player selects peterman
	if (peterman.GetSprite().getGlobalBounds().contains(sf::Vector2f(xPos, yPos)) && newGameClicked) { 
		characterSelected = true;
		petermanSelected = true;
		selectedCharacter = peterman;
		characterAssigned = true;
	}	 // If player selects wyatt
	if (wyatt.GetSprite().getGlobalBounds().contains(sf::Vector2f(xPos, yPos)) && newGameClicked) { 
		characterSelected = true;
		wyattSelected = true;
		selectedCharacter = wyatt;
		characterAssigned = true;
	} // If player selects egan
		if (egan.GetSprite().getGlobalBounds().contains(sf::Vector2f(xPos, yPos)) && newGameClicked) { 
		characterSelected = true;
		eganSelected = true;
		selectedCharacter = egan;
		characterAssigned = true;
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
	if (!characterSelected) {
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

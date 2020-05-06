#include "Button.h"

void Button::SetImage(const char* filename) {
	this->filename = filename;
	buttonSprite.setTexture(TextureManager::GetTexture(filename));
}

void Button::Display(sf::RenderWindow& window) {
	// Change to illuminated texture if button is illuminated
	if (illuminated) {
		string newFilename = filename + "I";
		const char* c = newFilename.c_str(); // Adds I to end of filename to get illuminated version
		buttonSprite.setTexture(TextureManager::GetTexture(c));
	}
	else { 
		const char* c = filename.c_str();
		buttonSprite.setTexture(TextureManager::GetTexture(c));
	}
	window.draw(buttonSprite);
}

void Button::SetPosition(int xPos, int yPos) {
	buttonSprite.setPosition(xPos, yPos);
}

sf::Sprite& Button::GetSprite() {
	return buttonSprite;
}

void Button::Illuminate() {
	illuminated = true;
}
void Button::Deluminate() {
	illuminated = false;
}

Button& Button::operator=(Button& rhs) {
	illuminated = rhs.illuminated;
	locked = rhs.locked;
	filename = rhs.filename;
	buttonSprite = rhs.buttonSprite;
	return *this;
}
#include "Player.h"
Player::Player() {
	this->playerName = "null";
}
void Player::Create(string playerName) {
	this->playerName = playerName;
	SetSprite();
	playerSprite.setPosition(500, 744);
	// Set 4 corners of sprites hitbox
	hitBox[0] = sf::Vector2f(34.f, 0); // Top 
	hitBox[1] = sf::Vector2f(68.f, 48.5f); // Right
	hitBox[2] = sf::Vector2f(34.f, 97.f); // Bottom 
	hitBox[3] = sf::Vector2f(0, 48.5f); // Left
}
void Player::SetSprite() { // When not moving, the character faces forward
	string temp = playerName;
	temp += "_front";
	const char* c = temp.c_str();
	playerSprite.setTexture(TextureManager::GetTexture(c));

}
void Player::Display(sf::RenderWindow& window) {
	// Get player position
	currentPosition = playerSprite.getPosition();
	// Check if player is falling -> make player fall if they are
	falling = CheckIfFalling();
	if (falling) {
		Fall();
	}
	// Check if any collisions are occuring -> collisions are handled in Collisions()
	CheckCollision();
	// Draw sprite
	window.draw(GetSprite());
	// Set Sprite
	SetSprite();

}
sf::Sprite& Player::GetSprite() {
	return playerSprite;
}
void Player::Walk(char direction) {
	Animate(direction);
	if (direction == 'r') {
		playerSprite.move(movementSpeedRight, 0);
	}
	if (direction == 'l') {
		playerSprite.move(movementSpeedLeft * -1, 0);
	}	// REMOVE LATER
	if (direction == 'd') {
		playerSprite.move(0, movementSpeedRight);
	} // 
	walkingCounter++;
	if (walkingCounter == 30)
		walkingCounter = 0;
}

void Player::Jump() {
	if (!falling) {
		falling = false;
		playerSprite.move(0, -50);
		falling = true;
	}
}

void Player::Animate(char direction) {
	moving = true;
	string temp = playerName;
	if (direction == 'r') { // If right key pressed, sets right facing animations
		facingRight = true;
		if (walkingCounter < 15) {
			temp += "_walk01";
			const char* c = temp.c_str();
			playerSprite.setTexture(TextureManager::GetTexture(c));
		}
		else {
			temp += "_walk03";
			const char* c = temp.c_str();
			playerSprite.setTexture(TextureManager::GetTexture(c));
		}
	}
	if (direction == 'l') { // If left key pressed, sets left facing animations
		facingRight = false;
		if (walkingCounter < 15) {
			temp += "_walk01l";
			const char* c = temp.c_str();
			playerSprite.setTexture(TextureManager::GetTexture(c));
		}
		else {
			temp += "_walk03l";
			const char* c = temp.c_str();
			playerSprite.setTexture(TextureManager::GetTexture(c));
		}
	}
		moving = false;
}

void Player::CheckCollision() {
	for (auto& layer : layers) {

		if (layer.type == tmx::ObjectGroup) {

			for (auto& obj : layer.objects) {

				if (layer.name == "collision") {
					for (auto& point : hitBox) {
						if (obj.contains(currentPosition + point)) {
							if (currentPosition + point == sf::Vector2f(currentPosition.x + 34.f, currentPosition.y)) // Top collision
								std::cout << "Top collision" << std::endl;
							if (currentPosition + point == sf::Vector2f(currentPosition.x + 68.f, currentPosition.y + 48.5f)) // Right
								std::cout << "Right collision" << std::endl;
							if (currentPosition + point == sf::Vector2f(currentPosition.x + 34.f, currentPosition.y + 97.f)) { // Bottom 
								std::cout << "Bottom collision" << std::endl;
							}
							if (currentPosition + point == sf::Vector2f(currentPosition.x, currentPosition.y + 48.5f)) // Left 
								std::cout << "Left collision" << std::endl;
							break;
						}
					}
				}
			}
		}
	}
} 

void Player::SetMap(std::vector<tmx::MapLayer>& layers) {
	this->layers = layers;
}

void Player::Fall() {
	playerSprite.move(0, gravitySpeed);
}

bool Player::CheckIfFalling() {
	for (auto& layer : layers) {
		if (layer.type == tmx::ObjectGroup) {
			for (auto& obj : layer.objects) {
				if (layer.name == "collision") {
					if (obj.contains(sf::Vector2f(currentPosition.x + 34.f, currentPosition.y + 97.f))) {
						return false;
					}
				}
			}
		}
	}
	return true;
}
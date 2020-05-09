#include "Player.h"
Player::Player() {
	this->playerName = "null";
}
void Player::Create(string playerName) {
	this->playerName = playerName;
	SetSprite();
	playerSprite.setPosition(500, 750);
	// Set 4 corners of sprites hitbox
	hitBox[0] = sf::Vector2f(-70.f, -70.f);
	hitBox[1] = sf::Vector2f(70.f, -70.f);
	hitBox[2] = sf::Vector2f(70.f, 70.f);
	hitBox[3] = sf::Vector2f(-70.f, 70.f);
}
void Player::SetSprite() { // When not moving, the character faces forward
	string temp = playerName;
	temp += "_front";
	const char* c = temp.c_str();
	playerSprite.setTexture(TextureManager::GetTexture(c));

}
void Player::Display(sf::RenderWindow& window) {
	currentPosition = playerSprite.getPosition();
	CheckCollision();
	window.draw(GetSprite());
	SetSprite();
}
sf::Sprite& Player::GetSprite() {
	return playerSprite;
}
void Player::Walk(char direction) {
	Animate(direction);
	if (direction == 'r') {
		playerSprite.move(movementSpeed, 0);
	}
	if (direction == 'l') {
		playerSprite.move(movementSpeed * -1, 0);
	}
	walkingCounter++;
	if (walkingCounter == 30)
		walkingCounter = 0;
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
	for (auto& layer : layers)
	{
		if (layer.type == tmx::ObjectGroup)
		{
			for (auto& obj : layer.objects)
			{
				if (layer.name == "collision")
				{
					for (auto& point : hitBox)
					{
						if (obj.contains(currentPosition + point))
						{
							std::cout << "Collision" << std::endl;
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
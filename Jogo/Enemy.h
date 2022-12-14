#pragma once

#include "Player.h"

class Enemy : public Character
{
protected:
	Player* player;

public:
	Enemy(GraphicsManager* graphicsManager, float* dt, int id, float spriteScale, sf::Vector2f position, sf::Vector2f bodySize, std::string pathToTexture, std::string textureName, float speed, long int hp);
	Enemy();
	~Enemy();

	virtual void update() {}

	void updateMovement();
	void updatePosition(float widthAux, float heightAux);

	/*void updateMovement();
	void updatePositions();
	void updateAnimation();*/

	void setPlayer(Player* player) { this->player = player; }
	Player* getPlayer() { return this->player; }
};
#include "Character.h"

const float GRAVITY = 981.f;

Character::Character(GraphicsManager* graphicsManager, sf::Vector2f position, std::string pathToTexture, std::string textureName, sf::Vector2f bodySize,
	float* dt, float spriteScale, float speed) :
	Entity(graphicsManager, position, pathToTexture, textureName, bodySize)
{
	this->dt = dt;
	this->spriteScale = spriteScale;
	this->speed = speed;

	this->sprite.setPosition(this->position + this->body.getSize());
	this->sprite.setScale(sf::Vector2f(this->spriteScale, this->spriteScale));
	this->sprite.setOrigin(this->body.getSize() / 2.f);

	this->velocity = sf::Vector2f(0.f, 0.f);
	this->gravity = GRAVITY;
	this->facingRight = true;

	this->hp = 1000;
}

Character::Character() :
	Entity()
{
	this->spriteScale = 1.f;
	this->speed = 1.f;
	this->dt = nullptr;
	this->facingRight = true;
	this->gravity = GRAVITY;
	this->hp = 1000;
}

Character::~Character()
{
}

void Character::updateCollision(sf::Vector2f direction)
{
	if (direction.x < 0.f)
		this->velocity.x = 0.f;
	else if (direction.x > 0.f)
		this->velocity.x = 0.f;

	if (direction.y < 0.f)
		this->velocity.y = 0.f;
	else if (direction.y > 0.f)
		this->velocity.y = 0.f;
}

void Character::move(float dir_x)
{
	if (this->facingRight && dir_x < 0.f)
		this->flip();
	else if (!this->facingRight && dir_x > 0.f)
		this->flip();

	this->velocity.x = dir_x * this->speed;
}

void Character::flip()
{
	if (this->facingRight)
		this->sprite.setScale(-this->spriteScale, this->spriteScale);
	else
		this->sprite.setScale(this->spriteScale, this->spriteScale);

	this->facingRight = !this->facingRight;
}

bool Character::isDead()
{
	if (this->hp <= 0)
		return true;
	return false;
}
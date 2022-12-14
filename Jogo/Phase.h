#pragma once

#include <fstream>
#include <sstream>
#include "EntityList.h"
#include "Archer.h"
#include "Skeleton.h"
#include "DarkKnight.h"
#include "Fire.h"
#include "Teleport.h"
#include "Slow.h"
#include "CollisionsManager.h"

class PlayingState;

class Phase : public Ent
{
protected:
	Player* player1;
	Player* player2;

	EntityList entityList;

	Entity** platformList;

	CollisionsManager collisionsManager;

	std::vector<std::string> texturePaths;
	std::vector <std::string> textureNames;

public:
	Phase(GraphicsManager* graphicsManager, float* dt, int id);
	Phase();
	~Phase();

	Entity createEntity(int id, float spriteScale, sf::Vector2f position, sf::Vector2f bodySize, std::string pathToTexture, std::string textureName);

	void loadMap(std::string pathToTilemap);

	void update();

	void render();

	void clearPlatformList();
	void clearEntityList();

	void initCollisionsManager();

	void addEntity(Entity* entity) { this->entityList.addEntity(entity); }

	void setPlayer1(Player* player) { this->player1 = player; }
	Player* getPlayer1() { return this->player1; }

	void setPlayer2(Player* player) { this->player2 = player; }
	Player* getPlayer2() { return this->player2; }

	EntityList* getEntityList() { return &this->entityList; }
	Entity** getPlatformList() { return this->platformList; }
};
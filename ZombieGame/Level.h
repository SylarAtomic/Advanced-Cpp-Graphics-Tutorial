#pragma once

#include <string>
#include <vector>

#include <Bengine/SpriteBatch.h>

const int TILE_WIDTH = 64;

class Level
{
public:

	//Load the level
	Level(const std::string& fileName);
	~Level();

	void draw();

	// Getters
	const std::vector<std::string>& getLevelData() const { return _levelData;  }
	glm::vec2 getStartPlayerPos() const { return _startPlayerPos; }
	const std::vector<glm::vec2>& getZombieStartPlayerPos() const { return _zombieStartPositions; } // Error Here

private:
	std::vector<std::string> _levelData;
	int _numHumans;
	Bengine::SpriteBatch _spriteBatch;

	glm::vec2 _startPlayerPos;
	std::vector<glm::vec2> _zombieStartPositions;
};


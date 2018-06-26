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

private:
	std::vector<std::string> _levelData;
	int _numHumans;
	Bengine::SpriteBatch _spriteBatch;

	glm::ivec2 _startPlayerPos;
	std::vector<glm::ivec2> _zombieStartPositions;
};


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
	glm::vec2 getStartPlayerPos() const { return _startPlayerPos; }
	const std::vector<glm::vec2>& getStartPlayerPos() const { return _zombieStartPosition; } // Error Here

private:
	std::vector<std::string> _levelData;
	int _numHumans;
	Bengine::SpriteBatch _spriteBatch;

	glm::vec2 _startPlayerPos;
	std::vector<glm::vec2> _zombieStartPositions;
};


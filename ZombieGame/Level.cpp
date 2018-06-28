#include "Level.h"

#include <Bengine/Errors.h>
#include <fstream>
#include <iostream>
#include <Bengine/ResourceManager.h>


Level::Level(const std::string& fileName){
	
	std::ifstream file;
	file.open(fileName);

	//Error checking
	if (file.fail()) {
		Bengine::fatalError("Failed to open " + fileName);
	}

	//Throw away the first string in temp
	std::string temp;
	file >> temp >> _numHumans;
	
	while (std::getline(file, temp)) {
		_levelData.push_back(temp);
	}

	_spriteBatch.init();
	_spriteBatch.begin();

	glm::vec4 uvRect(0.0f, 0.0f, 1.0f, 1.0f);

	Bengine::Color whiteColor;
	whiteColor.r = 255;
	whiteColor.g = 255;
	whiteColor.b = 255;
	whiteColor.a = 255;


	//Render all the tiles
	for (int y = 0; y < _levelData.size(); y++) {
		for (int x = 0; x < _levelData[y].size(); x++) {
			// Grab the tile
			char tile = _levelData[y][x];

			//Get dest rect
			glm::vec4 destRect(x * TILE_WIDTH, y * TILE_WIDTH, TILE_WIDTH, TILE_WIDTH);

			//Process the tile
			switch (tile) {
			case 'B':
			case 'R':
				_spriteBatch.draw(destRect,
									uvRect,
									Bengine::ResourceManager::getTexture("Textures/red_bricks.png").id,
									0.0f,
									whiteColor);
				break;
			case 'G':
				_spriteBatch.draw(destRect,
					uvRect,
					Bengine::ResourceManager::getTexture("Textures/glass.png").id,
					0.0f,
					whiteColor);
				break;
			case 'L':
				_spriteBatch.draw(destRect,
					uvRect,
					Bengine::ResourceManager::getTexture("Textures/light_bricks.png").id,
					0.0f,
					whiteColor);
				break;
			case '@':
				_startPlayerPos.x = x * TILE_WIDTH;
				_startPlayerPos.y = y * TILE_WIDTH;
				break;
			case 'Z':
				_zombieStartPositions.emplace_back(x * TILE_WIDTH, y * TILE_WIDTH);
				break;
			case '.':
				break;
			default:
				std::printf("Unexpected symbol %c at (%d,%d)", tile, x, y);
				break;
			}
		}
	}
	_spriteBatch.end();
}


Level::~Level() {

}

void Level::draw() {
	_spriteBatch.renderBatch();
}

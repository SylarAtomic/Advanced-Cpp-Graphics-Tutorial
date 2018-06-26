#pragma once

#include <string>
#include <vector>

class Level
{
public:

	//Load the level
	Level(const std::string& fileName);
	~Level();

private:
	std::vector<std::string> _levelData;
	int _numHumans;
};


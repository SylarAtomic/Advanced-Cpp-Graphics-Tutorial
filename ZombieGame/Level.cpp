#include "Level.h"

#include <Bengine/Errors.h>
#include <fstream>
#include <iostream>


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

	//Print it out
	for (int i = 0; i < _levelData.size(); i++){
		std::cout << _levelData[i] << std::endl;
	}

}


Level::~Level()
{
}

#pragma once

#include <include\SDL\SDL.h>
#include <include\GL\glew.h>

#include "GLSLProgram.h"
#include "Sprite.h"
#include <vector>

#include "GLTexture.h"

enum class GameState { PLAY, EXIT };

class MainGame
{
public:
	MainGame();
	~MainGame();

	void run();


private:
	void initSystems();
	void initShaders();
	void gameLoop();
	void processInput();
	void drawGame();
	void calculateFPS();

	SDL_Window* _window;
	int _screenWidth;
	int _screenHight;
	GameState _gameState;

	std::vector <Sprite*> _sprites;

	GLSLProgram _colorProgram;
	
	float _maxFPS;
	float _fps;
	float _frameTime;

	float _time;

};


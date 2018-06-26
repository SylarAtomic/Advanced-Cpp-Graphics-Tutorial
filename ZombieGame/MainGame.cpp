#include "MainGame.h"
#include <Bengine/Bengine.h>
#include <Include/SDL/SDL.h>
#include <iostream>
#include <Bengine/Timing.h>


MainGame::MainGame():	_screenWidth(1024),
						_screenHeight(798),
						_gameState(GameState::PLAY),
						_fps(0)
{

}

MainGame::~MainGame() 
{
	for (int i = 0; i < _levels.size(); i++) {
		{
			delete _levels[i];
		}
	}
}

void MainGame::run() {

	initSystems();

	gameLoop();

}

void MainGame::initSystems() {
	Bengine::init();

	_window.create("ZombieGame", _screenWidth, _screenHeight, 0);

	initShaders();

	_levels.push_back(new Level("Levels/level1.text"));
}

void MainGame::initShaders() {
    // Compile our color shader
	_textureProgram.compilerShaders("Resources/Shaders/vertexShader.vs", "Resources/Shaders/fragmentShader.fs");
	_textureProgram.addAttribute("vertexPosition");
	_textureProgram.addAttribute("vertexColor");
	_textureProgram.addAttribute("vertexUV");
	_textureProgram.linkShaders();
}

void MainGame::gameLoop() {
	
	Bengine::FpsLimiter fpsLimiter;
	fpsLimiter.setMaxFPS(60.0f);

	while (_gameState == GameState::PLAY) {
		fpsLimiter.begin();

		processInput();

		drawGame();

		_fps = fpsLimiter.end();
	}
}

void MainGame::processInput() {
    SDL_Event evnt;

    //Will keep looping until there are no more events to process
    while (SDL_PollEvent(&evnt)) {
        switch (evnt.type) {
            case SDL_QUIT:
                //Exit the game here!
                break;
            case SDL_MOUSEMOTION:
                _inputManager.setMouseCoords(evnt.motion.x, evnt.motion.y);
                break;
            case SDL_KEYDOWN:
				_inputManager.pressKey(evnt.key.keysym.sym);
                break;
            case SDL_KEYUP:
				_inputManager.releaseKey(evnt.key.keysym.sym);
                break;
            case SDL_MOUSEBUTTONDOWN:
				_inputManager.pressKey(evnt.button.button);
                break;
            case SDL_MOUSEBUTTONUP:
				_inputManager.releaseKey(evnt.button.button);
                break;
        }
    
	}

}

void MainGame::drawGame() {
    // Set the base depth to 1.0
    glClearDepth(1.0);
    // Clear the color and depth buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Draw code goes here

	//Swap our buffer and draw everything to the screen!
	_window.swapBuffer();
}
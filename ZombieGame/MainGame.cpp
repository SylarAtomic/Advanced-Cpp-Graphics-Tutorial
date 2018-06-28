#include "MainGame.h"
#include <Bengine/Bengine.h>
#include <Include/SDL/SDL.h>
#include <iostream>
#include <Bengine/Timing.h>


MainGame::MainGame():	_screenWidth(1024),
						_screenHeight(798),
						_gameState(GameState::PLAY),
						_fps(0),
						_player(nullptr)
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

	initLevel();

	gameLoop();

}

void MainGame::initSystems() {
	Bengine::init();

	_window.create("ZombieGame", _screenWidth, _screenHeight, 0);
	glClearColor(0.7f, 0.7f, 0.7f, 1.0f);

	initShaders();

	_agentSpriteBatch.init();

	_camera.init(_screenHeight, _screenHeight);


}

void MainGame::initLevel()
{
	// Level 1
	_levels.push_back(new Level("Levels/level1.txt"));
	_currentLevel = 0;

	_player = new Player();
	_player->init(1.0f, _levels[_currentLevel]->getStartPlayerPos());

	_humans.push_back(_player);
}


void MainGame::initShaders() {
    // Compile our color shader
	_textureProgram.compilerShaders("Shaders/textureShading.vert", "Shaders/textureShading.frag");
	_textureProgram.addAttribute("vertexPosition");
	_textureProgram.addAttribute("vertexColor");
	_textureProgram.addAttribute("vertexUV");
	_textureProgram.linkShaders();


	/*_colorProgram.compilerShaders("Shaders/colorShading.vert", "Shaders/colorShading.frag");
	_colorProgram.addAttribute("vertexPosition");
	_colorProgram.addAttribute("vertexColor");
	_colorProgram.addAttribute("vertexUV");
	_colorProgram.linkShaders();*/
}

void MainGame::gameLoop() {
	
	Bengine::FpsLimiter fpsLimiter;
	fpsLimiter.setMaxFPS(60.0f);

	while (_gameState == GameState::PLAY) {
		fpsLimiter.begin();

		processInput();
		_camera.update();


		drawGame();

		_fps = fpsLimiter.end();
	}
}

void MainGame::processInput() {
    SDL_Event evnt;

    // Will keep looping until there are no more events to process
    while (SDL_PollEvent(&evnt)) {
        switch (evnt.type) {
            case SDL_QUIT:
                // Exit the game here!
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

	_textureProgram.use();

	// Draw code goes here
	glActiveTexture(GL_TEXTURE0);

	// Make sure the shader uses texture 0

	GLint textureUniform = _textureProgram.getUniformLocation("mySampler");
	glUniform1i(textureUniform, 0);


	// Grab the camera matrix
	glm::mat4 projectionMatrix = _camera.getCameraMatrix();
	GLint pUniform = _textureProgram.getUniformLocation("P");
	glUniformMatrix4fv(pUniform, 1, GL_FALSE, &projectionMatrix[0][0]);

	// Draw the level
	_levels[_currentLevel]->draw();

	// Begin drawing agents
	_agentSpriteBatch.begin();

	//Draw the humans
	for (int i = 0; i < _humans.size(); i++) {
		_humans[i]->draw(;)
	}
	
	_agentSpriteBatch.end();

	_agentSpriteBatch.renderBatch();

	_textureProgram.unuse();

	// Swap our buffer and draw everything to the screen!
	_window.swapBuffer();

	//_textureProgram.linkShaders();
}
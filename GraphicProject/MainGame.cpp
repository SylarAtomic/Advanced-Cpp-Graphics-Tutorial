#include "MainGame.h"
#include "Errors.h"

#include <iostream>
#include <string>



MainGame::MainGame() : _screenWidth(1024), 
						_screenHight(768), 
						_window(nullptr), 
						_time(0), 
						_gameState(GameState::PLAY)
{

}


MainGame::~MainGame()
{
}


void MainGame::run()
{
	initSystems();

	//Initialize our sprite. (temporary)
	_sprites.push_back(new Sprite());
	_sprites.back()->init(-1.0f, -1.0f, 1.0f, 1.0f, "Textures/jummyJump_pack/PNG/CharacterRight_Standing.png");

	_sprites.push_back(new Sprite());
	_sprites.back()->init(0.0f, -1.0f, 1.0f, 1.0f, "Textures/jummyJump_pack/PNG/CharacterRight_Standing.png");

	for (int i = 0; i < 1000; i++)
	{
		_sprites.push_back(new Sprite());
		_sprites.back()->init(-1.0f, 0.0f, 1.0f, 1.0f, "Textures/jummyJump_pack/PNG/CharacterRight_Standing.png");
	}
	

//	_playerTexture = ImageLoader::loadPNG("Textures/jummyJump_pack/PNG/CharacterRight_Standing.png");

	//This only returns when the game ends
	gameLoop();
}

void MainGame::initSystems()
{	//Initialize SDL
	SDL_Init(SDL_INIT_EVERYTHING);

	_window = SDL_CreateWindow("Game Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _screenWidth, _screenHight,SDL_WINDOW_OPENGL);
	if (_window == nullptr) {
		fatalError("SDL Window could not be created!");
	}

	SDL_GLContext glContext = SDL_GL_CreateContext(_window);
	if (glContext == nullptr) {
		fatalError("SDL_GL context could not be created!");
	}

	GLenum error = glewInit();
	if (error != GLEW_OK) {
		fatalError("Could not initialize glue");
	}

	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	initShaders();

}

void MainGame::initShaders()
{
	_colorProgram.compilerShaders("Shaders/colorShading.vert", "Shaders/colorShading.frag");
	_colorProgram.addAttribute("vertexPosition");
	_colorProgram.addAttribute("vertexColor");
	_colorProgram.addAttribute("vertexUV");
	_colorProgram.linkShaders();
}

void MainGame::gameLoop()
{
	while (_gameState != GameState::EXIT) {
		processInput();
		_time += 0.01;
		drawGame();
	}

}

void MainGame::processInput()
{
	SDL_Event evnt;

	while (SDL_PollEvent(&evnt)) {
		switch (evnt.type) {
			case SDL_QUIT:
				_gameState = GameState::EXIT;
			break;
			case SDL_MOUSEMOTION:
				//std::cout << evnt.motion.x << " " << evnt.motion.y << std::endl;
			break;
		}
	}
}

void MainGame::drawGame() {
	
	
	//Set the base depth to 1.0
	glClearDepth(1.0);
	//Clear the color and depth buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	_colorProgram.use();
	glActiveTexture(GL_TEXTURE0);

	GLint textureLocation = _colorProgram.getUniformLocation("mySampler");
	glUniform1i(textureLocation, 0);

	GLint timeLocation = _colorProgram.getUniformLocation(("time"));
	glUniform1f(timeLocation, _time);

	//Draw our sprite!
	for (int i = 0; i < _sprites.size(); i++)
	{
		_sprites[i]->draw();
	}

	glBindTexture(GL_TEXTURE_2D, 0);
	_colorProgram.unuse();
	

	//Swap our buffer and draw everything to the screen!
	SDL_GL_SwapWindow(_window);
}

#pragma once

#include <Bengine\Window.h>
#include <BEngine\GLSLProgram.h>
#include <Bengine\Camera2D.h>
#include <Bengine\InputManager.h>

#include "Level.h"

enum class GameState {
	PLAY,
	EXIT
};


class MainGame
{
public:
    MainGame();
    ~MainGame();

    /// Runs the game
    void run();

private:
    /// Initializes the core systems
    void initSystems();
    /// Initializes the shaders
    void initShaders();

    /// Main game loop for the program
    void gameLoop();
    /// Handles input processing
    void processInput();
    /// Renders the game
    void drawGame();

private:
    /// Member Variables
    Bengine::Window _window; ///< The game window
	Bengine::GLSLProgram _textureProgram; ///< The shader program
	Bengine::InputManager _inputManager; ///< Handles input
    Bengine::Camera2D _camera; ///< Main Camera

	std::vector<Level*> _levels; // Vector of all levels

	int _screenWidth, _screenHeight;

	int _fps;

	GameState _gameState;
};


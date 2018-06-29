#pragma once

#include <Bengine\Window.h>
#include <BEngine\GLSLProgram.h>
#include <Bengine\Camera2D.h>
#include <Bengine\InputManager.h>
#include <Bengine/SpriteBatch.h>

#include "Player.h"
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

	/// Intilizies the lvel and sets up e verything
	void initLevel();

    /// Initializes the shaders
    void initShaders();

	/// Upadates all agents
	void updateAgents();

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

	Bengine::SpriteBatch _agentSpriteBatch; /// Draws all agents

	std::vector<Level*> _levels; // Vector of all levels

	int _screenWidth, _screenHeight;

	float _fps;

	int _currentLevel;

	Player* _player;
	std::vector<Human*> _humans; ///< Vector of all humans

	GameState _gameState;
};


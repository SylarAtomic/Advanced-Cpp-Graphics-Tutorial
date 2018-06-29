#include "Player.h"
#include <include/SDL/SDL.h>


Player::Player()
{
}


Player::~Player()
{
}

void Player::init(float speed, glm::vec2 pos, Bengine::InputManager* inputManager)
{
	_speed = speed;
	_position = pos;
	_inputManager = inputManager;
	_color.r = 0;
	_color.g = 0;
	_color.b = 185;
	_color.a = 255;
}

void Player::update(){
	if (_inputManager->isKeyPressed(SDLK_w)) {
		_position.y += _speed;
	}
	else if (_inputManager->isKeyPressed(SDLK_s)) {
		_position.y -= _speed;
	}
	if (_inputManager->isKeyPressed(SDLK_a)) {
		_position.x -= _speed;
	}
	else if (_inputManager->isKeyPressed(SDLK_d)) {
		_position.x += _speed;
	}
// May need to change inputManager to _inputManager or back?
}

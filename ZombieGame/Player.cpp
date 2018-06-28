#include "Player.h"
#include <include/SDL/SDL.h>


Player::Player()
{
}


Player::~Player()
{
}

void Player::init(int speed, glm::vec2 pos)
{
	_speed = speed;
	_position = pos;
	_color.r = 0;
	_color.g = 0;
	_color.b = 128;
	_color.a = 255;
}

void Player::update(Bengine::InputManager& inputManager){
	if (inputManager.isKeyPressed(SDLK_w)) {
		_position.x += _speed;
	}
	else if (inputManager.isKeyPressed(SDLK_s)) {
		_position.x -= _speed;
	}
	if (inputManager.isKeyPressed(SDLK_a)) {
		_position.y -= _speed;
	}
	else if (inputManager.isKeyPressed(SDLK_d)) {
		_position.y += _speed;
	}
}

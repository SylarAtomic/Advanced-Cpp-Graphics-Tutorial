#pragma once

#include "Human.h"
#include <Bengine/InputManager.h>

class Player : public Human
{
public:
	Player();
	~Player();

	void init(int speed, glm::vec2 pos);

	void update(Bengine::InputManager& inputManager);

};


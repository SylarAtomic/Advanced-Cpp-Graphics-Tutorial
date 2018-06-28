#pragma once

#include <glm/glm.hpp>
#include <Bengine/SpriteBatch.h>

const float AGENT_WIDTH = 60;

class Agent
{
public:
	Agent();
	virtual ~Agent();

	void draw(Bengine::SpriteBatch& _spriteBatch);

protected:
	glm::vec2 _position;
	Bengine::Color _color;
	float _speed;
};


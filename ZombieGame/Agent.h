#pragma once

#include <glm/glm.hpp>
#include <Bengine/SpriteBatch.h>

const float AGENT_WIDTH = 60;

class Agent
{
public:
	Agent();
	virtual ~Agent();

	virtual void update() = 0;

	void draw(Bengine::SpriteBatch& _spriteBatch);

	glm::vec2 getPosition() const { return _position; }

protected:
	glm::vec2 _position;
	Bengine::Color _color;
	float _speed;
};


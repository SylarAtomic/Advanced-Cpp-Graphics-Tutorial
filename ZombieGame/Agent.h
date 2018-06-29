#pragma once

#include <glm/glm.hpp>
#include <Bengine/SpriteBatch.h>

const float AGENT_WIDTH = 60;

class Zombie;
class Human;

class Agent
{
public:
	Agent();
	virtual ~Agent();

	virtual void update(const std::vector<std::string>& levelData,
						std::vector<Human*>& humans,
						std::vector<Zombie*>& zombies) = 0;

	void collideWithLevel(const std::vector<std::string>& levelData);


	void draw(Bengine::SpriteBatch& _spriteBatch);

	glm::vec2 getPosition() const { return _position; }

protected:
	glm::vec2 _position;
	Bengine::Color _color;
	float _speed;
};


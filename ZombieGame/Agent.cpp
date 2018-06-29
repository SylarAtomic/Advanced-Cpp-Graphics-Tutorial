#include "Agent.h"
#include <Bengine/ResourceManager.h>
#include "Level.h"


Agent::Agent()
{
}


Agent::~Agent()
{
}

void Agent::collideWithLevel(const std::vector<std::string>& levelData){
	
	std::vector<glm::vec2> collideTilePosition;

	// Check the four corners
	glm::vec2 cornerPos = _position;

}

void Agent::draw(Bengine::SpriteBatch & _spriteBatch){

	static int textureID = Bengine::ResourceManager::getTexture("Textures/circle.png").id;

	const glm::vec4 uvRect(0.0f, 0.0f, 1.0f, 1.0f);
	
	glm::vec4 destRect;
	destRect.x = _position.x;
	destRect.y = _position.y;
	destRect.z = AGENT_WIDTH;
	destRect.w = AGENT_WIDTH;

	_spriteBatch.draw(destRect, uvRect, textureID, 0.0f, _color);
}

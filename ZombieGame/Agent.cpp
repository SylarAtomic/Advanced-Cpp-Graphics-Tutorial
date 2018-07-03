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
	// First corner
	checkTilePosition(levelData,
					collideTilePosition,
					_position.x,
					_position.y);
	// Second corner
	checkTilePosition(levelData,
					collideTilePosition,
					_position.x + AGENT_WIDTH,
					_position.y);
	// Third corner
	checkTilePosition(levelData,
		collideTilePosition,
		_position.x,
		_position.y + AGENT_WIDTH);
	// Fourth corner
	checkTilePosition(levelData,
		collideTilePosition,
		_position.x + AGENT_WIDTH,
		_position.y + AGENT_WIDTH);

	for (int i = 0; i < collideTilePosition.size(); i++) {
		collideWithTile(collideTilePosition[i]);
	}

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

void Agent::checkTilePosition(	const std::vector<std::string>& levelData,
								std::vector<glm::vec2>& collideTilePosition, 
								float x, 
								float y){

	glm::vec2 cornerPos = glm::vec2(floor(x / (float)TILE_WIDTH),
									floor(y / (float)TILE_WIDTH));

	if (levelData[cornerPos.y][cornerPos.y] != '.') {
		collideTilePosition.push_back(cornerPos  * (float)TILE_WIDTH + glm::vec2((float)TILE_WIDTH/2.0f));
	}


}
// AABB collision
void Agent::collideWithTile(glm::vec2 tilePos){
	
	const float AGENT_RADIUS = (float)AGENT_WIDTH / 2.0f;
	const float TILE_RADIUS = (float)TILE_WIDTH / 2.0f;
	const float MIN_DISTANCE = AGENT_RADIUS + TILE_RADIUS;

	glm::vec2 distVec = _position - tilePos;

	float xDepth = MIN_DISTANCE - distVec.x;
	float yDepth = MIN_DISTANCE - distVec.y;

	float absXDepth = abs(xDepth);
	float absYDepth = abs(yDepth);


	if (xDepth > 0 || yDepth > 0) {
		if (absXDepth < absYDepth) {
			_position += xDepth;
		}
		else {
			_position += yDepth;
		}
	}
}

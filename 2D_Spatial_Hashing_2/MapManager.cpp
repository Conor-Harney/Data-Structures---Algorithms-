#include "stdafx.h"
#include "MapManager.h"

// Constructor method for the MapManager (see step 2 in the assignment)
MapManager::MapManager() {
	
	for(int i = 0; i < DemoConstants::ROWS * DemoConstants::COLUMNS; i++){
		list< CustomSprite const *> temp;
		m_buckets[i] = temp;
	}

}

void MapManager::initMap(list<CustomSprite>* spriteList){

	while (spriteList->size() > 0)
	{

		registerSprite(spriteList->front());
		spriteList->pop_front();
	}
}

// Clear each entry in the map (step 3 in the assignment)
void MapManager::clearBucketLists() {	
	// TODO: Implement logic here...
	for (int i = 0; i < m_buckets.size(); i++)
	{
		m_buckets[i].clear();
	}
}

// Register the given sprite in the map (step 5 in the assignment)
void MapManager::registerSprite( CustomSprite const & sprite ) {
	list<int> cellIds = getBucketId( sprite );
	while(cellIds.size() > 0){
		m_buckets.at(cellIds.front()).push_back(& sprite);
		cellIds.pop_front();
	}
	// TODO: Implement logic here...
}
	
// For each sprite corner, call the AddSpriteToBucket member function below. 
// See step 4 in the assignment for further details.
list<int> MapManager::getBucketId(CustomSprite const & sprite) {
	// A list of bucket id's that the given sprite is in.
	list<int> bucketsSpriteIsIn;

	// TODO: Implement logic here...
	//float t_size = sprite.getSize().x;
	float maxX = sprite.getPosition().x + (sprite.Size.x /2);
	float minX = sprite.getPosition().x - (sprite.Size.x /2);
	float maxY = sprite.getPosition().y + (sprite.Size.y /2);
	float minY = sprite.getPosition().y - (sprite.Size.y /2);
	list<sf::Vector2f> cornersList;
	
	cornersList.push_back(sf::Vector2f(minX, maxY));
	cornersList.push_back(sf::Vector2f(maxX, maxY));
	cornersList.push_back(sf::Vector2f(minX, minY));
	cornersList.push_back(sf::Vector2f(maxX, minY));

	while(cornersList.size() > 0){
		addSpriteToBucket(cornersList.front(), bucketsSpriteIsIn);
		cornersList.pop_front();
	}
	bucketsSpriteIsIn.sort();
	bucketsSpriteIsIn.unique();
	return bucketsSpriteIsIn;
}

// For the given sprite corner, work out which bucket the sprite should be added to, then
//  add it's bucketid to the list.
void MapManager::addSpriteToBucket( sf::Vector2f spriteCorner, list<int> & bucketsSpriteIsIn ) {
	// TODO: Implement logic here...
	int currentBucket = 0;
	sf::Vector2f cc = spriteCorner;
	for(int i = DemoConstants::CELLSIZE; cc.y > i; i += DemoConstants::CELLSIZE){currentBucket += DemoConstants::COLUMNS;}
	for(int i = DemoConstants::CELLSIZE; cc.x > i; i += DemoConstants::CELLSIZE){currentBucket++;}

	bucketsSpriteIsIn.push_back(currentBucket);
	
}

// Returns a list of nearby sprites for the given sprite (step 6 in the assignment).
list<CustomSprite const *> MapManager::getNearbySprites( CustomSprite const & sprite ) {
	// The list of nearby sprites to return.
	list<CustomSprite const *> nearbySprites;
	list<int> ids = getBucketId(sprite);
	while(ids.size() > 0){
		list<CustomSprite const*> curBucketSprites = m_buckets.at(ids.front());
		while(curBucketSprites.size() > 0){
			nearbySprites.push_front(curBucketSprites.front());
			curBucketSprites.pop_front();
		}
		ids.pop_front();
	}
	nearbySprites.sort();
	nearbySprites.unique();
	// TODO: Implement logic here...
	
	return nearbySprites;
}

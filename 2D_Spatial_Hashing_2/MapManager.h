#ifndef MAPMANAGER_H
#define MAPMANAGER_H

#include "DemoConstants.h"
#include "CustomSprite.h"

#include <map>
#include <list>
#include <algorithm> // for STL find()

using std::list;
using std::map;

// See MapManager.cpp for instructions on each member function below.

class MapManager {
public:

	MapManager();
	void initMap(list<CustomSprite>* spriteList);

	void clearBucketLists();

	void registerSprite( CustomSprite const & sprite );


	list<CustomSprite const*> getNearbySprites( CustomSprite const & sprite );
	map< int, list< CustomSprite const *> > m_buckets;

private:

	

	list<int> getBucketId( CustomSprite const & sprite );	

	void addSpriteToBucket( sf::Vector2f spriteCorner, list<int> & bucketsSpriteIsIn );

};

#endif
#ifndef SPRITEMANAGER_H
#define SPRITEMANAGER_H

#include "CustomSprite.h"
#include "DemoConstants.h"
#include <vector>
#include <map>
#include <math.h>
#include <cmath>
#include <list>

using std::vector;
using std::map;

class SpriteManager {
public:
	SpriteManager();

	vector<CustomSprite> & getAllSprites();
	void keepInBounds();
	void updateSprites();
	void sellectSprite(sf::Vector2f &cursorPos);
	void colourNearSprites(std::list<CustomSprite const *> nearSpriteList);
	CustomSprite * m_targetSprite;

private:
	vector<CustomSprite> m_sprites;
	static int const M_SPEED = 100;
	
};

#endif
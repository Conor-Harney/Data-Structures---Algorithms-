#include "stdafx.h"
#include "SpriteManager.h"

// Adds DemoConstants::NUM_SPRITES to a container, each sprite has a random screen position
//  and direction vector.
SpriteManager::SpriteManager() {
	m_targetSprite = 0;
	for (int i = 0 ; i < DemoConstants::NUM_SPRITES; ++i) {
		CustomSprite sprite;
		sprite.spriteIDNum = i;
		sprite.setScale( sf::Vector2f(0.5f, 0.5f) );
		 int x = rand() % static_cast<int> ( ( DemoConstants::SCREEN_WIDTH - sprite.getGlobalBounds().width ));
		 
		sprite.setPosition( rand() % static_cast<int> ( ( DemoConstants::SCREEN_WIDTH - sprite.getGlobalBounds().width ) ), 
			rand() % static_cast<int> ( ( DemoConstants::SCREEN_HEIGHT - sprite.getGlobalBounds().height ) ) );	   	
		sf::Vector2f pos = sprite.getPosition();

		// Give each sprite a random direction vector.
		float randXDir = ( rand() % 10 ) / 1000.0f * M_SPEED;
		float randYDir = ( rand() % 10 ) / 1000.0f * M_SPEED;
		sprite.setDirection( sf::Vector2f( randXDir + 0.01, randYDir + 0.01 ) );
		m_sprites.push_back( sprite );
	}	
}

vector<CustomSprite> & SpriteManager::getAllSprites() {
	return m_sprites;
}

// Iterate through the sprite container, and make sure each sprite stays within the
//  dimensions of the display (i.e. from 0,0 to DemoConstants::SCREEN_WIDTH, DemoConstants::SCREEN_HEIGHT)
void SpriteManager::keepInBounds() {	
	for(int i = 0; i < DemoConstants::NUM_SPRITES; i++){
		sf::Vector2f curPos = m_sprites.at(i).getPosition();
		sf::Vector2f newPos = sf::Vector2f(0,0);
		sf::Vector2u const sptSz = m_sprites.at(i).getSize();
		sf::Vector2f dir = m_sprites.at(i).getDirection();

		if (curPos.x + (sptSz.x / 2) > DemoConstants::SCREEN_WIDTH){//correct for offset 
			float temp = (curPos.x + (sptSz.x / 2)) - DemoConstants::SCREEN_WIDTH;
			temp = curPos.x - temp;
			m_sprites.at(i).setPosition(temp, curPos.y);
			dir = sf::Vector2f(-dir.x, dir.y);
		}
		else if (curPos.x < 0){
			float temp = (curPos.x);
			temp = curPos.x - temp;
			m_sprites.at(i).setPosition(temp, curPos.y);
			dir = sf::Vector2f(-dir.x, dir.y);
		} 
		if (curPos.y + (sptSz.y / 2) > DemoConstants::SCREEN_HEIGHT){//correct for 
			float temp = (curPos.y + (sptSz.y / 2)) - DemoConstants::SCREEN_HEIGHT;
			temp = curPos.y - temp;
			m_sprites.at(i).setPosition(curPos.x, temp);
			dir = sf::Vector2f(dir.x, -dir.y);
			
		}
		else if (curPos.y< 0){
			float temp = (curPos.y );
			temp = curPos.y - temp;
			m_sprites.at(i).setPosition(curPos.x, temp);
			dir = sf::Vector2f(dir.x, -dir.y);
		} 

		m_sprites.at(i).setDirection(dir);

		/*sf::Vector2f curPos = m_sprites.at(i).getPosition();
		sf::Vector2f curDir = m_sprites.at(i).getDirection();
		sf::Vector2u size = m_sprites.at(i).getSize();
		if(curPos.x - (size.x / 2) < 0 || curPos.x + (size.x / 2) > DemoConstants::SCREEN_WIDTH){
			curDir = sf::Vector2f(-curDir.x, curDir.y);
			if(curPos.x - (size.x / 2) < 0){m_sprites.at(i).setPosition(size.x / 2, curPos.y);}
			else{m_sprites.at(i).setPosition(DemoConstants::SCREEN_WIDTH - size.x / 2, curPos.y);}
		}
		else if(curPos.y - (size.y / 2) < 0 || curPos.y + (size.y / 2) > DemoConstants::SCREEN_HEIGHT){
			curDir = sf::Vector2f(curDir.x, -curDir.y);
			if(curPos.y - (size.y / 2) < 0){m_sprites.at(i).setPosition(curPos.x, size.y / 2);}
			else{m_sprites.at(i).setPosition(curPos.y, DemoConstants::SCREEN_HEIGHT - size.y / 2);}
		}
		m_sprites.at(i).setDirection(curDir);*/
	}
}

void SpriteManager::updateSprites(){
	for(int i = 0; i < DemoConstants::NUM_SPRITES; i++){
		m_sprites.at(i).update();	
	}
	keepInBounds();

}

void SpriteManager::sellectSprite(sf::Vector2f &cursorPos){
	sf::Vector2f cPos = cursorPos;
	sf::Vector2f sPos = m_sprites.at(0).getPosition();
	float curDist = sqrt( ( (cPos.x - sPos.x) * (cPos.x - sPos.x) ) + ( (cPos.y - sPos.y) * (cPos.y - sPos.y) ) );
	if(curDist < 0){curDist = - curDist;}
	float closestDist =  curDist;
	int spriteNum = 0;
	m_sprites.at(spriteNum).setColor(sf::Color(255, 255, 255, 255));
	m_sprites.at(spriteNum).target = false;

	for(int i = 1; i < m_sprites.size(); i++){
		m_sprites.at(i).setColor(sf::Color(255, 255, 255, 255));
		m_sprites.at(spriteNum).target = false;
		sf::Vector2f sPos = m_sprites.at(i).getPosition();
		float curDist = sqrt( ( (cPos.x - sPos.x) * (cPos.x - sPos.x) ) + ( (cPos.y - sPos.y) * (cPos.y - sPos.y) ) );
		if(curDist < 0){curDist = - curDist;}
		if(curDist < closestDist){spriteNum = i; closestDist = curDist;}
	}
	m_sprites.at(spriteNum).setColor(sf::Color(255, 0, 0, 255));
	m_sprites.at(spriteNum).target = true;
	m_targetSprite = &m_sprites.at(spriteNum);
}

void SpriteManager::colourNearSprites(std::list<CustomSprite const *> nearSpriteList){
	while(nearSpriteList.size() > 0){
		CustomSprite * curSprite;
		curSprite = const_cast<CustomSprite *>(nearSpriteList.front());
		curSprite->setColor(sf::Color(0,255,0));
		nearSpriteList.pop_front();
	}
}
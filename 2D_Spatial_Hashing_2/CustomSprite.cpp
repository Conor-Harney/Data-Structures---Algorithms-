#include "stdafx.h"
#include "CustomSprite.h"

sf::Texture CustomSprite::m_texture; 

bool CustomSprite::init(std::string const & imageFile) {
	//m_texture.
	return m_texture.loadFromFile(imageFile);
}

CustomSprite::CustomSprite(sf::Vector2f const & position, sf::Vector2f const & scale, sf::Vector2f const & dirVec) : 
	sf::Sprite(m_texture) {
		this->setScale(scale);
		this->setPosition(position);
		Size = m_texture.getSize();
		target = false;
	}


void CustomSprite::setDirection( sf::Vector2f const & dirVec ) {
	m_dirVec = dirVec;
}

sf::Vector2f const & CustomSprite::getDirection() const {
	return m_dirVec;
}

sf::Vector2u CustomSprite::getSize(){
	return m_texture.getSize();
}

void CustomSprite::update(){
	this->setPosition(this->getPosition() + m_dirVec);
}
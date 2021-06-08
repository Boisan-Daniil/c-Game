#pragma once

#include <SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<SFML/System.hpp>

class Base
{
protected:
	sf::Image image;
	sf::Texture texture;
	sf::Sprite sprite;
	int player; // 0 - левый игрок, 1 - правый.
	int health = 100;  //нужно забалансить

public:
	Base() :player(-1){};
	Base(int player,int x, int y):player(player) {

		if(player == 0)
			image.loadFromFile("img/building/buildig_CC_p1.png");
		else if (player ==1)
			image.loadFromFile("img/building/buildig_CC_p2.png");
		texture.loadFromImage(image);
		sprite.setTexture(texture);
		sprite.setPosition(x, y);
		
	}

	sf::Sprite getSprite()
	{
		return sprite;
	}

	int getHealth()
	{
		return health;
	}

	void getDamage(int damage)
	{
		health = health - damage;
	}
	void setHealth(int health)
	{
		this->health = health;
	}
};


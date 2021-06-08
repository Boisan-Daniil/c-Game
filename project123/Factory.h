#pragma once

#include <SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<SFML/System.hpp>
#include <iostream>

class Factory
{
	sf::Image image;
	sf::Texture texture;
	sf::Sprite sprite;

	int player; // 0 - левый игрок, 1 - правый.
	int damageBuff = 0;
public:
	Factory(int player, double x, double y) : player(player)
	{
		loadingImgaWhenSideCnanged();
		sprite.setPosition(x, y);
	}
	void MidControl(int player)
	{
		this->player = player;
		loadingImgaWhenSideCnanged();
	}

	void loadingImgaWhenSideCnanged()
	{
		if (player == 2)
			image.loadFromFile("img/building/buildig_atack_p0.png");
		else if (player == 1)
			image.loadFromFile("img/building/buildig_atack_p1.png");
		else if (player == 0)
			image.loadFromFile("img/building/buildig_atack_p2.png");
		texture.loadFromImage(image);
		sprite.setTexture(texture);
	}
	int getDamageBuff()
	{
		return damageBuff;
	}
	sf::Sprite getSprite()
	{
		return sprite;
	}
};

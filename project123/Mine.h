#pragma once

#include <SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<SFML/System.hpp>


class Mine
{
	sf::Image image;
	sf::Texture texture;
	sf::Sprite sprite;

	int player; // 0 - левый игрок, 1 - правый.
	int incomeBuff = 0;
public:
	Mine(int player, int x, int y) : player(player)
	{
		loadingImgaWhenSideCnanged();
		sprite.setPosition(x, y);
	}

	void ChangeLineControl(int player)
	{

		this->player = player;
		loadingImgaWhenSideCnanged();
	}

	

	void loadingImgaWhenSideCnanged()
	{
		if (player == 2)
			image.loadFromFile("FLAG");
		else if (player == 1)
			image.loadFromFile("FLAG");
		else if (player == 0)
			image.loadFromFile("FLAG");
		texture.loadFromImage(image);
		sprite.setTexture(texture);
	}

	int getIncomeBuff()
	{
		return incomeBuff;
	}

	sf::Sprite getSprite()
	{
		return sprite;
	}
};


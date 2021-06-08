#pragma once
#include <SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<SFML/System.hpp>
#include <iostream>
#include "Base.h"

class Tower :public Base
{
	int damage;
	int range;
	int line;

public:
	Tower(int health, int damage, int range, int line, int player) :
		 damage(damage), range(range),  line(line)
	{
		this->health = health;
		this->player = player;
		if (player == 0)
			image.loadFromFile("img/building/buildig_tower_p1.png");
		else if (player == 1)
			image.loadFromFile("img/building/buildig_tower_p2.png");

		texture.loadFromImage(image);
		sprite.setTexture(texture);

		if (player == 0)
		{
			if (line == 0)
			{
				sprite.setPosition(225, 1080 - 500);
			}
			else if (line == 1)
			{
				sprite.setPosition(525, 1080 - 500);
			}
			else if (line == 2)
			{
				sprite.setPosition(525, 1080 - 200);
			}
		}
		else if (player == 1)
		{
			if (line == 0)
			{
				sprite.setPosition(1495 - 300, -20);
			}
			else if (line == 1)
			{
				sprite.setPosition(1495 - 300, 300);
			}
			else if (line == 2)
			{
				sprite.setPosition(1550, 300);
			}
		}
	};

	void draw(sf::RenderWindow& window)
	{
		window.draw(sprite);
		std::cout << "Tower drawn" <<line<< std::endl;
	}

};


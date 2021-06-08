#pragma once
#include <SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<SFML/System.hpp>
#include <Windows.h>
#include <algorithm>
#include <iostream>
#include "Tower.h"
#include "Base.h"

class Unit
{
	sf::Image image;
	sf::Texture texture;
	sf::Sprite sprite;

	int player;
	int health=1;
	int damage=1;
	int price;
	int range;
	int line;
	int healthbuff = 0; //модификатор хп, что б новые юниты получали хп с бустом
	int damagebuff = 0; //модификатор урона, что б новые юниты получали урон с бустом

	int u_beg = 0;
	int u_end;

public:
	Unit() :health(1), damage(-1), price(-1), range(35), player(0), line(0) {};
	Unit( int price, int range, int player, int line) :
		price(price), range(range), line(line), player(player)
	{

		if (range == 35)
		{
			health = 25;
			damage = 5;
			if (player == 0)
				image.loadFromFile("img/unit/unit_v1_t1.png");
			else if (player == 1)
				image.loadFromFile("img/unit/unit_v2_t1.png");

			texture.loadFromImage(image);
			sprite.setTexture(texture);
		}

		else if (range == 125)
		{
			health = 20;
			damage = 25;

			if (player == 0)
				image.loadFromFile("img/unit/unit_v1_t2.png");
			else if (player == 1)
				image.loadFromFile("img/unit/unit_v2_t2.png");

			texture.loadFromImage(image);
			sprite.setTexture(texture);
		}

		else if (range == 200)
		{
			health = 15;
			damage = 20;

			if (player == 0)
				image.loadFromFile("img/unit/unit_v1_t3.png");
			else if (player == 1)
				image.loadFromFile("img/unit/unit_v2_t3.png");

			texture.loadFromImage(image);
			sprite.setTexture(texture);
		}
		

		if (player == 0)
		{
			sprite.setTextureRect(sf::IntRect(0, 0, 90, 119));
			sprite.setPosition(226, 949);
		}
			
		else if (player == 1)
		{
			sprite.setTextureRect(sf::IntRect(0,0,125,90));
			sprite.setPosition(1600, -5);
		}
			


	};

	int attack(std::vector<Unit>& u1, std::vector<Unit>& u2, Base &b1, Base &b2)// тут будем прописывать логику проверки и атаки с таймером. 
	{

		if (player == 0)
		{
			for (int i = 0; i < u2.size(); i++)
			{
				if (u2[i].sprite.getPosition().y >= sprite.getPosition().y)
				{
					if (u2[i].sprite.getPosition().x - sprite.getPosition().x <= range and u2[i].sprite.getPosition().y - sprite.getPosition().y <= range)
					{
						if (line == u2[i].getLine())
						{
							std::cout << "Target found Player 0 aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa" << std::endl;
							return i;
						}
					}
				}
				else
				{
					if (u2[i].sprite.getPosition().x - sprite.getPosition().x <= range and sprite.getPosition().y -  u2[i].sprite.getPosition().y <= range)
					{
						if (line == u2[i].getLine())
						{
							std::cout << "Target found Player 0 aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa" << std::endl;
							return i;
						}
					}
				}
			}

		

			if (b2.getSprite().getPosition().x - sprite.getPosition().x <= range and sprite.getPosition().y - b2.getSprite().getPosition().y <= range)
			{
				std::cout << "Target found base 2 aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa" << std::endl;
				return -2;
			}
			
		}

		else if (player == 1)
		{
			for (int i = 0; i < u1.size(); i++)
			{
				if (u1[i].sprite.getPosition().y >= sprite.getPosition().y)
				{
					if (sprite.getPosition().x - u1[i].sprite.getPosition().x <= range and u1[i].sprite.getPosition().y - sprite.getPosition().y   <= range)
					{
						if (line == u1[i].getLine())
						{
							std::cout << "Target found Player 1 aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa" << std::endl;
							return i;
						}
					}
				}
				else
				{
					if (u1[i].sprite.getPosition().x - sprite.getPosition().x <= range and sprite.getPosition().y - u1[i].sprite.getPosition().y <= range)
					{
						if (line == u1[i].getLine())
						{
							std::cout << "Target found Player 1 aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa" << std::endl;
							return i;
						}
					}
				}

			}

			if (sprite.getPosition().x - b1.getSprite().getPosition().x <= range and b1.getSprite().getPosition().y - sprite.getPosition().y  <= range)
			{
				std::cout << "Target found base 1 aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa" << std::endl;
				return -2;
			}
		}
		return -1;
	};

	void healthBuff(int n)
	{
		health = health + n; //тут нужно будет ещё сбаланасировать
	};
	void damageBuff(int n)
	{
		damage = damage + n; //тут нужно будет ещё сбаланасировать
	};



	void attacked(int damage) // сдесь передается итоговая формула дамага, но я думаю еще переделаем, что-то подозрительно выглядит
	{
		health = health - damage;
	}
	int getPrice()
	{
		return price;
	}
	int getDamage()
	{
		return damage + damagebuff;
	}
	
	int getHealth()
	{
		return health;
	}

	sf::Sprite getSprite()
	{
		return sprite;
	}

	sf::Vector2f getPos()
	{
		return sprite.getPosition();
	}

	int getRange()
	{
		return range;
	}

	int getLine()
	{
		return line;
	}

	void setRange(int range)
	{
		this->range = range;
	}

	void setLine(int line)
	{
		this->line = line;
	}

	void setPosition(int x,int y)
	{
		sprite.setPosition(x, y);
	}

	void setPlayer(int p)
	{
		player = p;
	}

	void move(std::vector<Unit>& u1, std::vector<Unit>& u2, Base &b1, Base &b2)
	{
		int enemy = attack(u1, u2, b1, b2);
		if (enemy == -1)
		{
			if (player == 0)
			{
				if (line == 0)
				{
					if (sprite.getPosition().y > -5)
					{
						sprite.move(0, -1);
						
					}

					else if (sprite.getPosition().x < 1590 and sprite.getPosition().y >= -5)
					{
						sprite.move(1, 0);
						
					}
				}
				else if (line == 1)
				{
					if (sprite.getPosition().y > 425 and sprite.getPosition().x < 750)
					{
						sprite.move(1, -1);
						
					}

					else if (sprite.getPosition().x < 1115)
					{
						sprite.move(1, 0);
					
					}
					else if (sprite.getPosition().x >= 1115 and sprite.getPosition().x <= 1475)
					{
						sprite.move(1, -1);
						
					}
				}
				else if (line == 2)
				{
					if (sprite.getPosition().x < 1590)
					{
						sprite.move(1, 0);
						
					}

					else if (sprite.getPosition().y > 50 and sprite.getPosition().x == 1590)
					{
						sprite.move(0, -1);
						
					}
				}
				
			}
			else if (player == 1)
			{
				if (line == 2)
				{
					if (sprite.getPosition().y < 949)
					{
						sprite.move(0, 1);
						
					}

					else if (sprite.getPosition().x > 1920 - 1590 and sprite.getPosition().y <= 950)
					{
						sprite.move(-1, 0);
						
					}
				}
				else if (line == 1)
				{
					if (sprite.getPosition().y < 680 and sprite.getPosition().x > 1170)
					{
						sprite.move(-1, 1);
						
					}

					else if (sprite.getPosition().x > 805)
					{
						sprite.move(-1, 0);
						
					}
					else if (sprite.getPosition().x <= 805 and sprite.getPosition().y <= 930)
					{
						sprite.move(-1, 1);
						
					}
				}
				else if (line == 0)
				{
					if (sprite.getPosition().x > 225)
					{
						sprite.move(-1, 0);
						
					}

					else if (sprite.getPosition().y < 950 and sprite.getPosition().x <= 225)
					{
						sprite.move(0, 1);
						
					}
				}
				
			}
		}

		else if (enemy == -2)
		{
			std::cout << "Bazu b'ut" << std::endl;

			u_end = clock();
			if (u_beg == 0)
			{
				u_beg = clock();
				if (player == 0) // драка против игрока 2
				{
					b2.getDamage(damage + damagebuff);
				}
				else if (player == 1) //драка против игрока 1
				{
					b1.getDamage(damage + damagebuff);
				}
			}
			if (clock() - u_beg >= 500)
			{
				u_beg = 0;
			}

		}

		else 
		{
			std::cout << "" << std::endl; //Special for Popov <3
			u_end = clock();
			if (u_beg == 0)
			{
				u_beg = clock();
				if (player == 0) // драка против игрока 2
				{
					u2[enemy].attacked(damage + damagebuff);
				}
				else if (player == 1) //драка против игрока 1
				{
					u1[enemy].attacked(damage + damagebuff);
				}
			}
			if (clock() - u_beg >= 500)
			{
				u_beg = 0;
			}	
		}
		
	}
};


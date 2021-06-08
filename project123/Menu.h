#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#pragma comment(lib, "ws2_32.lib")
#include <WinSock2.h>
#include <WS2tcpip.h>
#include <Windows.h>
#include <iostream>
#include <string>
#include <cstring>
#include "AllUi.h"

#pragma warning(disable: 4996)

void menuAb(sf::RenderWindow& window) {

	bool isMenu = true;
	
	int men = 0;
	// Текстуры кнопок + БГ
	sf::Texture menuAbout, menuButton;
	menuButton.loadFromFile("img/UI_MENU/button1.png");
	menuAbout.loadFromFile("img/UI_MENU/BG1.jpg");
	sf::Sprite menuA(menuAbout), menuB(menuButton);

	// Гружу текст + font к нему.

	sf::Text text1;
	sf::Text text4;
	sf::Font font1;
	sf::Font font2;
	font2.loadFromFile("img/Fonts/18710.otf");
	if (!font1.loadFromFile("img/UI_MENU/Roboto-Black.ttf"))
	{

	}
	text1.setFont(font1);
	text1.setString("CaHiTaPbI team \nUkrainian game development studio that presented you such projects as: \nStudent Catalog \nProduct Catalog \nOne-armed bandit and others .. \n Presents a new project - Battle for ITSTEP! \n\n\n\n\nDevelopers: \nBulbas Danyl \nLenin Bogdan \nStruk Nikita \nDaniil Boisan ");
	text1.setCharacterSize(24);
	text1.setFillColor(sf::Color::Red);
	text1.setPosition(380, 150);

	menuB.setPosition(850, 950);

	text4.setFillColor(sf::Color::Yellow);
	text4.setString("Back");
	text4.setFont(font2);
	text4.setCharacterSize(40);
	text4.setStyle(sf::Text::Bold | sf::Text::Underlined);
	text4.setPosition(920, 970);

	while (isMenu)
	{
		// Все так же как и в Главно Меню
		menuB.setColor(sf::Color::White);
		window.clear(sf::Color(129, 101, 221));
		men = 0;




		if (sf::IntRect(880, 950, 219, 90).contains(sf::Mouse::getPosition(window)))
		{
			menuB.setColor(sf::Color::Blue);
			men = 1;
		}


		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			if (men == 1)
			{
				isMenu = false;
			}
		}


		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.draw(menuA);
		window.draw(menuB);
		window.draw(text1);
		window.draw(text4);
		window.display();
	}




}



void mainMenu(sf::RenderWindow& window,bool &isOpen) {
	



	// Кнокпи + БГ
	sf::Texture menuStart, menuAbout, menuExit, menuBackg, Title,menuLoad;
	sf::Text text1, text2, text3,text4;
	menuStart.loadFromFile("img/UI_MENU/button1.png");
	menuAbout.loadFromFile("img/UI_MENU/button1.png");
	menuExit.loadFromFile("img/UI_MENU/button1.png");
	menuLoad.loadFromFile("img/UI_MENU/button1.png");
	menuBackg.loadFromFile("img/UI_MENU/BG1.jpg");
	Title.loadFromFile("img/UI_MENU/title.png");
	sf::Sprite menu1(menuStart), menu3(menuExit), menuBg(menuBackg), menu2(menuAbout), TitleSp(Title),menu4(menuLoad);
	sf::Font font;
	font.loadFromFile("img/Fonts/18710.otf");

	text4.setFillColor(sf::Color::Yellow);
	text4.setString("Load");
	text4.setFont(font);
	text4.setCharacterSize(40);
	text4.setStyle(sf::Text::Bold | sf::Text::Underlined);
	text4.setPosition(910, 320);

	text1.setFillColor(sf::Color::Yellow);
	text1.setString("Start");
	text1.setFont(font);
	text1.setCharacterSize(40);
	text1.setStyle(sf::Text::Bold | sf::Text::Underlined);
	text1.setPosition(900, 520);

	text2.setFillColor(sf::Color::Yellow);
	text2.setString("About");
	text2.setFont(font);
	text2.setCharacterSize(40);
	text2.setStyle(sf::Text::Bold | sf::Text::Underlined);
	text2.setPosition(900, 720);

	text3.setFillColor(sf::Color::Yellow);
	text3.setString("Exit");
	text3.setFont(font);
	text3.setCharacterSize(40);
	text3.setStyle(sf::Text::Bold | sf::Text::Underlined);
	text3.setPosition(920, 920);

	bool isMenu = true;
	int menuNum = 0;
	// Позиция кнопОЧЕК
	menu4.setPosition(850, 300);
	menu1.setPosition(850 , 500);
	menu2.setPosition(850, 700);
	menu3.setPosition(850, 900);
	

	TitleSp.setPosition(200, 60);

	///МЕНЮШКА///
	while (isMenu)
	{
		// При входе в цикл все кнопки стандартные(не имеют окраски)
		menu1.setColor(sf::Color::White);
		menu2.setColor(sf::Color::White);
		menu3.setColor(sf::Color::White);
		menu4.setColor(sf::Color::White);
		menuNum = 0;
		window.clear(sf::Color(129, 101, 221));


		// Если мы наводимся курсором на кнопку - то меняем значением переменной menunum  и окрыашываем кнопку
		if (sf::IntRect(850, 300, 219, 100).contains(sf::Mouse::getPosition(window))) {
			menu4.setColor(sf::Color::Blue);
			menuNum = 4;
		}
		if (sf::IntRect(850, 500, 219, 90).contains(sf::Mouse::getPosition(window))) {
			menu1.setColor(sf::Color::Blue);
			menuNum = 1;
		}
		if (sf::IntRect(850, 700, 219, 90).contains(sf::Mouse::getPosition(window))) {
			menu2.setColor(sf::Color::Blue);
			menuNum = 2;
		}
		if (sf::IntRect(850, 900, 219, 100).contains(sf::Mouse::getPosition(window))) {
			menu3.setColor(sf::Color::Blue);
			menuNum = 3;
		}

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) { // Если видим нажатие ЛКМ, то проверяем. Есть ли сейчас мышка на одной из кнопок
			if (menuNum == 1)
				isMenu = false; // Выход в игру
			if (menuNum == 2) {
				menuAb(window); // Меню разработчиков или "О программе"
			}


			if (menuNum == 3) {
				window.close();
				isMenu = false; // Выход из игры
			}
			if (menuNum == 4)
			{
				isOpen = true;
				isMenu = false;
			}
		}
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)		// Шоб не крашилось 
				window.close();
		}
		window.draw(menuBg);
		window.draw(menu1);
		window.draw(menu2);
		window.draw(menu3);
		window.draw(menu4);
		window.draw(TitleSp);
		window.draw(text1);
		window.draw(text2);
		window.draw(text3);
		window.draw(text4);
		window.display();
	}


}

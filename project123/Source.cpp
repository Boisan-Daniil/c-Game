#include "AllUi.h"
#include "ClientSideNetworking.h"
#include <thread>
#include <vector>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Battle for ITstep", sf::Style::Fullscreen);
    window.setKeyRepeatEnabled(false); //мб работает
    window.setVerticalSyncEnabled(true);
    std::vector<Unit> UnitsP1;
    std::vector<Unit> UnitsP2;

	bool isOpen = false;
    //std::thread th(chat); // Создание отдельного потока для чата
    UI(window); //Инициализация + всё  что один раз нужно

    mainMenu(window,isOpen);
    
    start = clock();
    window.clear();
	
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event)) //Вроде выход
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }        
        
        seconds = clock() - start - (minutes * 60 * 1000);
        seconds2 = seconds;
        if (seconds2 / 1000 >= 60)
        {
            bufftime = seconds % 1000;
            seconds2 = 0 + bufftime;
            seconds = seconds2;
            minutes++;
        }

        seconds /= 1000;
        endSpawn = clock();
        if (begSpawn == 0)
        {
            begSpawn = clock();
            GoldP1 += IncomeP1;
            GoldP2 += IncomeP2;
            for (int i = 0; i < 3; i++)
            {
                meleeP1.setLine(i);
                meleeP2.setLine(i);

                UnitsP1.push_back(meleeP1);
                UnitsP1[UnitsP1.size() - 1].damageBuff(AttackBuffP1);
                UnitsP1[UnitsP1.size() - 1].healthBuff(ArmorBuffP1);

                UnitsP2.push_back(meleeP2);
                UnitsP2[UnitsP2.size() - 1].damageBuff(AttackBuffP2);
                UnitsP2[UnitsP2.size() - 1].healthBuff(ArmorBuffP2);;
            }
            meleeP1.setLine(lineP1);
            meleeP2.setLine(lineP2);
        }
        if (endSpawn - begSpawn >= 15000)
        {
            begSpawn = 0;
        }
        
        if (isOpen == true)
        {
            load(UnitsP1, UnitsP2);
            isOpen = false;
            for (int i = 0; i < UnitsP1.size(); i++)
            {
                std::cout << UnitsP1[i].getSprite().getPosition().x << " " << UnitsP1[i].getSprite().getPosition().y << std::endl;
            }
            std::cout << "===" << std::endl;
            for (int i = 0; i < UnitsP2.size(); i++)
            {
                std::cout << UnitsP2[i].getSprite().getPosition().x << " " << UnitsP2[i].getSprite().getPosition().y << std::endl;
            }
        }

		
        UI_Func(window, UnitsP1, UnitsP2, minutes, seconds,b1, b2); //Отрисовка + функционал, работать с ней осторожно, находится в бесконечном цикле, если IQ<90 НЕ ЛЕЗЬ (Специально для Левина уточнил)

    
		move_attack_cycleP1(UnitsP1, UnitsP2, window); // Название функции говорит само за себя
		move_attack_cycleP2(UnitsP1, UnitsP2, window);
		checkBaseHealth(window); // Проверка ХП базы и присуждение победы игрокам
     
		save(UnitsP1, UnitsP2);  // Сохранение файла игры <3

        for (int i = 0; i < UnitsP1.size(); i++)
        {
            std::cout << UnitsP1[i].getSprite().getPosition().x << " " << UnitsP1[i].getSprite().getPosition().y << std::endl;
        }
        std::cout << "===" << std::endl;
        for (int i = 0; i < UnitsP2.size(); i++)
        {
            std::cout << UnitsP2[i].getSprite().getPosition().x << " " << UnitsP2[i].getSprite().getPosition().y << std::endl;
        }

        if (exitMenu == true)
        {
            UnitsP1.clear();
            UnitsP2.clear();
            f1.MidControl(2);
            b1.setHealth(1000);
            b2.setHealth(1000);
            GoldBuffP1 = 0;
            GoldBuffP2 = 0;
            AttackBuffP1 = 0;
            AttackBuffP2 = 0;
            ArmorBuffP1 = 0;
            ArmorBuffP2 = 0;
            
            exitWin = false;
            GoldP1 = 100;
            GoldP2 = 100;
            IncomeP1 = 100;
            IncomeP2 = 100;
            lineP1 = 1;
            lineP2 = 1;
            mainMenu(window,isOpen);
            exitMenu = false;
            start = 0;

            minutes = 0;
        }
        window.display();
    }        
    return 0;
}


#pragma once
#include "Menu.h"
#include "Unit.h"
#include "Factory.h"
#include "Tower.h"
#include "Mine.h"
#include <fstream>
// Áàôû

int GoldBuffP1 = 0;
int GoldBuffP2 = 0;
int AttackBuffP1 = 0;
int AttackBuffP2 = 0;
int ArmorBuffP1 = 0;
int ArmorBuffP2 = 0;

int GoldP1 = 100;
int GoldP2 = 100;
int IncomeP1 = 100;
int IncomeP2 = 100;

int s_beg = 0;
int s_end;



// Îáüÿâëåíèå ãëîáàëüíûõ ïåðåìåííûõ - òåêñòóð è ñïðàéòîâ
Unit meleeP1(35, 35, 0, 0); // 
Unit meleeP2(35, 35, 1, 0); // 

Unit rangeP1(85, 125, 0, 0); // 
Unit rangeP2(85, 125, 1, 0); // 

Unit siegeP1(200, 200, 0, 0); // 
Unit siegeP2(200, 200, 1, 0); // 


Unit meleeP11(35, 35, 0, 0); // 
Unit meleeP22(35, 35, 1, 0); // 

Unit rangeP11(85, 125, 0, 0); // 
Unit rangeP22(85, 125, 1, 0); // 

Unit siegeP11(200, 200, 0, 0); // 
Unit siegeP22(200, 200, 1, 0); // 


bool exitMenu = false;
bool exitWin = false;
std::string buffClock;

int lineP1 = 1;
int lineP2 = 1;

unsigned int minutes = 0;
unsigned int seconds;
float seconds2;
unsigned int begMeleeP1;
unsigned int begRangeP1;
unsigned int begSiegeP1;
unsigned int begArmP1;
unsigned int begAttP1;
unsigned int begGoP1;
unsigned int begBuP1;
unsigned int endMeleeP1;
unsigned int endRangeP1;
unsigned int endSiegeP1;
unsigned int endArmP1;
unsigned int endAttP1;
unsigned int endGoP1;
unsigned int endBuP1;
unsigned int begMeleeP2;
unsigned int begRangeP2;
unsigned int begSiegeP2;
unsigned int begArmP2;
unsigned int begAttP2;
unsigned int begGoP2;
unsigned int begBuP2;
unsigned int endMeleeP2;
unsigned int endRangeP2;
unsigned int endSiegeP2;
unsigned int endArmP2;
unsigned int endAttP2;
unsigned int endGoP2;
unsigned int endBuP2;
unsigned int begSpawn;
unsigned int endSpawn;
unsigned int start = 0;

int bufftime;
Factory f1(2, 880, 320);

Base b1(0, 225, 1080 - 150); //áàçû
Base b2(1, 1495, 0);

Tower t1p1(5, 5, 5, 0, 0);
Tower t2p1(5, 5, 5, 1, 0);
Tower t3p1(5, 5, 5, 2, 0);

Tower t1p2(5, 5, 5, 0, 1);
Tower t2p2(5, 5, 5, 1, 1);
Tower t3p2(5, 5, 5, 2, 1);

Mine mTop(2,226,-5);
Mine mBot(2,1590,949);


sf::Texture BG;
sf::Texture Melee;
sf::Texture Range;
sf::Texture Siege;
sf::Texture Melee2;
sf::Texture Range2;
sf::Texture Siege2;
sf::Texture Gold_Buff;
sf::Texture Attack_Buff;
sf::Texture Armor_Buff;
sf::Texture Building_Buff;
sf::Texture button;

sf::Font font;
sf::Text goldText;
sf::Text incomeText;;
sf::Text goldText2;
sf::Text incomeText2;
sf::Text upgrades;
sf::Text upgrades2;
sf::Text GoldBuff;
sf::Text AttackBuff;
sf::Text ArmorBuff;
sf::Text BuildingBuff;
sf::Text GoldBuff2;
sf::Text AttackBuff2;
sf::Text ArmorBuff2;
sf::Text BuildingBuff2;
sf::Text surrender;
sf::Text surrender2;
sf::Text LinetP1;
sf::Text LinetP2;
sf::Text Min;
sf::Text Sec;
sf::Text TGoldMP1;
sf::Text TGoldMP2;
sf::Text TIncomeP1;
sf::Text TIncomeP2;
sf::Text TAttackP1;
sf::Text TArmorP1;
sf::Text TGoldP1;
sf::Text TAttackP2;
sf::Text TArmorP2;
sf::Text TGoldP2;

sf::Sprite Melee_Sprite(Melee);
sf::Sprite Range_Sprite(Range);
sf::Sprite Siege_Sprite(Siege);
sf::Sprite Gold_Buff_Sprite(Gold_Buff);
sf::Sprite Attack_Buff_Sprite(Attack_Buff);
sf::Sprite Armor_Buff_Sprite(Armor_Buff);
sf::Sprite Building_Buff_Sprite(Building_Buff);

sf::Sprite Melee_Sprite2(Melee2);
sf::Sprite Range_Sprite2(Range2);
sf::Sprite Siege_Sprite2(Siege2);
sf::Sprite Gold_Buff_Sprite2(Gold_Buff);
sf::Sprite Attack_Buff_Sprite2(Attack_Buff);
sf::Sprite Armor_Buff_Sprite2(Armor_Buff);
sf::Sprite Building_Buff_Sprite2(Building_Buff);

sf::Sprite BG_sprite(BG);
sf::Sprite Surbutton_Spr(button);
sf::Sprite Surbutton2_Spr(button);

bool ex = true; // Test code! Check UI_func

           
std::string to_str(unsigned int n)
{
    char buf[40];
    sprintf(buf, "%d", n);
    return buf;
}

std::string to_str(int n)
{
    char buf[40];
    sprintf(buf, "%d", n);
    return buf;
}
// Ôóíêöèÿ çàãðóçêè òåêñòóð, óñòàíîâêà ïîçèöèé     
void UI(sf::RenderWindow& window)
{
    Melee.loadFromFile("img/UI/ico_v1_t1.png");
    Range.loadFromFile("img/UI/ico_v1_t2.png");
    Siege.loadFromFile("img/UI/ico_v1_t3.png");
    Melee2.loadFromFile("img/UI/ico_v2_t1.png");
    Range2.loadFromFile("img/UI/ico_v2_t2.png");
    Siege2.loadFromFile("img/UI/ico_v2_t3.png");
    Gold_Buff.loadFromFile("img/UI/buf_gold.png");
    Attack_Buff.loadFromFile("img/UI/buf_attack.png");
    Armor_Buff.loadFromFile("img/UI/buf_def.png");
    Building_Buff.loadFromFile("img/UI/buf_build.png");
    BG.loadFromFile("img/UI/BG_end.png");
    font.loadFromFile("img/Fonts/18710.otf");
    button.loadFromFile("img/UI_MENU/button1.png");

    Melee_Sprite.setTextureRect(sf::IntRect(0, 0, 114, 172));
    Range_Sprite.setTextureRect(sf::IntRect(0, 0, 114, 172));
    Siege_Sprite.setTextureRect(sf::IntRect(0, 0, 114, 172));
    Gold_Buff_Sprite.setTextureRect(sf::IntRect(0, 0, 60, 66));
    Attack_Buff_Sprite.setTextureRect(sf::IntRect(0, 0, 60, 66));
    Armor_Buff_Sprite.setTextureRect(sf::IntRect(0, 0, 60, 66));
    Building_Buff_Sprite.setTextureRect(sf::IntRect(0, 0, 60, 66));

    Melee_Sprite2.setTextureRect(sf::IntRect(0, 0, 114, 172));
    Range_Sprite2.setTextureRect(sf::IntRect(0, 0, 114, 172));
    Siege_Sprite2.setTextureRect(sf::IntRect(0, 0, 114, 172));
    Gold_Buff_Sprite2.setTextureRect(sf::IntRect(0, 0, 60, 66));
    Attack_Buff_Sprite2.setTextureRect(sf::IntRect(0, 0, 60, 66));
    Armor_Buff_Sprite2.setTextureRect(sf::IntRect(0, 0, 60, 66));
    Building_Buff_Sprite2.setTextureRect(sf::IntRect(0, 0, 60, 66));

    BG_sprite.setTextureRect(sf::IntRect(0, 0, 1920, 1080));
    Surbutton_Spr.setTextureRect(sf::IntRect(0, 0, 219, 101));
    Surbutton2_Spr.setTextureRect(sf::IntRect(0, 0, 219, 101));

    goldText.setFillColor(sf::Color::Yellow);
    goldText.setString("Gold:");
    goldText.setFont(font);
    goldText.setCharacterSize(40);
    goldText.setStyle(sf::Text::Bold | sf::Text::Underlined);
    goldText.setPosition(20, 20);

    incomeText.setFillColor(sf::Color::Yellow);
    incomeText.setString("Income:");
    incomeText.setFont(font);
    incomeText.setCharacterSize(40);
    incomeText.setStyle(sf::Text::Bold | sf::Text::Underlined);
    incomeText.setPosition(20, 150);

    goldText2.setFillColor(sf::Color::Yellow);
    goldText2.setString("Gold:");
    goldText2.setFont(font);
    goldText2.setCharacterSize(40);
    goldText2.setStyle(sf::Text::Bold | sf::Text::Underlined);
    goldText2.setPosition(1720, 20);

    incomeText2.setFillColor(sf::Color::Yellow);
    incomeText2.setString("Income:");
    incomeText2.setFont(font);
    incomeText2.setCharacterSize(40);
    incomeText2.setStyle(sf::Text::Bold | sf::Text::Underlined);
    incomeText2.setPosition(1720, 150);

    //2

    GoldBuff.setFillColor(sf::Color::Yellow);
    GoldBuff.setString("Gold Buff:");
    GoldBuff.setFont(font);
    GoldBuff.setCharacterSize(20);
    GoldBuff.setStyle(sf::Text::Bold | sf::Text::Underlined);
    GoldBuff.setPosition(10, 300);

    AttackBuff.setFillColor(sf::Color::Yellow);
    AttackBuff.setString("Attack Buff:");
    AttackBuff.setFont(font);
    AttackBuff.setCharacterSize(20);
    AttackBuff.setStyle(sf::Text::Bold | sf::Text::Underlined);
    AttackBuff.setPosition(10, 400);

    ArmorBuff.setFillColor(sf::Color::Yellow);
    ArmorBuff.setString("Armor Buff:");
    ArmorBuff.setFont(font);
    ArmorBuff.setCharacterSize(20);
    ArmorBuff.setStyle(sf::Text::Bold | sf::Text::Underlined);
    ArmorBuff.setPosition(10, 500);

    BuildingBuff.setFillColor(sf::Color::Yellow);
    BuildingBuff.setString("Build Buff:");
    BuildingBuff.setFont(font);
    BuildingBuff.setCharacterSize(20);
    BuildingBuff.setStyle(sf::Text::Bold | sf::Text::Underlined);
    BuildingBuff.setPosition(10, 600);

    GoldBuff2.setFillColor(sf::Color::Yellow);
    GoldBuff2.setString("Gold Buff:");
    GoldBuff2.setFont(font);
    GoldBuff2.setCharacterSize(20);
    GoldBuff2.setStyle(sf::Text::Bold | sf::Text::Underlined);
    GoldBuff2.setPosition(1710, 300);

    AttackBuff2.setFillColor(sf::Color::Yellow);
    AttackBuff2.setString("Attack Buff:");
    AttackBuff2.setFont(font);
    AttackBuff2.setCharacterSize(20);
    AttackBuff2.setStyle(sf::Text::Bold | sf::Text::Underlined);
    AttackBuff2.setPosition(1710, 400);

    ArmorBuff2.setFillColor(sf::Color::Yellow);
    ArmorBuff2.setString("Armor Buff:");
    ArmorBuff2.setFont(font);
    ArmorBuff2.setCharacterSize(20);
    ArmorBuff2.setStyle(sf::Text::Bold | sf::Text::Underlined);
    ArmorBuff2.setPosition(1710, 500);

    BuildingBuff2.setFillColor(sf::Color::Yellow);
    BuildingBuff2.setString("Build Buff :");
    BuildingBuff2.setFont(font);
    BuildingBuff2.setCharacterSize(20);
    BuildingBuff2.setStyle(sf::Text::Bold | sf::Text::Underlined);
    BuildingBuff2.setPosition(1710, 600);

    surrender.setFillColor(sf::Color::Red);
    surrender.setString("Surrender");
    surrender.setFont(font);
    surrender.setCharacterSize(30);
    surrender.setPosition(40, 1010);

    surrender2.setFillColor(sf::Color::Red);
    surrender2.setString("Surrender");
    surrender2.setFont(font);
    surrender2.setCharacterSize(30);
    surrender2.setPosition(1741, 1010);

    LinetP1.setFillColor(sf::Color::Yellow);
    LinetP1.setString("Mid");
    LinetP1.setFont(font);
    LinetP1.setCharacterSize(30);
    LinetP1.setStyle(sf::Text::Bold | sf::Text::Underlined);
    LinetP1.setPosition(82, 920);

    LinetP2.setFillColor(sf::Color::Yellow);
    LinetP2.setString("Mid");
    LinetP2.setFont(font);
    LinetP2.setCharacterSize(30);
    LinetP2.setStyle(sf::Text::Bold | sf::Text::Underlined);
    LinetP2.setPosition(1785, 920);

    Min.setString("000:");
    Min.setFont(font);
    Min.setCharacterSize(30);
    Min.setStyle(sf::Text::Bold | sf::Text::Underlined);
    Min.setPosition(900, 0);

    Sec.setString("00");
    Sec.setFont(font);
    Sec.setCharacterSize(30);
    Sec.setStyle(sf::Text::Bold | sf::Text::Underlined);
    Sec.setPosition(940, 0);
      //
    //6
    Melee_Sprite.setScale(0.6, 0.6);
    Melee_Sprite.setPosition(6, 686);//68
    Range_Sprite.setScale(0.6, 0.6);
    Range_Sprite.setPosition(74, 686);//68
    Siege_Sprite.setScale(0.6, 0.6);
    Siege_Sprite.setPosition(142, 686);
    //6
    Gold_Buff_Sprite.setScale(0.8, 0.8);
    Gold_Buff_Sprite.setPosition(6, 850); //53
    Attack_Buff_Sprite.setScale(0.8, 0.8);
    Attack_Buff_Sprite.setPosition(59, 850);//53
    Armor_Buff_Sprite.setScale(0.8, 0.8);
    Armor_Buff_Sprite.setPosition(112, 850); //53
    Building_Buff_Sprite.setScale(0.8, 0.8);
    Building_Buff_Sprite.setPosition(165, 850);

    Melee_Sprite2.setScale(0.6, 0.6);
    Melee_Sprite2.setPosition(1709, 686);
    Range_Sprite2.setScale(0.6, 0.6);
    Range_Sprite2.setPosition(1777, 686);
    Siege_Sprite2.setScale(0.6, 0.6);
    Siege_Sprite2.setPosition(1845, 686);

    Gold_Buff_Sprite2.setScale(0.8, 0.8);
    Gold_Buff_Sprite2.setPosition(1709, 850);
    Attack_Buff_Sprite2.setScale(0.8, 0.8);
    Attack_Buff_Sprite2.setPosition(1762, 850);
    Armor_Buff_Sprite2.setScale(0.8, 0.8);
    Armor_Buff_Sprite2.setPosition(1815, 850);
    Building_Buff_Sprite2.setScale(0.8, 0.8);
    Building_Buff_Sprite2.setPosition(1868, 850);

    TGoldMP1.setFillColor(sf::Color::Yellow);
    buffClock = to_str(GoldP1);
    TGoldMP1.setString(buffClock);
    TGoldMP1.setFont(font);
    TGoldMP1.setCharacterSize(40);
    TGoldMP1.setStyle(sf::Text::Bold);
    TGoldMP1.setPosition(30, 80);

    TGoldMP2.setFillColor(sf::Color::Yellow);
    buffClock = to_str(GoldP2);
    TGoldMP2.setString(buffClock);
    TGoldMP2.setFont(font);
    TGoldMP2.setCharacterSize(40);
    TGoldMP2.setStyle(sf::Text::Bold);
    TGoldMP2.setPosition(1730, 80);

    TIncomeP1.setFillColor(sf::Color::Yellow);
    buffClock = to_str(IncomeP1);
    TIncomeP1.setString(buffClock);
    TIncomeP1.setFont(font);
    TIncomeP1.setCharacterSize(40);
    TIncomeP1.setStyle(sf::Text::Bold);
    TIncomeP1.setPosition(30, 200);

    TIncomeP2.setFillColor(sf::Color::Yellow);
    buffClock = to_str(IncomeP2);
    TIncomeP2.setString(buffClock);
    TIncomeP2.setFont(font);
    TIncomeP2.setCharacterSize(40);
    TIncomeP2.setStyle(sf::Text::Bold | sf::Text::Underlined);
    TIncomeP2.setPosition(1730, 200);

    //
    TAttackP1.setFillColor(sf::Color::Yellow);
    buffClock = to_str(AttackBuffP1);
    TAttackP1.setString(buffClock);
    TAttackP1.setFont(font);
    TAttackP1.setCharacterSize(30);
    TAttackP1.setStyle(sf::Text::Bold | sf::Text::Underlined);
    TAttackP1.setPosition(30, 435);

    TAttackP2.setFillColor(sf::Color::Yellow);
    buffClock = to_str(AttackBuffP2);
    TAttackP2.setString(buffClock);
    TAttackP2.setFont(font);
    TAttackP2.setCharacterSize(30);
    TAttackP2.setStyle(sf::Text::Bold | sf::Text::Underlined);
    TAttackP2.setPosition(1730, 435);

    TArmorP1.setFillColor(sf::Color::Yellow);
    buffClock = to_str(ArmorBuffP1);
    TArmorP1.setString(buffClock);
    TArmorP1.setFont(font);
    TArmorP1.setCharacterSize(30);
    TArmorP1.setStyle(sf::Text::Bold | sf::Text::Underlined);
    TArmorP1.setPosition(30, 535);

    TArmorP2.setFillColor(sf::Color::Yellow);
    buffClock = to_str(ArmorBuffP2);
    TArmorP2.setString(buffClock);
    TArmorP2.setFont(font);
    TArmorP2.setCharacterSize(30);
    TArmorP2.setStyle(sf::Text::Bold | sf::Text::Underlined);
    TArmorP2.setPosition(1730, 535);

    TGoldP1.setFillColor(sf::Color::Yellow);
    buffClock = to_str(GoldBuffP1);
    TGoldP1.setString(buffClock);
    TGoldP1.setFont(font);
    TGoldP1.setCharacterSize(30);
    TGoldP1.setStyle(sf::Text::Bold | sf::Text::Underlined);
    TGoldP1.setPosition(30, 335);

    TGoldP2.setFillColor(sf::Color::Yellow);
    buffClock = to_str(GoldBuffP2);
    TGoldP2.setString(buffClock);
    TGoldP2.setFont(font);
    TGoldP2.setCharacterSize(30);
    TGoldP2.setStyle(sf::Text::Bold | sf::Text::Underlined);
    TGoldP2.setPosition(1730, 335);

    BG_sprite.setPosition(0, 0);
    Surbutton_Spr.setPosition(0, 979);
    Surbutton2_Spr.setPosition(1701, 979);
}

void UI_Func(sf::RenderWindow& window,  std::vector<Unit> &v1, std::vector<Unit>& v2, unsigned int min, unsigned int sec, Base& b1, Base& b2)
{
    window.draw(BG_sprite);
    window.draw(Melee_Sprite);
    window.draw(Range_Sprite);
    window.draw(Siege_Sprite);
    window.draw(Gold_Buff_Sprite);
    window.draw(Attack_Buff_Sprite);
    window.draw(Armor_Buff_Sprite);
    window.draw(Building_Buff_Sprite);
    window.draw(Melee_Sprite2);
    window.draw(Range_Sprite2);
    window.draw(Siege_Sprite2);
    window.draw(Gold_Buff_Sprite2);
    window.draw(Attack_Buff_Sprite2);
    window.draw(Armor_Buff_Sprite2);
    window.draw(Building_Buff_Sprite2);
    window.draw(goldText);
    window.draw(incomeText);
    window.draw(goldText2);
    window.draw(incomeText2);
    window.draw(GoldBuff);
    window.draw(GoldBuff2);
    window.draw(AttackBuff);
    window.draw(AttackBuff2);
    window.draw(ArmorBuff2);
    window.draw(ArmorBuff);
    window.draw(BuildingBuff2);
    window.draw(BuildingBuff);
    window.draw(Surbutton2_Spr);
    window.draw(Surbutton_Spr);
    window.draw(surrender);
    window.draw(surrender2);
    window.draw(LinetP1);
    window.draw(LinetP2);

    t1p1.draw(window);
    t2p1.draw(window);
    t3p1.draw(window);

    t1p2.draw(window);
    t2p2.draw(window);
    t3p2.draw(window);


    buffClock = to_str(GoldP1);
    TGoldMP1.setString(buffClock);
    window.draw(TGoldMP1);
    buffClock = to_str(GoldP2);
    TGoldMP2.setString(buffClock);
    window.draw(TGoldMP2);
    buffClock = to_str(IncomeP1);
    TIncomeP1.setString(buffClock);
    window.draw(TIncomeP1);
    buffClock = to_str(IncomeP2);
    TIncomeP2.setString(buffClock);
    window.draw(TIncomeP2);
    buffClock = to_str(AttackBuffP1 / 5);
    TAttackP1.setString(buffClock);
    window.draw(TAttackP1);
    buffClock = to_str(AttackBuffP2 / 5);
    TAttackP2.setString(buffClock);
    window.draw(TAttackP2);
    buffClock = to_str(ArmorBuffP1 / 5);
    TArmorP1.setString(buffClock);
    window.draw(TArmorP1);
    buffClock = to_str(ArmorBuffP2 / 5);
    TArmorP2.setString(buffClock);
    window.draw(TArmorP2);
    buffClock = to_str(GoldBuffP1 / 5);
    TGoldP1.setString(buffClock);
    window.draw(TGoldP1);
    buffClock = to_str(GoldBuffP2 / 5);
    TGoldP2.setString(buffClock);
    window.draw(TGoldP2);

    buffClock = to_str(min);
    if (min < 10)
        Min.setString("0" + buffClock + ":");
    else
        Min.setString(buffClock + ":");
    window.draw(Min);
    buffClock = to_str(sec);
    //std::cout << buffClock.str() << std::endl;
    if (sec < 10)
        Sec.setString("0" + buffClock);
    else
        Sec.setString(buffClock);
    window.draw(Sec);


    window.draw(f1.getSprite());
	window.draw(mTop.getSprite());
	window.draw(mBot.getSprite());
    window.draw(b1.getSprite());
    window.draw(b2.getSprite());
    


    if (sf::IntRect(0, 979, 219, 101).contains(sf::Mouse::getPosition(window))) // Melee button
    {
        
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            exitMenu = true;
        }
    }

    if (sf::IntRect(1701, 979, 219, 101).contains(sf::Mouse::getPosition(window))) // Range button
    {
        
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            exitMenu = true;
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
    {
        lineP1 = 2;
        LinetP1.setString("Bot");
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
    {
        lineP1 = 1;
        LinetP1.setString("Mid");
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
    {
        lineP1 = 0;
        LinetP1.setString("Top");
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad1))
    {
        lineP2 = 2;
        LinetP2.setString("Bot");
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad2))
    {
        lineP2 = 1;
        LinetP2.setString("Mid");
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad3))
    {
        lineP2 = 0;
        LinetP2.setString("Top");
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
    {
        if (GoldP1 - 35 >= 0)
        {
            endMeleeP1 = clock();
            if (begMeleeP1 == 0)
            {
                begMeleeP1 = clock();
                meleeP1.setLine(lineP1);
                v1.push_back(meleeP1);
                v1[v1.size() - 1].damageBuff(AttackBuffP1);
                v1[v1.size() - 1].healthBuff(ArmorBuffP1);
                IncomeP1 += 5;
                GoldP1 -= 35;
            }
            if (endMeleeP1 - begMeleeP1 >= 400)
            {
                begMeleeP1 = 0;
            }
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::I))
    {
        if (GoldP2 - 35 >= 0)
        {
            endMeleeP2 = clock();
            if (begMeleeP2 == 0)
            {
                begMeleeP2 = clock();
                meleeP2.setLine(lineP2);
                v2.push_back(meleeP2);
                v2[v2.size() - 1].damageBuff(AttackBuffP2);
                v2[v2.size() - 1].healthBuff(ArmorBuffP2);
                IncomeP2 += 5;
                GoldP2 -= 35;
            }
            if (endMeleeP2 - begMeleeP2 >= 400)
            {
                begMeleeP2 = 0;
            }
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        if (GoldP1 - 85 >= 0)
        {
            endRangeP1 = clock();
            if (begRangeP1 == 0)
            {
                begRangeP1 = clock();
                rangeP1.setLine(lineP1);
                v1.push_back(rangeP1);
                v1[v1.size() - 1].damageBuff(AttackBuffP1);
                v1[v1.size() - 1].healthBuff(ArmorBuffP1);
                IncomeP1 += 6;
                GoldP1 -= 85;
            }
            if (endRangeP1 - begRangeP1 >= 400)
            {
                begRangeP1 = 0;
            }
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::O))
    {
        if (GoldP2 - 85 >= 0)
        {
            endRangeP2 = clock();
            if (begRangeP2 == 0)
            {
                begRangeP2 = clock();
                rangeP2.setLine(lineP2);
                v2.push_back(rangeP2);
                v2[v2.size() - 1].damageBuff(AttackBuffP2);
                v2[v2.size() - 1].healthBuff(ArmorBuffP2);
                IncomeP2 += 6;
                GoldP2 -= 85;
            }
            if (endRangeP2 - begRangeP2 >= 400)
            {
                begRangeP2 = 0;
            }
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
    {
        if (GoldP1 - 200 >= 0)
        {
            endSiegeP1 = clock();
            if (begSiegeP1 == 0)
            {
                begSiegeP1 = clock();
                siegeP1.setLine(lineP1);
                v1.push_back(siegeP1);
                v1[v1.size() - 1].damageBuff(AttackBuffP1);
                v1[v1.size() - 1].healthBuff(ArmorBuffP1);
                IncomeP1 += 7;
                GoldP1 -= 200;
            }
            if (endSiegeP1 - begSiegeP1 >= 400)
            {
                begSiegeP1 = 0;
            }
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
    {
        if (GoldP2 - 200 >= 0)
        {
            endSiegeP2 = clock();
            if (begSiegeP2 == 0)
            {
                begSiegeP2 = clock();
                siegeP2.setLine(lineP2);
                v2.push_back(siegeP2);
                v2[v2.size() - 1].damageBuff(AttackBuffP2);
                v2[v2.size() - 1].healthBuff(ArmorBuffP2);
                IncomeP2 += 7;
                GoldP2 -= 200;
            }
            if (endSiegeP2 - begSiegeP2 >= 400)
            {
                begSiegeP2 = 0;
            }
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
    {
        if (GoldP1 - 120 >= 0)
        {
            endAttP1 = clock();
            if (begAttP1 == 0)
            {
                begAttP1 = clock();
                AttackBuffP1 += 5;
                GoldP1 -= 120;
            }
            if (endAttP1 - begAttP1 >= 400)
            {
                begAttP1 = 0;
            }
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::T))
    {
        if (GoldP1 - 120 >= 0)
        {
            endArmP1 = clock();
            if (begArmP1 == 0)
            {
                begArmP1 = clock();
                ArmorBuffP1 += 5;
                GoldP1 -= 120;
            }
            if (endArmP1 - begArmP1 >= 400)
            {
                begArmP1 = 0;
            }
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y))
    {
        if (GoldP1 - 200 >= 0)
        {
            endGoP1 = clock();
            if (begGoP1 == 0)
            {
                begGoP1 = clock();
                GoldBuffP1 += 5;
                IncomeP1 += 40;
                GoldP1 -= 200;
            }
            if (endGoP1 - begGoP1 >= 400)
            {
                begGoP1 = 0;
            }
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
    {
        if (GoldP2 - 120 >= 0)
        {
            endAttP2 = clock();
            if (begAttP2 == 0)
            {
                begAttP2 = clock();
                AttackBuffP2 += 5;
                GoldP2 -= 120;
            }
            if (endAttP2 - begAttP2 >= 400)
            {
                begAttP2 = 0;
            }
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::G))
    {
        if (GoldP2 - 120 >= 0)
        {
            endArmP2 = clock();
            if (begArmP2 == 0)
            {
                begArmP2 = clock();
                ArmorBuffP2 += 5;
                GoldP2 -= 120;
            }
            if (endArmP2 - begArmP2 >= 400)
            {
                begArmP2 = 0;
            }
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::H))
    {
        if (GoldP2 - 200 >= 0)
        {
            endGoP2 = clock();
            if (begGoP2 == 0)
            {
                begGoP2 = clock();
                GoldBuffP2 += 40;
                IncomeP2 += 40;
                GoldP2 -= 200;
            }
            if (endGoP2 - begGoP2 >= 400)
            {
                begGoP2 = 0;
            }
        }
    }
}

void move_attack_cycleP1(std::vector<Unit>& u1, std::vector<Unit>& u2, sf::RenderWindow& window)
{
	for (int i = 0; i < u1.size(); i++)
	{
		std::cout << u1.size() << "P1" << std::endl;
		window.draw(u1[i].getSprite());
        //u1[i].initialize(u1[i].getRange(), 0);
		u1[i].move(u1, u2, b1, b2);
		if (u1[i].getPos().x == 880 and u1[i].getPos().y == 425) // Êîíòðîëü çà ÌÈÄ 
			f1.MidControl(0);
		if (u1[i].getPos().x == 226 and u1[i].getPos().y == -5) // Êîíòðîëü çà ÒÎÏ
			mTop.ChangeLineControl(0);
		if (u1[i].getPos().x == 1590 and u1[i].getPos().y == 949) // Êîíòðîëü çà ÁÎÒ
			mBot.ChangeLineControl(0);
		if (u1[i].getHealth() <= 0 and u2.size() != 0)
		{
			GoldP2 += (u1.begin() + i)->getPrice() + 10;
			u1.erase(u1.begin() + i);

		}
	}
}

void move_attack_cycleP2(std::vector<Unit>& u1, std::vector<Unit>& u2, sf::RenderWindow& window)
{

	for (int i = 0; i < u2.size(); i++)
	{
		std::cout << u2.size() << "P2" << std::endl;
		window.draw(u2[i].getSprite());
        //u2[i].initialize(u2[i].getRange(),ö 1);
		u2[i].move(u1, u2, b1, b2);
		if (u2[i].getPos().x == 880 and u2[i].getPos().y == 425) // Êîíòðîëü çà ÌÈÄ 
			f1.MidControl(1);
		if (u2[i].getPos().x == 226 and u2[i].getPos().y == -5) // Êîíòðîëü çà ÒÎÏ
			mTop.ChangeLineControl(1);
		if (u2[i].getPos().x == 1600 and u2[i].getPos().y == 949) // Êîíòðîëü çà ÁÎT
			mBot.ChangeLineControl(1);
		if (u2[i].getHealth() <= 0 and u2.size() != 0)
		{
			GoldP1 += (u2.begin() + i)->getPrice() + 10;
			u2.erase(u2.begin() + i);
		}
	}

}

void checkBaseHealth(sf::RenderWindow& window)
{
    if (b1.getHealth() <= 0)   //////////////////////////////////////////////////////// ÒÓÒ ÃÎÐßÒ ÁÀÇÛ È ÌÎß ÆÆÆÆÆÆÆÆÆÆÆÆÆÆÆÆÆÆÆÆÆÆÆÆÆÆÆÆÆÆèçíü  <3
    {
        window.clear();
        sf::Texture menuBackg;
        menuBackg.loadFromFile("img/UI_MENU/BG1.jpg");
        sf::Sprite menuBg(menuBackg);
        sf::Text someText;
        someText.setFillColor(sf::Color::Yellow);
        someText.setString("\tPlayer 2 Win!\n\n\n\n\n\n\n Press Esc for Menu");
        someText.setFont(font);
        someText.setCharacterSize(50);
        someText.setStyle(sf::Text::Bold);
        someText.setPosition(650, 200);
        //bool exitM = true;
        while (window.isOpen())
        {

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                break;
            }

            window.draw(menuBg);
            window.draw(someText);
            window.display();

        }
        //std::cout << "Player 2 win" << std::endl;
        exitMenu = true;
    }

    if (b2.getHealth() <= 0)   //////////////////////////////////////////////////////// ÒÓÒ ÃÎÐßÒ ÁÀÇÛ È ÌÎß ÆÆÆÆÆÆÆÆÆÆÆÆÆÆÆÆÆÆÆÆÆÆÆÆÆÆÆÆÆÆèçíü  <3
    {
        window.clear();
        sf::Texture menuBackg;
        menuBackg.loadFromFile("img/UI_MENU/BG1.jpg");
        sf::Sprite menuBg(menuBackg);
        sf::Text someText;
        someText.setFillColor(sf::Color::Yellow);
        someText.setString("\tPlayer 1 Win!\n\n\n\n\n\n\n Press Esc for Menu");
        someText.setFont(font);
        someText.setCharacterSize(50);
        someText.setStyle(sf::Text::Bold);
        someText.setPosition(650, 200);
        //bool exitM = true;
        while (window.isOpen())
        {

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                break;
            }

            window.draw(menuBg);
            window.draw(someText);
            window.display();

        }

        //std::cout << "Player 1 win" << std::endl;
        exitMenu = true;
    }
}




void save(std::vector<Unit>& v1, std::vector<Unit>& v2)
{
    std::ofstream s("save.txt", std::ios_base::trunc); // save potok

    s_end = clock();
    if (s_beg == 0)
    {
        s_beg = clock(); //ss

        s << minutes * 60 + seconds << std::endl;
        s << v1.size() << std::endl;
        for (int i = 0; i < v1.size(); i++)
        {
            s << v1[i].getRange() << std::endl;
            s << v1[i].getLine() << std::endl;
            s << v1[i].getPos().x << std::endl;
            s << v1[i].getPos().y << std::endl;
        }

        s << v2.size() << std::endl;
        for (int i = 0; i < v2.size(); i++)
        {
            s << v2[i].getRange() << std::endl;
            s << v2[i].getLine() << std::endl;
            s << v2[i].getPos().x << std::endl;
            s << v2[i].getPos().y << std::endl;
        }
        s << GoldP1 << std::endl;
        s << GoldP2 << std::endl;
        s << "===================" << std::endl;
    }
    if (clock() - s_beg >= 1)
    {
        s_beg = 0;
    }
    
    s.close();
}

void load(std::vector<Unit>& v1, std::vector<Unit>& v2)
{
    std::ifstream in("save.txt");

    int size_p1 = 0;
    int size_p2 = 0;
	int sec = 0;
    
        in >> sec;
        in >> size_p1;
		std::cout << size_p1 << " sdaasfsafasjilhgfjlfdghjildfgijhgjgfhjahsfdsagfsahfasfashfasfhasfhkasfasfasfasfasjkfasgjkfgas" << std::endl;

        int buf_range = 0;
        int buf_line = 0;
        int buf_x = 0;
        int buf_y = 0;

        for (int i = 0; i < v1.size(); i++)
        {
            v1.erase(v1.begin() + i);
        }

        for (int i = 0; i < size_p1; i++)
        {
            in >> buf_range;
            in >> buf_line;
            in >> buf_x;
            in >> buf_y;

            if (buf_range == 35)
            {
                meleeP11.setLine(buf_line);
                meleeP11.setPosition(buf_x, buf_y);
                v1.push_back(meleeP11);
                
            }
            else if (buf_range == 125)
            {
                rangeP11.setLine(buf_line);
                rangeP11.setPosition(buf_x, buf_y);
                v1.push_back(rangeP11);

            }
            else if (buf_range == 200)
            {
                siegeP11.setLine(buf_line);
                siegeP11.setPosition(buf_x, buf_y);
                v1.push_back(siegeP11);

            }
        }
  
        int buf_range2 = 0;
        int buf_line2 = 0;
        int buf_x2 = 0;
        int buf_y2 = 0;

        in >> size_p2;

        for (int i = 0; i < v2.size(); i++)
        {
            v2.erase(v2.begin() + i);
        }

        for (int i = 0; i < size_p2; i++)
        {
            in >> buf_range2;
            in >> buf_line2;
            in >> buf_x2;
            in >> buf_y2;

            if (buf_range2 == 35)
            {
                meleeP22.setLine(buf_line2);
                meleeP22.setPosition(buf_x2, buf_y2);
                v2.push_back(meleeP22);

            }
            else if (buf_range2 == 125)
            {
                rangeP22.setLine(buf_line2);
                rangeP22.setPosition(buf_x2, buf_y2);
                v2.push_back(rangeP22);

            }
            else if (buf_range2 == 200)
            {
                siegeP22.setLine(buf_line2);
                siegeP22.setPosition(buf_x2, buf_y2);
                v2.push_back(siegeP22);

            }

        }

        in >> GoldP1;
        in >> GoldP2;

        std::string buff;
        in >> buff;
    

    in.close(); 
}

//Öîé æèâ
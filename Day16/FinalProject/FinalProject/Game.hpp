//
//  Game.hpp
//  FinalProject
//
//  Created by Ryan Mata on 9/21/22.
//

#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include "NPC.hpp"
#include "Corners.hpp"
#include "Player.hpp"

class Game
{
private:
    NPC npc;
    Corners corner;
    Player player;
    sf::RenderWindow* window;
    sf::Event event;
    sf::RectangleShape firstShape;
    sf::Vector2i mousePosWindow;
    sf::Vector2f mousePosView;
    int ptVal1 = 0;
    int ptVal2 = 150;
    int ptVal3 = 850;
    int ptVal4 = 1000;
    void initVariables();
    void initWindow();
    
public:
    //Constructors & Destructors
    Game();
    virtual ~Game();
    
    //Accessors
    const bool getWindowIsOpen() const;
    
    //Functions
    void pollEvents();
    void updateMousePos();
    void update();
    void render();
    
};

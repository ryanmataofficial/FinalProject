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
    sf::Font font;
    sf::Text text;
    sf::Text endGameText;
    sf::Text winGameText;
    sf::Texture WorldBkgTexture;
    sf::Sprite WorldBkg;
    sf::Clock clock;
    sf::Time time;
    bool inPosition = false;
    void initVariables();
    void initWindow();
    void initFont();
    void initText();
    void initWorld();
    
public:
    //Constructors & Destructors
    Game();
    virtual ~Game();
    
    const bool& getEndGame() const;
    
    //Accessors
    const bool getWindowIsOpen() const;
    
    //Functions
    void pollEvents();
    void statusPlayer();
    void updateMousePos();
    void update();
    void renderText(sf::RenderTarget& target);
    void renderWorld(sf::RenderTarget& target);
    void render();
    
};

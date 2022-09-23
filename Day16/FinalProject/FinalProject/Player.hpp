#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class Player {
private:
    
    sf::RectangleShape rectanglePlayer;
    float speed;
    void initVariables();
    void initShape();
    
public:
    Player(float x = 0.f, float y = 0.f);
    virtual ~Player();
    void updateInput();
    void updatePlayer();
    void renderPlayer(sf::RenderTarget& target);
};

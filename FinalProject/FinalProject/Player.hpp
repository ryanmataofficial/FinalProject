#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class Player {
private:
    
    
    float speed;
    void initVariables();
    void initShape();
    
public:
    sf::Sprite sprite;
    sf::Texture texture;
    Player(float x = 1400.f, float y = 650.f);
    virtual ~Player();
    void updateInput();
    void updatePlayer();
    void renderPlayer(sf::RenderTarget& target);
};

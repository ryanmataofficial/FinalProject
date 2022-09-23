#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <vector>

class Corners
{
private:
    
public:
    std::vector<sf::RectangleShape> allCorners;
    sf::RectangleShape corner;
    void initCorner();
    void initialSpawnCorner();
    void updateCorner();
    void renderCorner(sf::RenderTarget& target);
};

#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <vector>

class NPC
{
private:
    
public:
    //Game Logic
    float roundTimer;
    int removedSection;
    std::vector<sf::RectangleShape> allNPCs;
    sf::RectangleShape rectangleGuy;
    void initNPC();
    void initialSpawnNPCs();
    void updateNPCs();
    void renderNPCs(sf::RenderTarget& target);
};

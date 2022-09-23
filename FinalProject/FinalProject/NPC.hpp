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
    float direction;
    float roundTimer;
    int removedSection;
    bool endGame = false;
    bool winGame = false;
    std::vector<int> directions;
    std::vector<sf::RectangleShape> allNPCs;
    sf::RectangleShape rectangleGuy;
    /*sf::Sprite spriteNPC;
    sf::Texture textureNPC;
    std::vector<sf::Sprite> allSprites;;
    std::vector<sf::Texture> allTextures;*/
    void initNPC();
    void initialSpawnNPCs();
    void updateNPCs();
    void deleteNPCs();
    void renderNPCs(sf::RenderTarget& target);
};

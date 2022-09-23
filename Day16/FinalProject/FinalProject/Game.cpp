//
//  Game.cpp
//  FinalProject
//
//  Created by Ryan Mata on 9/21/22.
//

#include "Game.hpp"
#include "NPC.hpp"
#include "Corners.hpp"
#include "Player.hpp"
#include <ctime>

void Game::initVariables() {
    this->window = nullptr;
    this->npc.roundTimer = 0.f;
    this->npc.removedSection = 0;
}
void Game::initWindow() {
    this->window = new sf::RenderWindow(sf::VideoMode(1000, 1000), "The window", sf::Style::Titlebar | sf::Style::Close);
    this->window->setFramerateLimit(60);
}

Game::Game() {
    this->initVariables();
    this->initWindow();
    this->corner.initCorner();
    this->npc.initNPC();
}
Game::~Game() {
    delete this->window;
}


//Accessors
const bool Game::getWindowIsOpen() const {
    return this->window->isOpen();
}

//Functions
void Game::pollEvents() {
    while (this->window->pollEvent(this->event)) {
        if (this->event.type == sf::Event::Closed)
            this->window->close();
    }
}

void Game::updateMousePos() {
    this->mousePosWindow = sf::Mouse::getPosition(*this->window);
    this->mousePosView = this->window->mapPixelToCoords(this->mousePosWindow);
}

void Game::update() {
    this->pollEvents();
    this->updateMousePos();
    this->player.updatePlayer();
    this->corner.updateCorner();
    this->npc.updateNPCs();
    /*switch (npc.removedSection) {
        case 0:
            for (long i = npc.allNPCs.size() - 1; i >= 0; --i) {
                if (this->npc.allNPCs[i].getPosition().x <= 150 && this->npc.allNPCs[i].getPosition().y <= 150) {
                    npc.allNPCs.erase(npc.allNPCs.begin()+i);
                }
            }
            break;
        case 1:
            for (long i = npc.allNPCs.size() - 1; i >= 0; --i) {
                if (this->npc.allNPCs[i].getPosition().x >= 850 && this->npc.allNPCs[i].getPosition().y <= 150) {
                    npc.allNPCs.erase(npc.allNPCs.begin()+i);
                }
            }
            break;
        case 2:
            for (long i = npc.allNPCs.size() - 1; i >= 0; --i) {
                if (this->npc.allNPCs[i].getPosition().x <= 150 && this->npc.allNPCs[i].getPosition().y >= 850) {
                    npc.allNPCs.erase(npc.allNPCs.begin()+i);
                }
            }
            break;
        case 3:
            for (long i = npc.allNPCs.size() - 1; i >= 0; --i) {
                if (this->npc.allNPCs[i].getPosition().x >= 850 && this->npc.allNPCs[i].getPosition().y >= 850) {
                    npc.allNPCs.erase(npc.allNPCs.begin()+i);
                }
            }
            break;
    }*/
    
}
void Game::render() {
    this->window->clear(sf::Color::Black);
    this->corner.renderCorner(*this->window);
    this->npc.renderNPCs(*this->window);
    this->player.renderPlayer(*this->window);
    //this->npc.renderNPCs();
    this->window->display();
}

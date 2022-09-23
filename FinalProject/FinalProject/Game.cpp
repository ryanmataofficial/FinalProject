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
    this->npc.roundTimer = 10.f;
    this->npc.removedSection = rand() % 4;
    for (int i = 0; i < 10; ++i) {
        this->npc.direction = 0;
        while (this->npc.direction == 0) {
            this->npc.direction = rand() % 3 - 1;
        }
        npc.directions.push_back(npc.direction);
    }
    
}
void Game::initWindow() {
    this->window = new sf::RenderWindow(sf::VideoMode(3000, 1500), "The window", sf::Style::Titlebar | sf::Style::Close);
    this->window->setFramerateLimit(60);
}

void Game::initFont() {
    if(!this->font.loadFromFile("/Users/ryan.mata@divvypay.com/Downloads/roboto/Roboto-Medium.ttf")) {
        exit(0);
    }
}

void Game::initText() {
    this->text.setFont(this->font);
    this->text.setFillColor(sf::Color::Black);
    this->text.setCharacterSize(50);
    this->text.setPosition(sf::Vector2f(3000/4.0f,20.f));
    this->text.setString("NAVIGATE TO ONE OF THE FOUR CORNERS TO SEE IF YOU ARE LUCKY");
    
    this->endGameText.setFont(this->font);
    this->endGameText.setFillColor(sf::Color::Red);
    this->endGameText.setCharacterSize(100);
    this->endGameText.setPosition(sf::Vector2f(3000/5.0f,750.f));
    this->endGameText.setString("YOU PICKED THE WRONG SPOT! YOU LOSE!");
    
    this->winGameText.setFont(this->font);
    this->winGameText.setFillColor(sf::Color::Green);
    this->winGameText.setCharacterSize(100);
    this->winGameText.setPosition(sf::Vector2f(3000/5.0f,750.f));
    this->winGameText.setString("YOU PICKED THE RIGHT SPOT! YOU WIN!");
}

void Game::initWorld() {
    if(!this->WorldBkgTexture.loadFromFile("/Users/ryan.mata@divvypay.com/Downloads/bbcourt.jpeg")) {
        exit(0);
    }
    this->WorldBkg.setTexture(WorldBkgTexture);
    this->WorldBkg.scale(5.5f, 5.f);
}
Game::Game() {
    this->initVariables();
    this->initWindow();
    this->initWorld();
    this->initFont();
    this->initText();
    this->corner.initCorner();
    this->npc.initNPC();
    
}
Game::~Game() {
    delete this->window;
}

const bool& Game::getEndGame() const {
    return this->npc.endGame;
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

void Game::statusPlayer() {
    this->player.updatePlayer();
    if (this->player.sprite.getPosition().x <= 200 && this->player.sprite.getPosition().y <= 200) {
        this->inPosition = true;
        if (npc.removedSection == 0) {
            this->npc.endGame = true;
        }
    }
    else if (this->player.sprite.getPosition().x >= 2800 && this->player.sprite.getPosition().y <= 200) {
        this->inPosition = true;
        if (npc.removedSection == 1) {
            this->npc.endGame = true;
        }
    }
    else if (this->player.sprite.getPosition().x <= 200 && this->player.sprite.getPosition().y >= 1300) {
        this->inPosition = true;
        if (npc.removedSection == 2) {
            this->npc.endGame = true;
        }
    }
    else if (this->player.sprite.getPosition().x >= 2800 && this->player.sprite.getPosition().y >= 1300) {
        this->inPosition = true;
        if (npc.removedSection == 3) {
            this->npc.endGame = true;
        }
    }
}
void Game::updateMousePos() {
    this->mousePosWindow = sf::Mouse::getPosition(*this->window);
    this->mousePosView = this->window->mapPixelToCoords(this->mousePosWindow);
}

void Game::update() {
    this->pollEvents();
    
    if (this->npc.endGame == false) {
        this->updateMousePos();
        this->statusPlayer();
        this->corner.updateCorner();
        this->npc.updateNPCs();
        if (inPosition) {
            clock.restart();
            for(;clock.getElapsedTime().asSeconds() < 3.f;);
                npc.deleteNPCs();
            if (!npc.endGame) {
                npc.winGame = true;
            }
        }
    }
}

void Game::renderText(sf::RenderTarget& target) {
    target.draw(this->text);
}

void Game::renderWorld(sf::RenderTarget& target) {
    target.draw(this->WorldBkg);
}
void Game::render() {
    this->window->clear(sf::Color::Black);
    this->renderWorld(*this->window);
    this->corner.renderCorner(*this->window);
    this->npc.renderNPCs(*this->window);
    this->player.renderPlayer(*this->window);
    this->renderText(*this->window);
    
    if (npc.endGame) {
        this->window->draw(this->endGameText);
    }
    if (npc.winGame) {
        this->window->draw(this->winGameText);
    }
    this->window->display();
}

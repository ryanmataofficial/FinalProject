//
//  NPC.cpp
//  FinalProject
//
//  Created by Ryan Mata on 9/22/22.
//

#include "NPC.hpp"


void NPC::initNPC() {
    this->rectangleGuy.setSize(sf::Vector2f(50.f, 50.f));
    this->rectangleGuy.setFillColor(sf::Color::Cyan);
    initialSpawnNPCs();
    
}

void NPC::initialSpawnNPCs() {
    for (int i = 0; i < 8; ++i) {
        this->allNPCs.push_back(rectangleGuy);
        this->allNPCs[i].setPosition(475.f, 475.f);
    }
}

void NPC::updateNPCs() {
    
    
    for (int i = 0; i < this->allNPCs.size(); ++i) {
        this->allNPCs[i].move(0.f, 1.f);
    }
}

void NPC::renderNPCs(sf::RenderTarget& target) {
    for (auto &n : this->allNPCs) {
        target.draw(n);
    }
}

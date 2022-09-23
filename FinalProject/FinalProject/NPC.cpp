//
//  NPC.cpp
//  FinalProject
//
//  Created by Ryan Mata on 9/22/22.
//

#include "NPC.hpp"


void NPC::initNPC() {
    initialSpawnNPCs();
    
}

void NPC::initialSpawnNPCs() {
    
    for (int i = 0; i < 9; ++i) {
        this->allNPCs.push_back(rectangleGuy);
        this->rectangleGuy.setSize(sf::Vector2f(100.f, 100.f));
        this->allNPCs[i].setPosition(rand()%51+1400, rand()%51+650);
        this->rectangleGuy.setFillColor(sf::Color(rand()%256, rand()%256, rand()%256));
        this->rectangleGuy.setOutlineColor(sf::Color::Black);
        this->rectangleGuy.setOutlineThickness(5.f);
    }
}

void NPC::updateNPCs() {
    for (int i = 0; i < this->allNPCs.size(); ++i) {
            this->allNPCs[i].move(directions[i]*2, directions[i+1]);
        if ((allNPCs[0].getPosition().x < 250 || allNPCs[0].getPosition().x > 2750)) {
            break;
        }
    }
}

void NPC::deleteNPCs() {
    if (removedSection == 0) {
        for (long i = allNPCs.size() - 1; i >= 0; --i) {
            if (this->allNPCs[i].getPosition().x <= 350 && this->allNPCs[i].getPosition().y <= 350) {
                allNPCs[i].setFillColor(sf::Color(0, 0, 0, 0));
            }
        }
    }
    else if (removedSection == 1) {
        for (long i = allNPCs.size() - 1; i >= 0; --i) {
            if (this->allNPCs[i].getPosition().x >= 2650 && this->allNPCs[i].getPosition().y <= 350) {
                allNPCs[i].setFillColor(sf::Color(0, 0, 0, 0));
            }
        }
    }
    else if (removedSection == 2) {
        for (long i = allNPCs.size() - 1; i >= 0; --i) {
            if (this->allNPCs[i].getPosition().x <= 350 && this->allNPCs[i].getPosition().y >= 1150) {
                allNPCs[i].setFillColor(sf::Color(0, 0, 0, 0));
            }
        }
    }
    else if (removedSection == 3) {
        for (long i = allNPCs.size() - 1; i >= 0; --i) {
            if (this->allNPCs[i].getPosition().x >= 2650 && this->allNPCs[i].getPosition().y >= 1150) {
                allNPCs[i].setFillColor(sf::Color(0, 0, 0, 0));
            }
        }
    }
}
void NPC::renderNPCs(sf::RenderTarget& target) {
    for (auto &n : this->allNPCs) {
        target.draw(n);
    }
}

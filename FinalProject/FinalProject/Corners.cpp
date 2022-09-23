//
//  Corners.cpp
//  FinalProject
//
//  Created by Ryan Mata on 9/22/22.
//

#include "Corners.hpp"

void Corners::initCorner() {
    this->corner.setSize(sf::Vector2f(300.f, 300.f));
    this->corner.setFillColor(sf::Color(0, 0, 0, 0));
    this->corner.setOutlineThickness(25.f);
    this->corner.setOutlineColor(sf::Color::Blue);
}
void Corners::initialSpawnCorner() {
    for (int i = 0; i < 4; ++i) {
        this->allCorners.push_back(corner);
    }
    this->allCorners[0].setPosition(0.f, 0.f);
    this->allCorners[1].setPosition(2700.f, 0.f);
    this->allCorners[2].setPosition(0.f, 1200.f);
    this->allCorners[3].setPosition(2700.f, 1200.f);
}
void Corners::updateCorner() {
    initialSpawnCorner();
}
void Corners::renderCorner(sf::RenderTarget& target) {
    for (auto &c : this->allCorners) {
        target.draw(c);
    }
}

#include "Player.hpp"

void Player::initVariables() {
    this->speed = 10.f;
}

void Player::initShape() {
    this->rectanglePlayer.setFillColor(sf::Color::Blue);
    this->rectanglePlayer.setSize(sf::Vector2f(100.f, 100.f));
}

Player::Player(float x, float y) {
    this->rectanglePlayer.setPosition(x, y);
    this->initVariables();
    this->initShape();
}
Player::~Player() {
    
}
void Player::updateInput() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        this->rectanglePlayer.move(-this->speed, 0.f);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        this->rectanglePlayer.move(this->speed, 0.f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        this->rectanglePlayer.move(0.f, -this->speed);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        this->rectanglePlayer.move(0.f, this->speed);
    }

}
void Player::updatePlayer() {
    this->updateInput();
    

}
void Player::renderPlayer(sf::RenderTarget& target) {
    target.draw(this->rectanglePlayer);
}

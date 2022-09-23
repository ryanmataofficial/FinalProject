#include "Player.hpp"

void Player::initVariables() {
    this->speed = 10.f;
}

void Player::initShape() {
    if  (!this->texture.loadFromFile("/Users/ryan.mata@divvypay.com/myGithubRepo/Day16/FinalProject/FinalProject/k.png")){
        exit(0);
    }
    this->sprite.setTexture(texture);
    this->sprite.scale(2.f, 2.f);
}

Player::Player(float x, float y) {
    this->sprite.setPosition(x, y);
    this->initVariables();
    this->initShape();
}
Player::~Player() {
    
}
void Player::updateInput() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        this->sprite.move(-this->speed, 0.f);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        this->sprite.move(this->speed, 0.f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        this->sprite.move(0.f, -this->speed);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        this->sprite.move(0.f, this->speed);
    }

}
void Player::updatePlayer() {
    this->updateInput();
    

}
void Player::renderPlayer(sf::RenderTarget& target) {
    target.draw(this->sprite);
}

#include "include/Tank.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Image.hpp>

Tank::Tank(sf::Vector2f initial_pos, sf::Vector2f initial_speed) 
  : speed_(initial_speed), cooldown_timer_(0) {
      tank_shape_.setOrigin(50, 50);
      tank_shape_.setSize(sf::Vector2f(100,100));
      tank_shape_.setPosition(initial_pos);
  }

void TextureConstruct(sf::Vector2f pos){
  sf::Texture textureNoPiippu;
    if(!textureNoPiippu.loadFromFile("C://TankNoPiippu.png")){
  std::cout << "No can do";
  }
  sf::Sprite tankNoPiippu;
  tankNoPiippu.setTexture(textureNoPiippu);
  tankNoPiippu.setPosition(pos);
}


void Tank::Draw(sf::RenderWindow &window) const {
  window.draw(tank_shape_);
  TextureConstruct(tank_shape_.getPosition());
}


void Tank::Shoot(std::vector<Projectile> &projectiles, float angle) {
  Projectile new_projectile(tank_shape_.getPosition(), 3, angle);
  projectiles.push_back(new_projectile);
}
sf::RectangleShape Tank::GetShape() const { return tank_shape_; }
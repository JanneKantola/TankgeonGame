#pragma once
#include <SFML/Graphics.hpp>
#include <math.h>
#include <vector>
#include "Projectile.hpp"
#include "Tank.hpp"

class EnemyTank: public Tank {
  public:
    EnemyTank(sf::Vector2f initial_pos, float speed_scaler);
    void Update(std::vector<Projectile> &projectiles, sf::RectangleShape playerTank);

  private:
    void UpdateShape(float rotation_angle) override;
    float GetAngleToPlayer(sf::RectangleShape playerTank);
};
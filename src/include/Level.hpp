#pragma once
#include <SFML/Graphics.hpp>
#include <math.h>
#include "CollisionManager.hpp"
#include <SFML/Graphics.hpp>
#include <vector>
#include <list>
#include "Wall.hpp"
#include "Spike.hpp"
#include "PlayerTank.hpp"
#include "EnemyTank.hpp"
#include "Projectile.hpp"
#include "Shield.hpp"
#include "OBB.hpp"
#include <string>
#include <fstream>

struct LevelData {
  std::vector<Wall> walls;
  std::vector<Spike> spikes;
  std::list<EnemyTank> enemies;
  std::list<Projectile> projectiles;
  std::list<Shield> shields;
};


class Level {
  public:
    static constexpr int LEVEL_FILE_WIDTH = 32;
    static constexpr int LEVEL_FILE_HEIGHT = 9;

    Level();
    // Disallow copying
    Level(const Level &other) = delete;
    Level& operator=(const Level &other) = delete;

    void LoadFromFile(int level_number, sf::Vector2u window_size);
    void UpdateLevel(sf::RenderWindow &window);
    void DrawLevel(sf::RenderWindow &window);
    bool IsCompleted() const;
    const LevelData& GetLevelData();
    
  private:
    LevelData level_data_;
    PlayerTank player_; 

    void HandleProjectileCollisions();
    
/**
 * @brief Handles item pick ups by checking if the player collides with some item.
 * If a collision with an item is detected then the correct actions are executed
 * depending on the item type.
 */
    void HandleItemPickUps();

    void FillGridFromFile(std::vector<std::string> &level_grid, const std::string &filepath);

    void SetBorderWalls(sf::Vector2u window_size);

    sf::Vector2u CountNeighboringObstacles(const std::vector<std::string> &level_grid,
      std::array<std::array<bool, LEVEL_FILE_WIDTH>, LEVEL_FILE_HEIGHT> &visited, int start_x, int start_y, char obstacle);
};
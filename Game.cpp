#include "Game.h"

#include <iostream>
#include <fstream>

Game::Game (const std::string & config)
{
  init(config);
}

void Game::init(const std::string & path)
{
  //todo read in config gile using premade PlayerConfig, EnemyConfig, BulletConfig variables
  //
  //set up default window parameters
  
/*
  std::ifstream fin(path);

  fin >> m_playerConfig.SR >> m_playerConfig.CR; // >> ...
*/


  m_window.create(sf::VideoMode(1280, 720), "Game");
  m_window.setFramerateLimit(60);

  spawnPlayer();
}

void Game::run()
{
  //todo add pause functionality
  
  while (m_runnung)
  {
    m_entities.update();

/*
 * if (!m_paused) {...}
 */

    sEnemySpawner();
    sMovement();
    sCollision();
    sUserInput();
    sRender();

    m_currentFrame++;
  }
}

void Game::setPaused(bool paused)
{

}

void Game::spawnPlayer()
{
  //todo add all properties of the player with the correct values from the config

  auto entity = m_entities.addEntity("player");

  float mx = m_window.getSize().x / 2.0f;
  float my = m_window.getSize().y / 2.0f;
  entity->cTransform = std::make_shared<CTransform>(Vec2(mx, my), Vec2(1.0f, 1.0f), 0.0f);

  entity->cShape = std::make_shared<CShape>(32,0f, 8, sf::Color(10, 10, 10), sf::Color(255, 0, 0), 4.0f);

  entity->cInput = std::make_shared<CInput>();

  m_player = entity;
}

void Game::spawnEnemy()
{
/*
  auto entity = m_entities.addEntity("enemy");
  float ex = rand() % m_window.getSize().x;
  float ey = rand() % m_window.getSize().y;

  entity->cTransform = std::makeShared<CTransform>(Vec2(ex, ey), Vec2(5.0f, 5.0f), 0.0f);

  entity->cShape = std::make_shared<CShape>(16.0f, 3, sf::Color(100, 100, 255), sf::Color(0,255,0), 4.0f);


*/

  //todo make sure enemy spawned properly
  
  m_lastEnemySpawnTime = m_currentFrame; //record when most recent enemy was spawned
}

void Game::spawnSmallEnemies(std::shared_ptr<Entity> e)
{
 //todo spawn small enemies at the location of the input enemy e
}

void Game::spawnBullet(std::shared_ptr<Entity> entity, const Vec2 & target)
{
  //todo impliment spawning of bullet which travels toward target

}

void Game::spawnSpecialWeapon(std::shared_ptr<Entity> entity)
{
}

void Game::sMovement()
{
 //todo impliment all entity movement here, read m_player->CInput component to determine if the player is moving
  m_player->cTransform->velocity.y = 0;
 
 //impliment player movement
/*
  if (m_player->cInput->up)
  {
    m_player->cTransform->velocity.y = -5;
  }


*/



  m_player->cTransform->pos.x += m_player->cTransform->velocity.x;
  m_player->cTransform->pos.y += m_player->cTransform->velocity.y;
}

void Game::sLifespan()
{
  //todo impliment lifespan functionality, if entity has >1 lifespan subtract 1, scale alpha channel properly if it has lifespan and is alive
  //if it has lifespan and time is up, destroy the entity
}

void Game::sCollision()
{
  //todo impliment all collisions between entities
}

void Game::sEnemySpawner()
{
/*
  spawnEnemy(); 
*/


  //todo impliment enemy spawning, use m_currentFrame-m_lastEnemySpawnTime to determine how long since last spawn
}

void Game::sRender()
{
  //todo change code to draw all entities
  m_window.clear();

  m_player->cShape->circle.setPosition(m_player->cTransform->pos.x, m_player->cTransform->pos.y);

  m_player->cTransform->angle += 1.0f;
  m_player->cShape->circle.setRotation(m_player->cTransform->angle);

  m_window.draw(m_player->cShape->circle); //change to draw all entities

/*
  for (auto e : m_entities.getEntities())
  {
    e->cShape->circle.setPosition(m_player->cTransform->pos.x, m_player->cTransform->pos.y);

    e->cTransform->angle += 1.0f;
    e->cShape->circle.setRotation(m_player->cTransform->angle);

    m_window.draw(e->cShape->circle); //change to draw all entities
  }
*/
  m_window.display();
}

void Game::sUserInput()
{
  //todo handle user input

  sf::Event event;
  while (m_window.pollEvent(event))
  {
    if (event.type == sf::Event::Closed)
    {
      m_running = false;
    }

    if (event.type == sf::Event::KeyPressed)
    {
      switch (event.key.code)
      {
      case sf::Keyboard::W:
        std::cout << "W pressed\n";
        //todo up to true
        /*
        m_player->cInput->up = true;
        
        */
        break;
      default: break;
      }
    }

    if (event.type == sf::Event::KeyReleased)
    {
      switch (event.key.code)
      {
      case sf::Keyboard::W:
        std::cout << "W released\n";
        //todo up to false
        /*
        m_player->cInput->up = false;
        
        */
        break;
      default: break;
      }
    }

    if (event.type == sf::Event::MouseButtonPressed)
    {
      if (event.mouseButton.button == sf::Mouse::Left)
      {
        std::Cout << "Left mouse\n";
        //call spawnBullet
      }

      if (event.mouseButton.button == sf::Mouse::Right)
      {
        std::cout << "Right mouse\n";
        //call spawnSpecialWeapon
      }
    }   
}

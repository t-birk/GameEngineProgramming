#include "EntityManager.h"

EntityManager::EntityManager()
{

}

void EntityManager::update()
{
//todo add entities from m_entitiesToAdd to the proper locations (vector of all entities, vector inside the map with tag as key)

/*
  for (auto e: m_entitiesToAdd)
  {
    m_entities.push_back(e);

  }
 
*/


  removeDeadEntities(m_entities);

  for (auto& [tag, entityVec] : m_entityMap)
  {
    removeDeadEntities(entityVec);
  }
}

void EntityManager::removeDeadEntities(EntityVec & vec)
{
  //todo remove all dead entities from the latest input vector
}

std::shared_ptr<Entity> EntityManager::addEntity(const std::string & tag)
{
  auto entity = std::shared_ptr<Entity>(new Entity(m_totalEntities++, tag));

  m_entitiesToAdd.push_back(entity);

  return entity;
}

const EntityVec & EntityManager::getEntities()
{
  return m_entities;
}

const EntityVec & EntityManager::getEntities(const std::string & tag)
{
  //todo this is incorrect, return the correct vector from the map

  return m_entities;
}

/*
** Ghost.cpp for cpp_arcade in /home/osborn_s/Tek_2/cpp_arcade/Ghost.cpp
**
** Made by Samuel Osborne
** Login   <samuel.osborne@epitech.eu>
**
** Started on  Sat Mar 18 18:52:39 2017 Samuel Osborne
// Last update Thu Apr  6 17:28:27 2017 escorn_t
*/

#include "Ghost.hpp"

arcade::games::Ghost::Ghost(uint16_t x, uint16_t y, std::string path) : arcade::Enemy(x, y)
{
  this->direction = arcade::CommandType::GO_UP;
  this->asset = path;
  this->vulne = false;
  this->spawn = true;
  this->timer = 0;
  this->spawnTimer = 0;
  this->vulneAsset = "./misc/Pacman/GhostRekt";
}

arcade::games::Ghost::Ghost(const arcade::games::Ghost &other) : arcade::Enemy(other.getPos().x, other.getPos().y)
{
  if (this != &other)
    {
      this->asset = other.asset;
      this->pos = other.pos;
      this->vulneAsset = other.vulneAsset;
    }
}

arcade::games::Ghost 		&arcade::games::Ghost::operator=(const Ghost &other)
{
  if (this != &other)
    {
      this->asset = other.asset;
      this->pos = other.pos;
      this->vulneAsset = other.vulneAsset;
    }
  return (*this);
}

arcade::CommandType		arcade::games::Ghost::getDirection() const
{
  return (this->direction);
}

void	arcade::games::Ghost::setDirection(const arcade::CommandType &dir)
{
  this->direction = dir;
}

void	arcade::games::Ghost::setVulne(const bool state)
{
  this->vulne = state;
}

bool	arcade::games::Ghost::getVulne() const
{
  return (this->vulne);
}

long int	arcade::games::Ghost::getTimer() const
{
  return (this->timer);
}

void	arcade::games::Ghost::setTimer(const long int val)
{
  this->timer = val;
}

void		arcade::games::Ghost::switchAsset()
{
  std::string	tmp;

  tmp = this->asset;
  this->asset = this->vulneAsset;
  this->vulneAsset = tmp;
}

long int	arcade::games::Ghost::getSpawnTimer() const
{
  return (this->spawnTimer);
}

void 	arcade::games::Ghost::setSpawnTimer(long int timer)
{
  this->spawnTimer = timer;
}

bool	arcade::games::Ghost::getSpawn() const
{
  return (this->spawn);
}

void	arcade::games::Ghost::setSpawn(bool _spawn)
{
  this->spawn = _spawn;
}

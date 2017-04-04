/*
** Enemy.cpp for cpp_arcade in /home/osborn_s/Tek_2/cpp_arcade/Enemy.cpp
**
** Made by Samuel Osborne
** Login   <samuel.osborne@epitech.eu>
**
** Started on  Tue Mar 14 13:31:58 2017 Samuel Osborne
** Last update Tue Mar 14 13:31:58 2017 Samuel Osborne
*/

#include "Enemy.hpp"

arcade::Enemy::Enemy(const uint16_t x, const uint16_t y)
 : arcade::ACharacter(x, y)
{
  this->setTileType(arcade::TileType::EVIL_DUDE);
}

arcade::Enemy::Enemy(const arcade::Enemy &other)
 : ACharacter(other.pos.x, other.pos.y)
{
  if (this != &other)
    {
      this->pos.x = other.pos.x;
      this->pos.y = other.pos.y;
    }
}

arcade::Enemy	&arcade::Enemy::operator=(const arcade::Enemy & other)
{
  if (this != &other)
    {
      this->pos.x = other.pos.x;
      this->pos.y = other.pos.y;
    }
  return (*this);
}

void	arcade::Enemy::move(const arcade::Position &pos)
{
  this->pos.x = pos.x;
  this->pos.y = pos.y;
}
/*
** Projectile.cpp for cpp_arcade in /home/osborn_s/Tek_2/cpp_arcade/Projectile.cpp
**
** Made by Samuel Osborne
** Login   <samuel.osborne@epitech.eu>
**
** Started on  Tue Mar 14 16:26:35 2017 Samuel Osborne
** Last update Tue Mar 14 16:26:35 2017 Samuel Osborne
*/

#include "Projectile.hpp"

arcade::Projectile::Projectile(const uint16_t x, const uint16_t y)
 : arcade::AObjects(x, y)
{
  this->type = arcade::TileType::POWERUP;
}

arcade::Projectile::Projectile(const arcade::Projectile &other)
 : arcade::AObjects(other.pos.x, other.pos.y)
{
  if (this != &other)
    {
      this->pos = other.pos;
      this->type = other.type;
    }
}

arcade::Projectile	&arcade::Projectile::operator=(const arcade::Projectile &other)
{
  if (this != &other)
    {
      this->pos = other.pos;
      this->type = other.type;
    }
  return (*this);
}

void	arcade::Projectile::move(arcade::Position &pos)
{
  this->setPos(pos);
}
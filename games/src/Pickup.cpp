/*
** Pickup.cpp for cpp_arcade in /home/osborn_s/Tek_2/cpp_arcade/Pickup.cpp
**
** Made by Samuel Osborne
** Login   <samuel.osborne@epitech.eu>
**
** Started on  Tue Mar 14 16:19:59 2017 Samuel Osborne
** Last update Tue Mar 14 16:19:59 2017 Samuel Osborne
*/

#include "Pickup.hpp"

arcade::Pickup::Pickup(const uint16_t x, const uint16_t y)
 : AObjects(x, y)
{
  this->setTileType(arcade::TileType::POWERUP);
}

arcade::Pickup::Pickup(const arcade::Pickup &other)
 : AObjects(other.pos.x, other.pos.y)
{
  if (this != &other)
    {
      this->pos = other.pos;
      this->type = other.type;
    }
}

arcade::Pickup	&arcade::Pickup::operator=(const arcade::Pickup &other)
{
  if (this != &other)
    {
      this->pos = other.pos;
      this->type = other.type;
    }
  return (*this);
}

void	arcade::Pickup::move(arcade::Position &pos)
{
  this->setPos(pos);
}
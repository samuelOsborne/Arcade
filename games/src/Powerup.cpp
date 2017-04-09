/*
** Powerup.cpp for cpp_arcade in /home/osborn_s/Tek_2/cpp_arcade/Powerup.cpp
**
** Made by Samuel Osborne
** Login   <samuel.osborne@epitech.eu>
**
** Started on  Tue Mar 14 15:09:51 2017 Samuel Osborne
** Last update Tue Mar 14 15:09:51 2017 Samuel Osborne
*/

#include "Powerup.hh"

arcade::Powerup::Powerup(const uint16_t x, const uint16_t y)
 : AObjects(x, y)
{
  this->setTileType(arcade::TileType::POWERUP);
}

arcade::Powerup::Powerup(const arcade::Powerup& other)
 : AObjects(other.pos.x, other.pos.y)
{
  if (this != &other)
    {
      this->pos = other.pos;
      this->type = other.type;
    }
}

arcade::Powerup	&arcade::Powerup::operator=(const arcade::Powerup &other)
{
  if (this != &other)
    {
      this->pos = other.pos;
      this->type = other.type;
    }
  return (*this);
}

void	arcade::Powerup::move(arcade::Position &pos)
{
  this->setPos(pos);
}
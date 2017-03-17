/*
** Powerup.cpp for cpp_arcade in /home/osborn_s/Tek_2/cpp_arcade/Powerup.cpp
**
** Made by Samuel Osborne
** Login   <samuel.osborne@epitech.eu>
**
** Started on  Tue Mar 14 15:09:51 2017 Samuel Osborne
** Last update Tue Mar 14 15:09:51 2017 Samuel Osborne
*/

#include "Powerup.hpp"

arcade::games::Powerup::Powerup(uint16_t x, uint16_t y) : AObjects(x, y)
{
  this->pos.x = x;
  this->pos.y = y;
  this->type = arcade::TileType::POWERUP;
}

void				arcade::games::Powerup::move(arcade::Position& pos)
{
  this->setPos(pos);
}

arcade::games::Powerup::Powerup(const arcade::games::Powerup& other) : AObjects(other.pos.x, other.pos.y)
{
  if (this != &other)
    {
      this->pos = other.pos;
      this->type = other.type;
    }
}

const arcade::games::Powerup&	arcade::games::Powerup::operator=(const arcade::games::Powerup& other)
{
  if (this != &other)
    {
      this->pos = other.pos;
      this->type = other.type;
    }
  return (*this);
}

void				arcade::games::Powerup::setTileType()
{
  this->type = arcade::TileType::POWERUP;
}
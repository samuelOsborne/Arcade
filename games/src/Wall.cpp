/*
** Wall.cpp for cpp_arcade in /home/osborn_s/Tek_2/cpp_arcade/Wall.cpp
**
** Made by Samuel Osborne
** Login   <samuel.osborne@epitech.eu>
**
** Started on  Fri Mar 17 13:06:12 2017 Samuel Osborne
** Last update Fri Mar 17 13:06:12 2017 Samuel Osborne
*/

#include "Wall.hpp"

arcade::games::Wall::Wall(uint16_t x, uint16_t y) : ABlock(x, y)
{
  this->pos.x = x;
  this->pos.y = y;
  this->type = arcade::TileType::BLOCK;
}

arcade::games::Wall::Wall(const arcade::games::Wall& other) : ABlock(other.pos.x, other.pos.y)
{
  if (this != &other)
    {
      this->pos = other.pos;
      this->type = other.type;
    }
}

const arcade::games::Wall&	arcade::games::Wall::operator=(const arcade::games::Wall& other)
{
  if (this != &other)
    {
      this->pos = other.pos;
      this->type = other.type;
    }
  return (*this);
}
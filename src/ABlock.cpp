/*
** ABlock.cpp for cpp_arcade in /home/osborn_s/Tek_2/cpp_arcade/ABlock.cpp
**
** Made by Samuel Osborne
** Login   <samuel.osborne@epitech.eu>
**
** Started on  Thu Mar 16 18:15:39 2017 Samuel Osborne
** Last update Thu Mar 16 18:15:39 2017 Samuel Osborne
*/

#include "ABlock.hpp"

arcade::ABlock::ABlock(const uint16_t x, const uint16_t y)
 : arcade::AGameObject(x, y)
{
}

arcade::ABlock::ABlock(const arcade::ABlock& other)
 : arcade::AGameObject(other.pos.x, other.pos.y)
{
  if (this != &other)
    {
      this->pos.x = other.pos.x;
      this->pos.y = other.pos.y;
      this->type = other.type;
    }
}

arcade::ABlock	&arcade::ABlock::operator=(const arcade::ABlock & other)
{
  if (this != &other)
    {
      this->pos.x = other.pos.x;
      this->pos.y = other.pos.y;
      this->type = other.type;
    }
  return (*this);
}

void	arcade::ABlock::setPos(const arcade::Position &pos)
{
  this->pos = pos;
}

arcade::Position	arcade::ABlock::getPos() const
{
  return (this->pos);
}
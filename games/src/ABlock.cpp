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

arcade::games::ABlock::ABlock(uint16_t x, uint16_t y) : arcade::games::AGameObject(x, y)
{
  this->pos.x = x;
  this->pos.y = y;
}

arcade::games::ABlock::ABlock(const arcade::games::ABlock& other) : arcade::games::AGameObject(other.pos.x, other.pos.y)
{
  if (this != &other)
    {
      this->pos.x = other.pos.x;
      this->pos.y = other.pos.y;
      this->type = other.type;
    }
}

arcade::games::ABlock	&arcade::games::ABlock::operator=
 (const arcade::games::ABlock & other)
{
  if (this != &other)
    {
      this->pos.x = other.pos.x;
      this->pos.y = other.pos.y;
      this->type = other.type;
    }
  return (*this);
}

void 				arcade::games::ABlock::setPos(const arcade::Position &pos)
{
  this->pos = pos;
}

arcade::Position 		arcade::games::ABlock::getPos() const
{
  return (this->pos);
}
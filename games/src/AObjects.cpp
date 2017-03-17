/*
** Objects.cpp for cpp_arcade in /home/osborn_s/Tek_2/cpp_arcade/Objects.cpp
**
** Made by Samuel Osborne
** Login   <samuel.osborne@epitech.eu>
**
** Started on  Tue Mar 14 13:40:06 2017 Samuel Osborne
** Last update Tue Mar 14 13:40:06 2017 Samuel Osborne
*/

#include "AObjects.hpp"

arcade::games::AObjects::AObjects(uint16_t x, uint16_t y) : arcade::games::AGameObject(x, y)
{
  this->pos.x = x;
  this->pos.y = y;
}

arcade::games::AObjects::AObjects(const arcade::games::AObjects& other) : arcade::games::AGameObject(other.pos.x, other.pos.y)
{
  if (this != &other)
    {
      this->pos.x = other.pos.x;
      this->pos.y = other.pos.y;
      this->type = other.type;
    }
}

const arcade::games::AObjects&	arcade::games::AObjects::operator=
 (const arcade::games::AObjects& other)
{
  if (this != &other)
    {
      this->pos.x = other.pos.x;
      this->pos.y = other.pos.y;
      this->type = other.type;
    }
  return (*this);
}

void 				arcade::games::AObjects::setPos(const arcade::Position &pos)
{
  this->pos = pos;
}

arcade::Position 		arcade::games::AObjects::getPos() const
{
  return (this->pos);
}
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

arcade::AObjects::AObjects(const uint16_t x, const uint16_t y)
 : arcade::AGameObject(x, y)
{
}

arcade::AObjects::AObjects(const arcade::AObjects& other)
 : arcade::AGameObject(other.pos.x, other.pos.y)
{
  if (this != &other)
    {
      this->pos.x = other.pos.x;
      this->pos.y = other.pos.y;
      this->type = other.type;
    }
}

arcade::AObjects &arcade::AObjects::operator=(const arcade::AObjects& other)
{
  if (this != &other)
    {
      this->pos.x = other.pos.x;
      this->pos.y = other.pos.y;
      this->type = other.type;
    }
  return (*this);
}

void 	arcade::AObjects::setPos(const arcade::Position &pos)
{
  this->pos = pos;
}

arcade::Position	arcade::AObjects::getPos() const
{
  return (this->pos);
}
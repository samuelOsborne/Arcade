/*
** AGameObject.cpp for cpp_arcade in /home/osborn_s/Tek_2/cpp_arcade/AGameObject.cpp
**
** Made by Samuel Osborne
** Login   <samuel.osborne@epitech.eu>
**
** Started on  Tue Mar 14 13:31:58 2017 Samuel Osborne
** Last update Tue Mar 14 13:31:58 2017 Samuel Osborne
*/

#include "AGameObject.hpp"

arcade::games::AGameObject::AGameObject()
{
  this->pos.x = 0;
  this->pos.y = 0;
}

arcade::games::AGameObject::AGameObject(const arcade::games::AGameObject & other)
{
  if (this != &other)
    {
      this->pos.x = other.pos.x;
      this->pos.y = other.pos.y;
    }
}

arcade::games::AGameObject	&arcade::games::AGameObject::operator=
 (const arcade::games::AGameObject & other)
{
  if (this != &other)
    {
      this->pos.x = other.pos.x;
      this->pos.y = other.pos.y;
    }
  return (*this);
}

void 				arcade::games::AGameObject::setPos(const arcade::Position &pos)
{
  this->pos = pos;
}

arcade::Position 		arcade::games::AGameObject::getPos() const
{
  return (this->pos);
}
/*
** Objects.cpp for cpp_arcade in /home/osborn_s/Tek_2/cpp_arcade/Objects.cpp
**
** Made by Samuel Osborne
** Login   <samuel.osborne@epitech.eu>
**
** Started on  Tue Mar 14 13:40:06 2017 Samuel Osborne
** Last update Tue Mar 14 13:40:06 2017 Samuel Osborne
*/

#include "Objects.hpp"

arcade::games::Objects::Objects()
{
  this->pos.x = 0;
  this->pos.y = 0;
  this->type = arcade::TileType::OTHER;
}

arcade::games::Objects::Objects(const arcade::games::Objects& other)
{
  if (this != &other)
    {
      this->pos.x = other.pos.x;
      this->pos.y = other.pos.y;
      this->type = other.type;
    }
}

const arcade::games::Objects&	arcade::games::Objects::operator=
 (const arcade::games::Objects& other)
{
  if (this != &other)
    {
      this->pos.x = other.pos.x;
      this->pos.y = other.pos.y;
      this->type = other.type;
    }
  return (*this);
}

int	arcade::games::Objects::getPosX() const
{
  return (this->pos.x);
}

int	arcade::games::Objects::getPosY() const
{
  return (this->pos.y);
}

void	arcade::games::Objects::setPos(const arcade::Position& pos)
{
  this->pos.x = pos.x;
  this->pos.y = pos.y;
}
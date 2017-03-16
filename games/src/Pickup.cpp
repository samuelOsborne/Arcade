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

arcade::games::Pickup::Pickup() : AObjects()
{
  this->type = arcade::TileType::POWERUP;
}

void				arcade::games::Pickup::move(arcade::Position& pos)
{
  this->setPos(pos);
}

arcade::games::Pickup::Pickup(const arcade::games::Pickup& other) : AObjects()
{
  if (this != &other)
    {
      this->pos = other.pos;
      this->type = other.type;
    }
}

const arcade::games::Pickup&	arcade::games::Pickup::operator=(const arcade::games::Pickup& other)
{
  if (this != &other)
    {
      this->pos = other.pos;
      this->type = other.type;
    }
  return (*this);
}

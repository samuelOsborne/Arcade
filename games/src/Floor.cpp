/*
** Floor.cpp for cpp_arcade in /home/osborn_s/Tek_2/cpp_arcade/Floor.cpp
**
** Made by Samuel Osborne
** Login   <samuel.osborne@epitech.eu>
**
** Started on  Fri Mar 17 13:20:36 2017 Samuel Osborne
** Last update Fri Mar 17 13:20:36 2017 Samuel Osborne
*/

#include "Floor.hpp"

arcade::games::Floor::Floor() : ABlock()
{
  this->type = arcade::TileType::EMPTY;
}

arcade::games::Floor::Floor(const arcade::games::Floor& other) : ABlock()
{
  if (this != &other)
    {
      this->pos = other.pos;
      this->type = other.type;
    }
}

const arcade::games::Floor&	arcade::games::Floor::operator=(const arcade::games::Floor& other)
{
  if (this != &other)
    {
      this->pos = other.pos;
      this->type = other.type;
    }
  return (*this);
}
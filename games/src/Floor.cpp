/*
** Floor.cpp for cpp_arcade in /home/osborn_s/Tek_2/cpp_arcade/Floor.cpp
**
** Made by Samuel Osborne
** Login   <samuel.osborne@epitech.eu>
**
** Started on  Fri Mar 17 13:20:36 2017 Samuel Osborne
** Last update Fri Mar 17 13:20:36 2017 Samuel Osborne
*/

#include "Floor.hh"

arcade::Floor::Floor(uint16_t x, uint16_t y)
 : arcade::ABlock(x, y)
{
  this->setTileType(arcade::TileType::EMPTY);
  this->asset = "./misc/Pacman/black";
}

arcade::Floor::Floor(const arcade::Floor &other)
 : arcade::ABlock(other.pos.x, other.pos.y)
{
  if (this != &other)
    {
      this->pos = other.pos;
      this->type = other.type;
    }
}

arcade::Floor	&arcade::Floor::operator=(const arcade::Floor &other)
{
  if (this != &other)
    {
      this->pos = other.pos;
      this->type = other.type;
    }
  return (*this);
}
/*
** Wall.cpp for cpp_arcade in /home/osborn_s/Tek_2/cpp_arcade/Wall.cpp
**
** Made by Samuel Osborne
** Login   <samuel.osborne@epitech.eu>
**
** Started on  Fri Mar 17 13:06:12 2017 Samuel Osborne
** Last update Fri Mar 17 13:06:12 2017 Samuel Osborne
*/

#include <string.h>
#include "Wall.hpp"

arcade::Wall::Wall(const uint16_t x, const uint16_t y)
 : ABlock(x, y)
{
  this->type = arcade::TileType::BLOCK;
  this->asset = "./misc/Pacman/Horizontalpipe";
  this->setTileType();
}

arcade::Wall::Wall(const arcade::Wall &other)
 : ABlock(other.pos.x, other.pos.y)
{
  if (this != &other)
    {
      this->pos = other.pos;
      this->type = other.type;
    }
}

const arcade::Wall&	arcade::Wall::operator=(const arcade::Wall &other)
{
  if (this != &other)
    {
      this->pos = other.pos;
      this->type = other.type;
    }
  return (*this);
}

void			arcade::Wall::setAsset(std::string assetPath)
{
  this->asset = assetPath;
}

void			arcade::Wall::setTileType()
{
  this->extType = arcade::games::ExtTileType::WALL;
}

std::string		arcade::Wall::getObj() const
{
  return ("Wall");
}
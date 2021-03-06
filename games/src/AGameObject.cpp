/*
** AGameObject.cpp for cpp_arcade in /home/osborn_s/Tek_2/cpp_arcade/AGameObject.cpp
**
** Made by Samuel Osborne
** Login   <samuel.osborne@epitech.eu>
**
** Started on  Tue Mar 14 13:31:58 2017 Samuel Osborne
** Last update Tue Mar 14 13:31:58 2017 Samuel Osborne
*/

#include "AGameObject.hh"

arcade::AGameObject::AGameObject(const uint16_t x, const uint16_t y)
{
  this->pos.x = x;
  this->pos.y = y;
}

arcade::AGameObject::AGameObject(const arcade::AGameObject & other)
{
  if (this != &other)
    {
      this->pos.x = other.pos.x;
      this->pos.y = other.pos.y;
    }
}

arcade::AGameObject	&arcade::AGameObject::operator=
 (const arcade::AGameObject & other)
{
  if (this != &other)
    {
      this->pos.x = other.pos.x;
      this->pos.y = other.pos.y;
    }
  return (*this);
}

void 			arcade::AGameObject::setPos(const arcade::Position &pos)
{
  this->pos = pos;
}

arcade::Position 	arcade::AGameObject::getPos() const
{
  return (this->pos);
}

std::string		arcade::AGameObject::getSprite() const
{
  return (this->asset);
}

void			arcade::AGameObject::setSprite(const std::string &a)
{
  this->asset = a;
}

arcade::TileType	arcade::AGameObject::getTileType() const
{
  return (this->type);
}

void	arcade::AGameObject::setTileType(const arcade::TileType &tileType)
{
  this->type = tileType;
}

void 			arcade::AGameObject::setPos(uint16_t x, uint16_t y)
{
  this->pos.x = x;
  this->pos.y = y;
}

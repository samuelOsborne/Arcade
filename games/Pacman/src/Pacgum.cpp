/*
** Pacgum.cpp for cpp_arcade in /home/osborn_s/Tek_2/cpp_arcade/Pacgum.cpp
**
** Made by Samuel Osborne
** Login   <samuel.osborne@epitech.eu>
**
** Started on  Wed Mar 22 10:18:06 2017 Samuel Osborne
** Last update Wed Mar 22 10:18:06 2017 Samuel Osborne
*/

#include "Pacgum.hh"

arcade::games::Pacgum::Pacgum(uint16_t x, uint16_t y) :
 arcade::Pickup(x, y)
{
  this->asset = "./misc/Pacman/Pacgum";
  this->secondAsset = "./misc/Pacman/floor";
}

arcade::games::Pacgum::Pacgum(const arcade::games::Pacgum& other) :
 arcade::Pickup(other.getPos().x, other.getPos().y)
{
  if (this != &other)
    {
      this->asset = other.asset;
      this->secondAsset = other.secondAsset;
      this->pos = other.pos;
      this->type = other.type;
    }
}

arcade::games::Pacgum&		arcade::games::Pacgum::operator=(const Pacgum& other)
{
  if (this != &other)
    {
      this->asset = other.asset;
      this->secondAsset = other.secondAsset;
      this->pos = other.pos;
      this->type = other.type;
    }
  return (*this);
}
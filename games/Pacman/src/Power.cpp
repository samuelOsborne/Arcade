/*
** Power.cpp for cpp_arcade in /home/escorn_t/Rendu/cpp_arcade/Power.cpp
**
** Made by Thomas Escorne
** Login    <thomas.escorne@epitech.eu>
**
** Started on Sat Apr 08 11:28:45 2017 Thomas Escorne
** Last update Sat Apr 08 11:28:45 2017 Thomas Escorne 
**
*/

#include "Power.hh"

arcade::games::Power::Power(uint16_t x, uint16_t y) :
 arcade::Pickup(x, y)
{
  this->asset = "./misc/Pacman/PowerUp";
  this->secondAsset = "./misc/Pacman/floor";
}

arcade::games::Power::Power(const arcade::games::Power & other) :
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

arcade::games::Power &	arcade::games::Power::operator=(const Power& other)
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
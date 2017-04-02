/*
** ACharacter.cpp for cpp_arcade in /home/osborn_s/Tek_2/cpp_arcade/ACharacter.cpp
**
** Made by Samuel Osborne
** Login   <samuel.osborne@epitech.eu>
**
** Started on  Tue Mar 14 11:27:32 2017 Samuel Osborne
** Last update Tue Mar 14 11:27:32 2017 Samuel Osborne
*/

#include "ACharacter.hpp"


arcade::ACharacter::ACharacter(const uint16_t x, const uint16_t y)
 : arcade::AGameObject(x, y)
{
}

arcade::ACharacter::ACharacter(const arcade::ACharacter &other)
 : arcade::AGameObject(other.pos.x, other.pos.y)
{
  if (this != &other)
    {
      this->pos.x = other.pos.x;
      this->pos.y = other.pos.y;
    }
}

arcade::ACharacter	&arcade::ACharacter::operator=(const arcade::ACharacter &other)
{
  if (this != &other)
    {
      this->pos.x = other.pos.x;
      this->pos.y = other.pos.y;
    }
  return (*this);
}

void	arcade::ACharacter::setPos(const arcade::Position &pos)
{
  this->pos = pos;
}

arcade::Position	arcade::ACharacter::getPos() const
{
  return (this->pos);
}

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


arcade::games::ACharacter::ACharacter(void) : arcade::games::AGameObject()
{
  this->pos.x = 0;
  this->pos.y = 0;
}

arcade::games::ACharacter::ACharacter(const ACharacter& other) : arcade::games::AGameObject()
{
  if (this != &other)
    {
      this->pos.x = other.pos.x;
      this->pos.y = other.pos.y;
    }
}

arcade::games::ACharacter&	arcade::games::ACharacter::operator=
 (const arcade::games::ACharacter& other)
{
  if (this != &other)
    {
      this->pos.x = other.pos.x;
      this->pos.y = other.pos.y;
    }
  return (*this);
}

void 				arcade::games::ACharacter::setPos(const arcade::Position &pos)
{
  this->pos = pos;
}

arcade::Position 		arcade::games::ACharacter::getPos() const
{
  return (this->pos);
}

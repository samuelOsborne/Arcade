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

arcade::games::ACharacter::ACharacter(void)
{
  this->pos.x = 0;
  this->pos.y = 0;
  this->health = 100;
}

arcade::games::ACharacter::ACharacter(const ACharacter& other)
{
  if (this != &other)
    {
      this->pos.x = other.pos.x;
      this->pos.y = other.pos.y;
      this->health = other.health;
    }
}

arcade::games::ACharacter&	arcade::games::ACharacter::operator=
 (const arcade::games::ACharacter& other)
{
  if (this != &other)
    {
      this->pos.x = other.pos.x;
      this->pos.y = other.pos.y;
      this->health = other.health;
    }
  return (*this);
}

int		arcade::games::ACharacter::getPosX(void) const
{
  return (this->pos.x);
}

int		arcade::games::ACharacter::getPosY(void) const
{
  return (this->pos.y);
}

void		arcade::games::ACharacter::setPosX(const int a)
{
  this->pos.x = a;
}

void		arcade::games::ACharacter::setPosY(const int a)
{
  this->pos.y = a;
}

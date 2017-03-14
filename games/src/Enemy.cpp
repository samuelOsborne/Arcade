/*
** Enemy.cpp for cpp_arcade in /home/osborn_s/Tek_2/cpp_arcade/Enemy.cpp
**
** Made by Samuel Osborne
** Login   <samuel.osborne@epitech.eu>
**
** Started on  Tue Mar 14 13:31:58 2017 Samuel Osborne
** Last update Tue Mar 14 13:31:58 2017 Samuel Osborne
*/

#include "Enemy.hpp"

arcade::games::Enemy::Enemy(const arcade::games::Enemy & other)
 : ACharacter()
{
  if (this != &other)
    {
      this->health = other.health;
      this->pos.x = other.pos.x;
      this->pos.y = other.pos.y;
      this->health = other.health;
      this->powerup = other.powerup;
    }
}

arcade::games::Enemy	&arcade::games::Enemy::operator=
 (const arcade::games::Enemy & other)
{
  if (this != &other)
    {
      this->health = other.health;
      this->pos.x = other.pos.x;
      this->pos.y = other.pos.y;
      this->health = other.health;
      this->powerup = other.powerup;
    }
  return (*this);
}

void	arcade::games::Enemy::move(const arcade::Position & pos)
{
  this->setPosX(static_cast<int>(pos.x));
  this->setPosY(static_cast<int>(pos.y));
}
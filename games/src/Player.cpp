/*
** Player.cpp for cpp_arcade in /home/osborn_s/Tek_2/cpp_arcade/Player.hpp
**
** Made by Samuel Osborne
** Login   <samuel.osborne@epitech.eu>
**
** Started on  Tue Mar 14 11:27:32 2017 Samuel Osborne
** Last update Tue Mar 14 11:27:32 2017 Samuel Osborne
*/

#include "Player.hpp"

arcade::games::Player::Player(const arcade::games::Player& other)
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

arcade::games::Player	&arcade::games::Player::operator=(const Player & other)
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

void	arcade::games::Player::move(const arcade::Position & pos)
{
  this->setPosX(static_cast<int>(pos.x));
  this->setPosY(static_cast<int>(pos.y));
}


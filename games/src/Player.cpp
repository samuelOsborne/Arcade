/*
** Player.cpp for cpp_arcade in /home/osborn_s/Tek_2/cpp_arcade/Player.hpp
**
** Made by Samuel Osborne
** Login   <samuel.osborne@epitech.eu>
**
** Started on  Tue Mar 14 11:27:32 2017 Samuel Osborne
** Last update Tue Mar 14 11:27:32 2017 Samuel Osborne
*/

#include "AGameObject.hpp"
#include "Player.hpp"

arcade::games::Player::Player(uint16_t x, uint16_t y) : arcade::games::ACharacter(x, y)
{
  this->pos.x = x;
  this->pos.y = y;
  this->powerup = 0;
  this->type = arcade::TileType::OTHER;
  this->extType = arcade::games::ExtTileType::PLAYER;
}

arcade::games::Player::Player(const arcade::games::Player& other)
: arcade::games::ACharacter(other.pos.x, other.pos.y)
{
  if (this != &other)
    {
      this->pos = other.pos;
      this->powerup = other.powerup;
      this->extType = other.extType;
      this->type = other.type;
    }
}

arcade::games::Player		&arcade::games::Player::operator=(const Player & other)
{
  if (this != &other)
    {
      this->pos = other.pos;
      this->powerup = other.powerup;
      this->extType = other.extType;
      this->type = other.type;
    }
  return (*this);
}

void				arcade::games::Player::move(const arcade::Position & pos)
{
  this->pos.x = pos.x;
  this->pos.y = pos.y;
}

void				arcade::games::Player::setTileType()
{
  this->extType = arcade::games::ExtTileType::PLAYER;
}

arcade::games::ExtTileType	arcade::games::Player::getTileType() const
{
  return (this->extType);
}
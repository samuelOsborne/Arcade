/*
** Player.cpp for cpp_arcade in /home/osborn_s/Tek_2/cpp_arcade/Player.hpp
**
** Made by Samuel Osborne
** Login   <samuel.osborne@epitech.eu>
**
** Started on  Tue Mar 14 11:27:32 2017 Samuel Osborne
** Last update Tue Mar 14 11:27:32 2017 Samuel Osborne
*/

#include "AGameObject.hh"
#include "Player.hh"

arcade::Player::Player()
 : arcade::ACharacter(0, 0)
{
  this->powerup = 0;
  this->asset = "./misc/Pacman/Pacman";
  this->setTileType(arcade::TileType::OTHER);
}

arcade::Player::Player(const uint16_t x, const uint16_t y)
 : arcade::ACharacter(x, y)
{
  this->powerup = 0;
  this->setTileType(arcade::TileType::OTHER);
}

arcade::Player::Player(const arcade::Player& other)
 : arcade::ACharacter(other.pos.x, other.pos.y)
{
  if (this != &other)
    {
      this->pos = other.pos;
      this->powerup = other.powerup;
      this->type = other.type;
    }
}

arcade::Player		&arcade::Player::operator=(const Player &other)
{
  if (this != &other)
    {
      this->pos = other.pos;
      this->powerup = other.powerup;
      this->type = other.type;
    }
  return (*this);
}

void				arcade::Player::move(const arcade::Position & pos)
{
  this->pos.x = pos.x;
  this->pos.y = pos.y;
}
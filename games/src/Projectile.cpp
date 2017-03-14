/*
** Projectile.cpp for cpp_arcade in /home/osborn_s/Tek_2/cpp_arcade/Projectile.cpp
**
** Made by Samuel Osborne
** Login   <samuel.osborne@epitech.eu>
**
** Started on  Tue Mar 14 16:26:35 2017 Samuel Osborne
** Last update Tue Mar 14 16:26:35 2017 Samuel Osborne
*/

#include "../include/Projectile.hpp"

arcade::games::Projectile::Projectile() : Objects()
{
  this->type = arcade::TileType::POWERUP;
}

void					arcade::games::Projectile::move(arcade::Position pos)
{
  this->setPos(pos);
}

arcade::games::Projectile::Projectile(const arcade::games::Projectile& other) : Objects()
{
  if (this != &other)
    {
      this->pos = other.pos;
      this->type = other.type;
    }
}

const arcade::games::Projectile&	arcade::games::Projectile::operator=(const arcade::games::Projectile& other)
{
  if (this != &other)
    {
      this->pos = other.pos;
      this->type = other.type;
    }
  return (*this);
}

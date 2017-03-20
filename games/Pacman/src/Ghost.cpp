/*
** Ghost.cpp for cpp_arcade in /home/osborn_s/Tek_2/cpp_arcade/Ghost.cpp
**
** Made by Samuel Osborne
** Login   <samuel.osborne@epitech.eu>
**
** Started on  Sat Mar 18 18:52:39 2017 Samuel Osborne
** Last update Sat Mar 18 18:52:39 2017 Samuel Osborne
*/

#include "Ghost.hpp"

arcade::games::Ghost::Ghost(const arcade::games::Ghost &other) : arcade::Enemy(other.getPos().x, other.getPos().y)
{
  if (this != &other)
    {
      this->asset = other.asset;
    }
}

arcade::games::Ghost 		&arcade::games::Ghost::operator=(const Ghost &other)
{
  if (this != &other)
    {
      this->asset = other.asset;
      this->pos = other.pos;
    }
  return (*this);
}

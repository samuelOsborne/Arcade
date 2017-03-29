/*
** AGame.hpp for cpp_arcade in /home/osborn_s/Tek_2/cpp_arcade/AGame.hpp
**
** Made by Samuel Osborne
** Login   <samuel.osborne@epitech.eu>
**
** Started on  Wed Mar 15 16:56:32 2017 Samuel Osborne
** Last update Wed Mar 15 16:56:32 2017 Samuel Osborne
*/

#include "AGame.hpp"

arcade::games::AGame::AGame(arcade::games::AGame const &other) : map(other.map.getWidth(), other.map.getHeight())
{
  if (this != &other)
    {
      this->player = other.player;
    }
}

arcade::games::AGame &arcade::games::AGame::operator=(arcade::games::AGame const &other)
{
  if (this != &other)
    {
      this->player = other.player;
    }
  return (*this);
}

std::vector<arcade::Enemy*>	arcade::games::AGame::getEnemy() const
{
  return (this->enemies);
}
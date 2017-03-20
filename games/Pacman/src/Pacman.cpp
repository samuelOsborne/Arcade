/*
** Pacman.cpp for cpp_arcade in /home/osborn_s/Tek_2/cpp_arcade/Pacman.cpp
**
** Made by Samuel Osborne
** Login   <samuel.osborne@epitech.eu>
**
** Started on  Sat Mar 18 13:29:23 2017 Samuel Osborne
** Last update Sat Mar 18 13:29:23 2017 Samuel Osborne
*/

#include <iostream>
#include "Wall.hpp"
#include "Floor.hpp"
#include "../include/Pacman.hpp"

arcade::games::Pacman::Pacman() : arcade::games::AGame(20, 20)
{
  arcade::Position pos;
  pos.x = 15;
  pos.y = 15;
  this->player.setPos(pos);
  this->launch();
}

arcade::games::Pacman::Pacman(const arcade::games::Pacman &other)
 : arcade::games::AGame(20, 20)
{
  if (this != &other)
    {
      this->player = other.player;
    }
}

arcade::games::Pacman 				&arcade::games::Pacman::operator=(const Pacman& other)
{
  if (this != &other)
    {
      this->player = other.player;
    }
  return (*this);
}

void						arcade::games::Pacman::launch()
{
  arcade::Wall					*wall = new arcade::Wall(5, 5);

  this->map.setTile(wall->getPos(), wall);
  this->map.setTile(this->player.getPos(), &this->player);
}

arcade::Map					arcade::games::Pacman::getPacMap() const
{
  return (this->map);
}

arcade::Map					arcade::games::Pacman::receiveMapAndCtrl(arcade::Map map, arcade::CommandType cmd)
{
  arcade::Position				pos;

  pos = this->player.getPos();
  map.setTile(pos, &this->player);
  if (cmd == arcade::CommandType::GO_RIGHT)
    {
      pos.x++;
      this->player.move(pos);
      map.setTile(pos, &this->player);
    }
  else if (cmd == arcade::CommandType::GO_LEFT)
    {
      pos.x--;
      this->player.move(pos);
      map.setTile(pos, &this->player);
    }
  else if (cmd == arcade::CommandType::GO_UP)
    {
      pos.y--;
      this->player.move(pos);
      map.setTile(pos, &this->player);
    }
  else if (cmd == arcade::CommandType::GO_DOWN)
    {
      pos.y++;
      this->player.move(pos);
      map.setTile(pos, &this->player);
    }
  return (map);
}

/*
** PacmanFloor.cpp for cpp_arcade in /home/escorn_t/Rendu/cpp_arcade/PacmanFloor.cpp
**
** Made by Thomas Escorne
** Login    <thomas.escorne@epitech.eu>
**
** Started on Fri Apr 07 15:41:00 2017 Thomas Escorne
** Last update Fri Apr 07 15:41:00 2017 Thomas Escorne
**
*/

#include "Protocol.hpp"
#include "PacmanFloor.hh"

arcade::games::PacmanFloor::PacmanFloor(const uint16_t x, const uint16_t y)
 : Floor(x, y)
{
  this->asset = "./misc/Pacman/floor";
}

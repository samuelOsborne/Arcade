/*
** NEPipe.cpp for cpp_arcade in /home/escorn_t/Rendu/cpp_arcade/NEPipe.cpp
**
** Made by Thomas Escorne
** Login    <thomas.escorne@epitech.eu>
**
** Started on Fri Apr 07 16:30:34 2017 Thomas Escorne
** Last update Fri Apr 07 16:30:34 2017 Thomas Escorne 
**
*/

#include "Protocol.hpp"
#include "NEPipe.hh"

arcade::games::NEPipe::NEPipe(const uint16_t x, const uint16_t y)
 : Wall(x, y)
{
  this->asset = "./misc/Pacman/NEpipe";
}
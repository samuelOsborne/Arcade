/*
** SEPipe.cpp for cpp_arcade in /home/escorn_t/Rendu/cpp_arcade/SEPipe.cpp
**
** Made by Thomas Escorne
** Login    <thomas.escorne@epitech.eu>
**
** Started on Fri Apr 07 16:39:48 2017 Thomas Escorne
** Last update Fri Apr 07 16:39:48 2017 Thomas Escorne 
**
*/

#include "Protocol.hpp"
#include "SEPipe.hh"

arcade::games::SEPipe::SEPipe(const uint16_t x, const uint16_t y)
 : Wall(x, y)
{
  this->asset = "./misc/Pacman/SEpipe";
}
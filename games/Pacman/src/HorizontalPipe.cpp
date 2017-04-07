/*
** HorizontalPipe.cpp.cpp for cpp_arcade in /home/escorn_t/Rendu/cpp_arcade/HorizontalPipe.cpp.cpp
**
** Made by Thomas Escorne
** Login    <thomas.escorne@epitech.eu>
**
** Started on Fri Apr 07 16:25:45 2017 Thomas Escorne
** Last update Fri Apr 07 16:25:45 2017 Thomas Escorne 
**
*/

#include "Protocol.hpp"
#include "HorizontalPipe.hh"

arcade::games::HorizontalPipe::HorizontalPipe(const uint16_t x, const uint16_t y)
 : Wall(x, y)
{
  this->asset = "./misc/Pacman/Horizontalpipe";
}


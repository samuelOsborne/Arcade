/*
** VerticalPipe.cpp for cpp_arcade in /home/escorn_t/Rendu/cpp_arcade/VerticalPipe.cpp
**
** Made by Thomas Escorne
** Login    <thomas.escorne@epitech.eu>
**
** Started on Fri Apr 07 16:47:53 2017 Thomas Escorne
** Last update Fri Apr 07 16:47:53 2017 Thomas Escorne 
**
*/

#include "Protocol.hpp"
#include "VerticalPipe.hh"

arcade::games::VerticalPipe::VerticalPipe(const uint16_t x, const uint16_t y)
 : Wall(x, y)
{
  this->asset = "./misc/Pacman/Verticalpipe";
}
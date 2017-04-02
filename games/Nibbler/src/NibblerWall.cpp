/*
** NibblerWall.cpp for cpp_arcade in /home/villen_l/rendu/cpp_arcade/NibblerWall.cpp
**
** Made by Lucas Villeneuve
** Login   <lucas.villeneuve@epitech.eu>
**
** Started on  Sat Mar 25 20:08:01 2017 Lucas Villeneuve
** Last update Sat Mar 25 20:08:01 2017 Lucas Villeneuve
*/

#include "NibblerWall.hh"

arcade::games::NibblerWall::NibblerWall(const uint16_t x, const uint16_t y)
 : arcade::Wall(x, y)
{
  this->asset = "./misc/Nibbler/wall";
}
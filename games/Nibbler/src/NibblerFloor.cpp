/*
** NibblerFloor.cpp for cpp_arcade in /home/villen_l/rendu/cpp_arcade/NibblerFloor.cpp
**
** Made by Lucas Villeneuve
** Login   <lucas.villeneuve@epitech.eu>
**
** Started on  Sat Mar 25 20:11:24 2017 Lucas Villeneuve
** Last update Sat Mar 25 20:11:24 2017 Lucas Villeneuve
*/

#include "NibblerFloor.hh"

arcade::games::NibblerFloor::NibblerFloor(const uint16_t x, const uint16_t y)
 : arcade::Floor(x, y)
{
  this->asset = "./misc/Nibbler/floor";
};
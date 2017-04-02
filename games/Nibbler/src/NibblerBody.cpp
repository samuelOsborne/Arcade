/*
** NibblerBody.cpp for cpp_arcade in /home/villen_l/rendu/cpp_arcade/NibblerBody.cpp
**
** Made by Lucas Villeneuve
** Login   <lucas.villeneuve@epitech.eu>
**
** Started on  Fri Mar 24 13:45:18 2017 Lucas Villeneuve
** Last update Fri Mar 24 13:45:18 2017 Lucas Villeneuve
*/

#include "NibblerBody.hh"

arcade::games::NibblerBody::NibblerBody(const uint16_t x, const uint16_t y)
 : arcade::Enemy(x, y)
{
  this->asset = "./misc/Nibbler/snakebody";
}
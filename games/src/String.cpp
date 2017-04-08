/*
** String.cpp for cpp_arcade in /home/villen_l/rendu/cpp_arcade/String.cpp
**
** Made by Lucas Villeneuve
** Login   <lucas.villeneuve@epitech.eu>
**
** Started on  Fri Apr 07 17:43:05 2017 Lucas Villeneuve
** Last update Fri Apr 07 17:43:05 2017 Lucas Villeneuve
*/

#include "String.hh"

arcade::String::String(uint16_t x, uint16_t y, const std::string &str)
 : AGameObject(x, y)
{
  this->type = arcade::TileType::OTHER;
  this->asset = str;
}
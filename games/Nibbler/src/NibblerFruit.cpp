/*
** NibblerFruit.cpp for cpp_arcade in /home/villen_l/rendu/cpp_arcade/NibblerFruit.cpp
**
** Made by Lucas Villeneuve
** Login   <lucas.villeneuve@epitech.eu>
**
** Started on  Sat Mar 25 20:09:44 2017 Lucas Villeneuve
** Last update Sat Mar 25 20:09:44 2017 Lucas Villeneuve
*/

#include "NibblerFruit.hh"

arcade::games::NibblerFruit::NibblerFruit(const uint16_t x, const uint16_t y)
 : arcade::Pickup(x, y)
{
  this->asset = "./misc/Nibbler/fruit";
  this->secondAsset = "./misc/Nibbler/floor";
}
/*
** Map.cpp for cpp_arcade in /home/villen_l/rendu/cpp_arcade/Map.cpp
**
** Made by Lucas Villeneuve
** Login   <lucas.villeneuve@epitech.eu>
**
** Started on  Tue Mar 14 11:28:56 2017 Lucas Villeneuve
** Last update Tue Mar 14 11:28:56 2017 Lucas Villeneuve
*/

#include <iostream>
#include "Map.hh"
#include "Floor.hpp"

arcade::Map::Map(const uint16_t _width, const uint16_t _height)
 : width(_width), height(_height)
{
  uint16_t				i;
  uint16_t				j;
  std::vector<arcade::IGameObject*>	tmp;

  i = 0;
  while (i < _height)
    {
      tmp.clear();
      j = 0;
      while (j < _width)
	tmp.push_back(new arcade::Floor(j++, i));
      this->tiles.push_back(tmp);
      i++;
    }
}

arcade::Map::Map(const Map &other)
 : width(other.width), height(other.height)
{
  if (this != &other)
    this->tiles = other.tiles;
}

arcade::Map	&arcade::Map::operator=(const Map &other)
{
  if (this != &other)
    this->tiles = other.tiles;
  return (*this);
}

uint16_t	arcade::Map::getWidth() const
{
  return (this->width);
}

uint16_t	arcade::Map::getHeight() const
{
  return (this->height);
}

arcade::IGameObject	*arcade::Map::getTile(const arcade::Position &pos) const
{
  return (this->tiles[pos.y][pos.x]);
}

void	arcade::Map::setTile(const arcade::Position &pos, arcade::IGameObject *type)
{
  this->tiles[pos.y][pos.x] = type;
}
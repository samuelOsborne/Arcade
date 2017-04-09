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
#include "Floor.hh"
#include "Map.hh"

arcade::Map::Map(const uint16_t _width, const uint16_t _height)
 : width(_width), height(_height)
{
  uint16_t					i;
  uint16_t					j;
  std::vector<arcade::games::IGameObject*>	tmp;

  i = 0;
  while (i < _height)
    {
      tmp.clear();
      j = 0;
      while (j++ < _width)
	tmp.push_back(0);
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

arcade::Map::~Map()
{
  std::vector<std::vector<arcade::games::IGameObject*>>::iterator	it;

  it = this->tiles.begin();
  while (it != this->tiles.end())
    {
      (*it).clear();
      ++it;
    }
}

uint16_t	arcade::Map::getWidth() const
{
  return (this->width);
}

uint16_t	arcade::Map::getHeight() const
{
  return (this->height);
}

arcade::games::IGameObject	*arcade::Map::getTile(const arcade::Position &pos) const
{
  return (this->tiles[pos.y][pos.x]);
}

arcade::games::IGameObject	*arcade::Map::getTile(uint16_t x, uint16_t y) const
{
  return (this->tiles[y][x]);
}

void	arcade::Map::setTile(const arcade::Position &pos, arcade::games::IGameObject *tile)
{
  this->tiles[pos.y][pos.x] = tile;
}

void arcade::Map::setTile(uint16_t x, uint16_t y, arcade::games::IGameObject *tile)
{
  this->tiles[y][x] = tile;
}

void	arcade::Map::deleteTile(__attribute__((unused))const arcade::Position &pos)
{
}

void 	arcade::Map::deleteTile(__attribute__((unused))uint16_t x,
				    __attribute__((unused))uint16_t y)
{
}
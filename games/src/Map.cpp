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

arcade::games::Map::Map(const int16_t _width, const int16_t _height)
 : width(_width), height(_height)
{
  int16_t	i;

  i = 0;
  while (i++ < _height)
    this->tiles.push_back(std::vector<arcade::TileType>(static_cast<unsigned long>(_width),
							  arcade::TileType::EMPTY));
  this->mapChar[arcade::TileType::BLOCK] = 'X';
  this->mapChar[arcade::TileType::EMPTY] = ' ';
  this->mapChar[arcade::TileType::EVIL_DUDE] = 'E';
  this->mapChar[arcade::TileType::EVIL_SHOOT] = '-';
  this->mapChar[arcade::TileType::MY_SHOOT] = '~';
  this->mapChar[arcade::TileType::POWERUP] = '*';
  this->mapChar[arcade::TileType::OTHER] = '@';
  this->mapChar[arcade::TileType::OBSTACLE] = '#';
}

arcade::TileType	&arcade::games::Map::getTile(const Position &pos)
{
  return (this->tiles[pos.y][pos.x]);
}

void	arcade::games::Map::setTile(const Position &pos, const arcade::TileType &type)
{
  this->tiles[pos.y][pos.x] = type;
}

void		arcade::games::Map::drawMap()
{
  int16_t	i;
  int16_t 	j;

  i = 0;
  while (i < this->height)
    {
      j = 0;
      while (j < this->width)
	std::cout << this->mapChar.find(this->tiles[i][j++])->second;
      std::cout << std::endl;
      i++;
    }
}
/*

int main()
{
  arcade::games::Map map(10, 10);
  arcade::Position pos;

  pos.x = 0;
  pos.y = 0;
  while (pos.x < 10)
    {
      map.setTile(pos, arcade::TileType::BLOCK);
      pos.x++;
    }
  pos.x = 0;
  pos.y = 1;
  while (pos.y < 9)
    {
      pos.x = 0;
      map.setTile(pos, arcade::TileType::BLOCK);
      pos.x = 9;
      map.setTile(pos, arcade::TileType::BLOCK);
      pos.y++;
    }
  pos.x = 0;
  while (pos.x < 10)
    {
      map.setTile(pos, arcade::TileType::BLOCK);
      pos.x++;
    }

  pos.x = 5;
  pos.y = 4;
  map.setTile(pos, arcade::TileType::OTHER);

  pos.x = 6;
  map.setTile(pos, arcade::TileType::MY_SHOOT);

  pos.y = 3;
  pos.x = 1;
  map.setTile(pos, arcade::TileType::EVIL_DUDE);
  pos.x = 8;
  map.setTile(pos, arcade::TileType::EVIL_DUDE);

  pos.y = 4;
  map.setTile(pos, arcade::TileType::EVIL_SHOOT);

  map.drawMap();
}*/

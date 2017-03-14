/*
** Map.hh for cpp_arcade in /home/villen_l/rendu/cpp_arcade/Map.hh
**
** Made by Lucas Villeneuve
** Login   <lucas.villeneuve@epitech.eu>
**
** Started on  Tue Mar 14 11:18:10 2017 Lucas Villeneuve
** Last update Tue Mar 14 11:18:10 2017 Lucas Villeneuve
*/

#ifndef MAP_HH_
# define MAP_HH_

# include <vector>
# include <map>
# include "Protocol.hpp"

namespace						arcade
{
  namespace 						games
  {
    class 						Map
    {
      int16_t 						width;
      int16_t 						height;
      std::vector<std::vector<arcade::TileType>>	tiles;
      std::map<arcade::TileType, char>			mapChar;

     public:
      Map(const int16_t _width, const int16_t _height);
      ~Map() {};

      arcade::TileType 					&getTile(const Position &pos);
      void 						setTile(const Position &pos, const arcade::TileType &type);
      void 						drawMap();
    };

  };
};

#endif // !MAP_HH_

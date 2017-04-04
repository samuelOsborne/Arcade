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
# include "IMap.hh"
# include "IArcadeLibrary.hh"
# include "IGameObject.hpp"
# include "Protocol.hpp"

namespace						arcade
{
  class 						Map : public arcade::IMap
  {
    const uint16_t 					width;
    const uint16_t 					height;
    std::vector<std::vector<arcade::IGameObject*>>	tiles;

   public:
    Map(const uint16_t _width, const uint16_t _height);
    Map(const Map &other);
    Map &operator=(const Map &other);
    ~Map() {};

    virtual uint16_t 					getWidth() const;
    virtual uint16_t 					getHeight() const;
    arcade::IGameObject					*getTile(const arcade::Position &pos) const;
    void 						setTile(const arcade::Position &pos,
								arcade::IGameObject *type);
    virtual void 					deleteTile(const Position &pos);
  };

};

#endif // !MAP_HH_

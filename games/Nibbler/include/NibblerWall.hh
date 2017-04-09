/*
** NibblerWall.hh for cpp_arcade in /home/villen_l/rendu/cpp_arcade/NibblerWall.hh
**
** Made by Lucas Villeneuve
** Login   <lucas.villeneuve@epitech.eu>
**
** Started on  Fri Mar 24 10:40:33 2017 Lucas Villeneuve
** Last update Fri Mar 24 10:40:33 2017 Lucas Villeneuve
*/

#ifndef NIBBLERWALL_HH_
# define NIBBLERWALL_HH_

#include "Wall.hh"

namespace		arcade
{
  namespace		games
  {
    class 		NibblerWall : public arcade::Wall
    {
     public:
      NibblerWall(const uint16_t x, const uint16_t y);
      NibblerWall(const NibblerWall &other) = delete;
      NibblerWall &operator=(const NibblerWall &other) = delete;
      ~NibblerWall() {};
    };

  };
};

#endif // !CPP_ARCADE_NIBBLERWALL_HH

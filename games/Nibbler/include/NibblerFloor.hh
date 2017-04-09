/*
** NibblerFloor.hh for cpp_arcade in /home/villen_l/rendu/cpp_arcade/NibblerFloor.hh
**
** Made by Lucas Villeneuve
** Login   <lucas.villeneuve@epitech.eu>
**
** Started on  Fri Mar 24 10:28:24 2017 Lucas Villeneuve
** Last update Fri Mar 24 10:28:24 2017 Lucas Villeneuve
*/

#ifndef NIBBLERFLOOR_HH_
# define NIBBLERFLOOR_HH_

# include "Floor.hh"

namespace	arcade
{
  namespace	games
  {
    class	NibblerFloor : public arcade::Floor
    {
     public:
      NibblerFloor(const uint16_t x, const uint16_t y);
      NibblerFloor(const NibblerFloor &other) = delete;
      NibblerFloor &operator=(const NibblerFloor &other) = delete;
      ~NibblerFloor() {};
    };

  };
};

#endif // !NIBBLERFLOOR_HH_

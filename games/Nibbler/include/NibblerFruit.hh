/*
** NibblerFruit.hh for cpp_arcade in /home/villen_l/rendu/cpp_arcade/NibblerFruit.hh
**
** Made by Lucas Villeneuve
** Login   <lucas.villeneuve@epitech.eu>
**
** Started on  Fri Mar 24 17:15:01 2017 Lucas Villeneuve
** Last update Fri Mar 24 17:15:01 2017 Lucas Villeneuve
*/

#ifndef NIBBLERFRUIT_HH_
# define NIBBLERFRUIT_HH_

# include "Pickup.hpp"

namespace		arcade
{
  namespace 		games
  {
    class 		NibblerFruit : public arcade::Pickup
    {
     public:
      NibblerFruit(const uint16_t x, const uint16_t y);
      NibblerFruit(const NibblerFruit &) = delete;
      NibblerFruit &operator=(const NibblerFruit &) = delete;
      ~NibblerFruit() {};
    };
  };
};

#endif // !NIBBLERFRUIT_HH_

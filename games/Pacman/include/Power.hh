/*
** Power.hh for cpp_arcade in /home/escorn_t/Rendu/cpp_arcade/Power.hh
**
** Made by Thomas Escorne
** Login    <thomas.escorne@epitech.eu>
**
** Started on Sat Apr 08 11:23:07 2017 Thomas Escorne
** Last update Sat Apr 08 11:23:07 2017 Thomas Escorne 
**
*/

#ifndef CPP_ARCADE_POWER_HH
# define CPP_ARCADE_POWER_HH

# include "Pickup.hh"

namespace 	arcade
{
  namespace 	games
  {
    class	Power : public arcade::Pickup
    {
     public:
      Power(const uint16_t x, const uint16_t y);
      Power(const Power& other);
      Power	&operator=(const Power &);
      virtual ~Power() {};
    };
  };
};

#endif //CPP_ARCADE_POWER_HH

/*
** Pacgum.hh for cpp_arcade in /home/osborn_s/Tek_2/cpp_arcade/Pacgum.hh
**
** Made by Samuel Osborne
** Login   <samuel.osborne@epitech.eu>
**
** Started on  Wed Mar 22 10:18:07 2017 Samuel Osborne
** Last update Wed Mar 22 10:18:07 2017 Samuel Osborne
*/

#ifndef PACGUM_HH_
# define PACGUM_HH_

# include "Pickup.hh"

namespace 	arcade
{
  namespace 	games
  {
    class	Pacgum : public arcade::Pickup
    {
     public:
      Pacgum(const uint16_t x, const uint16_t y);
      Pacgum(const Pacgum& other);
      Pacgum &operator=(const Pacgum&);
      virtual ~Pacgum() {};
    };
  };
};

#endif //PACGUM_HH

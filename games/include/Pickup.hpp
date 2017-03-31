/*
** Pickup.hpp for cpp_arcade in /home/osborn_s/Tek_2/cpp_arcade/Pickup.hpp
**
** Made by Samuel Osborne
** Login   <samuel.osborne@epitech.eu>
**
** Started on  Tue Mar 14 16:19:59 2017 Samuel Osborne
** Last update Tue Mar 14 16:19:59 2017 Samuel Osborne
*/

#ifndef PICKUP_HPP_
# define PICKUP_HPP_

# include "AObjects.hpp"

namespace 		arcade
{
  class			Pickup : public arcade::AObjects
  {
   public:
    Pickup(const uint16_t, const uint16_t);
    Pickup(const Pickup&);
    Pickup &operator=(const Pickup&);
    ~Pickup() {};

    void		move(arcade::Position& pos);
    virtual void	setTileType();
  };

};

#endif // !PICKUP_HPP_

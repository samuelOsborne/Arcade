/*
** Projectile.hpp for cpp_arcade in /home/osborn_s/Tek_2/cpp_arcade/Projectile.hpp
**
** Made by Samuel Osborne
** Login   <samuel.osborne@epitech.eu>
**
** Started on  Tue Mar 14 16:26:35 2017 Samuel Osborne
** Last update Tue Mar 14 16:26:35 2017 Samuel Osborne
*/

#ifndef PROJECTILE_HPP_
# define PROJECTILE_HPP_

#include "AObjects.hh"

namespace 		arcade
{
  class			Projectile : public arcade::AObjects
  {
   public:
    Projectile(const uint16_t x, const uint16_t y);
    Projectile(const Projectile&);
    Projectile &operator=(const Projectile&);
    ~Projectile() {};

    void		move(arcade::Position& pos);
  };

};

#endif // !PROJECTILE_HPP_

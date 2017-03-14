/*
** Projectile.hpp for cpp_arcade in /home/osborn_s/Tek_2/cpp_arcade/Projectile.hpp
**
** Made by Samuel Osborne
** Login   <samuel.osborne@epitech.eu>
**
** Started on  Tue Mar 14 16:26:35 2017 Samuel Osborne
** Last update Tue Mar 14 16:26:35 2017 Samuel Osborne
*/

#ifndef ARCADE_PROJECTILE_HPP_
# define ARCADE_PROJECTILE_HPP_

#include "Objects.hpp"

namespace 		arcade
{
  namespace 		games
  {
    class		Projectile : public arcade::games::Objects
    {
     public:
      Projectile();
      Projectile(const Projectile&);
      const Projectile&	operator=(const Projectile&);
      void		move(arcade::Position& pos);
      ~Projectile() {};
    };
  }
}

#endif //ARCADE_PROJECTILE_HPP_

/*
** Objects.hpp for cpp_arcade in /home/osborn_s/Tek_2/cpp_arcade/Objects.h
**
** Made by Samuel Osborne
** Login   <samuel.osborne@epitech.eu>
**
** Started on  Tue Mar 14 13:40:06 2017 Samuel Osborne
** Last update Tue Mar 14 13:40:06 2017 Samuel Osborne
*/

#ifndef ARCADE_OBJECTS_HPP_
# define ARCADE_OBJECTS_HPP_

#include "Arcade.hpp"
#include "Protocol.hpp"

namespace 		arcade
{
  namespace 		games
  {
    class 		Objects
    {
     protected:
      arcade::Position	pos;
      arcade::TileType	type;
     public:
      Objects();
      Objects(const Objects&);
      const Objects&	operator=(const Objects&);
      int		getPosX() const;
      int		getPosY() const;
      void		setPos(const arcade::Position& pos);
      virtual 		~Objects() {};
      virtual void	move(const arcade::Position&) = 0;
    };
  }
}

#endif //CPP_ARCADE_OBJECTS_HPP_

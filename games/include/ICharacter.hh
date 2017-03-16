/*
** ICharacter.hpp for cpp_arcade in /home/osborn_s/rendu/cpp_arcade/Arcade.hh
**
** Made by Samuel Osborne
** Login   <samuel.osborne@epitech.eu>
**
** Started on  Sun Mar 12 19:00:40 2017 Samuel Osborne
** Last update Sun Mar 12 19:00:40 2017 Samuel Osborne
*/

#ifndef ICHARACTER_HH_
# define ICHARACTER_HH_

#include "AGameObject.hpp"
#include "Arcade.hpp"

namespace 			arcade
{
  namespace 			games
  {
    class 			ICharacter : arcade::games::AGameObject
    {
     public:
      virtual                	~ICharacter() {};

      virtual arcade::Position 	getPos() const = 0;
      virtual void 		setPos(const arcade::Position &pos) = 0;
      virtual void		setTileType() = 0;
      virtual void		move(const arcade::Position&) = 0;
    };
  };
};

#endif // !ICHARACTER_HH_

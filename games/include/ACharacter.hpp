/*
** ACharacter.hpp for cpp_arcade in /home/osborn_s/Tek_2/cpp_arcade/ACharacter.hpp
**
** Made by Samuel Osborne
** Login   <samuel.osborne@epitech.eu>
**
** Started on  Tue Mar 14 11:27:32 2017 Samuel Osborne
** Last update Tue Mar 14 11:27:32 2017 Samuel Osborne
*/

#ifndef ACHARACTER_HPP_
# define ACHARACTER_HPP_

#include "Protocol.hpp"
#include "AGameObject.hpp"

namespace 		arcade
{
  namespace 		games
  {
    class ACharacter : 	public arcade::games::AGameObject
    {
     public:
      virtual ~ACharacter() {};

      ACharacter(uint16_t, uint16_t);
      ACharacter(const ACharacter &);
      ACharacter&	operator=(const ACharacter&);
      virtual void		setTileType() = 0;
      virtual void 		move(const arcade::Position&) = 0;
      virtual void 		setPos(const arcade::Position &pos);
      virtual arcade::Position 		getPos() const;
    };
  };
}

#endif //ACHARACTER_HPP_

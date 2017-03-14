/*
** ACharacter.hpp for cpp_arcade in /home/osborn_s/Tek_2/cpp_arcade/ACharacter.hpp
**
** Made by Samuel Osborne
** Login   <samuel.osborne@epitech.eu>
**
** Started on  Tue Mar 14 11:27:32 2017 Samuel Osborne
** Last update Tue Mar 14 11:27:32 2017 Samuel Osborne
*/

#ifndef ARCADE_ACHARACTER_HPP_
#define ARCADE_ACHARACTER_HPP_

#include "Protocol.hpp"
#include "ICharacter.hh"

namespace 		arcade
{
  namespace 		games
  {
    class ACharacter : 	public ICharacter
    {
     protected:
      arcade::Position	pos;
      int 		health;
      int 		powerup;
     public:
      virtual int 	getPosX(void) const;
      virtual int 	getPosY(void) const;
      virtual void 	setPosX(const int);
      virtual void 	setPosY(const int);
      ACharacter();
      ACharacter(const ACharacter &);
      ACharacter&	operator=(const ACharacter&);
      virtual void 	move(const arcade::Position&) = 0;
      virtual        	~ACharacter() {};
    };
  };
}

#endif //ARCADE_ACHARACTER_HPP

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
 #define ICHARACTER_HH_

#include "Arcade.hpp"

namespace 			arcade
{
  namespace 			games
  {
    class 			ICharacter
    {
     public:
      virtual                	~ICharacter() {};
      virtual int 		getPosX(void) const = 0;
      virtual int 		getPosY(void) const = 0;
      virtual void 		setPosX(const int) = 0;
      virtual void 		setPosY(const int) = 0;
    };
  }
}

#endif // !ICHARACTER_HH_

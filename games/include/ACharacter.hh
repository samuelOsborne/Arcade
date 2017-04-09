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

# include "Protocol.hpp"
# include "AGameObject.hh"

namespace 			arcade
{
  class				ACharacter : public arcade::AGameObject
  {
   public:
    ACharacter(uint16_t, uint16_t);
    ACharacter(const ACharacter &);
    ACharacter &operator=(const ACharacter&);
    virtual ~ACharacter() {};

    virtual void 		move(const arcade::Position&) = 0;
  };

};

#endif // !ACHARACTER_HPP_

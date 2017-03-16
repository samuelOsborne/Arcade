/*
** Enemy.hpp for cpp_arcade in /home/osborn_s/Tek_2/cpp_arcade/Enemy.hpp
**
** Made by Samuel Osborne
** Login   <samuel.osborne@epitech.eu>
**
** Started on  Tue Mar 14 13:31:58 2017 Samuel Osborne
** Last update Tue Mar 14 13:31:58 2017 Samuel Osborne
*/

#ifndef ENEMY_HPP_
# define ENEMY_HPP_

#include "Protocol.hpp"
#include "ACharacter.hpp"

namespace 		arcade
{
  namespace 		games
  {
    class 		Enemy : public arcade::games::ACharacter
    {
     public:
      Enemy() : ACharacter() {};
      Enemy(const Enemy &);
      Enemy &operator=(const Enemy &);
      virtual void 	move(const arcade::Position &);
      ~Enemy() {};
    };
  };
};

#endif //ENEMY_HPP_

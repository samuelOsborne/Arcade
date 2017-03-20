/*
** Ghost.hpp for cpp_arcade in /home/osborn_s/Tek_2/cpp_arcade/Ghost.hpp
**
** Made by Samuel Osborne
** Login   <samuel.osborne@epitech.eu>
**
** Started on  Sat Mar 18 18:52:39 2017 Samuel Osborne
** Last update Sat Mar 18 18:52:39 2017 Samuel Osborne
*/

#ifndef GHOST_HPP_
# define GHOST_HPP_

#include "Enemy.hpp"

namespace 		arcade
{
  namespace 		games
  {
    class Ghost : public arcade::Enemy
    {
     public:
      Ghost() : Enemy(10, 10)
      {
	this->asset = "./misc/Pacman/RedGhost";
      };

      Ghost(const Ghost &);
      Ghost &operator=(const Ghost &);
      ~Ghost() {};
    };

  };
};

#endif //GHOST_HPP_

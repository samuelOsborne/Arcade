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

namespace 			arcade
{
  namespace 			games
  {
    class Ghost : public 	arcade::Enemy
    {
      arcade::CommandType	direction;

     public:
      Ghost(uint16_t x, uint16_t y) : Enemy(x, y)
      {
	this->direction = arcade::CommandType::GO_UP;
	this->asset = "./misc/Pacman/RedGhost";
      };

      Ghost(const Ghost &);
      Ghost &operator=(const Ghost &);
      ~Ghost() {};

      arcade::CommandType	getDirection() const
      {return (this->direction);}
      void 			setDirection(const arcade::CommandType &dir)
      {this->direction = dir;}
    };

  };
};

#endif //GHOST_HPP_

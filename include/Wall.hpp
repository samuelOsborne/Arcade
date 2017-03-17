/*
** Wall.hpp for cpp_arcade in /home/osborn_s/Tek_2/cpp_arcade/Wall.hpp
**
** Made by Samuel Osborne
** Login   <samuel.osborne@epitech.eu>
**
** Started on  Fri Mar 17 13:06:12 2017 Samuel Osborne
** Last update Fri Mar 17 13:06:12 2017 Samuel Osborne
*/

#ifndef WALL_HPP_
# define WALL_HPP_

# include "ABlock.hpp"

namespace 		arcade
{
  class 		Wall : public arcade::ABlock
  {
   public:
    Wall(const uint16_t, const uint16_t);
    Wall(const Wall &);
    const Wall 	&operator=(const Wall &);
    ~Wall() {};
  };

};

#endif // !WALL_HPP

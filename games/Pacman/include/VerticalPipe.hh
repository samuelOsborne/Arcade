/*
** VerticalPipe.hh for cpp_arcade in /home/villen_l/rendu/cpp_arcade/VerticalPipe.hh
**
** Made by Lucas Villeneuve
** Login   <lucas.villeneuve@epitech.eu>
**
** Started on  Sat Apr 01 11:05:31 2017 Lucas Villeneuve
** Last update Sat Apr 01 11:05:31 2017 Lucas Villeneuve
*/

#ifndef VERTICALPIPE_HH_
# define VERTICALPIPE_HH_

 # include "Wall.hpp"

namespace			arcade
{
  namespace 			games
  {
    class			VerticalPipe : public arcade::Wall
    {
     public:
      VerticalPipe(const uint16_t x, const uint16_t y)
       : arcade::Wall(x, y)
      {this->asset = "./misc/Pacman/Verticalpipe";}
      VerticalPipe(const VerticalPipe &) = delete;
      VerticalPipe &operator=(const VerticalPipe &) = delete;
      ~VerticalPipe() {};
    };
  };
};

#endif // !VERTICALPIPE_HH_

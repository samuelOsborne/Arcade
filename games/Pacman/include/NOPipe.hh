/*
** NOPipe.hh for cpp_arcade in /home/villen_l/rendu/cpp_arcade/NOPipe.hh
**
** Made by Lucas Villeneuve
** Login   <lucas.villeneuve@epitech.eu>
**
** Started on  Sat Apr 01 11:08:34 2017 Lucas Villeneuve
** Last update Sat Apr 01 11:08:34 2017 Lucas Villeneuve
*/

#ifndef NOPIPE_HH_
# define NOPIPE_HH_

# include "Wall.hpp"

namespace			arcade
{
  namespace 			games
  {
    class			NOPipe : public arcade::Wall
    {
     public:
      NOPipe(const uint16_t x, const uint16_t y);
      NOPipe(const NOPipe &) = delete;
      NOPipe &operator=(const NOPipe &) = delete;
      ~NOPipe() {};
    };
  };
};

#endif // !NOPIPE_HH_

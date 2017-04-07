/*
** NEPipe.hh for cpp_arcade in /home/villen_l/rendu/cpp_arcade/NEPipe.hh
**
** Made by Lucas Villeneuve
** Login   <lucas.villeneuve@epitech.eu>
**
** Started on  Sat Apr 01 11:07:32 2017 Lucas Villeneuve
** Last update Sat Apr 01 11:07:32 2017 Lucas Villeneuve
*/

#ifndef NEPIPE_HH_
# define NEPIPE_HH_

# include "Wall.hpp"

namespace			arcade
{
  namespace 			games
  {
    class			NEPipe : public arcade::Wall
    {
     public:
      NEPipe(const uint16_t x, const uint16_t y);
      NEPipe(const NEPipe &) = delete;
      NEPipe &operator=(const NEPipe &) = delete;
      ~NEPipe() {};
    };
  };
};

#endif // !NEPIPE_HH_

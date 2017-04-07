/*
** HorizontalPipe.hh for cpp_arcade in /home/villen_l/rendu/cpp_arcade/HorizontalPipe.hh
**
** Made by Lucas Villeneuve
** Login   <lucas.villeneuve@epitech.eu>
**
** Started on  Sat Apr 01 10:52:04 2017 Lucas Villeneuve
** Last update Sat Apr 01 10:52:04 2017 Lucas Villeneuve
*/

#ifndef HORIZONTALPIPE_HH_
# define HORIZONTALPIPE_HH_

# include "Wall.hpp"

namespace			arcade
{
  namespace 			games
  {
    class			HorizontalPipe : public arcade::Wall
    {
     public:
      HorizontalPipe(const uint16_t x, const uint16_t y);
      HorizontalPipe(const HorizontalPipe &) = delete;
      HorizontalPipe &operator=(const HorizontalPipe &) = delete;
      ~HorizontalPipe() {};
    };
  };
};

#endif // !HORIZONTALPIPE_HH_

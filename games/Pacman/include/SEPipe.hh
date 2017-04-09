/*
** SEPipe.hh for cpp_arcade in /home/villen_l/rendu/cpp_arcade/SEPipe.hh
**
** Made by Lucas Villeneuve
** Login   <lucas.villeneuve@epitech.eu>
**
** Started on  Sat Apr 01 11:14:36 2017 Lucas Villeneuve
** Last update Sat Apr 01 11:14:36 2017 Lucas Villeneuve
*/

#ifndef SEPIPE_HH_
# define SEPIPE_HH_

# include "Wall.hh"

namespace			arcade
{
  namespace 			games
  {
    class			SEPipe : public arcade::Wall
    {
     public:
      SEPipe(const uint16_t x, const uint16_t y);
      SEPipe(const SEPipe &) = delete;
      SEPipe &operator=(const SEPipe &) = delete;
      ~SEPipe() {};
    };
  };
};

#endif // !SEPIPE_HH_

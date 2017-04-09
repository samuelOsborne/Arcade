/*
** SOPipe.hh for cpp_arcade in /home/villen_l/rendu/cpp_arcade/SOPipe.hh
**
** Made by Lucas Villeneuve
** Login   <lucas.villeneuve@epitech.eu>
**
** Started on  Sat Apr 01 11:09:30 2017 Lucas Villeneuve
** Last update Sat Apr 01 11:09:30 2017 Lucas Villeneuve
*/

#ifndef SOPIPE_HH_
# define SOPIPE_HH_

# include "Wall.hh"

namespace			arcade
{
  namespace 			games
  {
    class			SOPipe : public arcade::Wall
    {
     public:
      SOPipe(const uint16_t x, const uint16_t y);
      SOPipe(const SOPipe &) = delete;
      SOPipe &operator=(const SOPipe &) = delete;
      ~SOPipe() {};
    };
  };
};

#endif // !SOPIPE_HH_

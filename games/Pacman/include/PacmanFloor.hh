/*
** PacmanFloor.hh for cpp_arcade in /home/villen_l/rendu/cpp_arcade/PacmanFloor.hh
**
** Made by Lucas Villeneuve
** Login   <lucas.villeneuve@epitech.eu>
**
** Started on  Sat Apr 01 11:17:41 2017 Lucas Villeneuve
** Last update Sat Apr 01 11:17:41 2017 Lucas Villeneuve
*/

#ifndef PACMANFLOOR_HH_
# define PACMANFLOOR_HH_

# include "Floor.hpp"

namespace			arcade
{
  namespace 			games
  {
    class			PacmanFloor : public arcade::Floor
    {
     public:
      PacmanFloor(const uint16_t x, const uint16_t y);
      PacmanFloor(const PacmanFloor &) = delete;
      PacmanFloor &operator=(const PacmanFloor &) = delete;
      ~PacmanFloor() {};
    };
  };
};

#endif // !PACMANFLOOR_HH_

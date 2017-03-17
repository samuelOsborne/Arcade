/*
** Floor.hpp for cpp_arcade in /home/osborn_s/Tek_2/cpp_arcade/Floor.hpp
**
** Made by Samuel Osborne
** Login   <samuel.osborne@epitech.eu>
**
** Started on  Fri Mar 17 13:20:36 2017 Samuel Osborne
** Last update Fri Mar 17 13:20:36 2017 Samuel Osborne
*/

#ifndef FLOOR_HPP_
# define FLOOR_HPP_

#include "ABlock.hpp"

namespace 		arcade
{
  namespace 		games
  {
    class 		Floor : public ABlock
    {
     public:
      ~Floor() {};

      Floor();
      Floor(const Floor &);
      const Floor 	&operator=(const Floor &);
    };
  };
};

#endif //FLOOR_HPP_

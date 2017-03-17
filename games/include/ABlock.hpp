/*
** ABlock.hpp for cpp_arcade in /home/osborn_s/Tek_2/cpp_arcade/ABlock.hpp
**
** Made by Samuel Osborne
** Login   <samuel.osborne@epitech.eu>
**
** Started on  Thu Mar 16 18:15:40 2017 Samuel Osborne
** Last update Thu Mar 16 18:15:40 2017 Samuel Osborne
*/

#ifndef ABLOCK_HPP_
# define ABLOCK_HPP_

#include "AGameObject.hpp"

namespace 			arcade
{
  namespace 			games
  {
    class			ABlock : public arcade::games::AGameObject
    {
     public:
      virtual			~ABlock() {};

      ABlock();
      ABlock(const ABlock&);
      ABlock&operator=(const ABlock&);
      virtual arcade::Position 	getPos() const;
      virtual void 		setPos(const arcade::Position &pos);
    };
  };
};

#endif //ABLOCK_HPP_

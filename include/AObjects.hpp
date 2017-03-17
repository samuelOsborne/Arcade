/*
** Objects.hpp for cpp_arcade in /home/osborn_s/Tek_2/cpp_arcade/Objects.h
**
** Made by Samuel Osborne
** Login   <samuel.osborne@epitech.eu>
**
** Started on  Tue Mar 14 13:40:06 2017 Samuel Osborne
** Last update Tue Mar 14 13:40:06 2017 Samuel Osborne
*/

#ifndef AOBJECTS_HPP_
# define AOBJECTS_HPP_

# include "AGameObject.hpp"
# include "Protocol.hpp"

namespace 			arcade
{
  class 			AObjects : public arcade::AGameObject
  {
   public:
    AObjects(const uint16_t, const uint16_t);
    AObjects(const AObjects&);
    AObjects &operator=(const AObjects&);
    virtual ~AObjects() {};

    virtual void		setTileType() = 0;
    virtual arcade::Position 	getPos() const;
    virtual void 		setPos(const arcade::Position &pos);
  };

};

#endif // !AOBJECTS_HPP_

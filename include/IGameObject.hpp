/*
** IGameObject.hpp for cpp_arcade in /home/osborn_s/Tek_2/cpp_arcade/IGameObject.hpp
**
** Made by Samuel Osborne
** Login   <samuel.osborne@epitech.eu>
**
** Started on  Wed Mar 15 17:11:37 2017 Samuel Osborne
** Last update Wed Mar 15 17:11:37 2017 Samuel Osborne
*/

#ifndef ARCADE_IGAMEOBJECT_HPP_
# define ARCADE_IGAMEOBJECT_HPP_

# include <string>
# include "Protocol.hpp"

namespace 			arcade
{
  class 			IGameObject
  {
   public:
    virtual			~IGameObject() {};

    virtual arcade::Position 	getPos() const = 0;
    virtual void 		setPos(const arcade::Position &pos) = 0;
    virtual std::string 	getSprite() const = 0;
    virtual void 		setSprite(const std::string &) = 0;
    virtual arcade::TileType 	getTileType() const = 0;
    virtual void		setTileType(const arcade::TileType &) = 0;
  };

};

#endif // !ARCADE_IGAMEOBJECT_HPP_

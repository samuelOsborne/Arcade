/*
** AGameObject.hpp for cpp_arcade in /home/osborn_s/Tek_2/cpp_arcade/AGameObject.hpp
**
** Made by Samuel Osborne
** Login   <samuel.osborne@epitech.eu>
**
** Started on  Wed Mar 15 17:16:24 2017 Samuel Osborne
** Last update Wed Mar 15 17:16:24 2017 Samuel Osborne
*/

#ifndef AGAMEOBJECT_HPP_
# define AGAMEOBJECT_HPP_

# include <string>
# include <iostream>
# include "Arcade.hpp"
# include "IGameObject.hh"
# include "Protocol.hpp"

namespace 				arcade
{
  class 				AGameObject : public arcade::games::IGameObject
  {
   protected:
    std::string				asset;
    arcade::Position			pos;
    arcade::TileType 			type;

   public:
    AGameObject(const uint16_t, const uint16_t);
    AGameObject(const AGameObject&);
    AGameObject &operator=(const AGameObject&);
    virtual ~AGameObject() {};

    virtual arcade::Position 		getPos() const;
    virtual std::string 		getSprite() const;
    virtual arcade::TileType 		getTileType() const;
    virtual void 			setSprite(const std::string &);
    virtual void 			setPos(const arcade::Position &pos);
    virtual void			setPos(uint16_t x, uint16_t y);
    virtual void			setTileType(const arcade::TileType &);
  };

};

#endif // !AGAMEOBJECT_HPP_
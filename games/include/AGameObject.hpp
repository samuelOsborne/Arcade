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


#include "IGameObject.hpp"

#include "Protocol.hpp"

namespace 				arcade
{
  namespace 				games
  {
    class 				AGameObject : public arcade::games::IGameObject
    {
     protected:
      arcade::Position			pos;
      arcade::TileType 			type;
      arcade::games::ExtTileType 	extType;
     public:
      virtual ~AGameObject() {};

      AGameObject();
      AGameObject(const AGameObject&);
      AGameObject&			operator=(const AGameObject&);
      virtual arcade::Position 		getPos() const;
      virtual void 			setPos(const arcade::Position &pos);
      virtual void			setTileType() = 0;
    };
  };
};

#endif //AGAMEOBJECT_HPP_

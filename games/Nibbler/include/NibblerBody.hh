/*
** NibblerBody.hh for cpp_arcade in /home/villen_l/rendu/cpp_arcade/NibblerBody.hh
**
** Made by Lucas Villeneuve
** Login   <lucas.villeneuve@epitech.eu>
**
** Started on  Fri Mar 24 13:45:18 2017 Lucas Villeneuve
** Last update Fri Mar 24 13:45:18 2017 Lucas Villeneuve
*/

#ifndef NIBBLERBODY_HH_
# define NIBBLERBODY_HH_

# include "IGameObject.hpp"
# include "Enemy.hpp"

namespace		arcade
{
  namespace		games
  {
    class		NibblerBody : public arcade::Enemy
    {
     public:
      NibblerBody(const uint16_t x, const uint16_t y);
      NibblerBody(const NibblerBody &) = delete;
      NibblerBody &operator=(const NibblerBody &) = delete;
      ~NibblerBody() {};
    };

  };
};

#endif // !NIBBLERBODY_HH_
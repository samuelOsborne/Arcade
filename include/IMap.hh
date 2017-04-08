/*
** IMap.hh for cpp_arcade in /home/villen_l/rendu/cpp_arcade/IMap.hh
**
** Made by Lucas Villeneuve
** Login   <lucas.villeneuve@epitech.eu>
**
** Started on  Thu Mar 16 10:14:40 2017 Lucas Villeneuve
** Last update Thu Mar 16 10:14:40 2017 Lucas Villeneuve
*/

#ifndef IMAP_HH_
# define IMAP_HH_

# include "IGameObject.hh"
# include "Protocol.hpp"

namespace 				arcade
{
  class 				IMap
  {
   public:
    virtual 				~IMap() {}

    virtual uint16_t 			getWidth() const = 0;
    virtual uint16_t 			getHeight() const = 0;
    virtual arcade::games::IGameObject	*getTile(const arcade::Position &pos) const = 0;
    virtual arcade::games::IGameObject	*getTile(uint16_t x, uint16_t y) const = 0;
    virtual void			setTile(const arcade::Position &pos,
						arcade::games::IGameObject *tile) = 0;
    virtual void			setTile(uint16_t x, uint16_t y,
						arcade::games::IGameObject *tile) = 0;
    /*TODO A ajouter */
    virtual void 			deleteTile(const Position &pos) = 0;
    virtual void 			deleteTile(uint16_t x, uint16_t y) = 0;
  };

};

#endif // !IMAP_HH_

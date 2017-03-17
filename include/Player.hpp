/*
** Player.hpp for cpp_arcade in /home/osborn_s/Tek_2/cpp_arcade/Player.hpp
**
** Made by Samuel Osborne
** Login   <samuel.osborne@epitech.eu>
**
** Started on  Tue Mar 14 11:27:32 2017 Samuel Osborne
** Last update Tue Mar 14 11:27:32 2017 Samuel Osborne
*/

#ifndef PLAYER_HPP_
# define PLAYER_HPP_

# include "Arcade.hpp"
# include "Protocol.hpp"
# include "ACharacter.hpp"

namespace 				arcade
{
  class 				Player : public arcade::ACharacter
  {
   private:
    bool 				powerup;

   public:
    Player(const uint16_t, const uint16_t);
    Player(const Player &);
    Player &operator=(const Player &);
    ~Player() {};

    virtual void 			move(const arcade::Position &);
    virtual void			setTileType();
    virtual arcade::games::ExtTileType	getTileType() const;
  };

};

#endif // !PLAYER_HPP_

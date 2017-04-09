/*
** AGame.hpp for cpp_arcade in /home/osborn_s/Tek_2/cpp_arcade/AGame.hpp
**
** Made by Samuel Osborne
** Login   <samuel.osborne@epitech.eu>
**
** Started on  Wed Mar 15 16:56:32 2017 Samuel Osborne
// Last update Sat Apr  8 16:44:18 2017 escorn_t
*/

#ifndef ARCADE_AGAME_HPP_
# define ARCADE_AGAME_HPP_

# include "Map.hh"
# include "Player.hh"
# include "IGame.hh"
//# include "String.hh"

namespace 					arcade
{
  namespace 					games
  {
    class 					AGame : public IGame
    {
     protected:
      arcade::Player				player;
      arcade::Map				map;
      int 					score;
      std::vector<arcade::games::IGameObject*>	strings;
      std::string				playerName;

      virtual bool				processCmd(const arcade::CommandType&) = 0;
      virtual bool 				checkIfCanMove(const arcade::Position &) const;

     public:
      AGame(const uint16_t width, const uint16_t height) : map(width, height) {};
      AGame(AGame const &other);
      AGame &operator=(AGame const &other);
      ~AGame();

      virtual const arcade::IMap		*getMap() const;
      virtual const arcade::games::IGameObject	*getPlayer() const;
      virtual const std::vector<arcade::games::IGameObject*>	&getEnemies() const = 0;
      virtual bool				playRound(const arcade::CommandType &cmd) = 0;
      virtual const std::vector<IGameObject*>	&getStrings() const;
      virtual void 				setPlayerName(const std::string &);

    };
  };
};

#endif //ARCADE_AGAME_HPP_

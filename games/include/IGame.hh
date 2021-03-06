/*
** IGame.hpp for cpp_arcade in /home/osborn_s/Tek_2/cpp_arcade/IGame.hpp
**
** Made by Samuel Osborne
** Login   <samuel.osborne@epitech.eu>
**
** Started on  Wed Mar 15 16:52:23 2017 Samuel Osborne
** Last update Wed Mar 15 16:52:23 2017 Samuel Osborne
*/

#ifndef ARCADE_IGAME_HPP_
# define ARCADE_IGAME_HPP_

# include <vector>
# include <string>
# include "IMap.hh"

namespace 					arcade
{
  namespace 					games
  {
    class 					IGame
    {
     public:
      virtual ~IGame() {};

      virtual const arcade::IMap		*getMap() const = 0;
      virtual const arcade::games::IGameObject	*getPlayer() const = 0;
      virtual const std::vector<arcade::games::IGameObject*> &getEnemies() const = 0;
      virtual bool				playRound(const arcade::CommandType &cmd) = 0;
      virtual const std::vector<IGameObject*>	&getStrings() const = 0;
      virtual void 				setPlayerName(const std::string &) = 0;
    };
  }
}

#endif //ARCADE_IGAME_HPP_

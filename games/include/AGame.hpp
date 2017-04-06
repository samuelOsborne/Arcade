/*
** AGame.hpp for cpp_arcade in /home/osborn_s/Tek_2/cpp_arcade/AGame.hpp
**
** Made by Samuel Osborne
** Login   <samuel.osborne@epitech.eu>
**
** Started on  Wed Mar 15 16:56:32 2017 Samuel Osborne
** Last update Wed Mar 15 16:56:32 2017 Samuel Osborne
*/

#ifndef ARCADE_AGAME_HPP_
# define ARCADE_AGAME_HPP_

# include "Map.hh"
# include "Player.hpp"
# include "IGame.hpp"

namespace 					arcade
{
  namespace 					games
  {
    class 					AGame : public IGame
    {
     protected:
      arcade::Player				player;
      arcade::Map				map;
      std::string				name;
      int 					score;

      virtual bool				processCmd(const arcade::CommandType&) = 0;
      virtual bool 				checkIfCanMove(const arcade::Position &) const;

     public:
      AGame(const uint16_t width, const uint16_t height) : map(width, height) {};
      AGame(AGame const &other);
      AGame &operator=(AGame const &other);
      virtual ~AGame() {};

      virtual void				launch() = 0;
      virtual std::string			getName() const;
      virtual const arcade::Map			&getMap() const;
      virtual const arcade::IGameObject		*getPlayer() const;
      virtual const std::vector<arcade::IGameObject*>	&getEnemies() const = 0;
/*
      virtual std::string			getScore() const;
*/
      virtual bool				playRound(const arcade::CommandType &cmd) = 0;
      //TODO
//      virtual const std::vector<IGameObject*>	&getStrings() const {std::vector<IGameObject*> ret;  return (ret);}
    };
  };
};

#endif //ARCADE_AGAME_HPP_
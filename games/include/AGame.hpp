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

#include "Map.hh"
#include "Player.hpp"
#include "IGame.hpp"

namespace 			arcade
{
  namespace 			games
  {
    class 			AGame : public IGame
    {
     protected:
      arcade::Player		player;
      arcade::Map		map;

     public:
      virtual ~AGame() {};

      AGame(uint16_t width, uint16_t height) : map(width, height) {};
      AGame(AGame const &other);
      AGame &operator=(AGame const &other);
      virtual void		launch() = 0;
    };
  };
};

#endif //ARCADE_AGAME_HPP_

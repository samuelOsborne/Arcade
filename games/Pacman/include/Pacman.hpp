/*
** Pacman.hpp for cpp_arcade in /home/osborn_s/Tek_2/cpp_arcade/Pacman.hpp
**
** Made by Samuel Osborne
** Login   <samuel.osborne@epitech.eu>
**
** Started on  Sat Mar 18 13:29:24 2017 Samuel Osborne
** Last update Sat Mar 18 13:29:24 2017 Samuel Osborne
*/

#ifndef PACMAN_HPP_
# define PACMAN_HPP_

#include "Map.hh"
#include "AGame.hpp"

namespace	arcade
{
  namespace 	games
  {
    class 	Pacman : public AGame
    {
     public:
      Pacman();
      Pacman(const Pacman &);
      Pacman &operator=(const Pacman &);
      virtual ~Pacman() {};

      virtual void 					launch();
      arcade::Map					getPacMap() const;
      arcade::Map					receiveMapAndCtrl(arcade::Map, arcade::CommandType);
    };

  };
};

#endif //!PACMAN_HPP_

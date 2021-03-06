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

# include "Protocol.hpp"
# include "Map.hh"
# include "AGame.hh"
# include "Ghost.hh"

namespace					arcade
{
  namespace 					games
  {
    class 					Pacman : public arcade::games::AGame
    {
      bool 					waka;
      arcade::CommandType 			oldcmd;
      std::vector<arcade::games::IGameObject*>	enemies;
      int 					count;
      int 					endGameCount;
      char 					textmap[31][28] = {{3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4},
								     {2, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 2, 2, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 2},
								     {2, 7, 3, 1, 1, 4, 7, 3, 1, 1, 1, 4, 7, 2, 2, 7, 3, 1, 1, 1, 4, 7, 3, 1, 1, 4, 7, 2},
								     {2, 8, 2, 0, 0, 2, 7, 2, 0, 0, 0, 2, 7, 2, 2, 7, 2, 0, 0, 0, 2, 7, 2, 0, 0, 2, 8, 2},
								     {2, 7, 6, 1, 1, 5, 7, 6, 1, 1, 1, 5, 7, 6, 5, 7, 6, 1, 1, 1, 5, 7, 6, 1, 1, 5, 7, 2},
								     {2, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 2},
								     {2, 7, 3, 1, 1, 4, 7, 3, 4, 7, 3, 1, 1, 1, 1, 1, 1, 4, 7, 3, 4, 7, 3, 1, 1, 4, 7, 2},
								     {2, 7, 6, 1, 1, 5, 7, 2, 2, 7, 6, 1, 1, 4, 3, 1, 1, 5, 7, 2, 2, 7, 6, 1, 1, 5, 7, 2},
								     {2, 7, 7, 7, 7, 7, 7, 2, 2, 7, 7, 7, 7, 2, 2, 7, 7, 7, 7, 2, 2, 7, 7, 7, 7, 7, 7, 2},
								     {6, 1, 1, 1, 1, 4, 7, 2, 6, 1, 1, 4, 0, 2, 2, 0, 3, 1, 1, 5, 2, 7, 3, 1, 1, 1, 1, 5},
								     {0, 0, 0, 0, 0, 2, 7, 2, 3, 1, 1, 5, 0, 6, 5, 0, 6, 1, 1, 4, 2, 7, 2, 0, 0, 0, 0, 0},
								     {0, 0, 0, 0, 0, 2, 7, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 7, 2, 0, 0, 0, 0, 0},
								     {0, 0, 0, 0, 0, 2, 7, 2, 2, 0, 3, 1, 1, 0, 0, 1, 1, 4, 0, 2, 2, 7, 2, 0, 0, 0, 0, 0},
								     {1, 1, 1, 1, 1, 5, 7, 6, 5, 0, 2, 0, 0, 0, 0, 0, 0, 2, 0, 6, 5, 7, 6, 1, 1, 1, 1, 1},
								     {0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0},
								     {1, 1, 1, 1, 1, 4, 7, 3, 4, 0, 2, 0, 0, 0, 0, 0, 0, 2, 0, 3, 4, 7, 3, 1, 1, 1, 1, 1},
								     {0, 0, 0, 0, 0, 2, 7, 2, 2, 0, 6, 1, 1, 1, 1, 1, 1, 5, 0, 2, 2, 7, 2, 0, 0, 0, 0, 0},
								     {0, 0, 0, 0, 0, 2, 7, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 7, 2, 0, 0, 0, 0, 0},
								     {0, 0, 0, 0, 0, 2, 7, 2, 2, 0, 3, 1, 1, 1, 1, 1, 1, 4, 0, 2, 2, 7, 2, 0, 0, 0, 0, 0},
								     {3, 1, 1, 1, 1, 5, 7, 6, 5, 0, 6, 1, 1, 4, 3, 1, 1, 5, 0, 6, 5, 7, 6, 1, 1, 1, 1, 4},
								     {2, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 2, 2, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 2},
								     {2, 7, 3, 1, 1, 4, 7, 3, 1, 1, 1, 4, 7, 2, 2, 7, 3, 1, 1, 1, 4, 7, 3, 1, 1, 4, 7, 2},
								     {2, 7, 6, 1, 4, 2, 7, 6, 1, 1, 1, 5, 7, 6, 5, 7, 6, 1, 1, 1, 5, 7, 2, 3, 1, 5, 7, 2},
								     {2, 8, 7, 7, 2, 2, 7, 7, 7, 7, 7, 7, 7, 7, 0, 7, 7, 7, 7, 7, 7, 7, 2, 2, 7, 7, 8, 2},
								     {6, 1, 4, 7, 2, 2, 7, 3, 4, 7, 3, 1, 1, 1, 1, 1, 1, 4, 7, 3, 4, 7, 2, 2, 7, 3, 1, 5},
								     {3, 1, 5, 7, 6, 5, 7, 2, 2, 7, 6, 1, 1, 4, 3, 1, 1, 5, 7, 2, 2, 7, 6, 5, 7, 6, 1, 4},
								     {2, 7, 7, 7, 7, 7, 7, 2, 2, 7, 7, 7, 7, 2, 2, 7, 7, 7, 7, 2, 2, 7, 7, 7, 7, 7, 7, 2},
								     {2, 7, 3, 1, 1, 1, 1, 5, 6, 1, 1, 4, 7, 2, 2, 7, 3, 1, 1, 5, 6, 1, 1, 1, 1, 4, 7, 2},
								     {2, 7, 6, 1, 1, 1, 1, 1, 1, 1, 1, 5, 7, 6, 5, 7, 6, 1, 1, 1, 1, 1, 1, 1, 1, 5, 7, 2},
								     {2, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 2},
								     {6, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 5}};

      void 					takePowerUp(const arcade::Position &pos);
      arcade::Position				checkIfTeleport(const arcade::Position &pos) const;
      bool 					movePlayer(const arcade::Position &pos,
							     const arcade::CommandType &cmd);
      void 					moveAi(arcade::games::Ghost*);
      bool 					checkCollision() const;
      void 					rotatePacman(int dir);
      void					initEnemies();
      void					runAi();
      void					pushBackHighScore();

     public:
      Pacman();
      Pacman(const Pacman &) = delete;
      Pacman &operator=(const Pacman &) = delete;
      ~Pacman();

      virtual const std::vector<arcade::games::IGameObject*>	&getEnemies() const;
      virtual bool				playRound(const arcade::CommandType &cmd);
      virtual bool				processCmd(const arcade::CommandType &cmd);
      bool 					saveScoreAndQuit();
    };
  };
};

#endif // !PACMAN_HPP_

/*
** Nibbler.hh for cpp_arcade in /home/villen_l/rendu/cpp_arcade/Nibbler.hh
**
** Made by Lucas Villeneuve
** Login   <lucas.villeneuve@epitech.eu>
**
** Started on  Thu Mar 23 15:08:40 2017 Lucas Villeneuve
** Last update Thu Mar 23 15:08:40 2017 Lucas Villeneuve
*/

#ifndef NIBBLER_HH_
# define NIBBLER_HH_

# include <vector>
# include "AGame.hpp"

namespace 					arcade
{
  namespace 					games
  {
    class					Nibbler : public arcade::games::AGame
    {
      arcade::CommandType 			oldcmd;
      std::vector<arcade::games::IGameObject*>		body;

      char 					textmap[15][15] = {{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
								     {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
								     {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
								     {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
								     {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
								     {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
								     {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
								     {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
								     {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
								     {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
								     {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
								     {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
								     {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
								     {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
								     {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};

      bool 					movePlayer(const arcade::Position &pos,
							     const arcade::CommandType &cmd);
      void 					moveBody();
      void 					pickFruit();
      void 					spawnFruit();
      arcade::Position				getPosBodyFreeCase() const;
      bool 					checkPosInBody(const arcade::Position &pos) const;
      virtual bool				checkIfCanMove(const arcade::Position &pos) const;
      virtual bool				processCmd(const arcade::CommandType &cmd);

     public:
      Nibbler();
      Nibbler(const Nibbler &other) = delete;
      Nibbler &operator=(const Nibbler &other) = delete;
      ~Nibbler() {};

      virtual const std::vector<arcade::games::IGameObject*>	&getEnemies() const;
      virtual bool				playRound(const arcade::CommandType &cmd);
    };

  };
};

#endif // !NIBBLER_HH_

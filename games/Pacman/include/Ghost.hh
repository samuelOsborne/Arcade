/*
** Ghost.hpp for cpp_arcade in /home/osborn_s/Tek_2/cpp_arcade/Ghost.hpp
**
** Made by Samuel Osborne
** Login   <samuel.osborne@epitech.eu>
**
** Started on  Sat Mar 18 18:52:39 2017 Samuel Osborne
** Last update Sat Mar 18 18:52:39 2017 Samuel Osborne
*/

#ifndef GHOST_HPP_
# define GHOST_HPP_

# include "Enemy.hh"

namespace 			arcade
{
  namespace 			games
  {
    class Ghost : public 	arcade::Enemy
    {
      bool                      vulne;
      long int                  timer;
      bool 			spawn;
      long int			spawnTimer;
      arcade::CommandType	direction;
      std::string 		vulneAsset;

     public:
      Ghost(uint16_t x, uint16_t y, std::string path);
      Ghost(const Ghost &);
      Ghost &operator=(const Ghost &);
      ~Ghost() {};

      arcade::CommandType	getDirection() const;
      void 			setDirection(const arcade::CommandType &dir);
      bool                      getVulne() const;
      void                      setVulne(const bool state);
      long int                  getTimer() const;
      void                      setTimer(const long int val);
      void 			switchAsset();
      bool 			getSpawn() const;
      void 			setSpawn(bool);
      long int 			getSpawnTimer() const;
      void 			setSpawnTimer(long int);
    };
  };
};

#endif //GHOST_HPP_

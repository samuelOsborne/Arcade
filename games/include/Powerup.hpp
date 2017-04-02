/*
** Powerup.hpp for cpp_arcade in /home/osborn_s/Tek_2/cpp_arcade/Powerup.hpp
**
** Made by Samuel Osborne
** Login   <samuel.osborne@epitech.eu>
**
** Started on  Tue Mar 14 15:09:51 2017 Samuel Osborne
** Last update Tue Mar 14 15:09:51 2017 Samuel Osborne
*/

#ifndef POWERUP_HPP_
# define POWERUP_HPP_

# include "Protocol.hpp"
# include "AObjects.hpp"

namespace 		arcade
{
  class			Powerup : public arcade::AObjects
  {
   public:
    Powerup(const uint16_t, const uint16_t);
    Powerup(const Powerup&);
    Powerup &operator=(const Powerup&);
    ~Powerup() {};

    void		move(arcade::Position& pos);
    virtual void	setTileType();
    virtual std::string	getObj() const;
  };

};

#endif // !POWERUP_HPP_

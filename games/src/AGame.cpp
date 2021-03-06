/*
** AGame.hpp for cpp_arcade in /home/osborn_s/Tek_2/cpp_arcade/AGame.hpp
**
** Made by Samuel Osborne
** Login   <samuel.osborne@epitech.eu>
**
** Started on  Wed Mar 15 16:56:32 2017 Samuel Osborne
** Last update Wed Mar 15 16:56:32 2017 Samuel Osborne
*/

#include "AGame.hh"

arcade::games::AGame::AGame(arcade::games::AGame const &other)
 : map(other.map.getWidth(), other.map.getHeight()), score(0)
{
  if (this != &other)
    this->player = other.player;
}

arcade::games::AGame &arcade::games::AGame::operator=(arcade::games::AGame const &other)
{
  if (this != &other)
    this->player = other.player;
  return (*this);
}

arcade::games::AGame::~AGame()
{
  this->strings.clear();
}

bool	arcade::games::AGame::checkIfCanMove(const arcade::Position &pos) const
{
  return ((this->map.getTile(pos)->getTileType() == arcade::TileType::EMPTY ||
      this->map.getTile(pos)->getTileType() == arcade::TileType::POWERUP ||
      this->map.getTile(pos)->getTileType() == arcade::TileType::OTHER));
}

const arcade::IMap	*arcade::games::AGame::getMap() const
{
  const arcade::IMap	*_map;

  _map = &this->map;
  return (_map);
}

const arcade::games::IGameObject	*arcade::games::AGame::getPlayer() const
{
  return (&this->player);
}

const std::vector<arcade::games::IGameObject*>	&arcade::games::AGame::getStrings() const
{
  return (this->strings);
}

void	arcade::games::AGame::setPlayerName(const std::string &name)
{
  this->playerName = name;
}

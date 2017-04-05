/*
** Nibbler.cpp for cpp_arcade in /home/villen_l/rendu/cpp_arcade/Nibbler.cpp
**
** Made by Lucas Villeneuve
** Login   <lucas.villeneuve@epitech.eu>
**
** Started on  Thu Mar 23 15:14:18 2017 Lucas Villeneuve
** Last update Thu Mar 23 15:14:18 2017 Lucas Villeneuve
*/

#include <cstdlib>
#include <ctime>
#include "IGameObject.hpp"
#include "Nibbler.hh"
#include "NibblerFloor.hh"
#include "NibblerWall.hh"
#include "NibblerBody.hh"
#include "NibblerFruit.hh"

arcade::games::Nibbler::Nibbler()
 : AGame(15, 15)
{
  arcade::Position	pos;

  this->name = "Nibbler";
  this->score = 0;
  pos.x = 5;
  pos.y = 5;
  this->player.setPos(pos);
  this->body.push_back(new arcade::games::NibblerBody(4, 5));
  this->body.push_back(new arcade::games::NibblerBody(3, 5));
  this->body.push_back(new arcade::games::NibblerBody(2, 5));
  this->player.setSprite("./misc/Nibbler/snake");
  this->oldcmd = arcade::CommandType::ILLEGAL;
  pos.y = 0;
  while (pos.y < this->map.getHeight())
    {
      pos.x = 0;
      while (pos.x < this->map.getWidth())
	{
	  if (this->textmap[pos.y][pos.x] == 0)
	    this->map.setTile(pos, new arcade::games::NibblerFloor(pos.x, pos.y));
	  else if (this->textmap[pos.y][pos.x] == 1)
	    this->map.setTile(pos, new arcade::games::NibblerWall(pos.x, pos.y));
	  pos.x++;
  	}
      pos.y++;
    }
  std::srand(std::time(0));
  this->spawnFruit();
}

void	arcade::games::Nibbler::launch()
{
  std::cout << "NIBBLER LAUNCHED" << std::endl;
}

bool	arcade::games::Nibbler::checkIfCanMove(const arcade::Position &pos) const
{
  return (((this->map.getTile(pos)->getTileType() == arcade::TileType::EMPTY ||
      this->map.getTile(pos)->getTileType() == arcade::TileType::POWERUP ||
      this->map.getTile(pos)->getTileType() == arcade::TileType::OTHER) &&
      !this->checkPosInBody(pos)));
}

bool 		arcade::games::Nibbler::movePlayer(const arcade::Position &pos,
							const arcade::CommandType &cmd)
{
  if (this->checkIfCanMove(pos))
    {
      this->player.move(pos);
      this->pickFruit();
      this->oldcmd = cmd;
      return (true);
    }
  return (false);
}

bool			arcade::games::Nibbler::processCmd(const arcade::CommandType &cmd)
{
  arcade::Position	pos;

  pos = this->player.getPos();

  if (cmd == arcade::CommandType::GO_RIGHT)
    {
      if (this->oldcmd == arcade::CommandType::GO_LEFT)
	return (this->processCmd(this->oldcmd));
      pos.x++;
      return (this->movePlayer(pos, cmd));
    }
  else if (cmd == arcade::CommandType::GO_LEFT)
    {
      if (this->oldcmd == arcade::CommandType::GO_RIGHT)
	return (this->processCmd(this->oldcmd));
      pos.x--;
      return (this->movePlayer(pos, cmd));
    }
  else if (cmd == arcade::CommandType::GO_UP)
    {
      if (this->oldcmd == arcade::CommandType::GO_DOWN)
	return (this->processCmd(this->oldcmd));
      pos.y--;
      return (this->movePlayer(pos, cmd));
    }
  else if (cmd == arcade::CommandType::GO_DOWN)
    {
      if (this->oldcmd == arcade::CommandType::GO_UP)
	return (this->processCmd(this->oldcmd));
      pos.y++;
      return (this->movePlayer(pos, cmd));
    }
  return (true);
}

void			arcade::games::Nibbler::pickFruit()
{
  arcade::Position	pos;
  arcade::Position	bodyPos;
  arcade::AObjects	*pu;

  pos = this->player.getPos();
  if (this->map.getTile(pos)->getTileType() == arcade::TileType::POWERUP)
    {
      if (!(pu = dynamic_cast<arcade::AObjects*>(this->map.getTile(pos)))->getTaken())
	{
	  pu->take();
	  this->score += 100;
	  bodyPos = this->getPosBodyFreeCase();
	  this->body.push_back(new arcade::games::NibblerBody(bodyPos.x, bodyPos.y));
	  this->spawnFruit();
	}
    }
}

const std::vector<arcade::IGameObject*>	&arcade::games::Nibbler::getEnemies() const
{
  return (this->body);
}

void						arcade::games::Nibbler::moveBody()
{
  arcade::Position				pos;
  arcade::Position				save;
  std::vector<arcade::IGameObject*>::iterator	it;

  pos = this->player.getPos();
  it = this->body.begin();
  while (it != this->body.end())
    {
      save = (*it)->getPos();
      (*it)->setPos(pos);
      pos = save;
      it++;
    }
}

bool	arcade::games::Nibbler::checkPosInBody(const arcade::Position &pos) const
{
  std::vector<arcade::IGameObject*>::const_iterator	it;

  it = this->body.begin();
  while (it != this->body.end())
    {
      if (pos.x == (*it)->getPos().x && pos.y == (*it)->getPos().y)
	return (true);
      it++;
    }
  return (false);
}

void			arcade::games::Nibbler::spawnFruit()
{
  arcade::Position	pos;

  pos.x = std::rand() % this->map.getWidth();
  pos.y = std::rand() % this->map.getWidth();
  if (this->textmap[pos.y][pos.x] != 1 &&
      (this->player.getPos().x != pos.x || this->player.getPos().y != pos.y) &&
      !this->checkPosInBody(pos))
    this->map.setTile(pos, new arcade::games::NibblerFruit(pos.x, pos.y));
  else
    this->spawnFruit();
}

arcade::Position	arcade::games::Nibbler::getPosBodyFreeCase() const
{
  arcade::Position	pos;

  pos = this->body.back()->getPos();
  pos.x--;
  if (this->textmap[pos.y][pos.x] != 1 && !this->checkPosInBody(pos))
    return (pos);
  pos.x += 2;
  if (this->textmap[pos.y][pos.x] != 1 && !this->checkPosInBody(pos))
    return (pos);
  pos.x--;
  pos.y--;
  if (this->textmap[pos.y][pos.x] != 1 && !this->checkPosInBody(pos))
    return (pos);
  pos.y += 2;
  if (this->textmap[pos.y][pos.x] != 1 && !this->checkPosInBody(pos))
    return (pos);
  pos.y--;
  std::cerr << "Can't create body" << std::endl;
  return (pos);
}

bool	arcade::games::Nibbler::playRound(const arcade::CommandType &cmd)
{
  if (cmd == arcade::CommandType::PLAY)
    {
      if (this->oldcmd != arcade::CommandType::ILLEGAL)
	this->moveBody();
      return (this->processCmd(this->oldcmd));
    }
  else
    {
      this->moveBody();
      return (this->processCmd(cmd));
    }
}

extern "C" arcade::games::IGame	*entry_point()
{
  return (new arcade::games::Nibbler());
}
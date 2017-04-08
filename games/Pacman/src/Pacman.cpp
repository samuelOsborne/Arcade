/*
** Pacman.cpp for cpp_arcade in /home/osborn_s/Tek_2/cpp_arcade/Pacman.cpp
**
** Made by Samuel Osborne
** Login   <samuel.osborne@epitech.eu>
**
** Started on  Sat Mar 18 13:29:23 2017 Samuel Osborne
// Last update Thu Apr  6 17:29:25 2017 escorn_t
*/

#include <ctime>
#include <cmath>
#include <typeinfo>
#include <iostream>
#include "Ghost.hpp"
#include "Pacgum.hh"
#include "Pacman.hpp"
#include "PacmanFloor.hh"
#include "SEPipe.hh"
#include "SOPipe.hh"
#include "NEPipe.hh"
#include "NOPipe.hh"
#include "VerticalPipe.hh"
#include "HorizontalPipe.hh"
#include "Power.hh"

arcade::games::Pacman::Pacman()
 : arcade::games::AGame(28, 31)
{
  arcade::Position pos;

  this->name = "Pacman";
  pos.x = 14;
  pos.y = 23;
  this->player.setPos(pos);
  this->oldcmd = arcade::CommandType::ILLEGAL;
  this->score = 0;
  srand(time(0));
  pos.y = 0;
  while (pos.y < this->map.getHeight())
    {
      pos.x = 0;
      while (pos.x < this->map.getWidth())
	{
	  if (this->textmap[pos.y][pos.x] == 0)
	    this->map.setTile(pos, new arcade::games::PacmanFloor(pos.x, pos.y));
	  else if (this->textmap[pos.y][pos.x] == 1)
	    this->map.setTile(pos, new arcade::games::HorizontalPipe(pos.x, pos.y));
	  else if (this->textmap[pos.y][pos.x] == 2)
	    this->map.setTile(pos, new arcade::games::VerticalPipe(pos.x, pos.y));
	  else if (this->textmap[pos.y][pos.x] == 3)
	    this->map.setTile(pos, new arcade::games::NOPipe(pos.x, pos.y));
	  else if (this->textmap[pos.y][pos.x] == 4)
	    this->map.setTile(pos, new arcade::games::NEPipe(pos.x, pos.y));
	  else if (this->textmap[pos.y][pos.x] == 5)
	    this->map.setTile(pos, new arcade::games::SEPipe(pos.x, pos.y));
	  else if (this->textmap[pos.y][pos.x] == 6)
	    this->map.setTile(pos, new arcade::games::SOPipe(pos.x, pos.y));
	  else if (this->textmap[pos.y][pos.x] == 7)
	    this->map.setTile(pos, new arcade::games::Pacgum(pos.x, pos.y));
	  else if (this->textmap[pos.y][pos.x] == 8)
	    this->map.setTile(pos, new arcade::games::Power(pos.x, pos.y));
	  pos.x++;
	}
      pos.y++;
    }
  this->initEnemies();
}

arcade::games::Pacman::Pacman(const arcade::games::Pacman &other)
 : arcade::games::AGame(28, 31)
{
  if (this != &other)
    {
      this->player = other.player;
      this->enemies = other.enemies;
    }
}

void 						arcade::games::Pacman::initEnemies()
{
  this->enemies.push_back(new arcade::games::Ghost(13, 14, "./misc/Pacman/RedGhost"));
  this->enemies.push_back(new arcade::games::Ghost(14, 15, "./misc/Pacman/BlueGhost"));
  this->enemies.push_back(new arcade::games::Ghost(15, 14, "./misc/Pacman/PinkGhost"));
  this->enemies.push_back(new arcade::games::Ghost(14, 11, "./misc/Pacman/OrangeGhost"));
}

arcade::games::Pacman 				&arcade::games::Pacman::operator=(const Pacman& other)
{
  if (this != &other)
    {
      this->player = other.player;
    }
  return (*this);
}

void			arcade::games::Pacman::launch()
{
}

void 				arcade::games::Pacman::moveAi(arcade::games::Ghost *ghost)
{
  arcade::Position		pos;
  std::vector<arcade::Position> dir;
  std::vector<arcade::CommandType> newDir;
  int 				i;

  pos = ghost->getPos();
  pos.y++;
  if ((this->textmap[pos.y][pos.x] == 0 || this->textmap[pos.y][pos.x] == 7
      || this->textmap[pos.y][pos.x] == 8) &&
      ghost->getDirection() != arcade::CommandType::GO_DOWN)
    {
      dir.push_back(pos);
      newDir.push_back(arcade::CommandType::GO_UP);
    }
  pos.y -= 2;
  if ((this->textmap[pos.y][pos.x] == 0 || this->textmap[pos.y][pos.x] == 7
      || this->textmap[pos.y][pos.x] == 8) &&
      ghost->getDirection() != arcade::CommandType::GO_UP)
    {
      dir.push_back(pos);
      newDir.push_back(arcade::CommandType::GO_DOWN);
    }
  pos.y++;
  pos.x++;
  if ((this->textmap[pos.y][pos.x] == 0 || this->textmap[pos.y][pos.x] == 7
      || this->textmap[pos.y][pos.x] == 8) &&
      ghost->getDirection() != arcade::CommandType::GO_LEFT)
    {
      dir.push_back(pos);
      newDir.push_back(arcade::CommandType::GO_RIGHT);
    }
  pos.x -= 2;
  if ((this->textmap[pos.y][pos.x] == 0 || this->textmap[pos.y][pos.x] == 7
      || this->textmap[pos.y][pos.x] == 8) &&
      ghost->getDirection() != arcade::CommandType::GO_RIGHT)
    {
      dir.push_back(pos);
      newDir.push_back(arcade::CommandType::GO_LEFT);
    }
  if (dir.size() == 0)
    std::cerr << "Error : cannot find directions for ghost" << std::endl;
  else
    {
      i = rand() % dir.size();
      ghost->move(this->checkIfTeleport(dir[i]));
      ghost->setDirection(newDir[i]);
    }
}

void						arcade::games::Pacman::runAi()
{
  std::vector<arcade::IGameObject*>::iterator	it;

  it = this->enemies.begin();
  while (it != this->enemies.end())
    {
      this->moveAi(dynamic_cast<arcade::games::Ghost*>(*it));
      it++;
    }
}

void			arcade::games::Pacman::takePowerUp(const arcade::Position &pos)
{
  arcade::AObjects	*pu;
  std::vector<arcade::IGameObject*>::iterator	it;

  if (this->map.getTile(pos)->getTileType() == arcade::TileType::POWERUP &&
   !((pu = dynamic_cast<arcade::AObjects *>(this->map.getTile(pos)))->getTaken()))
    {
      if (this->textmap[pos.y][pos.x] == 8)
      {
	it = this->enemies.begin();
	while (it != this->enemies.end())
	{
	  dynamic_cast<arcade::games::Ghost *>(*it)->setVulne(true);
	  dynamic_cast<arcade::games::Ghost *>(*it)->switchAsset();
	  dynamic_cast<arcade::games::Ghost *>(*it)->setTimer(0);
	  it++;
	}
      }
      pu->take();
      this->score += 100;
    }
}

arcade::Position	arcade::games::Pacman::checkIfTeleport(const arcade::Position &pos) const
{
  arcade::Position	posTeleport;

  posTeleport.y = 14;
  if (pos.x == 0 && pos.y == 14)
    {
      posTeleport.x = 26;
      return (posTeleport);
    }
  else if (pos.x == 27 && pos.y == 14)
    {
      posTeleport.x = 1;
      return (posTeleport);
    }
  return (pos);
}

bool	arcade::games::Pacman::movePlayer(const arcade::Position &pos,
					      const arcade::CommandType &cmd)
{
  if (checkIfCanMove(pos))
    {
      this->oldcmd = cmd;
      this->takePowerUp(pos);
      this->player.move(this->checkIfTeleport(pos));
      return (true);
    }
  else if (this->oldcmd != cmd)
    return (processCmd(this->oldcmd));
  return (true);
}

bool			arcade::games::Pacman::processCmd(const arcade::CommandType &cmd)
{
  arcade::Position	pos;

  pos = this->player.getPos();
  if (cmd == arcade::CommandType::GO_RIGHT)
    {
      pos.x++;
      this->movePlayer(pos, cmd);
    }
  else if (cmd == arcade::CommandType::GO_LEFT)
    {
      pos.x--;
      this->movePlayer(pos, cmd);
    }
  else if (cmd == arcade::CommandType::GO_UP)
    {
      pos.y--;
      this->movePlayer(pos, cmd);
    }
  else if (cmd == arcade::CommandType::GO_DOWN)
    {
      pos.y++;
      this->movePlayer(pos, cmd);
    }
  if (this->checkCollision())
  {
    if (!this->checkVulne())
      return (false);
  }
  return (true);
}

bool							arcade::games::Pacman::checkCollision() const
{
  arcade::Position					playerPos;
  arcade::Position					ghostPos;
  std::vector<arcade::IGameObject*>::const_iterator	it;

  playerPos = this->player.getPos();
  it = this->enemies.begin();
  while (it != this->enemies.end())
    {
      ghostPos = (*it)->getPos();
      if (playerPos.x == ghostPos.x && playerPos.y == ghostPos.y)
	return (true);
      it++;
    }
  return (false);
}

bool 	arcade::games::Pacman::checkVulne()
{
  arcade::Position					playerPos;
  arcade::Position					ghostPos;
  std::vector<arcade::IGameObject*>::iterator		it;

  playerPos = this->player.getPos();
  it = this->enemies.begin();
  while (it != this->enemies.end())
   {
     ghostPos = (*it)->getPos();
     if (playerPos.x == ghostPos.x && playerPos.y == ghostPos.y)
     {
       if (dynamic_cast<arcade::games::Ghost *>(*it)->getVulne() == true)
       {
	 it = enemies.erase(it);
	 return (true);
       }
     }
     it++;
   }
  return (false);
}

bool	arcade::games::Pacman::playRound(const arcade::CommandType &cmd) {
  std::vector<arcade::IGameObject*>::iterator it;

  it = this->enemies.begin();

  this->runAi();
  while (it != this->enemies.end())
  {
    if (dynamic_cast<arcade::games::Ghost *>(*it)->getVulne() == true)
    {
      dynamic_cast<arcade::games::Ghost *>(*it)->setTimer(dynamic_cast<arcade::games::Ghost *>(*it)->getTimer() + 1);
      if (dynamic_cast<arcade::games::Ghost *>(*it)->getTimer() == 30)
      {
	dynamic_cast<arcade::games::Ghost *>(*it)->setVulne(false);
	dynamic_cast<arcade::games::Ghost *>(*it)->switchAsset();
      }
    }
    it++;
  }
  if (this->checkCollision())
  {
    if (!this->checkVulne())
      return (false);
  }
  if (cmd == arcade::CommandType::PLAY
      && this->oldcmd != arcade::CommandType::ILLEGAL)
    return (this->processCmd(this->oldcmd));
  else
    return (this->processCmd(cmd));
}

const std::vector<arcade::IGameObject*>	&arcade::games::Pacman::getEnemies() const
{
  return (this->enemies);
}

extern "C"
{
void Play()
{
  arcade::CommandType cmd;
  arcade::games::Pacman pacman;
  struct arcade::WhereAmI *whereAmI;
  struct arcade::GetMap *getMap;
  int i;
  std::vector<arcade::IGameObject *>::const_iterator it;
  arcade::Position pos;

  while (1)
    {
      std::cin.read(reinterpret_cast<char *>(&cmd), sizeof(arcade::CommandType));
      if (std::cin.eof())
	return;
      if (cmd == arcade::CommandType::WHERE_AM_I)
	{
	  whereAmI = new arcade::WhereAmI[sizeof(arcade::Position) + sizeof(arcade::WhereAmI)];
	  whereAmI->type = cmd;
	  whereAmI->lenght = 1;
	  whereAmI->position[0] = pacman.getPlayer()->getPos();
	  std::cout.write(reinterpret_cast<char *>(whereAmI),
			  sizeof(arcade::Position) + sizeof(arcade::WhereAmI));
	}

      if (cmd == arcade::CommandType::GET_MAP)
	{
	  getMap = new arcade::GetMap[28 * 31 * sizeof(arcade::TileType) +
				      sizeof(arcade::GetMap)];
	  getMap->type = cmd;
	  getMap->height = 31;
	  getMap->width = 28;
	  i = 0;
	  while (i < 28 * 31)
	    {
	      pos.y = i / 31;
	      pos.x = i % 28;
	      getMap->tile[i] = pacman.getMap()->getTile(pos)->getTileType();
	      i++;
	    }
	  std::cout.write(reinterpret_cast<char *>(getMap),
			  28 * 31 * sizeof(arcade::TileType) +
			  sizeof(arcade::GetMap));
	}

      if (cmd == arcade::CommandType::GO_UP ||
	  cmd == arcade::CommandType::GO_DOWN ||
	  cmd == arcade::CommandType::GO_LEFT ||
	  cmd == arcade::CommandType::GO_RIGHT)
	pacman.playRound(cmd);
    }
}
}

extern "C" arcade::games::IGame	*entry_point()
{
  return (new arcade::games::Pacman());
}

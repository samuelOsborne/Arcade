/*
** Pacman.cpp for cpp_arcade in /home/osborn_s/Tek_2/cpp_arcade/Pacman.cpp
**
** Made by Samuel Osborne
** Login   <samuel.osborne@epitech.eu>
**
** Started on  Sat Mar 18 13:29:23 2017 Samuel Osborne
** Last update Sat Apr  8 16:44:48 2017 escorn_t
*/

#include <ctime>
#include <iostream>
#include <fstream>
#include <vector>
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
#include "String.hh"

arcade::games::Pacman::Pacman()
 : arcade::games::AGame(28, 31)
{
  arcade::Position pos;

  pos.x = 14;
  pos.y = 23;
  this->count = 0;
  this->player.setPos(pos);
  this->player.setSprite("./misc/Pacman/PacmanRight");
  this->oldcmd = arcade::CommandType::ILLEGAL;
  this->score = 0;
  this->endGameCount = 0;
  this->waka = false;
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
  this->strings.push_back(new arcade::String(0, 0, std::to_string(this->score)));
  this->pushBackHighScore();
}

arcade::games::Pacman::~Pacman()
{
  this->enemies.clear();
}

void	arcade::games::Pacman::pushBackHighScore()
{
  std::fstream scoreFile;
  std::string line;
  int y;

  y = 1;
  scoreFile.open("./.Pacman");
  if (scoreFile.is_open())
  {
    this->strings.push_back(new arcade::String(32, y, "Laderboard"));
    while (std::getline(scoreFile, line))
    {
      y += 2;
      this->strings.push_back(new arcade::String(32, y, line));
    }
  }
  else
    std::cerr << "Couldn't open score file" << std::endl;
}

void 						arcade::games::Pacman::initEnemies()
{
  this->enemies.push_back(new arcade::games::Ghost(13, 14, "./misc/Pacman/RedGhost"));
  this->enemies.push_back(new arcade::games::Ghost(14, 15, "./misc/Pacman/BlueGhost"));
  this->enemies.push_back(new arcade::games::Ghost(15, 14, "./misc/Pacman/PinkGhost"));
  this->enemies.push_back(new arcade::games::Ghost(14, 11, "./misc/Pacman/OrangeGhost"));
}

const std::vector<arcade::games::IGameObject*>	&arcade::games::Pacman::getEnemies() const
{
  return (this->enemies);
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

void							arcade::games::Pacman::runAi()
{
  std::vector<arcade::games::IGameObject*>::iterator	it;
  arcade::games::Ghost					*ghost;

  it = this->enemies.begin();
  while (it != this->enemies.end())
    {
      ghost = dynamic_cast<arcade::games::Ghost*>(*it);
      if (ghost->getVulne())
	{
	  ghost->setTimer(ghost->getTimer() + 1);
	  if (ghost->getTimer() >= 30)
	    {
	      ghost->setTimer(0);
	      ghost->setVulne(false);
	      ghost->switchAsset();
	    }
	}
      if (ghost->getSpawn())
	{
	  if (ghost->getSpawnTimer() >= 25)
	    {
	      ghost->setSpawn(false);
	      ghost->setSpawnTimer(0);
	    }
	  else
	    ghost->setSpawnTimer(ghost->getSpawnTimer() + 1);
	}
      else
	this->moveAi(ghost);
      it++;
    }
}

void			arcade::games::Pacman::takePowerUp(const arcade::Position &pos)
{
  arcade::AObjects	*pu;
  std::vector<arcade::games::IGameObject*>::iterator	it;

  if (this->map.getTile(pos)->getTileType() == arcade::TileType::POWERUP &&
   !((pu = dynamic_cast<arcade::AObjects *>(this->map.getTile(pos)))->getTaken()))
    {
      this->score += 10;
      this->count++;
      if (this->textmap[pos.y][pos.x] == 8)
      {
	this->score += 40;
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
      this->strings[0]->setSprite(std::to_string(this->score));
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
    processCmd(this->oldcmd);
  return (false);
}

void 	arcade::games::Pacman::rotatePacman(int dir)
{
  if (dir == 1)
    {
      if (!this->waka)
	this->player.setSprite("./misc/Pacman/PacmanRight");
      else
	this->player.setSprite("./misc/Pacman/PacmanRight2");
    }
  else if (dir == 2)
    {
      if (!this->waka)
	this->player.setSprite("./misc/Pacman/PacmanLeft");
      else
	this->player.setSprite("./misc/Pacman/PacmanLeft2");
    }
  else if (dir == 3)
    {
      if (!this->waka)
	this->player.setSprite("./misc/Pacman/PacmanUp");
      else
	this->player.setSprite("./misc/Pacman/PacmanUp2");
    }
  else if (dir == 4)
    {
      if (!this->waka)
	this->player.setSprite("./misc/Pacman/PacmanDown");
      else
	this->player.setSprite("./misc/Pacman/PacmanDown2");
    }
  this->waka = !this->waka;
}

bool			arcade::games::Pacman::processCmd(const arcade::CommandType &cmd)
{
  arcade::Position	pos;

  pos = this->player.getPos();
  if (cmd == arcade::CommandType::GO_RIGHT)
    {
      pos.x++;
      if (this->movePlayer(pos, cmd))
	this->rotatePacman(1);
    }
  else if (cmd == arcade::CommandType::GO_LEFT)
    {
      pos.x--;
      if (this->movePlayer(pos, cmd))
	this->rotatePacman(2);
    }
  else if (cmd == arcade::CommandType::GO_UP)
    {
      pos.y--;
      if (this->movePlayer(pos, cmd))
	this->rotatePacman(3);
    }
  else if (cmd == arcade::CommandType::GO_DOWN)
    {
      pos.y++;
      if (this->movePlayer(pos, cmd))
	this->rotatePacman(4);
    }
  if (this->checkCollision())
    return (this->saveScoreAndQuit());
  return (true);
}

bool							arcade::games::Pacman::checkCollision() const
{
  arcade::Position					playerPos;
  arcade::Position					ghostPos;
  std::vector<arcade::games::IGameObject*>::const_iterator	it;
  arcade::games::Ghost					*ghost;

  playerPos = this->player.getPos();
  it = this->enemies.begin();
  while (it != this->enemies.end())
    {
      ghostPos = (*it)->getPos();
      if (playerPos.x == ghostPos.x && playerPos.y == ghostPos.y)
	{
	  if ((ghost = dynamic_cast<arcade::games::Ghost*>(*it))->getVulne())
	    {
	      ghost->setPos(13, 14);
	      ghost->setVulne(false);
	      ghost->switchAsset();
	      ghost->setSpawn(true);
	    }
	  else
	    return (true);
	}
      it++;
    }
  return (false);
}

bool					arcade::games::Pacman::saveScoreAndQuit() {
  std::fstream				scoreFile;
  std::string				line;
  std::vector<std::string>		vec;
  std::vector<std::string>::iterator	it;
  std::string				tmp;
  size_t				found;
  bool					printed;
  int					oldScore;
  int					i;

  i = 0;
  scoreFile.open("./.Pacman");
  if (scoreFile.is_open())
    {
      while (i++ < 3)
	{
	  std::getline(scoreFile, line);
	  vec.push_back(line);
	}
      scoreFile.close();
    }
  else
    std::cerr << "Couldn't open score file" << std::endl;
  it = vec.begin();
  scoreFile.open("./.Pacman", std::fstream::out);
  i = 0;
  if (scoreFile.is_open())
    {
      while (it != vec.end() && i < 3)
	{
	  found = (*it).find(":");
	  if (found != std::string::npos)
	    {
	      tmp = (*it).substr(found + 1);
	      if (tmp.find_first_not_of("0123456789") != std::string::npos && tmp != "")
		{
		  oldScore = std::stoi(tmp);
		  if (this->score > oldScore && !printed)
		    {
		      if (this->playerName == "")
			scoreFile << "Unknown:" << this->score << "\n";
		      else
			scoreFile << this->playerName << ":" << this->score << "\n";
		      printed = true;
		    }
		  else
		    {
		      scoreFile << (*it) << "\n";
		      it++;
		    }
		}
	    }
	  i++;
	}
      if (i < 3)
	{
	  if (this->playerName == "")
	    scoreFile << "Unknown:" << this->score << "\n";
	  else
	    scoreFile << this->playerName << ":" << this->score << "\n";
	}
      scoreFile.close();
    }
  else
    std::cerr << "Couldn't open score file (2)" << std::endl;
  return (false);
}

bool	arcade::games::Pacman::playRound(const arcade::CommandType &cmd)
{
  std::vector<arcade::games::IGameObject*>::iterator it;

  if (this->count == 245)
    {
      if (this->endGameCount == 0)
	this->strings.push_back(new arcade::String(15, 15, "YOU WIN"));
      if (this->endGameCount == 15)
	return (this->saveScoreAndQuit());
      this->endGameCount++;
      return (true);
    }
  this->runAi();
  if (this->checkCollision())
    return (this->saveScoreAndQuit());
  if (cmd != arcade::CommandType::GO_RIGHT && cmd != arcade::CommandType::GO_LEFT
      && cmd != arcade::CommandType::GO_UP && cmd != arcade::CommandType::GO_DOWN
      && this->oldcmd != arcade::CommandType::ILLEGAL)
    return (this->processCmd(this->oldcmd));
  else
    return (this->processCmd(cmd));
}

extern "C" void Play()
{
  arcade::CommandType		cmd;
  arcade::CommandType		cmdbuff;
  arcade::games::Pacman		pacman;
  struct arcade::WhereAmI	*whereAmI;
  struct arcade::GetMap		*getMap;
  arcade::Position		pos;
  int				i;

  cmdbuff = arcade::CommandType::PLAY;
  while (1)
    {
      std::cin.read(reinterpret_cast<char*>(&cmd), sizeof(arcade::CommandType));
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
			  28 * 31 * sizeof(arcade::TileType) + sizeof(arcade::GetMap));
	}
      if (cmd == arcade::CommandType::GO_UP || cmd == arcade::CommandType::GO_DOWN ||
	  cmd == arcade::CommandType::GO_LEFT || cmd == arcade::CommandType::GO_RIGHT)
	cmdbuff = cmd;
      else if (cmd == arcade::CommandType::PLAY)
	pacman.playRound(cmdbuff);
    }
}

extern "C" arcade::games::IGame	*entry_game()
{
  return (new arcade::games::Pacman());
}

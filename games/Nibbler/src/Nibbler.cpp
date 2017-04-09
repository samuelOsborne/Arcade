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
#include <fstream>
#include "IGameObject.hh"
#include "Nibbler.hh"
#include "NibblerFloor.hh"
#include "NibblerWall.hh"
#include "NibblerBody.hh"
#include "NibblerFruit.hh"
#include "String.hh"

arcade::games::Nibbler::Nibbler()
 : AGame(15, 15)
{
  arcade::Position	pos;

  this->score = 0;
  pos.x = 5;
  pos.y = 5;
  this->player.setPos(pos);
  this->body.push_back(new arcade::games::NibblerBody(4, 5));
  this->body.push_back(new arcade::games::NibblerBody(3, 5));
  this->body.push_back(new arcade::games::NibblerBody(2, 5));
  this->player.setSprite("./misc/Nibbler/snake");
  this->oldcmd = arcade::CommandType::GO_RIGHT;
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
  this->strings.push_back(new arcade::String(0, 0, std::to_string(this->score)));
  this->pushBackHighScore();
  std::srand(std::time(0));
  this->spawnFruit();
}

arcade::games::Nibbler::~Nibbler()
{
  this->body.clear();
}

void	arcade::games::Nibbler::pushBackHighScore()
{
  std::fstream scoreFile;
  std::string line;
  int y;

  y = 1;
  scoreFile.open("./.Nibbler");
  if (scoreFile.is_open())
  {
    this->strings.push_back(new arcade::String(30, y, "Laderboard"));
    while (std::getline(scoreFile, line))
    {
      y += 2;
      this->strings.push_back(new arcade::String(30, y, line));
    }
    scoreFile.close();
  }
  else
    std::cerr << "Couldn't open score file" << std::endl;
}

bool	arcade::games::Nibbler::checkIfCanMove(const arcade::Position &pos) const
{
  return (((this->map.getTile(pos)->getTileType() == arcade::TileType::EMPTY ||
      this->map.getTile(pos)->getTileType() == arcade::TileType::POWERUP ||
      this->map.getTile(pos)->getTileType() == arcade::TileType::OTHER) &&
      !this->checkPosInBody(pos)));
}

bool					arcade::games::Nibbler::saveScoreAndQuit() {
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
      while (i < 3)
	{
	  std::getline(scoreFile, line);
	  vec.push_back(line);
	  i++;
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
	      if (tmp.find_first_not_of("0123456789") == std::string::npos && tmp != "")
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
  return (this->saveScoreAndQuit());
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
	  this->strings[0]->setSprite(std::to_string(this->score));
	  bodyPos = this->getPosBodyFreeCase();
	  this->body.push_back(new arcade::games::NibblerBody(bodyPos.x, bodyPos.y));
	  this->spawnFruit();
	}
    }
}

const std::vector<arcade::games::IGameObject*>	&arcade::games::Nibbler::getEnemies() const
{
  return (this->body);
}

void						arcade::games::Nibbler::moveBody()
{
  arcade::Position				pos;
  arcade::Position				save;
  std::vector<arcade::games::IGameObject*>::iterator	it;

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
  std::vector<arcade::games::IGameObject*>::const_iterator	it;

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
    {
      this->map.deleteTile(pos);
      this->map.setTile(pos, new arcade::games::NibblerFruit(pos.x, pos.y));
    }
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
  this->moveBody();
  if (cmd != arcade::CommandType::GO_RIGHT && cmd != arcade::CommandType::GO_LEFT
      && cmd != arcade::CommandType::GO_DOWN && cmd != arcade::CommandType::GO_UP)
    return (this->processCmd(this->oldcmd));
  else
    return (this->processCmd(cmd));
}

extern "C" void                				Play()
{
  arcade::CommandType					cmd;
  arcade::CommandType					cmdbuff;
  arcade::games::Nibbler				nibbler;
  struct arcade::WhereAmI				*whereAmI;
  struct arcade::GetMap					*getMap;
  std::vector<arcade::games::IGameObject*>::const_iterator	it;
  arcade::Position					pos;
  uint16_t						length;
  int 							i;

  cmdbuff = arcade::CommandType::PLAY;
  while (1)
    {
      std::cin.read(reinterpret_cast<char*>(&cmd), sizeof(arcade::CommandType));
      if (std::cin.eof())
	return ;

      if (cmd == arcade::CommandType::WHERE_AM_I)
	{
	  length = 1 + nibbler.getEnemies().size();
	  whereAmI = new arcade::WhereAmI[length * sizeof(arcade::Position) + sizeof(arcade::WhereAmI)];
	  whereAmI->type = cmd;
	  whereAmI->lenght = length;
	  it = nibbler.getEnemies().begin();
	  i = 0;
	  while (i < length)
	    {
	      if (i == 0)
		whereAmI->position[i] = nibbler.getPlayer()->getPos();
	      else
		{
		  whereAmI->position[i] = (*it)->getPos();
		  it++;
		}
	      i++;
	    }
	  std::cout.write(reinterpret_cast<char*>(whereAmI),
			  length * sizeof(arcade::Position) + sizeof(arcade::WhereAmI));
	  delete whereAmI;
	}

      if (cmd == arcade::CommandType::GET_MAP)
	{
	  getMap = new arcade::GetMap[15 * 15 * sizeof(arcade::TileType) +
				      sizeof(arcade::GetMap)];
	  getMap->type = cmd;
	  getMap->height = 15;
	  getMap->width = 15;
	  int i = 0;
	  while (i < 15 * 15)
	    {
	      pos.y = i / 15;
	      pos.x = i % 15;
	      getMap->tile[i] = nibbler.getMap()->getTile(pos)->getTileType();
	      i++;
	    }
	  std::cout.write(reinterpret_cast<char *>(getMap),
			  15 * 15 * sizeof(arcade::TileType) +
			  sizeof(arcade::GetMap));
	  delete getMap;
	}
      if (cmd == arcade::CommandType::GO_UP || cmd == arcade::CommandType::GO_DOWN ||
	  cmd == arcade::CommandType::GO_LEFT || cmd == arcade::CommandType::GO_RIGHT)
	cmdbuff = cmd;
      if (cmd == arcade::CommandType::PLAY)
	nibbler.playRound(cmdbuff);
    }
}

extern "C" arcade::games::IGame	*entry_game()
{
  return (new arcade::games::Nibbler());
}
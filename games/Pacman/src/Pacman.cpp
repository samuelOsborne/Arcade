/*
** Pacman.cpp for cpp_arcade in /home/osborn_s/Tek_2/cpp_arcade/Pacman.cpp
**
** Made by Samuel Osborne
** Login   <samuel.osborne@epitech.eu>
**
** Started on  Sat Mar 18 13:29:23 2017 Samuel Osborne
** Last update Sat Mar 18 13:29:23 2017 Samuel Osborne
*/

#include <typeinfo>
#include <iostream>
#include "../include/Pacgum.hh"
#include "Wall.hpp"
#include "Floor.hpp"
#include "../include/Pacman.hpp"

arcade::games::Pacman::Pacman() : arcade::games::AGame(27, 31)
{
  arcade::Position pos;
  pos.x = 15;
  pos.y = 24;
  this->player.setPos(pos);
  this->launch();
}

arcade::games::Pacman::Pacman(const arcade::games::Pacman &other)
 : arcade::games::AGame(27, 31)
{
  if (this != &other)
    {
      this->player = other.player;
    }
}

arcade::games::Pacman 				&arcade::games::Pacman::operator=(const Pacman& other)
{
  if (this != &other)
    {
      this->player = other.player;
    }
  return (*this);
}

void						arcade::games::Pacman::createWallsHor(int start, int end, int y)
{
  std::vector<arcade::Wall*>			walls;

  while (start < end)
    {
      walls.push_back(new arcade::Wall(start, y));
      this->map.setTile(walls.back()->getPos(), walls.back());
      start++;
    }
}

void						arcade::games::Pacman::createWallsVer(int startX, int startY, int endY)
{
  std::vector<arcade::Wall*>			walls;

  while (startY < endY)
    {
      walls.push_back(new arcade::Wall(startX, startY));
      walls.back()->setAsset("./misc/Pacman/Verticalpipe");
      this->map.setTile(walls.back()->getPos(), walls.back());
      startY++;
    }
}

void						arcade::games::Pacman::createWallsNOpipe(int startX, int startY)
{
  arcade::Wall					*wall = new arcade::Wall(startX, startY);

  wall->setAsset("./misc/Pacman/NOpipe");
  this->map.setTile(wall->getPos(), wall);
}

void						arcade::games::Pacman::createWallsNEpipe(int startX, int startY)
{
  arcade::Wall					*wall = new arcade::Wall(startX, startY);

  wall->setAsset("./misc/Pacman/NEpipe");
  this->map.setTile(wall->getPos(), wall);
}

void						arcade::games::Pacman::createWallsSEpipe(int startX, int startY)
{
  arcade::Wall					*wall = new arcade::Wall(startX, startY);

  wall->setAsset("./misc/Pacman/SEpipe");
  this->map.setTile(wall->getPos(), wall);
}

void						arcade::games::Pacman::createWallsLine(int x, int y, int length)
{
  int 						i = 0;
  std::vector<arcade::Wall*>			walls;

  while (i < length)
    {
      walls.push_back(new arcade::Wall(x + i, y));
      walls.back()->setAsset("./misc/Pacman/Horizontalpipe");
      this->map.setTile(walls.back()->getPos(), walls.back());
      i++;
    }
}

void						arcade::games::Pacman::createCube(int length, int height, int x, int y)
{
  this->createWallsNOpipe(x, y);
  this->createWallsLine(x + 1, y, length - 1);
  this->createWallsNEpipe(x + length, y);
  this->createWallsVer(x, y + 1, y + height);

  this->createWallsVer(x + length, y + 1, y + height);
  this->createWallsSOpipe(x, y + height);
  this->createWallsLine(x + 1, y + height, length - 1);
  this->createWallsSEpipe(x + length, y + height);
}

void 						arcade::games::Pacman::createStraightWall(int startX, int startY, int size)
{
  int						i = 0;

  while (i < size)
    {
      createWallsLine(startX, startY++, 1);
      i++;
    }
}

void						arcade::games::Pacman::createWallsSOpipe(int startX, int startY)
{
  arcade::Wall					*wall = new arcade::Wall(startX, startY);

  wall->setAsset("./misc/Pacman/SOpipe");
  this->map.setTile(wall->getPos(), wall);
}

void						arcade::games::Pacman::createUpRightT(int x, int y, int size)
{
  this->createWallsLine(x, y, size + 1);
  this->createWallsVer(x + size / 2 , y + 1, y + size);
}

void						arcade::games::Pacman::createUpLeftT(int x, int y, int size)
{
  this->createWallsVer(x, y, y + size + 1);
  this->createWallsLine(x + 1, y + size / 2, size);
}

void 						arcade::games::Pacman::createRightSideT(int x, int y, int size)
{
  this->createWallsVer(x, 8, 11);
  this->createWallsHor(x - size, x, y + size / 2);
}

void						arcade::games::Pacman::initPacgum()
{
  int 						x = 0;
  int 						y = 1;
  std::vector<arcade::games::Pacgum*>		gum;
  int						a[30][40]= {{0, 0, 0, 0, 0, 1, 1, 1, 1, 1,
								   0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
								   0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
								   0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
								 {0, 0, 0, 0, 0, 1, 1, 1, 1, 1,
								  1, 1, 1, 1, 1, 0, 1, 1, 1, 1,
								  1, 1, 1, 1, 1, 1, 0, 0, 0, 0,
								  0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
								 {0, 0, 0, 0, 0, 1, 1, 1, 1, 1,
								  1, 1, 1, 1, 1, 0, 1, 1, 1, 1,
								  1, 1, 1, 1, 1, 1, 0, 0, 0, 0,
								  0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
								 {0, 0, 0, 0, 0, 1, 0, 0, 1, 1,
								  1, 1, 0, 1, 1, 1, 1, 1, 0, 1,
								  1, 1, 1, 0, 1, 1, 0, 0, 0, 0,
								  0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
								 {0, 0, 0, 0, 0, 1, 1, 1, 1, 1,
								  1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
								  1, 1, 1, 1, 1, 1, 0, 0, 0, 0,
								  0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
								 {0, 0, 0, 0, 0, 1, 1, 1, 1, 1,
								  1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
								  1, 1, 1, 1, 1, 1, 0, 0, 0, 0,
								  0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
								 {0, 0, 0, 0, 0, 1, 1, 1, 1, 1,
								  1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
								  1, 1, 1, 1, 1, 1, 0, 0, 0, 0,
								  0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
								 {0, 0, 0, 0, 0, 1, 1, 1, 1, 1,
								  1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
								  1, 1, 1, 1, 1, 1, 0, 0, 0, 0,
								  0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
								 {0, 0, 0, 0, 0, 1, 1, 1, 1, 1,
								  1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
								  1, 1, 1, 1, 1, 1, 0, 0, 0, 0,
								  0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
								 {0, 0, 0, 0, 0, 1, 1, 1, 1, 1,
								  1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
								  1, 1, 1, 1, 1, 1, 0, 0, 0, 0,
								  0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
								 {0, 0, 0, 0, 0, 1, 1, 1, 1, 1,
								  1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
								  1, 1, 1, 1, 1, 1, 0, 0, 0, 0,
								  0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
								 {0, 0, 0, 0, 0, 1, 1, 1, 1, 1,
								  1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
								  1, 1, 1, 1, 1, 1, 0, 0, 0, 0,
								  0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
								 {0, 0, 0, 0, 0, 1, 1, 1, 1, 1,
								  1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
								  1, 1, 1, 1, 1, 1, 0, 0, 0, 0,
								  0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
								 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
								  1, 1, 0, 0, 0, 0, 0, 0, 0, 1,
								  1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
								  0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
								 {0, 0, 0, 0, 0, 1, 1, 1, 1, 1,
								  1, 1, 0, 0, 1, 0, 0, 0, 0, 1,
								  1, 0, 0, 0, 1, 1, 0, 0, 0, 0,
								  0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
								 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
								  1, 0, 0, 1, 0, 0, 0, 0, 0, 1,
								  1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
								  0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
								 {0, 0, 0, 0, 0, 1, 1, 1, 1, 1,
								  1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
								  1, 1, 1, 0, 0, 0, 0, 0, 0, 0,
								  0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
								 {0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
								  1, 1, 0, 0, 1, 1, 1, 1, 0, 1,
								  1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
								  0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
								 {0, 0, 0, 0, 0, 1, 1, 1, 1, 1,
								  1, 1, 0, 0, 0, 0, 0, 0, 0, 1,
								  1, 1, 1, 1, 1, 1, 0, 0, 0, 0,
								  0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
								 {0, 0, 0, 0, 0, 1, 1, 1, 1, 1,
								  1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
								  1, 1, 1, 1, 1, 1, 0, 0, 0, 0,
								  0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
								 {0, 0, 0, 0, 0, 1, 1, 1, 1, 1,
								  1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
								  1, 1, 1, 1, 1, 1, 0, 0, 0, 0,
								  0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
								 {0, 0, 0, 0, 0, 1, 1, 0, 1, 1,
								  1, 1, 1, 1, 1, 0, 1, 1, 0, 1,
								  1, 1, 1, 0, 0, 1, 0, 0, 0, 0,
								  0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
								 {0, 0, 0, 0, 0, 1, 1, 1, 1, 1,
								  1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
								  1, 1, 1, 1, 1, 1, 0, 0, 0, 0,
								  0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
								 {0, 0, 0, 0, 0, 1, 1, 1, 1, 1,
								  1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
								  1, 1, 1, 1, 1, 1, 0, 0, 0, 0,
								  0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
								 {0, 0, 0, 0, 0, 1, 1, 1, 1, 1,
								  1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
								  1, 1, 1, 1, 1, 1, 0, 0, 0, 0,
								  0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
								 {0, 0, 0, 0, 0, 1, 1, 1, 1, 1,
								  1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
								  1, 1, 1, 1, 1, 1, 0, 0, 0, 0,
								  0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
								 {0, 0, 0, 0, 0, 1, 1, 1, 1, 1,
								  1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
								  1, 1, 1, 1, 1, 1, 0, 0, 0, 0,
								  0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
								 {0, 0, 0, 0, 0, 1, 1, 1, 1, 1,
								  1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
								  1, 1, 1, 1, 1, 1, 0, 0, 0, 0,
								  0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
								 {0, 0, 0, 0, 0, 1, 1, 1, 1, 1,
								  1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
								  1, 1, 1, 1, 1, 1, 0, 0, 0, 0,
								  0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
								 {0, 0, 0, 0, 0, 1, 1, 1, 1, 1,
								  1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
								  1, 1, 1, 1, 1, 1, 0, 0, 0, 0,
								  0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

  arcade::Position	pos;
  while (y < 30)
    {
      x = 0;
       while (x < 27)
	 {
	   if (a[y][x] == 1)
	     {
	       gum.push_back(new arcade::games::Pacgum(x, y));
	       pos.x = x;
	       pos.y = y;
	       if (this->map.getTile(pos)->getObj() == "Floor")
	       	this->map.setTile(gum.back()->getPos(), gum.back());
	     }
	   x++;
	 }
      y++;
    }
}

void						arcade::games::Pacman::launch()
{
  this->createCube(2, 2, 6, 2);
  this->createCube(2, 2, 11, 2);

  this->createCube(2, 2, 17, 2);
  this->createCube(2, 2, 22, 2);

  this->createCube(2, 1, 6, 7);
  this->createCube(2, 1, 22, 7);
  //top line
  this->createWallsHor(5, 26, 0);

  //top right corner
  this->createWallsNOpipe(4, 0);
  //right vert line and weird square thing
  this->createWallsVer(26, 0, 12);
  this->createWallsSEpipe(26,12);
  this->createWallsHor(21, 26, 12);
  this->createWallsNOpipe(21, 12);
  this->createWallsVer(21, 13, 14);
  this->createWallsSOpipe(21, 14);
  this->createWallsHor(22, 26, 14);

  this->createWallsHor(23, 26, 24);
  this->createWallsHor(4, 8, 24);

  this->createWallsNEpipe(26, 18);
  this->createWallsHor(22, 26, 18);
  this->createWallsSOpipe(21, 18);
  this->createWallsVer(21, 17, 18);
  this->createWallsNOpipe(21, 16);
  this->createWallsHor(22, 26, 16);

  //end of right line
  this->createWallsVer(26, 19, 30);
  //top left corner
  this->createWallsNEpipe(26, 0);
  //left wall
  this->createWallsVer(4, 1, 12);
  this->createWallsSOpipe(4, 12);
  this->createWallsHor(5, 9, 12);
  this->createWallsNEpipe(9,12);
  this->createWallsVer(9, 13, 14);
  this->createWallsSEpipe(9, 14);
  this->createWallsHor(5, 9, 14);


  //middle linedays
  this->createWallsVer(15, 1, 3);
  //bottom line
  this->createWallsHor(5, 26, 30);
  //bottom right corner
  this->createWallsSEpipe(26, 30);
  //bottom left corner
  this->createWallsSOpipe(4, 30);


  //left wall and box
  this->createWallsVer(4, 19, 30);
  this->createWallsNOpipe(4, 18);
  this->createWallsHor(5, 9, 18);
  this->createWallsSEpipe(9, 18);
  this->createWallsVer(9, 17, 18);
  this->createWallsNEpipe(9, 16);
  this->createWallsHor(5, 9, 16);


  //enemy spawn point
  this->createWallsHor(14, 15, 14);
  this->createWallsHor(16, 17, 14);
  this->createWallsNOpipe(13, 14);
  this->createWallsVer(13, 15, 17);
  this->createWallsSOpipe(13, 17);
  this->createWallsHor(14, 17, 17);
  //right line middle spawn
  this->createWallsSEpipe(17, 17);
  this->createWallsVer(17, 15, 17);
  this->createWallsNEpipe(17, 14);

  //creating the t's
  this->createUpRightT(14, 6, 2);
  this->createUpLeftT(11, 8, 2);
  this->createRightSideT(19, 8, 2);

  //mid obstacle lines
  this->createWallsVer(11, 13, 18);
  this->createWallsVer(19, 13, 18);

  //bottom sections
  this->createUpRightT(13, 19, 4);
  this->createUpRightT(13, 25, 4);
  this->createWallsLine(7, 27, 4);
  this->createWallsVer(7, 26, 29);
  this->createCube(1, 1, 12, 27);
  this->createCube(1, 1, 17, 27);
  this->createWallsLine(20, 27, 3);
  this->createWallsVer(23, 26, 29);
  this->createWallsLine(18, 21, 3);
  this->createCube(2, 2, 22, 20);
  this->createWallsLine(10, 21, 3);
  this->createCube(2, 2, 6, 20);

  this->initPacgum();
}

arcade::Map					arcade::games::Pacman::getPacMap() const
{
  return (this->map);
}

arcade::Player					*arcade::games::Pacman::getPlayer()
{
  return (&this->player);
}

void						arcade::games::Pacman::runAi()
{

}

int 						arcade::games::Pacman::checkIfCanMove(arcade::Position pos, arcade::CommandType cmd)
{

  std::cout << this->map.getTile(pos)->getObj() << std::endl;
  if (this->map.getTile(pos)->getObj() == "Floor" ||
   this->map.getTile(pos)->getObj() == "Pickup" ||
   this->map.getTile(pos)->getObj() == "Powerup" ||
   this->map.getTile(pos)->getObj() == "Pacgum")
    {
      if (this->map.getTile(pos)->getObj() == "Pacgum")
	this->map.setTile(pos, new arcade::Floor(pos.x, pos.y));
      return (0);
    }
  return (1);
}

arcade::Map					arcade::games::Pacman::receiveMapAndCtrl(arcade::Map map, arcade::CommandType cmd)
{
  arcade::Position				pos;

  pos = this->player.getPos();
  if (cmd == arcade::CommandType::GO_RIGHT)
    {
      pos.x++;
      if (this->checkIfCanMove(pos, arcade::CommandType::GO_RIGHT) != 1)
	this->player.move(pos);
      else
	pos.x--;
    }
  else if (cmd == arcade::CommandType::GO_LEFT)
    {
      pos.x--;
      if (this->checkIfCanMove(pos, arcade::CommandType::GO_LEFT) != 1)
	this->player.move(pos);
      else
      	pos.x++;
    }
  else if (cmd == arcade::CommandType::GO_UP)
    {
      pos.y--;
      if (this->checkIfCanMove(pos, arcade::CommandType::GO_UP) != 1)
	  this->player.move(pos);
      else
	pos.y++;
    }
  else if (cmd == arcade::CommandType::GO_DOWN)
    {
      pos.y++;
      if (this->checkIfCanMove(pos, arcade::CommandType::GO_DOWN) != 1)
	this->player.move(pos);
      else
	pos.y--;
    }
  this->runAi();
  return (map);
}

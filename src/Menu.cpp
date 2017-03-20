/*
** Menu.cpp for cpp_arcade in /home/villen_l/rendu/cpp_arcade/Menu.cpp
**
** Made by Lucas Villeneuve
** Login   <lucas.villeneuve@epitech.eu>
**
** Started on  Mon Mar 13 16:09:37 2017 Lucas Villeneuve
** Last update Mon Mar 13 16:09:37 2017 Lucas Villeneuve
*/

#include <thread>
#include "IGameObject.hpp"
#include "Protocol.hpp"
#include "Map.hh"
#include "Menu.hh"

//Sam test
#include "../games/Pacman/include/Pacman.hpp"

arcade::Menu::Menu(const char *nameLib)
{
  this->setLib(nameLib);
//  this->lib->playMusic("./misc/CrashTheme.wav");
  this->lib->playMusic("./misc/Pacman/Pacman.wav");
}

arcade::Menu::~Menu()
{
}

const char	*arcade::Menu::getLibName() const
{
  return (this->libList.list[this->libList.index].c_str());
}

void	arcade::Menu::incrementLibListIndex()
{
  this->libList.index++;
  if (this->libList.index == static_cast<int>(this->libList.list.size()))
    this->libList.index = 0;
}

void 	arcade::Menu::decrementLibListIndex()
{
  this->libList.index--;
  if (this->libList.index == -1)
    this->libList.index = static_cast<int>(this->libList.list.size() - 1);
}

void	arcade::Menu::setLib(const char *nameLib)
{
  if (!(this->lib = this->loader.getInstance(nameLib)))
    throw (std::exception());
  this->lib->openWindow();
}

void	arcade::Menu::closeLib()
{
  this->lib->closeWindow();
  delete (lib);
  this->loader.closeHandler();
}

void 	arcade::Menu::switchLib(const MenuIndexLib &switchType)
{
  this->lib->stopMusic();
  this->closeLib();
  if (switchType == MenuIndexLib::INCREMENT)
    this->incrementLibListIndex();
  else if (switchType == MenuIndexLib::DECREMENT)
    this->decrementLibListIndex();
  std::this_thread::sleep_for(std::chrono::milliseconds(250));
  this->setLib(this->getLibName());
  this->lib->playMusic("./misc/CrashTheme.wav");
}


void			arcade::Menu::drawMap(const arcade::Map &map)
{
  uint16_t		width;
  uint16_t		height;
  uint16_t		i;
  uint16_t		j;
  arcade::Position	pos;

  width = map.getWidth();
  height = map.getHeight();
  i = 0;
  while (i < height)
    {
      j = 0;
      while (j < width)
	{
	  pos.x = j;
	  pos.y = i;
	  this->lib->drawGameObject(map.getTile(pos));
	  j++;
	}
      i++;
    }
}

//#include "Kappa.hh"

void			arcade::Menu::loopMenu()
{
  arcade::games::Pacman	pacMan;
  pacMan.launch();
//  map. = pacMan.getPacMap();

  //arcade::Map           map(8, 8);
  arcade::Map           map = pacMan.getPacMap();
//  Kappa			kap(5, 5);
  arcade::Position	pos;
  /*
  arcade::games::IGameObject* test = new arcade::Floor();
  arcade::Floor 	floor1;
  arcade::Floor 	floor2;
  arcade::Floor 	floor3;
  arcade::Floor 	floor4;
  arcade::Floor 	floor5;
  arcade::Floor 	floor6;
  arcade::Floor 	floor7;
  arcade::Floor 	floor8;
  arcade::Floor 	floor9;

  pos.x = 0;
  pos.y = 0;
  floor1.setPos(pos);
  map->setTile(pos, &floor1);

  pos.x += 5;
  floor2.setPos(pos);
  map->setTile(pos, &floor2);

  pos.x += 1;
  floor3.setPos(pos);
  map->setTile(pos, &floor3);

  pos.x += 1;
  floor4.setPos(pos);
  map->setTile(pos, &floor4);
  pos.x += 1;
  floor5.setPos(pos);
  map->setTile(pos, &floor5);
  pos.x += 1;
  floor6.setPos(pos);
  map->setTile(pos, &floor6);
  pos.x += 1;
  floor7.setPos(pos);
  map->setTile(pos, &floor7);
  pos.x += 1;
  floor8.setPos(pos);
  map->setTile(pos, &floor8);
  pos.y += 1;
  floor9.setPos(pos);
  map->setTile(pos, &floor9);
  */
  pos.x = 5;
  pos.y = 5;
//  map.setTile(pos, &kap);

  while (!this->lib->isEventQuit() &&
	 !this->lib->isKeyPressed(arcade::Input(arcade::InputState::KEY_PRESSED, arcade::InputKey::ESCAPE)))
    {
      this->lib->clear();
      if (this->lib->isKeyPressed(arcade::Input(arcade::InputState::KEY_PRESSED, arcade::InputKey::NUM2)))
	this->switchLib(MenuIndexLib::DECREMENT);
      else if (this->lib->isKeyPressed(arcade::Input(arcade::InputState::KEY_PRESSED, arcade::InputKey::NUM3)))
	this->switchLib(MenuIndexLib::INCREMENT);
      else if (this->lib->isKeyPressed(arcade::Input(arcade::InputState::KEY_PRESSED, arcade::InputKey::NUM4)))
	{
	  this->launchGame("Pacman");
	  break;
	}
      else
	{
	  //this->drawMap(map);
	  //this->drawMap(map);
	  pos.y = 0;
	  this->lib->drawText("Controls :", pos);
	  pos.y = 35;
	  this->lib->drawText("2 : Prev. lib", pos);
	  pos.y = 60;
	  this->lib->drawText("3 : Next lib", pos);
	  pos.y = 75;
	  this->lib->drawText("4 : Play Pacman!", pos);
	}
      this->lib->display();
//      std::this_thread::sleep_for(std::chrono::seconds(3));
    }
	  this->closeLib();
}

void 			arcade::Menu::launchGame(std::string gameName)
{
  arcade::games::Pacman	pacMan;
  arcade::Map           map = pacMan.getPacMap();
  arcade::Player	player;
  arcade::CommandType 	cmd;

  if (gameName == "Pacman")
    {
      while (!this->lib->isEventQuit() &&
	     !this->lib->isKeyPressed(arcade::Input(arcade::InputState::KEY_PRESSED, arcade::InputKey::ESCAPE)))
	{
	  if (this->lib->isKeyPressed(arcade::Input(arcade::InputState::KEY_PRESSED, arcade::InputKey::NUM3)))
	    this->loopMenu();
	  // cmd = process input -> pass cmd to the game
	  map = pacMan.receiveMapAndCtrl(map, this->lib->processInput());
	  this->lib->clear();
	  this->drawMap(map);
	  this->lib->display();
	  std::this_thread::sleep_for(std::chrono::milliseconds(250));
	}
    }
}
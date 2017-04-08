/*
** LibNcurses.cpp for cpp_arcade in /home/osborn_s/Tek_2/cpp_arcade/LibNcurses.cpp
**
** Made by Samuel Osborne
** Login   <samuel.osborne@epitech.eu>
**
** Started on  Mon Apr 03 10:00:48 2017 Samuel Osborne
** Last update Mon Apr 03 10:00:48 2017 Samuel Osborne
*/

#include <fstream>
#include <iostream>
#include <sstream>
#include "LibNcurses.hh"

arcade::library::LibNcurses::LibNcurses()
{
  this->keymap.insert(std::pair<arcade::InputKey, int>(arcade::InputKey::UNKNOWN, 0));
  this->keymap.insert(std::pair<arcade::InputKey, int>(arcade::InputKey::ESCAPE, 27));
  this->keymap.insert(std::pair<arcade::InputKey, int>(arcade::InputKey::NUM0, '0'));
  this->keymap.insert(std::pair<arcade::InputKey, int>(arcade::InputKey::NUM1, '1'));
  this->keymap.insert(std::pair<arcade::InputKey, int>(arcade::InputKey::NUM2, '2'));
  this->keymap.insert(std::pair<arcade::InputKey, int>(arcade::InputKey::NUM3, '3'));
  this->keymap.insert(std::pair<arcade::InputKey, int>(arcade::InputKey::NUM4, '4'));
  this->keymap.insert(std::pair<arcade::InputKey, int>(arcade::InputKey::NUM5, '5'));
  this->keymap.insert(std::pair<arcade::InputKey, int>(arcade::InputKey::NUM6, '6'));
  this->keymap.insert(std::pair<arcade::InputKey, int>(arcade::InputKey::NUM7, '7'));
  this->keymap.insert(std::pair<arcade::InputKey, int>(arcade::InputKey::NUM8, '8'));
  this->keymap.insert(std::pair<arcade::InputKey, int>(arcade::InputKey::NUM9, '9'));
  this->keymap.insert(std::pair<arcade::InputKey, int>(arcade::InputKey::LEFT, KEY_LEFT));
  this->keymap.insert(std::pair<arcade::InputKey, int>(arcade::InputKey::RIGHT, KEY_RIGHT));
  this->keymap.insert(std::pair<arcade::InputKey, int>(arcade::InputKey::UP, KEY_UP));
  this->keymap.insert(std::pair<arcade::InputKey, int>(arcade::InputKey::DOWN, KEY_DOWN));
  this->keymap.insert(std::pair<arcade::InputKey, int>(arcade::InputKey::SPACE, 32));
  this->keymap.insert(std::pair<arcade::InputKey, int>(arcade::InputKey::ENTER, 10));
}

arcade::library::LibNcurses::~LibNcurses()
{
}

void	arcade::library::LibNcurses::openWindow()
{
  raw();
  initscr();
  noecho();
  cbreak();
  set_escdelay(1);
  start_color();
  curs_set(false);
  nodelay(stdscr, true);
  keypad(stdscr, true);
}

void	arcade::library::LibNcurses::closeWindow()
{
  endwin();
}

bool 		arcade::library::LibNcurses::isKeyPressed(const arcade::Input &input)
{
  if (getch() == this->keymap.find(input.key)->second)
      return (true);
  return (false);
}

bool	arcade::library::LibNcurses::isEventQuit()
{
  if (getch() == 27)
    return (true);
  return (false);
}

arcade::CommandType	arcade::library::LibNcurses::processInput()
{
  int 			key;

  key = getch();
  if (key == KEY_LEFT)
    return (arcade::CommandType::GO_LEFT);
  if (key == KEY_RIGHT)
    return (arcade::CommandType::GO_RIGHT);
  if (key == KEY_UP)
    return (arcade::CommandType::GO_UP);
  if (key == KEY_DOWN)
    return (arcade::CommandType::GO_DOWN);
  if (key == '2')
    return (arcade::CommandType::PREV_LIB);
  if (key == '3')
    return (arcade::CommandType::NEXT_LIB);
  if (key == '4')
    return (arcade::CommandType::PREV_GAME);
  if (key == '5')
    return (arcade::CommandType::NEXT_GAME);
  if (key == 10)
    return (arcade::CommandType::LAUNCH);
  if (key == 27)
    return (arcade::CommandType::EXIT);
  if (key == '8')
    return (arcade::CommandType::RESET);
  if (key == '9')
    return (arcade::CommandType::MENU);
  if (key == ' ')
    return (arcade::CommandType::SHOOT);
  return (arcade::CommandType::ILLEGAL);
}

void	arcade::library::LibNcurses::drawText(const std::string &str, const arcade::Position &pos)
{
  mvprintw(pos.y, pos.x, "%s", str.c_str());
}

void	arcade::library::LibNcurses::winClear()
{
  clear();
}

void	arcade::library::LibNcurses::display()
{
  refresh();
}

void	arcade::library::LibNcurses::playMusic(__attribute__((unused)) const std::string &music)
{
  std::cerr << "Can't play music with LibNcurses" << std::endl;
}


void			arcade::library::LibNcurses::drawGameObject(const arcade::games::IGameObject *obj)
{
  std::string		color;
  std::string		character;
  std::ifstream		file;
  std::stringstream 	ss;
  uint16_t		colornb;

  if (obj == NULL)
    return ;
  file.open((obj->getSprite() + ".txt").c_str());
  if (file.is_open())
    {
      if (getline(file, color) && getline(file, character))
	{
	  ss << color;
	  ss >> colornb;
	  mvprintw(obj->getPos().y * 2, obj->getPos().x * 2, "%s", character.c_str());
	  if (getline(file, character))
	    mvprintw(obj->getPos().y * 2 + 1, obj->getPos().x * 2, "%s", character.c_str());
	  file.close();
	  return ;
	}
      file.close();
    }
  std::cerr << "Can't read file" << std::endl;
}

extern "C" arcade::library::IArcadeLibrary	*entry_lib()
{
  return (new arcade::library::LibNcurses());
}
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
//  std::cout << "Keymap" << std::endl;
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
//  std::cout << "done Keymap" << std::endl;
}

arcade::library::LibNcurses::~LibNcurses()
{
}

void	arcade::library::LibNcurses::openWindow()
{
//  std::cout << "openwindow" << std::endl;
  //raw();
  initscr();
  noecho();
  cbreak();
  set_escdelay(1);
  start_color();
  //this->window = newwin(1000, 1000, 0, 0);
//  nodelay(this->window, TRUE);
//  keypad(this->window, TRUE);
  nodelay(stdscr, true);
  keypad(stdscr, true);
//  refresh();
//  std::cout << "done openwindow" << std::endl;
}

void	arcade::library::LibNcurses::closeWindow()
{
//  std::cout << "closewindow" << std::endl;
//  delwin(this->window);
  endwin();
//  std::cout << "done closewindow" << std::endl;
}

bool 		arcade::library::LibNcurses::isKeyPressed(const arcade::Input &input)
{
//  std::cout << "Keypressed" << std::endl;
//  if (wgetch(this->window) == this->keymap.find(input.key)->second)
//    {
//      std::cout << "Keypressed" << std::endl;
//      return (true);
//    }
//  std::cout << "done Keypressed" << std::endl;
//  return (false);
  if (getch() == this->keymap.find(input.key)->second)
    {
//      std::cout << "Keypressed" << std::endl;
      return (true);
    }
//  std::cout << "done Keypressed" << std::endl;
  return (false);
}

bool	arcade::library::LibNcurses::isEventQuit()
{
//  std::cout << "eventquit" << std::endl;
//  if (wgetch(this->window) == 27)
//    {
//      std::cout << " done eventquit" << std::endl;
//      return (true);
//    }
  if (getch() == 27)
    {
//      std::cout << " done eventquit" << std::endl;
      return (true);
    }
//  std::cout << "done eventquit" << std::endl;

  return (false);
}

arcade::CommandType	arcade::library::LibNcurses::processInput()
{
//  std::cout << "process input" << std::endl;

//  if (wgetch(this->window) == KEY_LEFT)
//    return (arcade::CommandType::GO_LEFT);
//  else if (wgetch(this->window) == KEY_RIGHT)
//    return (arcade::CommandType::GO_RIGHT);
//  else if (wgetch(this->window) == KEY_UP)
//    return (arcade::CommandType::GO_UP);
//  else if (wgetch(this->window) == KEY_DOWN)
//    return (arcade::CommandType::GO_DOWN);
//  return (arcade::CommandType::GET_MAP);
  if (getch() == KEY_LEFT)
    return (arcade::CommandType::GO_LEFT);
  else if (getch() == KEY_RIGHT)
    return (arcade::CommandType::GO_RIGHT);
  else if (getch() == KEY_UP)
    return (arcade::CommandType::GO_UP);
  else if (getch() == KEY_DOWN)
    return (arcade::CommandType::GO_DOWN);
  return (arcade::CommandType::GET_MAP);
}

void	arcade::library::LibNcurses::drawText(const std::string &str, const arcade::Position &pos)
{
  //caca_put_str(this->canvas, pos.x / 8, pos.y / 16, str.c_str());
//  std::cout << str << std::endl;
//  std::cout << "drawtext" << std::endl;
//  mvwprintw(this->window, pos.y / 16, pos.x / 16, "%s", str.c_str());
  mvprintw(pos.y / 16, pos.x / 16, "%s", str.c_str());
//  std::cout << "done drawtext" << std::endl;
}

void	arcade::library::LibNcurses::clear()
{
//  wclear(this->window);
//  std::cout << "clear" << std::endl;
  clear();
//  std::cout << "done clear" << std::endl;
}

void	arcade::library::LibNcurses::display()
{
//  std::cout << "disply" << std::endl;

//  wrefresh(this->window);
  refresh();
//  std::cout << "done disply" << std::endl;
}

void	arcade::library::LibNcurses::playMusic(__attribute__((unused)) const std::string &music)
{
  std::cerr << "Can't play music with LibNcurses" << std::endl;
}


void			arcade::library::LibNcurses::drawGameObject(const arcade::IGameObject *obj)
{
  std::string		color;
  std::string		character;
  std::ifstream		file((obj->getSprite() + ".txt").c_str());
  std::stringstream 	ss;
  uint16_t		colornb;

//  std::cout << "gameobject" << std::endl;

  if (file.is_open())
    {
      if (getline(file, color) && getline(file, character))
	{
	  ss << color;
	  ss >> colornb;
//	  caca_set_color_ansi(this->canvas, COLOR_BLACK, colornb);
//	  caca_put_char(this->window, obj->getPos().x, obj->getPos().y, *(character.c_str()));

//	  mvwprintw(this->window, obj->getPos().x / 16, obj->getPos().y / 16, "%c", *(character.c_str()));
	  mvprintw(obj->getPos().x / 16, obj->getPos().y / 16, "%c", *(character.c_str()));

//	  caca_set_color_ansi(this->canvas, COLOR_BLACK, COLOR_BLACK);
	  return ;
	}
      file.close();
    }
  std::cerr << "Can't read file" << std::endl;
}

extern "C" arcade::library::IArcadeLibrary	*entry_point()
{
  return (new arcade::library::LibNcurses());
}
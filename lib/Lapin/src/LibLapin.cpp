//
// LibLapin.cpp for cpp_arcade in /home/escorn_t/Rendu/cpp_arcade/LibLapin.cpp
//
// Made by Thomas Escorne
// Login    <thomas.escorne@epitech.eu>
//
// Started on Tue Mar 14 11:22:25 2017 Thomas Escorne
// Last update Thu Mar 23 16:24:56 2017 escorn_t
//

#include "LibLapin.hh"

arcade::library::LibLapin::LibLapin()
{
  this->keymap.insert(std::pair<arcade::InputKey, int>(arcade::InputKey::UNKNOWN, -1));
  this->keymap.insert(std::pair<arcade::InputKey, int>(arcade::InputKey::ESCAPE, 36));
  this->keymap.insert(std::pair<arcade::InputKey, int>(arcade::InputKey::NUM0, 27));
  this->keymap.insert(std::pair<arcade::InputKey, int>(arcade::InputKey::NUM1, 28));
  this->keymap.insert(std::pair<arcade::InputKey, int>(arcade::InputKey::NUM2, 29));
  this->keymap.insert(std::pair<arcade::InputKey, int>(arcade::InputKey::NUM3, 30));
  this->keymap.insert(std::pair<arcade::InputKey, int>(arcade::InputKey::NUM4, 31));
  this->keymap.insert(std::pair<arcade::InputKey, int>(arcade::InputKey::NUM5, 32));
  this->keymap.insert(std::pair<arcade::InputKey, int>(arcade::InputKey::NUM6, 33));
  this->keymap.insert(std::pair<arcade::InputKey, int>(arcade::InputKey::NUM7, 34));
  this->keymap.insert(std::pair<arcade::InputKey, int>(arcade::InputKey::NUM8, 35));
  this->keymap.insert(std::pair<arcade::InputKey, int>(arcade::InputKey::NUM9, 36));
  this->keymap.insert(std::pair<arcade::InputKey, int>(arcade::InputKey::LEFT, 71));
  this->keymap.insert(std::pair<arcade::InputKey, int>(arcade::InputKey::RIGHT, 72));
  this->keymap.insert(std::pair<arcade::InputKey, int>(arcade::InputKey::UP, 73));
  this->keymap.insert(std::pair<arcade::InputKey, int>(arcade::InputKey::DOWN, 74));
  this->keymap.insert(std::pair<arcade::InputKey, int>(arcade::InputKey::ENTER, 58));
  this->keymap.insert(std::pair<arcade::InputKey, int>(arcade::InputKey::SPACE, 57));
}

arcade::library::LibLapin::~LibLapin()
{
}

#include <iostream>
#include <functional>

t_bunny_response			arcade::library::LibLapin::key_response(t_bunny_event_state state,
										t_bunny_keysym sym,
										void *data)
{
  LibLapin				*obj;

  obj = static_cast<LibLapin *>(data);
  if (state == GO_DOWN)
    obj->keytab[sym] = true;
  else if (state == GO_UP)
    obj->keytab[sym] = false;
  return (GO_ON);
}

t_bunny_response			arcade::library::LibLapin::main_loop(__attribute__((unused)) void *data)
{
  return (GO_ON);
}

void	                        	arcade::library::LibLapin::openWindow()
{
  this->win = bunny_start(800, 600, false, "Arcade - LibLapin");
  bunny_clear(&this->win->buffer, BLACK);
  bunny_display(this->win);
  bunny_set_key_response(&key_response);
  bunny_set_loop_main_function(&main_loop);
  bunny_loop(this->win, 30, this);
}

void                            	arcade::library::LibLapin::closeWindow()
{
  bunny_stop(this->win);
}

bool 	                         	arcade::library::LibLapin::isKeyPressed(const arcade::Input &input)
{
  if (this->keytab[this->keymap.find(input.key)->second] == true)
    return (true);
  return (false);
}

bool                              	arcade::library::LibLapin::isEventQuit()
{
  if (this->keytab[36] == true)
    return (true);
  return (false);
}

void                              	arcade::library::LibLapin::drawText(const std::string &str, const arcade::Position &pos)
{
  (void)str;
  (void)pos;

}

void                               	arcade::library::LibLapin::clear()
{
  bunny_clear(&this->win->buffer, BLACK);
}

void                               	arcade::library::LibLapin::display()
{
  bunny_display(this->win);
}

void 					arcade::library::LibLapin::playMusic(const std::string &music)
{
  (void)music;
}

void 					arcade::library::LibLapin::stopMusic()
{

}

void 					arcade::library::LibLapin::drawGameObject(const arcade::IGameObject *obj)
{
  (void)obj;
}

arcade::CommandType	 		arcade::library::LibLapin::processInput()
{
  if (this->keytab[71] == true)
    return (arcade::CommandType::GO_LEFT);
  if (this->keytab[72] == true)
    return (arcade::CommandType::GO_RIGHT);
  if (this->keytab[73] == true)
    return (arcade::CommandType::GO_UP);
  if (this->keytab[74] == true)
    return (arcade::CommandType::GO_DOWN);
  return (arcade::CommandType::GET_MAP);
}

extern "C" arcade::library::IArcadeLibrary	*entry_point()
{
  return (new arcade::library::LibLapin());
}

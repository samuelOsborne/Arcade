//
// LibCaca.cpp for Arcade in /home/villen_l/rendu/C++/cpp_arcade
// 
// Made by Lucas Villeneuve
// Login   <lucas.villeneuve@epitech.eu>
// 
// Started on  Sat Mar 11 16:53:38 2017 Lucas Villeneuve
// Last update Sun Mar 12 00:32:04 2017 Lucas Villeneuve
//

#include "LibCaca.hh"

arcade::library::LibCaca::LibCaca()
{
  this->keymap.insert(std::pair<arcade::InputKey, int>(arcade::InputKey::UNKNOWN, CACA_KEY_UNKNOWN));
  this->keymap.insert(std::pair<arcade::InputKey, int>(arcade::InputKey::ESCAPE, CACA_KEY_ESCAPE));
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
  this->keymap.insert(std::pair<arcade::InputKey, int>(arcade::InputKey::LEFT, CACA_KEY_LEFT));
  this->keymap.insert(std::pair<arcade::InputKey, int>(arcade::InputKey::RIGHT, CACA_KEY_RIGHT));
  this->keymap.insert(std::pair<arcade::InputKey, int>(arcade::InputKey::UP, CACA_KEY_UP));
  this->keymap.insert(std::pair<arcade::InputKey, int>(arcade::InputKey::DOWN, CACA_KEY_DOWN));
}

arcade::library::LibCaca::~LibCaca()
{
}

#include <iostream>

void	arcade::library::LibCaca::openWindow()
{
  /* TODO
   * Check Retour de fonction
   */

  /*
   * Canvas
   * Width = 8 * nbWidth
   * Height = 16 * nbLength
   */
  this->canvas = caca_create_canvas(38, 19);
  this->window = caca_create_display(this->canvas);
}

void	arcade::library::LibCaca::closeWindow()
{
  caca_free_display(this->window);
  caca_free_canvas(this->canvas);
}

bool 		arcade::library::LibCaca::isKeyPressed(const arcade::Input &input)
{
  caca_event_t	event;

  if (input.key == arcade::InputKey::UNKNOWN)
    {
      if (caca_get_event(this->window, CACA_EVENT_KEY_PRESS, NULL, 0) == 1)
	return (true);
    }
  else
    {
      if (caca_get_event(this->window, CACA_EVENT_KEY_PRESS, &event, 100) == 1)
	if (caca_get_event_key_ch(&event) == this->keymap.find(input.key)->second)
	  return (true);
    }
  return (false);
}

bool	arcade::library::LibCaca::isEventQuit()
{
  if (caca_get_event(this->window, CACA_EVENT_QUIT, NULL, 0) == 1)
    return (true);
  return (false);
}

void	arcade::library::LibCaca::drawText(const std::string &str, const arcade::Position &pos)
{
  caca_put_str(this->canvas, pos.x / 8, pos.y / 16, str.c_str());
}

void	arcade::library::LibCaca::clear()
{
  caca_clear_canvas(this->canvas);
}

void	arcade::library::LibCaca::display()
{
  caca_refresh_display(this->window);
}

extern "C" arcade::library::IArcadeLibrary	*entry_point()
{
  return (new arcade::library::LibCaca());
}
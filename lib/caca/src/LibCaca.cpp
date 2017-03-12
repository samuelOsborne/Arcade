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
  keymap.insert(std::pair<arcade::InputKey, int>(arcade::InputKey::UNKNOWN, CACA_KEY_UNKNOWN));
  keymap.insert(std::pair<arcade::InputKey, int>(arcade::InputKey::ESCAPE, CACA_KEY_ESCAPE));
  keymap.insert(std::pair<arcade::InputKey, int>(arcade::InputKey::NUM0, '0'));
  keymap.insert(std::pair<arcade::InputKey, int>(arcade::InputKey::NUM1, '1'));
  keymap.insert(std::pair<arcade::InputKey, int>(arcade::InputKey::NUM2, '2'));
  keymap.insert(std::pair<arcade::InputKey, int>(arcade::InputKey::NUM3, '3'));
  keymap.insert(std::pair<arcade::InputKey, int>(arcade::InputKey::NUM4, '4'));
  keymap.insert(std::pair<arcade::InputKey, int>(arcade::InputKey::NUM5, '5'));
  keymap.insert(std::pair<arcade::InputKey, int>(arcade::InputKey::NUM6, '6'));
  keymap.insert(std::pair<arcade::InputKey, int>(arcade::InputKey::NUM7, '7'));
  keymap.insert(std::pair<arcade::InputKey, int>(arcade::InputKey::NUM8, '8'));
  keymap.insert(std::pair<arcade::InputKey, int>(arcade::InputKey::NUM9, '9'));
  keymap.insert(std::pair<arcade::InputKey, int>(arcade::InputKey::LEFT, CACA_KEY_LEFT));
  keymap.insert(std::pair<arcade::InputKey, int>(arcade::InputKey::RIGHT, CACA_KEY_RIGHT));
  keymap.insert(std::pair<arcade::InputKey, int>(arcade::InputKey::UP, CACA_KEY_UP));
  keymap.insert(std::pair<arcade::InputKey, int>(arcade::InputKey::DOWN, CACA_KEY_DOWN));
}

arcade::library::LibCaca::~LibCaca()
{
}

void	arcade::library::LibCaca::openWindow()
{
  /* TODO
   * Check Retour de fonction
   */
  this->window = caca_create_display(NULL);
}

void	arcade::library::LibCaca::closeWindow()
{
  caca_free_display(this->window);
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
      if (caca_get_event(this->window, CACA_EVENT_KEY_PRESS, &event, 0) == 1)
	if (caca_get_event_key_ch(&event) == this->keymap[input.key])
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

extern "C" arcade::library::IArcadeLibrary	*entry_point()
{
  return (new arcade::library::LibCaca());
}
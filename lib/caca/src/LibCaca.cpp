//
// LibCaca.cpp for Arcade in /home/villen_l/rendu/C++/cpp_arcade
// 
// Made by Lucas Villeneuve
// Login   <lucas.villeneuve@epitech.eu>
// 
// Started on  Sat Mar 11 16:53:38 2017 Lucas Villeneuve
// Last update Sun Mar 12 00:32:04 2017 Lucas Villeneuve
//

#include <fstream>
#include <iostream>
#include <sstream>
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
  this->keymap.insert(std::pair<arcade::InputKey, int>(arcade::InputKey::SPACE, 32));
  this->keymap.insert(std::pair<arcade::InputKey, int>(arcade::InputKey::ENTER, CACA_KEY_RETURN));
}

arcade::library::LibCaca::~LibCaca()
{
}

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
  this->canvas = caca_create_canvas(38, 38);
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

  if (caca_get_event(this->window, CACA_EVENT_KEY_PRESS, &event, 0) == 1)
    if (caca_get_event_key_ch(&event) == this->keymap.find(input.key)->second)
      return (true);
  return (false);
}

bool		arcade::library::LibCaca::isEventQuit()
{
  caca_event_t	event;

  caca_get_event(this->window, CACA_EVENT_ANY, &event, 0);
  if (caca_get_event_type(&event) == CACA_EVENT_QUIT)
      return (true);
  else if (caca_get_event_key_ch(&event) == CACA_KEY_ESCAPE)
    return (true);
  return (false);
}

arcade::CommandType	arcade::library::LibCaca::processInput()
{
  caca_event_t		event;
  int 			key;

  if (caca_get_event(this->window, CACA_EVENT_KEY_PRESS, &event, 0) == 1)
    {
      key = caca_get_event_key_ch(&event);
      std::cout << "Input : " << key << std::endl;
      if (key == CACA_KEY_LEFT)
	return (arcade::CommandType::GO_LEFT);
      if (key == CACA_KEY_RIGHT)
	return (arcade::CommandType::GO_RIGHT);
      if (key == CACA_KEY_UP)
	return (arcade::CommandType::GO_UP);
      if (key == CACA_KEY_DOWN)
	return (arcade::CommandType::GO_DOWN);
      if (key == '2')
	return (arcade::CommandType::PREV_LIB);
      if (key == '3')
	return (arcade::CommandType::NEXT_LIB);
      if (key == '4')
	return (arcade::CommandType::PREV_GAME);
      if (key == '5')
	return (arcade::CommandType::NEXT_GAME);
      if (key == CACA_KEY_RETURN)
	return (arcade::CommandType::LAUNCH);
      if (key == CACA_KEY_ESCAPE)
	return (arcade::CommandType::EXIT);
      if (key == '8')
	return (arcade::CommandType::RESET);
      if (key == '9')
	return (arcade::CommandType::MENU);
    }
  return (arcade::CommandType::PLAY);
}

void	arcade::library::LibCaca::drawText(const std::string &str, const arcade::Position &pos)
{
  caca_put_str(this->canvas, pos.x / 8, pos.y / 16, str.c_str());
}

void	arcade::library::LibCaca::winClear()
{
  caca_clear_canvas(this->canvas);
}

void	arcade::library::LibCaca::display()
{
  caca_refresh_display(this->window);
}

void	arcade::library::LibCaca::playMusic(__attribute__((unused)) const std::string &music)
{
  std::cerr << "Can't play music with libcaca" << std::endl;
}

void			arcade::library::LibCaca::drawGameObject(const arcade::IGameObject *obj)
{
  std::string		color;
  std::string		character;
  std::ifstream		file((obj->getSprite() + ".txt").c_str());
  std::stringstream 	ss;
  uint16_t		colornb;

  if (file.is_open())
    {
      if (getline(file, color) && getline(file, character))
	{
	  ss << color;
	  ss >> colornb;
	  caca_set_color_ansi(this->canvas, CACA_BLACK, colornb);
	  caca_put_char(this->canvas, obj->getPos().x, obj->getPos().y, *(character.c_str()));
	  caca_set_color_ansi(this->canvas, CACA_BLACK, CACA_BLACK);
	  return ;
	}
      file.close();
    }
  std::cerr << "Can't read file" << std::endl;
}

extern "C" arcade::library::IArcadeLibrary	*entry_point()
{
  return (new arcade::library::LibCaca());
}
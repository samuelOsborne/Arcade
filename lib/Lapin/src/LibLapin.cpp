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


#include <iostream>

arcade::library::LibLapin::LibLapin()
{
  this->keymap.insert(std::pair<arcade::InputKey, int>(arcade::InputKey::UNKNOWN, -1));
  this->keymap.insert(std::pair<arcade::InputKey, int>(arcade::InputKey::ESCAPE, 36));
  this->keymap.insert(std::pair<arcade::InputKey, int>(arcade::InputKey::NUM0, 26));
  this->keymap.insert(std::pair<arcade::InputKey, int>(arcade::InputKey::NUM1, 27));
  this->keymap.insert(std::pair<arcade::InputKey, int>(arcade::InputKey::NUM2, 28));
  this->keymap.insert(std::pair<arcade::InputKey, int>(arcade::InputKey::NUM3, 29));
  this->keymap.insert(std::pair<arcade::InputKey, int>(arcade::InputKey::NUM4, 30));
  this->keymap.insert(std::pair<arcade::InputKey, int>(arcade::InputKey::NUM5, 31));
  this->keymap.insert(std::pair<arcade::InputKey, int>(arcade::InputKey::NUM6, 32));
  this->keymap.insert(std::pair<arcade::InputKey, int>(arcade::InputKey::NUM7, 33));
  this->keymap.insert(std::pair<arcade::InputKey, int>(arcade::InputKey::NUM8, 34));
  this->keymap.insert(std::pair<arcade::InputKey, int>(arcade::InputKey::NUM9, 35));
  this->keymap.insert(std::pair<arcade::InputKey, int>(arcade::InputKey::LEFT, 71));
  this->keymap.insert(std::pair<arcade::InputKey, int>(arcade::InputKey::RIGHT, 72));
  this->keymap.insert(std::pair<arcade::InputKey, int>(arcade::InputKey::UP, 73));
  this->keymap.insert(std::pair<arcade::InputKey, int>(arcade::InputKey::DOWN, 74));
  this->keymap.insert(std::pair<arcade::InputKey, int>(arcade::InputKey::ENTER, 58));
  this->keymap.insert(std::pair<arcade::InputKey, int>(arcade::InputKey::SPACE, 57));
  this->font = bunny_load_picture("./misc/font.png");
  this->font->scale.x = 2;
  this->font->scale.y = 3;
}

arcade::library::LibLapin::~LibLapin()
{
}

t_bunny_response			arcade::library::LibLapin::key_response(t_bunny_event_state state,
										t_bunny_keysym sym,
										void *data)
{
  LibLapin				*obj;

  obj = static_cast<LibLapin *>(data);
  if (state == GO_DOWN)
    obj->keytab[sym] = true;
  return (EXIT_ON_SUCCESS);
}

t_bunny_response			arcade::library::LibLapin::clear_loop(void *data)
{
  LibLapin				*obj;

  obj = static_cast<LibLapin *>(data);
  bunny_clear(&obj->win->buffer, BLACK);
  return (EXIT_ON_SUCCESS);
}

t_bunny_response			arcade::library::LibLapin::display_loop(void *data)
{
  LibLapin				*obj;

  obj = static_cast<LibLapin *>(data);
  bunny_display(obj->win);
  return (EXIT_ON_SUCCESS);
}

void	                        	arcade::library::LibLapin::openWindow()
{
  this->win = bunny_start(800, 600, false, "Arcade - LibLapin");
}

void                            	arcade::library::LibLapin::closeWindow()
{
  bunny_stop(this->win);
}

bool 	                         	arcade::library::LibLapin::isKeyPressed(const arcade::Input &input)
{
  bunny_set_key_response(&key_response);
  bunny_loop(this->win, 30, this);
  if (this->keytab[this->keymap.find(input.key)->second])
  {
    this->keytab[this->keymap.find(input.key)->second] = false;
    return (true);
  }
  return (false);
}

bool                              	arcade::library::LibLapin::isEventQuit()
{
  bunny_set_key_response(&key_response);
  bunny_loop(this->win, 30, this);

  if (this->keytab[36])
  {
    this->keytab[36] = false;
    return (true);
  }
  return (false);
}

t_bunny_response			arcade::library::LibLapin::drawtext_loop(void *data)
{
  LibLapin				*obj;
  t_bunny_position			pos;
//  t_bunny_position			size;
  const char 					*str;
  int 					i;

  obj = static_cast<LibLapin *>(data);
  if (obj->font != NULL)
  {
    i = 0;
    str = obj->txt.c_str();
    obj->font->clip_y_position = 0;
    obj->font->clip_width = 5;
    obj->font->clip_height = 7;
    pos.x = obj->txt_pos.x;
    pos.y = obj->txt_pos.y;
    while (str[i])
    {
      if (str[i] == ' ')
	pos.x += obj->font->scale.x * 7;
      else
      {
	obj->font->clip_x_position = str[i] * 5;
	bunny_blit(&obj->win->buffer, obj->font, &pos);
	pos.x += obj->font->scale.x * 7;
      }
      i++;
    }
  }
  return (EXIT_ON_SUCCESS);
}

void                              	arcade::library::LibLapin::drawText(const std::string &str, const arcade::Position &pos)
{
  this->txt = str;
  this->txt_pos = pos;
  bunny_set_loop_main_function(&drawtext_loop);
  bunny_loop(this->win, 30, this);
}

void                               	arcade::library::LibLapin::clear()
{
  bunny_set_loop_main_function(&clear_loop);
  bunny_loop(this->win, 30, this);
}

void                               	arcade::library::LibLapin::display()
{
  bunny_set_loop_main_function(&display_loop);
  bunny_loop(this->win, 30, this);
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
  bunny_set_key_response(&key_response);
  bunny_loop(this->win, 30, this);
  if (this->keytab[71])
  {
    this->keytab[71] = false;
    return (arcade::CommandType::GO_LEFT);
  }
  if (this->keytab[72])
  {
    this->keytab[72] = false;
    return (arcade::CommandType::GO_RIGHT);
  }
  if (this->keytab[73])
  {
    this->keytab[73] = false;
    return (arcade::CommandType::GO_UP);
  }
  if (this->keytab[74])
  {
    this->keytab[71] = false;
    return (arcade::CommandType::GO_DOWN);
  }
  return (arcade::CommandType::GET_MAP);
}

extern "C" arcade::library::IArcadeLibrary	*entry_point()
{
  return (new arcade::library::LibLapin());
}

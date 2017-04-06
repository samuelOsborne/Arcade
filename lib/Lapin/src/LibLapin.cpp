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
  keymap.insert(std::pair<arcade::InputKey, sf::Keyboard::Key>(arcade::InputKey::UNKNOWN, sf::Keyboard::Key::Unknown));
  keymap.insert(std::pair<arcade::InputKey, sf::Keyboard::Key>(arcade::InputKey::ESCAPE, sf::Keyboard::Key::Escape));
  keymap.insert(std::pair<arcade::InputKey, sf::Keyboard::Key>(arcade::InputKey::NUM0, sf::Keyboard::Key::Num0));
  keymap.insert(std::pair<arcade::InputKey, sf::Keyboard::Key>(arcade::InputKey::NUM1, sf::Keyboard::Key::Num1));
  keymap.insert(std::pair<arcade::InputKey, sf::Keyboard::Key>(arcade::InputKey::NUM2, sf::Keyboard::Key::Num2));
  keymap.insert(std::pair<arcade::InputKey, sf::Keyboard::Key>(arcade::InputKey::NUM3, sf::Keyboard::Key::Num3));
  keymap.insert(std::pair<arcade::InputKey, sf::Keyboard::Key>(arcade::InputKey::NUM4, sf::Keyboard::Key::Num4));
  keymap.insert(std::pair<arcade::InputKey, sf::Keyboard::Key>(arcade::InputKey::NUM5, sf::Keyboard::Key::Num5));
  keymap.insert(std::pair<arcade::InputKey, sf::Keyboard::Key>(arcade::InputKey::NUM6, sf::Keyboard::Key::Num6));
  keymap.insert(std::pair<arcade::InputKey, sf::Keyboard::Key>(arcade::InputKey::NUM7, sf::Keyboard::Key::Num7));
  keymap.insert(std::pair<arcade::InputKey, sf::Keyboard::Key>(arcade::InputKey::NUM8, sf::Keyboard::Key::Num8));
  keymap.insert(std::pair<arcade::InputKey, sf::Keyboard::Key>(arcade::InputKey::NUM9, sf::Keyboard::Key::Num9));
  keymap.insert(std::pair<arcade::InputKey, sf::Keyboard::Key>(arcade::InputKey::LEFT, sf::Keyboard::Key::Left));
  keymap.insert(std::pair<arcade::InputKey, sf::Keyboard::Key>(arcade::InputKey::RIGHT, sf::Keyboard::Key::Right));
  keymap.insert(std::pair<arcade::InputKey, sf::Keyboard::Key>(arcade::InputKey::UP, sf::Keyboard::Key::Up));
  keymap.insert(std::pair<arcade::InputKey, sf::Keyboard::Key>(arcade::InputKey::DOWN, sf::Keyboard::Key::Down));
  keymap.insert(std::pair<arcade::InputKey, sf::Keyboard::Key>(arcade::InputKey::SPACE, sf::Keyboard::Key::Space));
  keymap.insert(std::pair<arcade::InputKey, sf::Keyboard::Key>(arcade::InputKey::ENTER, sf::Keyboard::Key::Return));
  this->font = bunny_load_picture("./misc/font.png");
  this->font->scale.x = 2;
  this->font->scale.y = 2;
}

arcade::library::LibLapin::~LibLapin()
{
}

void	                        	arcade::library::LibLapin::openWindow()
{
  this->win = bunny_start(1400, 1000, false, "Arcade - LibLapin");
}

void                            	arcade::library::LibLapin::closeWindow()
{
  std::map<std::string, t_bunny_picture *>::iterator	pos;

  bunny_delete_clipable(this->font);
  pos = this->loadedTextures.begin();
  while (pos != this->loadedTextures.end()) {
    bunny_delete_clipable(pos->second);
    pos++;
  }
  bunny_stop(this->win);
}

bool 	                         	arcade::library::LibLapin::isKeyPressed(const arcade::Input &input)
{
  return (sf::Keyboard::isKeyPressed(this->keymap.find(input.key)->second));
}

bool                              	arcade::library::LibLapin::isEventQuit()
{
  struct bunny_window			*nwin;
  sf::Event	event;

  nwin = (struct bunny_window *)this->win;
  if (nwin->window->pollEvent(event))
    if (event.type == sf::Event::Closed)
      return (true);
  return (false);
}

void                              	arcade::library::LibLapin::drawText(const std::string &str, const arcade::Position &pos)
{
  const char 				*txt;
  int 					i;
  t_bunny_position			bpos;

  if (this->font != NULL)
  {
    i = 0;
    txt = str.c_str();
    this->font->clip_y_position = 0;
    this->font->clip_width = 5;
    this->font->clip_height = 7;
    bpos.x = pos.x;
    bpos.y = pos.y;
    while (txt[i])
    {
      if (txt[i] == ' ')
	bpos.x += this->font->scale.x * 7;
      else
      {
	this->font->clip_x_position = str[i] * 5;
	bunny_blit(&this->win->buffer, this->font, &bpos);
	bpos.x += this->font->scale.x * 7;
      }
      i++;
    }
  }
}

void                               	arcade::library::LibLapin::winClear()
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
  t_bunny_picture			*texture;
  std::string				filename;
  std::map<std::string, t_bunny_picture *>::iterator	pos;

  if ((pos = this->loadedTextures.find(obj->getSprite())) == this->loadedTextures.end())
  {
    filename = obj->getSprite() + ".png";
    texture = bunny_load_picture(filename.c_str());
    this->loadedTextures.insert(std::pair<std::string, t_bunny_picture *>(obj->getSprite(), texture));
  }
  else
    texture = pos->second;
  this->pngPos.x = obj->getPos().x * 32;
  this->pngPos.y = obj->getPos().y * 32;
  if (texture != NULL)
    bunny_blit(&this->win->buffer, texture, &this->pngPos);
}

arcade::CommandType	 		arcade::library::LibLapin::processInput()
{
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    return (arcade::CommandType::GO_LEFT);
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    return (arcade::CommandType::GO_RIGHT);
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    return (arcade::CommandType::GO_UP);
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    return (arcade::CommandType::GO_DOWN);
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
    return (arcade::CommandType::PREV_LIB);
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
    return (arcade::CommandType::NEXT_LIB);
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4))
    return (arcade::CommandType::PREV_GAME);
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5))
    return (arcade::CommandType::NEXT_GAME);
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
    return (arcade::CommandType::LAUNCH);
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    return (arcade::CommandType::EXIT);
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num8))
    return (arcade::CommandType::RESET);
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num9))
    return (arcade::CommandType::MENU);
  return (arcade::CommandType::PLAY);
}

extern "C" arcade::library::IArcadeLibrary	*entry_point()
{
  return (new arcade::library::LibLapin());
}

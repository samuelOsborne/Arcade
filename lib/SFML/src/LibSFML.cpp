//
// LibSFML.cpp for Arcade in /home/villen_l/rendu/C++/cpp_arcade
// 
// Made by Lucas Villeneuve
// Login   <lucas.villeneuve@epitech.eu>
// 
// Started on  Sun Mar 12 13:53:30 2017 Lucas Villeneuve
// Last update Sun Mar 12 13:53:31 2017 Lucas Villeneuve
//

#include <iostream>
#include "LibSFML.hh"

arcade::library::LibSFML::LibSFML()
{
  if (!(this->font.loadFromFile("./misc/Aaargh.ttf")))
    {
      std::cerr << "Can't load font 'Aaargh.ttf' in ./misc folder" << std::endl;
      this->text = 0;
    }
  else
    this->text = new sf::Text("", this->font, 15);
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
}

arcade::library::LibSFML::~LibSFML()
{
  if (this->text)
    delete (this->text);
}

void	arcade::library::LibSFML::openWindow()
{
  /* TODO
   * Check Retour de fonction
   */
  this->window.create(sf::VideoMode(1400, 1000), "Arcade");
}

void	arcade::library::LibSFML::closeWindow()
{
  this->window.close();
}

bool		arcade::library::LibSFML::isKeyPressed(const arcade::Input &input)
{
  sf::Event	event;

  if (input.key == arcade::InputKey::UNKNOWN)
    {
      if (this->window.pollEvent(event))
	if (event.type == sf::Event::KeyPressed)
	  return (true);
    }
  else
    return (sf::Keyboard::isKeyPressed(this->keymap.find(input.key)->second));
  return (false);
}

bool		arcade::library::LibSFML::isEventQuit()
{
  sf::Event	event;

  if (this->window.pollEvent(event))
    if (event.type == sf::Event::Closed ||
     	(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
      return (true);
  return (false);
}

arcade::CommandType	arcade::library::LibSFML::processInput()
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
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    return (arcade::CommandType::SHOOT);
  return (arcade::CommandType::ILLEGAL);
}

void		arcade::library::LibSFML::drawText(const std::string &str, const arcade::Position &pos)
{
  if (this->text)
    {
      this->text->setString(str);
      this->text->setPosition(pos.x * 32, pos.y * 32);
      this->window.draw(*(this->text));
    }
}

int	arcade::library::LibSFML::getKey()
{
  sf::Event	event;

  if (this->window.pollEvent(event))
    if (event.type == sf::Event::TextEntered && event.text.unicode < 128)
      return (event.text.unicode);
  return (-1);
}

void	arcade::library::LibSFML::winClear()
{
  this->window.clear(sf::Color::Black);
}

void	arcade::library::LibSFML::display()
{
  this->window.display();
}

void		arcade::library::LibSFML::playMusic(const std::string &musicName)
{
  if (!(this->music.openFromFile(musicName)))
    std::cerr << "Can't open music file : " << musicName << std::endl;
  else
    this->music.play();
}

void	arcade::library::LibSFML::stopMusic()
{
  this->music.stop();
}

void						arcade::library::LibSFML::drawGameObject(const arcade::games::IGameObject *obj)
{
  sf::Texture					texture;
  sf::Sprite					sprite;
  std::map<std::string, sf::Texture>::iterator 	pos;

  if (obj == NULL)
    return ;
  if ((pos = this->loadedTextures.find(obj->getSprite())) == this->loadedTextures.end())
    {
      if (!texture.loadFromFile(obj->getSprite() + ".png"))
	if (!texture.loadFromFile(obj->getSprite() + ".bmp"))
	  std::cerr << "Error loading sprite : " << obj->getSprite() << std::endl;
      this->loadedTextures.insert(std::pair<std::string, sf::Texture>(obj->getSprite(), texture));
    }
  else
    texture = pos->second;
  sprite.setTexture(texture);
  sprite.setOrigin(obj->getPos().x * -32, obj->getPos().y * -32);
  this->window.draw(sprite);
}

extern "C" arcade::library::IArcadeLibrary	*entry_lib()
{
  return (new arcade::library::LibSFML());
}
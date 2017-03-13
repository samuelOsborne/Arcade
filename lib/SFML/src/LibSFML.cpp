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
    text = new sf::Text("", this->font, 15);
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
  this->window.create(sf::VideoMode(300, 300), "Arcade");
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
    if (event.type == sf::Event::Closed)
      return (true);
  return (false);
}

void		arcade::library::LibSFML::drawText(const std::string &str, const arcade::Position &pos)
{
  if (this->text)
    {
      this->text->setString(str);
      this->text->setPosition(pos.x, pos.y);
      this->window.draw(*(this->text));
    }
}

void	arcade::library::LibSFML::clear()
{
  this->window.clear(sf::Color::Black);
}

void	arcade::library::LibSFML::display()
{
  this->window.display();
}

extern "C" arcade::library::IArcadeLibrary	*entry_point()
{
  return (new arcade::library::LibSFML());
}
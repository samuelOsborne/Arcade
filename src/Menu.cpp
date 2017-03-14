/*
** Menu.cpp for cpp_arcade in /home/villen_l/rendu/cpp_arcade/Menu.cpp
**
** Made by Lucas Villeneuve
** Login   <lucas.villeneuve@epitech.eu>
**
** Started on  Mon Mar 13 16:09:37 2017 Lucas Villeneuve
** Last update Mon Mar 13 16:09:37 2017 Lucas Villeneuve
*/

#include <thread>
#include "Menu.hh"

arcade::Menu::Menu(const char *nameLib)
{
  this->setLib(nameLib);
}

arcade::Menu::~Menu()
{
}

const char	*arcade::Menu::getLibName() const
{
  return (this->libList.list[this->libList.index].c_str());
}

void	arcade::Menu::incrementLibListIndex()
{
  this->libList.index++;
  if (this->libList.index == NB_LIB)
    this->libList.index = 0;
}

void 	arcade::Menu::decrementLibListIndex()
{
  this->libList.index--;
  if (this->libList.index == -1)
    this->libList.index = NB_LIB - 1;
}

void	arcade::Menu::setLib(const char *nameLib)
{
  if (!(this->lib = this->loader.getInstance(nameLib)))
    throw (std::exception());
  this->lib->openWindow();
}

void	arcade::Menu::closeLib()
{
  this->lib->closeWindow();
  delete (lib);
  this->loader.closeHandler();
}

void 	arcade::Menu::switchLib(const MenuIndexLib &switchType)
{
  this->closeLib();
  if (switchType == MenuIndexLib::INCREMENT)
    this->incrementLibListIndex();
  else if (switchType == MenuIndexLib::DECREMENT)
    this->decrementLibListIndex();
  std::this_thread::sleep_for(std::chrono::milliseconds(250));
  this->setLib(this->getLibName());
}

void			arcade::Menu::loopMenu()
{
  arcade::Position	pos;

  pos.x = 10;
  while (!this->lib->isEventQuit() &&
	 !this->lib->isKeyPressed(arcade::Input(arcade::InputState::KEY_PRESSED, arcade::InputKey::ESCAPE)))
    {
      if (this->lib->isKeyPressed(arcade::Input(arcade::InputState::KEY_PRESSED, arcade::InputKey::NUM2)))
	this->switchLib(MenuIndexLib::DECREMENT);
      else if (this->lib->isKeyPressed(arcade::Input(arcade::InputState::KEY_PRESSED, arcade::InputKey::NUM3)))
	this->switchLib(MenuIndexLib::INCREMENT);

      this->lib->clear();

      pos.y = 0;
      this->lib->drawText("Controls :", pos);
      pos.y = 35;
      this->lib->drawText("2 : Prev. lib", pos);
      pos.y = 60;
      this->lib->drawText("3 : Next lib", pos);

      this->lib->display();
    }
  this->closeLib();
}
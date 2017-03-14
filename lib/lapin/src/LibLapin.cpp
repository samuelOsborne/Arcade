//
// LibLapin.cpp for cpp_arcade in /home/escorn_t/Rendu/cpp_arcade/LibLapin.cpp
//
// Made by Thomas Escorne
// Login    <thomas.escorne@epitech.eu>
//
// Started on Tue Mar 14 11:22:25 2017 Thomas Escorne
// Last update Tue Mar 14 20:12:32 2017 escorn_t
//

#include "LibLapin.hh"

arcade::library::LibLapin::LibLapin()
{
  this->keymap.insert(std::pair<arcade::InputKey, int>(arcade::InputKey::UNKNOWN, -1));
  this->keymap.insert(std::pair<arcade::InputKey, int>(arcade::InputKey::ESCAPE, 27));
  this->keymap.insert(std::pair<arcade::InputKey, int>(arcade::InputKey::NUM0, 0));
  this->keymap.insert(std::pair<arcade::InputKey, int>(arcade::InputKey::NUM1, 1));
  this->keymap.insert(std::pair<arcade::InputKey, int>(arcade::InputKey::NUM2, 2));
  this->keymap.insert(std::pair<arcade::InputKey, int>(arcade::InputKey::NUM3, 3));
  this->keymap.insert(std::pair<arcade::InputKey, int>(arcade::InputKey::NUM4, 4));
  this->keymap.insert(std::pair<arcade::InputKey, int>(arcade::InputKey::NUM5, 5));
  this->keymap.insert(std::pair<arcade::InputKey, int>(arcade::InputKey::NUM6, 6));
  this->keymap.insert(std::pair<arcade::InputKey, int>(arcade::InputKey::NUM7, 7));
  this->keymap.insert(std::pair<arcade::InputKey, int>(arcade::InputKey::NUM8, 8));
  this->keymap.insert(std::pair<arcade::InputKey, int>(arcade::InputKey::NUM9, 9));
  this->keymap.insert(std::pair<arcade::InputKey, int>(arcade::InputKey::LEFT, GLUT_KEY_LEFT));
  this->keymap.insert(std::pair<arcade::InputKey, int>(arcade::InputKey::RIGHT, GLUT_KEY_RIGHT));
  this->keymap.insert(std::pair<arcade::InputKey, int>(arcade::InputKey::UP, GLUT_KEY_UP));
  this->keymap.insert(std::pair<arcade::InputKey, int>(arcade::InputKey::DOWN, GLUT_KEY_DOWN));
}

arcade::library::LibLapin::~LibLapin()
{
}

void	arcade::library::LibLapin::openWindow()
{
  glutInitWindowPosition(100, 100);
  glutInitWindowSize(800, 600);
  glutInitDisplayMode(GLUT_RGBA);
  this->win = glutCreateWindow("Arcade Lapin");
}

void 	arcade::library::LibLapin::closeWindow()
{
  glutDestroyWindow(this->win);
}

bool 	arcade::library::LibLapin::isKeyPressed(const arcade::Input &input)
{
  bool 	*keyState = new bool[256];


}

extern "C" arcade::library::IArcadeLibrary	*entry_point()
{
  return (new arcade::library::LibLapin());
}

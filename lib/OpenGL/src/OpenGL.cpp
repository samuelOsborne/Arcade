//
// OpenGL.cpp for cpp_arcade in /home/escorn_t/Rendu/cpp_arcade/OpenGL.cpp
//
// Made by Thomas Escorne
// Login    <thomas.escorne@epitech.eu>
//
// Started on Tue Mar 14 11:22:25 2017 Thomas Escorne
// Last update Wed Mar 15 14:25:02 2017 escorn_t
//

#include "OpenGL.hh"

arcade::library::OpenGL::OpenGL()
{
  this->keymap.insert(std::pair<arcade::InputKey, int>(arcade::InputKey::UNKNOWN, -1));
  this->keymap.insert(std::pair<arcade::InputKey, int>(arcade::InputKey::ESCAPE, 27));
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
  this->keymap.insert(std::pair<arcade::InputKey, int>(arcade::InputKey::LEFT, GLUT_KEY_LEFT));
  this->keymap.insert(std::pair<arcade::InputKey, int>(arcade::InputKey::RIGHT, GLUT_KEY_RIGHT));
  this->keymap.insert(std::pair<arcade::InputKey, int>(arcade::InputKey::UP, GLUT_KEY_UP));
  this->keymap.insert(std::pair<arcade::InputKey, int>(arcade::InputKey::DOWN, GLUT_KEY_DOWN));
  this->keymap.insert(std::pair<arcade::InputKey, int>(arcade::InputKey::SPACE, 32));
  this->keymap.insert(std::pair<arcade::InputKey, int>(arcade::InputKey::ENTER, 13));
  glutInitDisplayMode(GLUT_RGBA);
  glutInitWindowSize(800,600);

}

arcade::library::OpenGL::~OpenGL()
{
}

void	                        arcade::library::OpenGL::openWindow()
{
  this->win = glutCreateWindow("Arcade OpenGL");
}

void                            arcade::library::OpenGL::closeWindow()
{
  bunny_stop(this->win);
}

t_bunny_response                arcade::library::OpenGL::key_response(t_bunny_event_state state,
                                                                        t_bunny_keysym sym,
                                                                        __attribute__ ((unused)) void *data)
{
  if (state == GO_DOWN)
    this->key[sym] = true;
  if (state == GO_UP)
    this->key[sym] = false;
  return (GO_ON);
}

bool 	                         arcade::library::OpenGL::isKeyPressed(const arcade::Input &input)
{
  if (this->key[this->keymap.find(input.key)->second] == true)
    return (true);
  return (false);
}

bool                              arcade::library::OpenGL::isEventQuit()
{
  return (false);
}

void                              arcade::library::OpenGL::drawText(const std::string &str, const arcade::Position &pos)
{
  
}

void                               arcade::library::OpenGL::clear()
{
  bunny_clear(&this->win->buffer, BLACK);
}

void                               arcade::library::OpenGL::display()
{
  bunny_display(this->win);
}

extern "C" arcade::library::IArcadeLibrary	*entry_point()
{
  return (new arcade::library::OpenGL());
}

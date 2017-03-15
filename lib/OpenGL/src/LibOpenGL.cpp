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
  glutKeyboardFunc(this->keyDown);
  glutKeyboardUpFunc(this->keyUp);
  glutSpecialFunc(this->keySpecDown);
  glutSpecialUpFunc(this->keySpecUp);
  glutDisplayFunc(/* Fonction de display */);
  glutMainLoop(/* Fonction de loop */);
}

arcade::library::OpenGL::~OpenGL()
{
}

void	                        arcade::library::OpenGL::openWindow()
{
  this->win = glutCreateWindow("Arcade OpenGL");
  glClearColor(0.0, 0.0, 0.0, 1.0);
}

void                            arcade::library::OpenGL::closeWindow()
{
  bunny_stop(this->win);
}

void		                arcade::library::OpenGL::keyDown(unsigned char key,
                                                                 __attribute__ ((unused)) int x,
                                                                 __attribute__ ((unused)) int y)
{
  this->normal[key] = true;
}

void		                arcade::library::OpenGL::keyUp(unsigned char key,
								__attribute__ ((unused)) int x,
								__attribute__ ((unused)) int y)
{
  this->normal[key] = false;
}

void		                arcade::library::OpenGL::keySpecDown(int key,
								 __attribute__ ((unused)) int x,
								 __attribute__ ((unused)) int y)
{
  this->special[key] = true;
}

void		                arcade::library::OpenGL::keySpecUp(int key,
								 __attribute__ ((unused)) int x,
								 __attribute__ ((unused)) int y)
{
  this->special[key] = false;
}

bool 	                         arcade::library::OpenGL::isKeyPressed(const arcade::Input &input)
{
  if (input.key != arcade::InputKey::LEFT &&
      input.key != arcade::InputKey::RIGHT &&
      input.key != arcade::InputKey::UP &&
      input.key != arcade::InputKey::DOWN)
  {
    if (this->normal[this->keymap.find(input.key)->second] == true)
      return (true);
  }
  else if (this->special[this->keymap.find(input.key)->second] == true)
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
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void                               arcade::library::OpenGL::display()
{

}

extern "C" arcade::library::IArcadeLibrary	*entry_point()
{
  return (new arcade::library::OpenGL());
}

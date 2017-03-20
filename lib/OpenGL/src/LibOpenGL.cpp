//
// OpenGL.cpp for cpp_arcade in /home/escorn_t/Rendu/cpp_arcade/OpenGL.cpp
//
// Made by Thomas Escorne
// Login    <thomas.escorne@epitech.eu>
//
// Started on Tue Mar 14 11:22:25 2017 Thomas Escorne
// Last update Fri Mar 17 14:37:05 2017 escorn_t
//

#include "LibOpenGL.hh"

arcade::library::LibOpenGL::LibOpenGL()
{
  this->keymap.insert(std::pair<arcade::InputKey, int>(arcade::InputKey::UNKNOWN, GLFW_KEY_UNKNOWN));
  this->keymap.insert(std::pair<arcade::InputKey, int>(arcade::InputKey::ESCAPE, GLFW_KEY_ESCAPE));
  this->keymap.insert(std::pair<arcade::InputKey, int>(arcade::InputKey::NUM0, GLFW_KEY_0));
  this->keymap.insert(std::pair<arcade::InputKey, int>(arcade::InputKey::NUM1, GLFW_KEY_1));
  this->keymap.insert(std::pair<arcade::InputKey, int>(arcade::InputKey::NUM2, GLFW_KEY_2));
  this->keymap.insert(std::pair<arcade::InputKey, int>(arcade::InputKey::NUM3, GLFW_KEY_3));
  this->keymap.insert(std::pair<arcade::InputKey, int>(arcade::InputKey::NUM4, GLFW_KEY_4));
  this->keymap.insert(std::pair<arcade::InputKey, int>(arcade::InputKey::NUM5, GLFW_KEY_5));
  this->keymap.insert(std::pair<arcade::InputKey, int>(arcade::InputKey::NUM6, GLFW_KEY_6));
  this->keymap.insert(std::pair<arcade::InputKey, int>(arcade::InputKey::NUM7, GLFW_KEY_7));
  this->keymap.insert(std::pair<arcade::InputKey, int>(arcade::InputKey::NUM8, GLFW_KEY_8));
  this->keymap.insert(std::pair<arcade::InputKey, int>(arcade::InputKey::NUM9, GLFW_KEY_9));
  this->keymap.insert(std::pair<arcade::InputKey, int>(arcade::InputKey::LEFT, GLFW_KEY_LEFT));
  this->keymap.insert(std::pair<arcade::InputKey, int>(arcade::InputKey::RIGHT, GLFW_KEY_RIGHT));
  this->keymap.insert(std::pair<arcade::InputKey, int>(arcade::InputKey::UP, GLFW_KEY_UP));
  this->keymap.insert(std::pair<arcade::InputKey, int>(arcade::InputKey::DOWN, GLFW_KEY_DOWN));
  this->keymap.insert(std::pair<arcade::InputKey, int>(arcade::InputKey::ENTER, GLFW_KEY_ENTER));
  /*if (!*/glfwInit()/*)*/;
}

arcade::library::LibOpenGL::~LibOpenGL()
{
  glfwTerminate();
}

void	                        	arcade::library::LibOpenGL::openWindow()
{
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
  glfwWindowHint(GLFW_SAMPLES, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  this->win = glfwCreateWindow(800, 600, "Arcade OpenGL", NULL, NULL);
  // If (this->win == NULL)
  // glfwTerminate();
  //throw
  glfwMakeContextCurrent(this->win);
  glewInit(); // if (glewInit != GLEW_OK) throw
  glfwSetInputMode(this->win, GLFW_STICKY_KEYS, GL_TRUE);
}

void                            	arcade::library::LibOpenGL::closeWindow()
{
  glfwDestroyWindow(this->win);
}

bool 	                         	arcade::library::LibOpenGL::isKeyPressed(const arcade::Input &input)
{
  if (glfwGetKey(this->win, this->keymap.find(input.key)->second) == GLFW_PRESS)
    return (true);
  return (false);
}

bool                              	arcade::library::LibOpenGL::isEventQuit()
{
  if (glfwWindowShouldClose(this->win) != 0)
    return (true);
  return (false);
}

void                              	arcade::library::LibOpenGL::drawText(const std::string &str, const arcade::Position &pos)
{
  (void)str;
  (void)pos;
}

void                               	arcade::library::LibOpenGL::clear()
{
}

void                               	arcade::library::LibOpenGL::display()
{
  glfwSwapBuffers(this->win);
  glfwPollEvents();
}

void 					arcade::library::LibOpenGL::playMusic(const std::string &music)
{
  (void)music;
}

void 					arcade::library::LibOpenGL::stopMusic()
{

}

void 					arcade::library::LibOpenGL::drawGameObject(const arcade::IGameObject *obj)
{

}

arcade::CommandType 		arcade::library::LibOpenGL::processInput()
{

}

extern "C" arcade::library::IArcadeLibrary	*entry_point()
{
  return (new arcade::library::LibOpenGL());
}

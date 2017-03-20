
//
// OpenGL.hh for cpp_arcade in /home/escorn_t/Rendu/cpp_arcade/OpenGL.hh
//
// Made by Thomas Escorne
// Login    <thomas.escorne@epitech.eu>
//
// Started on Tue Mar 14 11:03:50 2017 Thomas Escorne
// Last update Sun Mar 19 13:46:43 2017 escorn_t
//
//

#ifndef OPENGL_HH_
# define OPENGL_HH_

# include <map>
# include <GL/glew.h>
# include <GLFW/glfw3.h>
# include <glm/glm.hpp>
# include <stdlib.h> 
# include "IArcadeLibrary.hh"
# include "Arcade.hpp"
# include "Protocol.hpp"

namespace		 		arcade
{
  namespace 				library
  {
    class				LibOpenGL : public arcade::library::IArcadeLibrary
    {
      std::map<arcade::InputKey, int>	keymap;
      GLFWwindow			*win;

     public:
      LibOpenGL();
      ~LibOpenGL();

      virtual void			openWindow();
      virtual void 			closeWindow();
      virtual bool 			isKeyPressed(const arcade::Input &input);
      virtual bool			isEventQuit();
      virtual void 			drawText(const std::string &str, const arcade::Position &pos);
      virtual void 			clear();
      virtual void 			display();
      virtual void 			playMusic(const std::string &music);
      virtual void 			stopMusic();
      virtual void 			drawGameObject(const arcade::IGameObject *obj);
      virtual arcade::CommandType 	processInput();
    };
  };
};

#endif // !OPENGL_HH_

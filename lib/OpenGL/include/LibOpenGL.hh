//
// OpenGL.hh for cpp_arcade in /home/escorn_t/Rendu/cpp_arcade/OpenGL.hh
//
// Made by Thomas Escorne
// Login    <thomas.escorne@epitech.eu>
//
// Started on Tue Mar 14 11:03:50 2017 Thomas Escorne
// Last update Wed Mar 15 14:24:24 2017 escorn_t
//
//

#ifndef OPENGL_HH_
# define OPENGL_HH_

# include <map>
# include <gl/glut.h>
# include "IArcadeLibrary.hh"
# include "Arcade.hpp"
# include "Protocol.hpp"

namespace		 		arcade
{
  namespace 				library
  {
    class				OpenGL : public arcade::library::IArcadeLibrary
    {
      std::map<arcade::InputKey, int>	keymap;
      int         			win;
      bool                              normal[256];
      bool                              special[256];

     private:
      void                              keyDown(unsigned char key,
						__attribute__ ((unused)) int x,
						__attribute__ ((unused)) int y);
      void                              keyUp(unsigned char key,
                                              __attribute__ ((unused)) int x,
                                              __attribute__ ((unused)) int y);
      void                              keySpecDown(int key,
						    __attribute__ ((unused)) int x,
						    __attribute__ ((unused)) int y);
      void                              keySpecUp(int key,
						  __attribute__ ((unused)) int x,
						  __attribute__ ((unused)) int y);

     public:
      OpenGL();
      ~OpenGL();

      virtual void			openWindow();
      virtual void 			closeWindow();
      virtual bool 			isKeyPressed(const arcade::Input &input);
      virtual bool			isEventQuit();
      virtual void 			drawText(const std::string &str, const arcade::Position &pos);
      virtual void 			clear();
      virtual void 			display();
    };
  };
};

#endif // !OPENGL_HH_

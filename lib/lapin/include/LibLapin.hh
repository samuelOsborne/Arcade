/*
** LibLapin.hh for cpp_arcade in /home/escorn_t/Rendu/cpp_arcade/LibLapin.hh
**
** Made by Thomas Escorne
** Login    <thomas.escorne@epitech.eu>
**
** Started on Tue Mar 14 11:03:50 2017 Thomas Escorne
// Last update Tue Mar 14 20:12:48 2017 escorn_t
**
*/

#ifndef LIBLAPIN_HH_
# define LIBLAPIN_HH_

# include <SDL/SDL.h>
# include <GL/gl.h>
# include <GL/glu.h>
# include <map>
# include <IArcadeLibrary.hh>
# include "Arcade.hpp"
# include "Protocol.hpp"

namespace		 		arcade
{
  namespace 				library
  {
    class				LibLapin : public arcade::library::IArcadeLibrary
    {
      std::map<arcade::InputKey, int>	keymap;
      int				win;

     private:


     public:
      LibLapin();
      ~LibLapin();

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

#endif // !LIBLAPIN_HH_

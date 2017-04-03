/*
** LibNcurses.h for cpp_arcade in /home/osborn_s/Tek_2/cpp_arcade/LibNcurses.h
**
** Made by Samuel Osborne
** Login   <samuel.osborne@epitech.eu>
**
** Started on  Mon Apr 03 10:00:48 2017 Samuel Osborne
** Last update Mon Apr 03 10:00:48 2017 Samuel Osborne
*/

#ifndef LIBNCURSES_H
# define LIBNCURSES_H

# include <map>
# include "ncurses.h"
# include "IArcadeLibrary.hh"
# include "Arcade.hpp"
# include "Protocol.hpp"

namespace 						arcade
{
  namespace						library
  {
    class						LibNcurses : public arcade::library::IArcadeLibrary
    {
      WINDOW						*window;
      std::map<arcade::InputKey, int>			keymap;

     public:
      LibNcurses();
      ~LibNcurses();

      virtual void					openWindow();
      virtual void					closeWindow();
      virtual bool 					isKeyPressed(const arcade::Input &input);
      virtual bool					isEventQuit();
      virtual void 					clear();
      virtual void 					display();
      virtual void 					playMusic(const std::string &music);
      virtual void 					stopMusic(){};
      virtual void 					drawText(const std::string &str,
								   const arcade::Position &pos);
      virtual void 					drawGameObject(const arcade::IGameObject*);
      virtual arcade::CommandType 			processInput();
    };

  };
};

#endif //LIBNCURSES_H

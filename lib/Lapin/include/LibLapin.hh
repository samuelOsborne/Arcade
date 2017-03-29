//
// LibLapin.hh for cpp_arcade in /home/escorn_t/Rendu/cpp_arcade/LibLapin.hh
//
// Made by Thomas Escorne
// Login    <thomas.escorne@epitech.eu>
//
// Started on Tue Mar 14 11:03:50 2017 Thomas Escorne
// Last update Thu Mar 23 16:25:25 2017 escorn_t
//
//

#ifndef LIBLAPIN_HH_
# define LIBLAPIN_HH_

# include <map>
# include "lapin.h"
# include "IArcadeLibrary.hh"
# include "Arcade.hpp"
# include "Protocol.hpp"

namespace		 		arcade
{
  namespace 				library
  {
    class				LibLapin : public arcade::library::IArcadeLibrary
    {
      std::map<arcade::InputKey, int>	keymap;
      t_bunny_window			*win;
      bool 				keytab[256];

     public:
      static t_bunny_response			key_response(t_bunny_event_state state, t_bunny_keysym sym, void *data);
      static t_bunny_response			main_loop(void *data);

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
      virtual void 			playMusic(const std::string &music);
      virtual void 			stopMusic();
      virtual void 			drawGameObject(const arcade::IGameObject *obj);
      virtual arcade::CommandType 	processInput();
    };
  };
};

#endif // !LIBLAPIN_HH_

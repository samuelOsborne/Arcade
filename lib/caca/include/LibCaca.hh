//
// LibCaca.hh for Arcade in /home/villen_l/rendu/C++/cpp_arcade
// 
// Made by Lucas Villeneuve
// Login   <lucas.villeneuve@epitech.eu>
// 
// Started on  Sat Mar 11 16:48:58 2017 Lucas Villeneuve
// Last update Sat Mar 11 16:48:59 2017 Lucas Villeneuve
//

#ifndef LIBCACA_HH_
# define LIBCACA_HH_

# include <map>
# include "config.h"
# include "caca.h"
# include "IArcadeLibrary.hh"
# include "Arcade.hpp"
# include "Protocol.hpp"

namespace 				arcade
{
  namespace				library
  {
    class				LibCaca : public arcade::library::IArcadeLibrary
    {
      caca_display_t			*window;
      caca_canvas_t			*canvas;
      caca_event_t			event;
      std::map<arcade::InputKey, int>	keymap;

     public:
      LibCaca();
      LibCaca(const LibCaca &other) = delete;
      LibCaca &operator=(const LibCaca &other) = delete;
      ~LibCaca();

      virtual void			openWindow();
      virtual void			closeWindow();
      virtual bool			isKeyPressed(const arcade::Input &input);
      virtual bool			isEventQuit();
      virtual void 			drawText(const std::string &str, const arcade::Position &pos);
      virtual void 			winClear();
      virtual void 			display();
      virtual int 			getKey();
      virtual void 			playMusic(const std::string &music);
      virtual void 			stopMusic() {};
      virtual void 			drawGameObject(const arcade::games::IGameObject*);
      virtual arcade::CommandType 	processInput();
    };

  };
};

#endif // !LIBCACA_HH_
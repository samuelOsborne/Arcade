//
// LibLapin.hh for cpp_arcade in /home/escorn_t/Rendu/cpp_arcade/LibLapin.hh
//
// Made by Thomas Escorne
// Login    <thomas.escorne@epitech.eu>
//
// Started on Tue Mar 14 11:03:50 2017 Thomas Escorne
// Last update Tue Apr  4 14:06:08 2017 escorn_t
//
//

#ifndef LIBLAPIN_HH_
# define LIBLAPIN_HH_

# include <map>
# include <iterator>
# include <SFML/Window/Keyboard.hpp>
# include <SFML/Config.hpp>
# include <SFML/Window.hpp>
# include <SFML/Graphics.hpp>
# include <gtk/gtk.h>
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
      std::map<arcade::InputKey, sf::Keyboard::Key>	keymap;
      t_bunny_window			*win;
      t_bunny_picture			*font;
      t_bunny_position			pngPos;
      std::map<std::string, t_bunny_picture *>		loadedTextures;
      struct                          bunny_window
      {
	size_t                        type;
	sf::RenderWindow              *window;
	ssize_t                       width;
	ssize_t                       height;
	const char                    *window_name;
      };

     public:
      LibLapin();
      ~LibLapin();

      virtual void			openWindow();
      virtual void 			closeWindow();
      virtual bool 			isKeyPressed(const arcade::Input &input);
      virtual bool			isEventQuit();
      virtual void 			drawText(const std::string &str, const arcade::Position &pos);
      virtual int 			getKey();
      virtual void 			winClear();
      virtual void 			display();
      virtual void 			playMusic(const std::string &music);
      virtual void 			stopMusic();
      virtual void 			drawGameObject(const arcade::games::IGameObject *obj);
      virtual arcade::CommandType 	processInput();
    };
  };
};

#endif // !LIBLAPIN_HH_

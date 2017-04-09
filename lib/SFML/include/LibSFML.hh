//
// LibSFML.hh for Arcade in /home/villen_l/rendu/C++/cpp_arcade
// 
// Made by Lucas Villeneuve
// Login   <lucas.villeneuve@epitech.eu>
// 
// Started on  Sun Mar 12 13:53:40 2017 Lucas Villeneuve
// Last update Sun Mar 12 13:53:41 2017 Lucas Villeneuve
//

#ifndef LIBSFML_HH_
# define LIBSFML_HH_

# include <string>
# include <map>
# include <SFML/Graphics.hpp>
# include <SFML/Audio.hpp>
# include "IArcadeLibrary.hh"
# include "Arcade.hpp"
# include "Protocol.hpp"

namespace 						arcade
{
  namespace						library
  {
    class						LibSFML : public arcade::library::IArcadeLibrary
    {
      sf::RenderWindow					window;
      sf::Font						font;
      sf::Text						*text;
      sf::Music						music;
      bool 						fontLoaded;
      std::map<arcade::InputKey, sf::Keyboard::Key>	keymap;
      std::map<std::string, sf::Texture>		loadedTextures;

     public:
      LibSFML();
      ~LibSFML();

      virtual int 					getKey();
      virtual void					openWindow();
      virtual void					closeWindow();
      virtual bool 					isKeyPressed(const arcade::Input &input);
      virtual bool					isEventQuit();
      virtual void 					winClear();
      virtual void 					display();
      virtual void 					playMusic(const std::string &music);
      virtual void 					stopMusic();
      virtual void 					drawText(const std::string &str,
								   const arcade::Position &pos);
      virtual void 					drawGameObject(const arcade::games::IGameObject*);
      virtual arcade::CommandType 			processInput();
    };

  };
};

#endif // !LIBSFML_HH_
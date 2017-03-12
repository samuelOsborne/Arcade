//
// sfml.cpp for SFML in /mnt/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/villen_l/rendu/C++/cpp_arcade
// 
// Made by Lucas Villeneuve
// Login   <lucas.villeneuve@epitech.eu>
// 
// Started on  Sat Mar 11 15:25:44 2017 Lucas Villeneuve
// Last update Sun Mar 12 15:21:16 2017 Lucas Villeneuve
//

#include "DLLoader.hpp"
#include "IArcadeLibrary.hh"
#include "Arcade.hh"

//void	sfml_test()
//{
//  void 	*dlhandle1;
//  void 	*dlhandle2;
//  void 	*dlhandle3;
//
//  dlhandle1 = dlopen("./libsfml-system.so", RTLD_LAZY);
//  dlhandle2 = dlopen("./libsfml-window.so", RTLD_LAZY);
//  dlhandle3 = dlopen("./libsfml-graphics.so", RTLD_LAZY);
//  if (!dlhandle1 || !dlhandle2 || !dlhandle3)
//    {
//      std::cerr << "Error cant open lib" << std::endl;
//      return ;
//    }
//  sf::RenderWindow	window(sf::VideoMode(200, 200), "Arcade");
//  sf::Event		event;
//  sf::CircleShape	shape(100.f);

//  shape.setFillColor(sf::Color::Green);
//  while (window.isOpen())
//    {
//  	while (window.pollEvent(event))
//	  {
//	    if (event.type == sf::Event::Closed)
//	      window.close();
//	  }
//      window.clear();
//      window.draw(shape);
//      window.display();
//    }
//
//  dlclose(dlhandle1);
//  dlclose(dlhandle2);
//  dlclose(dlhandle3);
//}

int 							main(int argc, char **argv)
{
  arcade::DLLoader<arcade::library::IArcadeLibrary*>	loader;
  arcade::library::IArcadeLibrary			*lib;

  if (argc != 2)
    {
      std::cerr << "Usage : " << std::endl
       		<< "\t" << argv[0] << "./lib/lib_arcade_XXX.so" << std::endl;
      return (1);
    }
  if (!(lib = loader.getInstance(argv[1])))
    return (1);
  lib->openWindow();
  while (!lib->isEventQuit() &&
	 !lib->isKeyPressed(arcade::Input(arcade::InputState::KEY_PRESSED, arcade::InputKey::ESCAPE)))
    {
    }
  lib->closeWindow();
  delete (lib);
  loader.closeHandler();
  return (0);
}

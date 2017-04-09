//
// sfml.cpp for SFML in /mnt/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/villen_l/rendu/C++/cpp_arcade
// 
// Made by Lucas Villeneuve
// Login   <lucas.villeneuve@epitech.eu>
// 
// Started on  Sat Mar 11 15:25:44 2017 Lucas Villeneuve
// Last update Sun Mar 12 15:21:16 2017 Lucas Villeneuve
//

#include <stdexcept>
#include "Menu.hh"

int		main(int argc, char **argv)
{
  arcade::Menu	*menu;

  if (argc != 2)
    {
      std::cerr << "Usage : " << std::endl
       		<< "\t" << argv[0] << "./lib/lib_arcade_XXX.so" << std::endl;
      return (1);
    }
  try
    {
      menu = new arcade::Menu(argv[1]);
      menu->loopMenu();
      delete (menu);
    }
  catch (const std::exception &e) {}
  return (0);
}
/*
** Menu.hh for cpp_arcade in /home/villen_l/rendu/cpp_arcade/Menu.hh
**
** Made by Lucas Villeneuve
** Login   <lucas.villeneuve@epitech.eu>
**
** Started on  Mon Mar 13 16:06:27 2017 Lucas Villeneuve
** Last update Mon Mar 13 16:06:27 2017 Lucas Villeneuve
*/

#ifndef MENU_HH_
# define MENU_HH_

# include "Arcade.hpp"
# include "IArcadeLibrary.hh"
# include "DLLoader.hpp"
# include "Map.hh"

namespace						arcade
{
  enum class						MenuIndexLib
  {
    INCREMENT						= 0,
    DECREMENT						= 1
  };

  class 						Menu
  {
    arcade::LibraryList					libList;
    arcade::DLLoader<arcade::library::IArcadeLibrary*>	loader;
    arcade::library::IArcadeLibrary			*lib;

    void 						incrementLibListIndex();
    void 						decrementLibListIndex();

   public:
    Menu(const char *nameLib);
    ~Menu();

    const char 						*getLibName() const;
    void 						setLib(const char *nameLib);
    void 						closeLib();
    void 						switchLib(const MenuIndexLib&);
    void 						loopMenu();
    void 						drawMap(const arcade::Map &map);
    void 						launchGame(std::string);
  };

};

#endif // !MENU_HH_

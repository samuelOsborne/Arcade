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

# include <vector>
# include "Arcade.hpp"
# include "LibraryList.hh"
# include "IArcadeLibrary.hh"
# include "DLLoader.hpp"
# include "IMap.hh"
# include "IGame.hh"

namespace						arcade
{
  class 						Menu
  {
    arcade::LibraryList					libList;
    arcade::LibraryList					gamesList;
    arcade::DLLoader<arcade::library::IArcadeLibrary*>	libLoader;
    arcade::DLLoader<arcade::games::IGame*>		gameLoader;
    arcade::library::IArcadeLibrary			*lib;
    arcade::games::IGame				*game;
    bool 						gameLaunched;
    arcade::CommandType 				bufferCmd;
    arcade::CommandType 				cmd;
    std::string						playerName;

    void 						update();
    void 						eventHandler();
    void 						drawMap(const arcade::IMap *map);
    void 						drawStrings(const std::vector<arcade::games::IGameObject*> &strings);

    enum						MenuIndexLib
    {
      INCREMENT						= 0,
      DECREMENT						= 1
    };

   public:
    Menu(const char *nameLib);
    Menu(const Menu &other) = delete;
    Menu &operator=(const Menu &other) = delete;
    ~Menu();

    void 						setLib(const char *nameLib);
    void 						closeLib();
    void 						setGame(const char *nameGame);
    void 						closeGame();
    void 						switchLib(const MenuIndexLib&);
    void 						switchGame(const MenuIndexLib&);
    void 						loopMenu();
    void 						drawEnemies(const std::vector<arcade::games::IGameObject*> &);
  };

};

#endif // !MENU_HH_

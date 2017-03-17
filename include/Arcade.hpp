/*
** Arcade.hpp for cpp_arcade in /home/villen_l/rendu/cpp_arcade/Arcade.hh
**
** Made by Lucas Villeneuve
** Login   <lucas.villeneuve@epitech.eu>
**
** Started on  Sun Mar 12 19:00:40 2017 Lucas Villeneuve
** Last update Sun Mar 12 19:00:40 2017 Lucas Villeneuve
*/

#ifndef ARCADE_HPP_
# define ARCADE_HPP_

# include <vector>
# include <string>
# include <cstdint>
# include <dirent.h>

namespace			arcade
{
  enum class 			InputState : uint16_t
  {
    NONE		= 0,
    KEY_PRESSED		= 1,
    KEY_RELEASED	= 2
  };

  enum class			InputKey : uint16_t
  {
    UNKNOWN		= 0,
    ESCAPE		= 1,
    NUM0		= 2,
    NUM1		= 3,
    NUM2		= 4,
    NUM3		= 5,
    NUM4		= 6,
    NUM5		= 7,
    NUM6		= 8,
    NUM7		= 9,
    NUM8		= 10,
    NUM9		= 11,
    LEFT		= 12,
    RIGHT		= 13,
    UP			= 14,
    DOWN		= 15,
    SPACE		= 16,
    ENTER		= 17
  };

  struct 			Input
  {
    InputState			state;
    InputKey 			key;

    Input(const InputState _state = InputState::NONE, const InputKey _key = InputKey::UNKNOWN)
    {
      this->state = _state;
      this->key = _key;
    }
  };

  struct			LibraryList
  {
    std::vector<std::string>	list;
    int 			index;

    LibraryList()
    {
      DIR			*dir;
      struct dirent		*ent;
      std::string		str;
      std::string::size_type 	i;

      if ((dir = opendir("./lib")))
	{
	  while ((ent = readdir(dir)))
	    {
	      str = ent->d_name;
	      i = str.find_last_of(".");
	      if (i != std::string::npos && str.substr(i) == ".so")
		list.push_back("./lib/" + str);
	    }
	  closedir(dir);
	}
    }
  };

  namespace			games
  {
    enum class			ExtTileType : uint16_t
    {
      PLAYER			= 8
    };

  };

};

#endif // !ARCADE_HPP_

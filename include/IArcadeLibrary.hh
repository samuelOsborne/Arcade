/*
** IArcadeLibrary.hh for Arcade in /home/villen_l/rendu/C++/cpp_arcade
** 
** Made by Lucas Villeneuve
** Login   <lucas.villeneuve@epitech.eu>
** 
** Started on  Sat Mar 11 16:45:27 2017 Lucas Villeneuve
** Last update Sat Mar 11 16:45:29 2017 Lucas Villeneuve
*/

#ifndef IARCADELIBRARY_HH_
# define IARCADELIBRARY_HH_

# include <string>
# include "Arcade.hh"

namespace 			arcade
{
  namespace 			library
  {
    class				IArcadeLibrary
    {
     public:
      virtual				~IArcadeLibrary() {}

//  virtual std::string const	&getName() const = 0;
      virtual void 			openWindow() = 0;
      virtual void 			closeWindow() = 0;
      virtual bool 			isKeyPressed(const arcade::Input &input) = 0;
      virtual bool			isEventQuit() = 0;
    };

  };
};

#endif // !IARCADELIBRARY_HH_
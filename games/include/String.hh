/*
** String.hh for cpp_arcade in /home/villen_l/rendu/cpp_arcade/String.hh
**
** Made by Lucas Villeneuve
** Login   <lucas.villeneuve@epitech.eu>
**
** Started on  Fri Apr 07 17:07:43 2017 Lucas Villeneuve
** Last update Fri Apr 07 17:07:43 2017 Lucas Villeneuve
*/

#ifndef STRING_HH_
# define STRING_HH_

# include "AGameObject.hh"

namespace		arcade
{
  class			String : public arcade::AGameObject
  {
   public:
    String(uint16_t x, uint16_t y, const std::string &str);
    String(const arcade::String &other) = delete;
    String &operator=(const arcade::String &other) = delete;
    ~String() {};
  };
};

#endif // !STRING_HH_

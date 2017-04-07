/*
** LibraryList.cpp for cpp_arcade in /home/villen_l/rendu/cpp_arcade/LibraryList.cpp
**
** Made by Lucas Villeneuve
** Login   <lucas.villeneuve@epitech.eu>
**
** Started on  Wed Mar 22 10:35:16 2017 Lucas Villeneuve
** Last update Wed Mar 22 10:35:16 2017 Lucas Villeneuve
*/

#include <cstdint>
#include <dirent.h>
#include "LibraryList.hh"

arcade::LibraryList::LibraryList(const std::string &dirName)
{
  DIR				*dir;
  struct dirent			*ent;
  std::string			str;
  std::string::size_type 	i;

  this->index = 0;
  if ((dir = opendir(dirName.c_str())))
    {
      while ((ent = readdir(dir)))
	{
	  str = ent->d_name;
	  i = str.find_last_of(".");
	  if (i != std::string::npos && str.substr(i) == ".so")
	    list.push_back(dirName + str);
	}
      closedir(dir);
    }
}

const char	*arcade::LibraryList::getName() const
{
  if (this->list.size() > 0)
    return (this->list[this->index].c_str());
  else
    return (NULL);
}

int	arcade::LibraryList::getIndex() const
{
  return (this->index);
}

void	arcade::LibraryList::incrementIndex()
{
  this->index++;
  if (this->index >= static_cast<int>(this->list.size()))
    this->index = 0;
}

void 	arcade::LibraryList::decrementIndex()
{
  this->index--;
  if (this->index <= -1)
    this->index = static_cast<int>(this->list.size() - 1);
}

unsigned long	arcade::LibraryList::getSize() const
{
  return (this->list.size());
}

const std::string	&arcade::LibraryList::operator[](int i)
{
  return (this->list[i]);
}
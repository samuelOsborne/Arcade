/*
** LibraryList.hh for cpp_arcade in /home/villen_l/rendu/cpp_arcade/LibraryList.hh
**
** Made by Lucas Villeneuve
** Login   <lucas.villeneuve@epitech.eu>
**
** Started on  Wed Mar 22 10:30:32 2017 Lucas Villeneuve
** Last update Wed Mar 22 10:30:32 2017 Lucas Villeneuve
*/

#ifndef LIBRARYLIST_HH_
# define LIBRARYLIST_HH_

# include <vector>
# include <string>

namespace			arcade
{
  class				LibraryList
  {
    std::vector<std::string>	list;
    int 			index;

   public:
    LibraryList(const std::string &dirName);
    LibraryList(const LibraryList &other) = delete;
    LibraryList &operator=(const LibraryList &other) = delete;
    ~LibraryList() {};

    const char 			*getName() const;
    unsigned long		getSize() const;
    int 			getIndex() const;
    void 			incrementIndex();
    void 			decrementIndex();
    const std::string		&operator[](int i);
  };

};

#endif // !LIBRARYLIST_HH_

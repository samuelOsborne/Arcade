//
// DLLoader.hh for cpp_arcade in /home/villen_l/rendu/C++/cpp_arcade
// 
// Made by Lucas Villeneuve
// Login   <lucas.villeneuve@epitech.eu>
// 
// Started on  Sun Mar 12 19:05:25 2017 Lucas Villeneuve
// Last update Sun Mar 12 19:05:32 2017 Lucas Villeneuve
//

#ifndef DLLOADER_HH_
# define DLLOADER_HH_

# include <iostream>
# include <dlfcn.h>

namespace 		arcade
{
  template <typename T>
  class			DLLoader
  {
    void			*dlhandle;

   public:
    DLLoader<T>() {};
    ~DLLoader<T>() {};

    T			getInstance(const char *name)
    {
      T	(*func)();

      if (!(this->dlhandle = dlopen(name, RTLD_LAZY)))
	{
	  std::cerr << "Can't open lib : " << dlerror() << std::endl;
	  /*
	   * TODO Throw std::exception
	   */
	  return (NULL);
	}

      if (!(func = reinterpret_cast<T(*)()>(dlsym(this->dlhandle, "entry_point"))))
	{
	  std::cerr << "Can't load symbol" << std::endl;
	  return (NULL);
	}

      return (func());
    }

    void			closeHandler()
    {
      if (this->dlhandle)
	dlclose(this->dlhandle);
    }

  };

};

#endif	// !DLLOADER_HH_

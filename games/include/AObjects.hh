/*
** Objects.hpp for cpp_arcade in /home/osborn_s/Tek_2/cpp_arcade/Objects.h
**
** Made by Samuel Osborne
** Login   <samuel.osborne@epitech.eu>
**
** Started on  Tue Mar 14 13:40:06 2017 Samuel Osborne
** Last update Tue Mar 14 13:40:06 2017 Samuel Osborne
*/

#ifndef AOBJECTS_HPP_
# define AOBJECTS_HPP_

# include "AGameObject.hh"
# include "Protocol.hpp"

namespace 			arcade
{
  class 			AObjects : public arcade::AGameObject
  {
   protected:
    bool 			taken;
    std::string			secondAsset;

    void 			switchAsset();

   public:
    AObjects(const uint16_t, const uint16_t);
    AObjects(const AObjects&);
    AObjects &operator=(const AObjects&);
    virtual ~AObjects() {};


    virtual arcade::Position 	getPos() const;
    bool 			getTaken() const;
    std::string			getSecondAsset() const;
    virtual void 		setPos(const arcade::Position &pos);
    void 			setSecondAsset(const std::string &asset);
    void			take();
  };

};

#endif // !AOBJECTS_HPP_

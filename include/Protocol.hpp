// Kind of Advanced Language Assistant Laboratory 2006-2042
// Epitech 1999-2042
// Jason Brillante brilla_a brilla_b
// Have you played Atari today?
//
// WELCOME TO THE ARCADE
// ENJOY OR DIE

#ifndef			__ARCADE_PROTOCOL_HPP__
# define		__ARCADE_PROTOCOL_HPP__

# include		<stdint.h>

namespace		arcade
{
  enum class		CommandType : uint16_t
  {
      WHERE_AM_I	= 0,
      GET_MAP		= 1,
      GO_UP		= 2,
      GO_DOWN		= 3,
      GO_LEFT		= 4,
      GO_RIGHT		= 5,
      GO_FORWARD	= 6,
      SHOOT		= 7,
      ILLEGAL		= 8,
      PLAY		= 9,
      
      EXIT		= 10,
      PREV_LIB		= 11,
      NEXT_LIB		= 12,
      PREV_GAME		= 13,
      NEXT_GAME		= 14,
      LAUNCH		= 15,
      RESET		= 16,
      MENU		= 17
   };
  
  enum class		TileType : uint16_t
    {
      EMPTY		= 0,
      BLOCK		= 1,
      OBSTACLE		= 2,
      EVIL_DUDE		= 3,
      EVIL_SHOOT	= 4,
      MY_SHOOT		= 5,
      POWERUP		= 6,
      OTHER		= 7
    };
  

  struct		GetMap
  {
    CommandType		type;
    uint16_t		width;
    uint16_t		height;
    TileType		tile[0];
  } __attribute__((packed));
  

  struct		Position
  {
    uint16_t		x;
    uint16_t		y;
  } __attribute__((packed));
  
  struct		WhereAmI
  {
    CommandType		type;
    uint16_t		lenght;
    Position		position[0];
  } __attribute__((packed));

}

#endif	//		__ARCADE_PROTOCOL_HPP__

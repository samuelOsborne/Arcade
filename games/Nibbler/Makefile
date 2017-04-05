##
## Makefile for arcade in /mnt/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/villen_l/rendu/C++/cpp_arcade/games
## 
## Made by Lucas Villeneuve
## Login   <lucas.villeneuve@epitech.eu>
## 
## Started on  Mon Mar 20 13:49:12 2017 Lucas Villeneuve
## Last update Tue Apr  4 10:24:06 2017 Samuel Osborne
##

NAME		=	../lib_arcade_nibbler.so

SRCPATH		=	./src
INCPATH		=	./include
GMEPATH		=	../src

SRCS		=	$(SRCPATH)/Nibbler.cpp			\
			$(SRCPATH)/NibblerWall.cpp		\
			$(SRCPATH)/NibblerFloor.cpp		\
			$(SRCPATH)/NibblerFruit.cpp		\
			$(SRCPATH)/NibblerBody.cpp		\
			$(GMEPATH)/Map.cpp			\
			$(GMEPATH)/Player.cpp			\
			$(GMEPATH)/Enemy.cpp			\
			$(GMEPATH)/AGameObject.cpp		\
			$(GMEPATH)/ACharacter.cpp		\
			$(GMEPATH)/AObjects.cpp			\
			$(GMEPATH)/Powerup.cpp			\
			$(GMEPATH)/Pickup.cpp			\
			$(GMEPATH)/ABlock.cpp			\
			$(GMEPATH)/Wall.cpp			\
			$(GMEPATH)/Floor.cpp			\
			$(GMEPATH)/AGame.cpp			

OBJS		=	$(SRCS:.cpp=.o)

CXX		=	g++

RM		=	rm -f


CXXFLAGS	=	-W -Wextra -Wall
CXXFLAGS	+=	-std=c++11 -fPIC
CXXFLAGS	+=	-I$(INCPATH) -I../../include -I../include

RED		=	\033[0;31m
GREEN		=	\033[0;32m
YELLOW		=	\033[0;33m
BLUE		=	\033[0;34m
NO_COLOR	=	\033[m

$(NAME):	obj_echo $(OBJS)
		@$(call compile,  $(CXX) -shared $(OBJS) -o $(NAME) $(LDFLAGS))

all:		$(NAME)

%.o:		%.cpp
		@$(call compile,  $(CXX) -c $(CXXFLAGS) -o $@ $<)

obj_echo:
		@echo "\n $(BLUE)Nibbler$(NO_COLOR)"

clean:
		$(RM) $(OBJS)

fclean: 	clean
		$(RM) $(NAME)

re: 		fclean all


define	compile

echo -n "$(1) : ";						\
$(1) 2> $@.log || touch $@.errors;				\
if test -e $@.errors;						\
then echo "[$(RED)KO$(NO_COLOR)]" && cat $@.log; 		\
elif test -s $@.log;						\
then echo "[$(YELLOW)WARNINGS$(NO_COLOR)]" && cat $@.log; 	\
else echo "[$(GREEN)OK$(NO_COLOR)]"; fi;			\
$(RM) $@.log $@.errors

endef

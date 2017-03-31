##
## Makefile for Makefile in /mnt/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/villen_l/rendu/C++/cpp_arcade
## 
## Made by Lucas Villeneuve
## Login   <lucas.villeneuve@epitech.eu>
## 
## Started on  Sun Mar 12 13:53:13 2017 Lucas Villeneuve
## Last update Fri Mar 24 22:21:41 2017 Lucas Villeneuve
##

NAME		=	arcade

SRCPATH		=	./src
GMEPATH		=	./games
PCMPATH		=	./games/Pacman/src
INCPATH		=	./include
INCGMEPATH	=	./games/include
PACMANINC	=	./games/Pacman/include

SRCS		=	$(SRCPATH)/main.cpp			\
			$(SRCPATH)/Menu.cpp			\
			$(SRCPATH)/LibraryList.cpp
#			$(SRCPATH)/Map.cpp
#			$(SRCPATH)/Player.cpp			\
#			$(SRCPATH)/Enemy.cpp			\
#			$(SRCPATH)/AGameObject.cpp		\
#			$(SRCPATH)/ACharacter.cpp		\
#			$(SRCPATH)/AObjects.cpp			\
#			$(SRCPATH)/Powerup.cpp			\
#			$(SRCPATH)/ABlock.cpp			\
#			$(SRCPATH)/Wall.cpp			\
#			$(SRCPATH)/Floor.cpp			\
#			$(GMEPATH)/AGame.cpp
#			$(PCMPATH)/Ghost.cpp			\
#			$(PCMPATH)/Pacman.cpp

OBJS		=	$(SRCS:.cpp=.o)

CXX		=	g++ -g

RM		=	rm -f

CAT		=	cat

BANNER		=	./misc/banner.txt


LIBPATH		=	./lib

CXXFLAGS	=	-W -Wextra -Wall -std=c++11
CXXFLAGS	+=	-I$(INCPATH) -I$(INCGMEPATH) -I$(PACMANINC)

LDFLAGS		=	-ldl


RED		=	\033[0;31m
GREEN		=	\033[0;32m
YELLOW		=	\033[0;33m
BLUE		=	\033[0;34m
NO_COLOR	=	\033[m


$(NAME):	banner obj_echo $(OBJS)
		@echo "\n$(GREEN)Compiling binary : $(NO_COLOR)"
		@$(call compile , $(CXX) $(OBJS) -o $(NAME) $(LDFLAGS))

libraries:
		@echo "\n$(GREEN)Compiling libraries :$(NO_COLOR)"
		@$(MAKE) --no-print-directory -C $(LIBPATH)

all:		$(NAME) libraries

banner:
		@echo "$(BLUE)"
		@cat $(BANNER)
		@echo "$(NO_COLOR)"

%.o:		%.cpp
		@$(call compile, $(CXX) -c $(CXXFLAGS) -o $@ $<)

obj_echo:
		@echo "\n$(GREEN)Compiling object files : $(NO_COLOR)"

clean:
		@echo "$(YELLOW)Cleaning :$(NO_COLOR)"
		$(RM) $(OBJS)
		@$(MAKE) --no-print-directory -C $(LIBPATH) clean

fclean:		clean
		$(RM) $(NAME)
		@$(MAKE) --no-print-directory -C $(LIBPATH) fclean

re:		fclean all


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

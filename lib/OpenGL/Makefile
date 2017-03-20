##
## Makefile for Arcade Library in /mnt/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/villen_l/rendu/C++/cpp_arcade
## 
## Made by Lucas Villeneuve
## Login   <lucas.villeneuve@epitech.eu>
## 
## Started on  Sat Mar 11 17:28:24 2017 Lucas Villeneuve
## Last update Mon Mar 20 10:26:40 2017 escorn_t
##

NAME		=	../lib_arcade_opengl.so

SRCS		=	$(SRCPATH)/LibOpenGL.cpp

OBJS		=	$(SRCS:.cpp=.o)

CXX		=	g++

RM		=	rm -f

SRCPATH		=	./src
INCPATH		=	./include

CXXFLAGS	=	-W -Wextra -Wall
CXXFLAGS	+=	-std=c++11 -fPIC
CXXFLAGS	+=	-I$(INCPATH) -I../../include

LDFLAGS		+=	-ldl -lGL -lGLU -lglfw3 -lGLEW -lX11 -lXxf86vm -lXrandr -lpthread -lXi -lXcursor -lXinerama

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
		@echo "\n $(BLUE)OPENGL$(NO_COLOR)"

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

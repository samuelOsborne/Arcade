##
## Makefile for Makefile in /mnt/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/villen_l/rendu/C++/cpp_arcade
## 
## Made by Lucas Villeneuve
## Login   <lucas.villeneuve@epitech.eu>
## 
## Started on  Sun Apr  2 12:57:42 2017 Lucas Villeneuve
## Last update Sun Apr  2 12:58:46 2017 Lucas Villeneuve
##

NIBBLERPATH	=	./Nibbler

PACMANPATH	=	./Pacman

all:
		@$(MAKE) --no-print-directory -C $(NIBBLERPATH)
		@$(MAKE) --no-print-directory -C $(PACMANPATH)

clean:
		@$(MAKE) --no-print-directory -C $(NIBBLERPATH) clean
		@$(MAKE) --no-print-directory -C $(PACMANPATH) clean

fclean:		clean
		@$(MAKE) --no-print-directory -C $(NIBBLERPATH) fclean
		@$(MAKE) --no-print-directory -C $(PACMANPATH) fclean

re:		fclean all

##
## Makefile for Makefile in /mnt/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/villen_l/rendu/C++/cpp_arcade/lib
## 
## Made by Lucas Villeneuve
## Login   <lucas.villeneuve@epitech.eu>
## 
## Started on  Sun Mar 12 13:41:51 2017 Lucas Villeneuve
## Last update Sat Apr  8 19:13:07 2017 Lucas Villeneuve
##

SFMLPATH	=	./SFML

CACAPATH	=	./caca

NCURSEPATH	=	./Ncurses

LAPINPATH	=	./Lapin

all:
		@$(MAKE) --no-print-directory -C $(SFMLPATH)
		@$(MAKE) --no-print-directory -C $(CACAPATH)
		@$(MAKE) --no-print-directory -C $(LAPINPATH)
		@$(MAKE) --no-print-directory -C $(NCURSEPATH)

clean:
		@$(MAKE) --no-print-directory -C $(SFMLPATH) clean
		@$(MAKE) --no-print-directory -C $(CACAPATH) clean
		@$(MAKE) --no-print-directory -C $(LAPINPATH) clean
		@$(MAKE) --no-print-directory -C $(NCURSEPATH) clean

fclean:		clean
		@$(MAKE) --no-print-directory -C $(SFMLPATH) fclean
		@$(MAKE) --no-print-directory -C $(CACAPATH) fclean
		@$(MAKE) --no-print-directory -C $(LAPINPATH) fclean
		@$(MAKE) --no-print-directory -C $(NCURSEPATH) fclean

re:		fclean all

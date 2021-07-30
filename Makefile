##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## .
##

SRC	=	bases.c		\
		bases2.c	\
		lib/my_putstr.c	\
		lib/my_putchar.c	\

NAME	=	my_hunter	\

all:
	gcc -o $(NAME) $(SRC) -lcsfml-graphics

clean:
	rm -f *~
	rm -f \#*\#

fclean: clean
	rm -f $(NAME)

re: fclean all

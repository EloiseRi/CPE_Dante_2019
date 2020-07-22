##
## EPITECH PROJECT, 2019
## makefile
## File description:
## Makefile
##

all:
		$(MAKE) -C solver
		$(MAKE) -C generator

clean:
		make -C solver/ clean
		make -C generator/ clean

fclean:
		make -C solver fclean
		make -C generator fclean

re:		fclean all
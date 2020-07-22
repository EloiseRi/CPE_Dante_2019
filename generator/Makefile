##
## EPITECH PROJECT, 2019
## makefile
## File description:
## Makefile
##

NAME	= 	generator

SRC	=	main.c				\

OBJ	=	$(SRC:.c=.o)

CFLAGS	+=	-I./include/

LDFLAGS +=	-Wall -Wextra -g3

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ)

clean:
	rm -f $(NAME)
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all

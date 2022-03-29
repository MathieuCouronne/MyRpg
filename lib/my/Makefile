##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile that compile the mylib library
##

SRC	= $(wildcard *.c)

NAME	= libmy.a

OBJ	= $(SRC:.c=.o)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	mkdir -p ../../include
	cp my.h ../../include
	cp $(NAME) ../

all:	$(NAME)

clean:
	rm -rf $(OBJ)

fclean:	clean
	rm $(NAME)

re:	fclean all

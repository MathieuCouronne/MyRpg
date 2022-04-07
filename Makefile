##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile that build the project
##

NAME		= my_rpg

CFLAGS		= -Wall -Wextra -I include

LDFLAGS		= 	-l csfml-window -l csfml-graphics -l csfml-system \
				-l csfml-audio

SRC_DIR 	= src/

SRC			=	$(SRC_DIR)my_rpg.c

SRC			+=	$(SRC_DIR)events/handling.c \
				$(SRC_DIR)events/keys/arrows.c \
				$(SRC_DIR)events/mouse/wheel.c

SRC			+=	$(SRC_DIR)init/game.c \
				$(SRC_DIR)init/menu.c

SRC			+=	$(SRC_DIR)destroy/game.c \
				$(SRC_DIR)destroy/menu.c

OBJ			= $(SRC:.c=.o)

RM 			= rm -rf

$(NAME): build_libs $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LDFLAGS)

all:		$(NAME)

build_libs:
	make -C lib/my
	make -C lib/my_printf

clean:
	$(RM) $(OBJ)

fclean:		clean
	$(RM) $(NAME)

debug: CFLAGS += -g
debug: re

re:	fclean all

##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile that build the project
##

NAME		= my_rpg

CFLAGS		= -Wall -Wextra -I include

LDFLAGS		= 	-l csfml-window -l csfml-graphics -l csfml-system \
				-l csfml-audio -l csfml-network -L lib -l my -L lib -l my_printf

SRC_DIR 	= src/

SRC			=	$(SRC_DIR)my_rpg.c

SRC			+=	$(SRC_DIR)player/move_down.c \
				$(SRC_DIR)player/move_left.c \
				$(SRC_DIR)player/move_right.c \
				$(SRC_DIR)player/move_up.c \
				$(SRC_DIR)player/clock.c

SRC			+=	$(SRC_DIR)events/handling.c \
				$(SRC_DIR)events/keys/arrows.c \
				$(SRC_DIR)events/mouse/wheel.c \
				$(SRC_DIR)events/mouse/menu_button.c

SRC			+=	$(SRC_DIR)init/game.c \
				$(SRC_DIR)init/menu.c \
				$(SRC_DIR)init/sound.c \
				$(SRC_DIR)init/init_menu_button.c \
				$(SRC_DIR)init/map_game.c \
				$(SRC_DIR)init/player.c \
				$(SRC_DIR)init/fight/fight.c \
				$(SRC_DIR)init/fight/ogre.c \
				$(SRC_DIR)init/fight/hp_bar.c \
				$(SRC_DIR)init/fight/text.c \
				$(SRC_DIR)init/chest.c \
				$(SRC_DIR)init/assets.c \
				$(SRC_DIR)init/config/read_file.c \
				$(SRC_DIR)init/config/parse_config.c \
				$(SRC_DIR)init/config/write_file.c \

SRC			+=	$(SRC_DIR)destroy/game.c \
				$(SRC_DIR)destroy/menu.c \
				$(SRC_DIR)destroy/button.c \
				$(SRC_DIR)destroy/music.c \
				$(SRC_DIR)destroy/map.c \
				$(SRC_DIR)destroy/player.c \
				$(SRC_DIR)destroy/destroy_all.c \
				$(SRC_DIR)destroy/fight.c \
				$(SRC_DIR)destroy/enemy.c

SRC			+=	$(SRC_DIR)menu/create_button.c \
				$(SRC_DIR)menu/title.c

SRC			+=	$(SRC_DIR)scenes/manager.c \
				$(SRC_DIR)scenes/menus/main.c \
				$(SRC_DIR)scenes/game/main_game.c \
				$(SRC_DIR)scenes/fight/main_fight.c


SRC			+=	$(SRC_DIR)inventory/create_inventory.c \
				$(SRC_DIR)inventory/add_to_inventory.c \
				$(SRC_DIR)inventory/remove_from_inventory.c \
				$(SRC_DIR)inventory/swap_slots.c \

SRC			+=	$(SRC_DIR)character/create_character.c \

SRC			+=	$(SRC_DIR)map/get_pixel_at_pos.c \

SRC			+=	$(SRC_DIR)utils/color_cmp.c \

OBJ			= $(SRC:.c=.o)

RM 			= rm -rf

$(NAME): $(OBJ)
	make -C lib/my
	make -C lib/my_printf
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LDFLAGS)

all:		$(NAME)

clean:
	$(RM) $(OBJ)

fclean:		clean
	$(RM) $(NAME)

debug: CFLAGS += -g
debug: re

re:	fclean all

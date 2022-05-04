##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile that build the project
##

NAME		= my_rpg

CFLAGS		= -Wall -Wextra -I include

LDFLAGS		= 	-l csfml-window -l csfml-graphics -l csfml-system \
				-l csfml-audio -l csfml-network -L lib -l my \
				-L lib -l my_printf -l m

SRC_DIR 	= 	src/

SRC			=	$(SRC_DIR)my_rpg.c \
				$(SRC_DIR)constants.c

SRC			+=	$(SRC_DIR)events/handling.c \
				$(SRC_DIR)events/keys/arrows.c \
				$(SRC_DIR)events/mouse/move.c \
				$(SRC_DIR)events/mouse/click.c \

SRC			+=	$(SRC_DIR)init/game/game.c \
				$(SRC_DIR)init/game/thread.c \
				$(SRC_DIR)init/sound.c \
				$(SRC_DIR)init/player.c \
				$(SRC_DIR)init/albert.c \
				$(SRC_DIR)init/chest.c \
				$(SRC_DIR)init/assets.c \
				$(SRC_DIR)init/create_icons.c \
				$(SRC_DIR)init/config.c \
				$(SRC_DIR)init/chief.c \

SRC			+=	$(SRC_DIR)init/scenes/menu/menu.c \
				$(SRC_DIR)init/scenes/menu/create_button.c \
				$(SRC_DIR)init/scenes/menu/title.c \
				$(SRC_DIR)init/scenes/menu/init_buttons.c \
				$(SRC_DIR)init/scenes/fight/fight.c \
				$(SRC_DIR)init/scenes/fight/ogre.c \
				$(SRC_DIR)init/scenes/fight/player_bar.c \
				$(SRC_DIR)init/scenes/fight/enemy_bar.c \
				$(SRC_DIR)init/scenes/fight/text.c \
				$(SRC_DIR)init/scenes/fight/init_buttons.c \
				$(SRC_DIR)init/scenes/pause.c \
				$(SRC_DIR)init/scenes/inventory.c \
				$(SRC_DIR)init/scenes/game.c \
				$(SRC_DIR)init/scenes/settings.c \
				$(SRC_DIR)init/scenes/saves/saves.c \
				$(SRC_DIR)init/scenes/saves/init_buttons.c \
				$(SRC_DIR)init/scenes/saves/init_sprite_saves.c \
				$(SRC_DIR)init/scenes/creation_player/menu_creation.c \
				$(SRC_DIR)init/scenes/creation_player/buttons_creation.c \
				$(SRC_DIR)init/scenes/creation_player/create_text_stat.c \
				$(SRC_DIR)init/clock.c \
				$(SRC_DIR)init/load_assets.c

SRC			+=	$(SRC_DIR)destroy/game.c \
				$(SRC_DIR)destroy/menu.c \
				$(SRC_DIR)destroy/button.c \
				$(SRC_DIR)destroy/music.c \
				$(SRC_DIR)destroy/map.c \
				$(SRC_DIR)destroy/player.c \
				$(SRC_DIR)destroy/destroy_all.c \
				$(SRC_DIR)destroy/fight.c \
				$(SRC_DIR)destroy/chest.c \
				$(SRC_DIR)destroy/inventory.c \
				$(SRC_DIR)destroy/albert.c \
				$(SRC_DIR)destroy/chief.c \
				$(SRC_DIR)destroy/settings.c

SRC			+=	$(SRC_DIR)scenes/manager.c \
				$(SRC_DIR)scenes/menus/main.c \
				$(SRC_DIR)scenes/game/game.c \
				$(SRC_DIR)scenes/game/pause.c \
				$(SRC_DIR)scenes/game/inventory.c \
				$(SRC_DIR)scenes/fight/main_fight.c \
				$(SRC_DIR)scenes/settings/main_settings.c \
				$(SRC_DIR)scenes/creation/creation.c \

SRC			+=	$(SRC_DIR)controllers/navigation/global.c \
				$(SRC_DIR)controllers/navigation/menu.c \
				$(SRC_DIR)controllers/navigation/saves.c \
				$(SRC_DIR)controllers/navigation/pause.c \

SRC			+=	$(SRC_DIR)controllers/camera/move_left.c \
				$(SRC_DIR)controllers/camera/move_right.c \
				$(SRC_DIR)controllers/camera/move_top.c \
				$(SRC_DIR)controllers/camera/move_bottom.c \

SRC			+=	$(SRC_DIR)controllers/setup_stats/up_stat.c \
				$(SRC_DIR)controllers/setup_stats/down_stat.c \

SRC			+=	$(SRC_DIR)controllers/inventory/create_inventory.c \
				$(SRC_DIR)controllers/inventory/add_to_inventory.c \
				$(SRC_DIR)controllers/inventory/remove_from_inventory.c \
				$(SRC_DIR)controllers/inventory/swap_slots.c \

SRC			+=	$(SRC_DIR)controllers/parsing/character/read.c \
				$(SRC_DIR)controllers/parsing/character/get_data.c \
				$(SRC_DIR)controllers/parsing/character/get_inventory.c \
				$(SRC_DIR)controllers/parsing/character/get_stats.c \
				$(SRC_DIR)controllers/parsing/config/read.c \
				$(SRC_DIR)controllers/parsing/config/get_options.c \

SRC			+=	$(SRC_DIR)controllers/storage/config/write.c \
				$(SRC_DIR)controllers/storage/config/save_infos.c \
				$(SRC_DIR)controllers/storage/config/save_keys.c \

SRC			+=	$(SRC_DIR)scenes/saves/scene_saves.c

SRC			+=	$(SRC_DIR)character/create_character.c \
				$(SRC_DIR)character/experience/add_experience.c \

SRC			+=	$(SRC_DIR)utils/color_cmp.c \
				$(SRC_DIR)utils/map/get_pixel_at_pos.c \
				$(SRC_DIR)utils/array/get_2d_array_length.c \
				$(SRC_DIR)utils/array/itoa.c \
				$(SRC_DIR)utils/string/clear_str.c \
				$(SRC_DIR)utils/is_pos_in_button.c \

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

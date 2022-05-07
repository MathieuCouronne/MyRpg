/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** my_rpg main file
*/

#include "my_rpg.h"
#include "inventory.h"
#include "macros.h"

static const char *SAVE_FILENAMES[] = {
    PLAYER1_FILE_PATH, PLAYER2_FILE_PATH, PLAYER3_FILE_PATH
};

static void save_data(game_t *game)
{
    write_config(game->config);
    for (unsigned int i = 0; i < 3; i++) {
        if (game->saves[i])
            write_character(game->saves[i], SAVE_FILENAMES[i]);
    }
}

int main(void)
{
    game_t *game = init_game();

    if (!game)
        return 84;
    while (sfRenderWindow_isOpen(game->window)) {
        sfRenderWindow_clear(game->window, sfBlack);
        scene_manager(game);
        sfRenderWindow_display(game->window);
    }
    save_data(game);
    destroy_all(game);
}

/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** my_rpg main file
*/

#include "my_rpg.h"
#include "inventory.h"

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
    destroy_all(game);
}

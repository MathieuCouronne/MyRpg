/*
** EPITECH PROJECT, 2021
** game.c
** File description:
** Game destroyer
*/

#include <stdlib.h>
#include "my_rpg.h"

void destroy_game_lava(sfCircleShape **lava)
{
    if (!lava)
        return;
    for (unsigned int i = 0; lava[i]; i++) {
        if (lava[i])
            sfCircleShape_destroy(lava[i]);
    }
}

// TODO: destroy game scenes
void destroy_game(game_t *game)
{
    if (!game)
        return;
    sfRenderWindow_destroy(game->window);
    free(game);
}

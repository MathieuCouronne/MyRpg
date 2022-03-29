/*
** EPITECH PROJECT, 2021
** game.c
** File description:
** Game destroyer
*/

#include <stdlib.h>
#include "my_rpg.h"

// TODO: destroy game scenes
void destroy_game(game_t *game)
{
    sfRenderWindow_destroy(game->window);
    free(game);
}

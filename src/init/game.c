/*
** EPITECH PROJECT, 2021
** game.c
** File description:
** Game initializer
*/

#include <stdlib.h>
#include "my_rpg.h"

static sfRenderWindow *init_window(void)
{
    sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow *window = sfRenderWindow_create(mode, "MyRPG",
    sfFullscreen, NULL);

    if (!window)
        return NULL;
    sfRenderWindow_setFramerateLimit(window, 60);
    return window;
}

game_t *init_game(void)
{
    game_t *game = malloc(sizeof(game_t));

    game->window = init_window();
    if (!game->window)
        return NULL;
    return game;
}

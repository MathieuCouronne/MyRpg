/*
** EPITECH PROJECT, 2021
** game.c
** File description:
** Game initializer
*/

#include <stdlib.h>
#include "my_rpg.h"
#include "scenes.h"

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

scenes_t *init_scenes(void)
{
    scenes_t *scenes = malloc(sizeof(scenes_t));

    scenes->main_menu = init_main_menu();
    return scenes;
}

game_t *init_game(void)
{
    game_t *game = malloc(sizeof(game_t));

    game->window = init_window();
    game->scenes = init_scenes();
    if (!game->window || !game->scenes)
        return NULL;
    return game;
}

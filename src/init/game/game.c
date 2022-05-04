/*
** EPITECH PROJECT, 2021
** game.c
** File description:
** Game initializer
*/

#include <SFML/System.h>
#include <stdlib.h>
#include "my_rpg.h"
#include "macros.h"

static sfRenderWindow *init_window(void)
{
    sfVideoMode mode = {WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_BITS};
    sfRenderWindow *window = sfRenderWindow_create(mode, WINDOW_NAME,
    sfDefaultStyle, NULL);

    if (!window)
        return NULL;
    sfRenderWindow_setFramerateLimit(window, 60);
    return window;
}

// TODO: destroy / free window
static void open_loader_window(int *total)
{
    loader_t *loader = init_loader_window(total);
    sfColor background = sfColor_fromRGB(125, 125, 125);

    while (sfRenderWindow_isOpen(loader->window)) {
        if (*total == -1)
            sfRenderWindow_close(loader->window);
        sfRenderWindow_clear(loader->window, background);
        display_loader(loader, *total);
        sfRenderWindow_display(loader->window);
    }
}

game_t *init_game(void)
{
    thread_params_t *params = malloc(sizeof(thread_params_t));
    game_t *game = malloc(sizeof(game_t));
    sfThread *thread = NULL;

    params->game = game;
    params->loaded = malloc(sizeof(int));
    *(params->loaded) = 0;
    thread = sfThread_create((void *) load_game, params);
    sfThread_launch(thread);
    open_loader_window(params->loaded);
    sfThread_wait(thread);
    load_game(params);
    if (!game->scenes || !game->config || !game->player || !game->saves ||
    !game->view || !game->collisions)
        return NULL;
    game->window = init_window();
    if (!game->window)
        return NULL;
    return game;
}

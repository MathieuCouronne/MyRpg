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

static void open_loader_window(const int *total)
{
    loader_t *loader = init_loader_window();
    sfColor background = sfColor_fromRGB(125, 125, 125);

    if (!loader->window)
        return;
    while (sfRenderWindow_isOpen(loader->window)) {
        sfRenderWindow_clear(loader->window, background);
        display_loader(loader, *total);
        sfRenderWindow_display(loader->window);
        if (*total == -1) {
            sfSleep(sfMilliseconds(500));
            sfRenderWindow_close(loader->window);
        }
    }
    sfRenderWindow_destroy(loader->window);
    free(loader);
}

static bool are_params_invalid(game_t *game)
{
    return (
        !game->view || !game->sounds || !game->collisions || !game->saves ||
        !game->characters || !game->stats || !game->player || !game->quests ||
        !check_all_characters(game->saves)
    );
}

game_t *init_game(void)
{
    thread_params_t *params = malloc(sizeof(thread_params_t));
    game_t *game = malloc(sizeof(game_t));
    sfThread *thread = NULL;

    params->game = game;
    params->loaded = malloc(sizeof(int));
    thread = sfThread_create((void *) load_game, params);
    if (!thread)
        return NULL;
    sfThread_launch(thread);
    open_loader_window(params->loaded);
    sfThread_wait(thread);
    sfThread_destroy(thread);
    if (are_params_invalid(game))
        return NULL;
    game->window = init_window();
    if (!game->window)
        return NULL;
    return game;
}

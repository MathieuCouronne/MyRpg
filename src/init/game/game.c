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

static void open_loader_window(int *total)
{
    sfVideoMode mode = {500, 500, 32};
    sfRenderWindow *window = sfRenderWindow_create(mode, NULL, sfNone, NULL);
    sfEvent event = {};
    sfVideoMode default_mode = sfVideoMode_getDesktopMode();
    sfVector2i pos = {default_mode.width / 2 - mode.width / 2, default_mode.height / 2 - mode.height / 2};
    sfCircleShape *circle = sfCircleShape_create();
    sfCircleShape_setFillColor(circle, sfRed);
    sfCircleShape_setPosition(circle, (sfVector2f) {50, 50});
    sfCircleShape_setRadius(circle, 0);
    sfRenderWindow_setPosition(window, pos);
    sfRenderWindow_setFramerateLimit(window, 60);

    while (sfRenderWindow_isOpen(window)) {
        if (*total == -1)
            sfRenderWindow_close(window);
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
        }
        sfCircleShape_setRadius(circle, *total);
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawCircleShape(window, circle, NULL);
        sfRenderWindow_display(window);
    }
}

game_t *init_game(void)
{
    thread_params_t *params = malloc(sizeof(thread_params_t));
    game_t *game = malloc(sizeof(game_t));
    sfThread *thread = NULL;

    params->game = game;
    params->loaded = malloc(sizeof(int));
    (*params->loaded) = 0;
    thread = sfThread_create((void *) load_game, params);
    sfThread_launch(thread);
    open_loader_window(params->loaded);
    sfThread_wait(thread);

    if (!game->scenes || !game->config || !game->player || !game->saves ||
        !game->inventory || !game->view || !game->collisions)
        return NULL;
    game->window = init_window();
    if (!game->window)
        return NULL;
    return game;
}

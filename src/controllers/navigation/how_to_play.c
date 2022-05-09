/*
** EPITECH PROJECT, 2021
** global.c
** File description:
** Globals navigation functions
*/

#include "my_rpg.h"

void event_handling(sfRenderWindow *window, sfEvent event)
{
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
    }
}

void window_help(game_t *game)
{
    sfVideoMode mode = {1200, 700, 32};
    sfRenderWindow *window = sfRenderWindow_create(mode, "Help", sfClose, NULL);
    game_asset_t *help = NULL;
    sfEvent event = {0};

    if (!game || !game->help)
        return;
    help = game->help;
    sfRenderWindow_setVisible(game->window, false);
    while (sfRenderWindow_isOpen(window)) {
        event_handling(window, event);
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, help->sprite, NULL);
        sfRenderWindow_display(window);
    }
    sfRenderWindow_destroy(window);
    sfRenderWindow_setVisible(game->window, true);
}

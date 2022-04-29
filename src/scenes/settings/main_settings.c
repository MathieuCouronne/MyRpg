/*
** EPITECH PROJECT, 2021
** handling.c
** File description:
** Game arrow keys events handling
*/

#include <stdbool.h>
#include "my_rpg.h"
#include "structs.h"

static void event_handling(game_t *game)
{
    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
        if (game->event.type == sfEvtClosed)
            sfRenderWindow_close(game->window);
    }
}

bool display_settings(game_t *game)
{
    sfRenderWindow *window = NULL;
    settings_t *settings = NULL;
    button_t **buttons = NULL;

    if (!game || !game->window || !game->scenes || !game->scenes->settings)
        return false;
    event_handling(game);
    window = game->window;
    settings = game->scenes->settings;
    buttons = settings->buttons;
    sfRenderWindow_drawSprite(window, settings->background->sprite, NULL);
    sfRenderWindow_drawSprite(window, buttons[0]->asset->sprite, NULL);
    sfRenderWindow_drawText(window, buttons[0]->text, NULL);
    return true;
}

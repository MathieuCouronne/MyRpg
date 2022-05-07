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
        default_event_handling(game, game->scenes->settings->buttons);
        default_event_handling(game, game->scenes->settings->icons);
    }
}

bool display_settings(game_t *game)
{
    sfRenderWindow *window = NULL;
    settings_t *settings = NULL;
    button_t **buttons = NULL;
    button_t **icons = NULL;

    if (!game || !game->window || !game->scenes || !game->scenes->settings)
        return false;
    event_handling(game);
    window = game->window;
    settings = game->scenes->settings;
    buttons = settings->buttons;
    icons = settings->icons;
    sfRenderWindow_drawSprite(window, settings->background->sprite, NULL);
    sfRenderWindow_drawSprite(window, buttons[0]->asset->sprite, NULL);
    sfRenderWindow_drawText(window, buttons[0]->text, NULL);
    for (size_t i = 0; i < 7; i++)
         sfRenderWindow_drawSprite(window, icons[i]->asset->sprite, NULL);
    for (size_t i = 0; i < 7; i++)
        sfRenderWindow_drawText(window, settings->keys[i], NULL);
    return true;
}

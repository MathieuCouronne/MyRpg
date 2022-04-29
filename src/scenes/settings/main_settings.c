/*
** EPITECH PROJECT, 2021
** handling.c
** File description:
** Game arrow keys events handling
*/

#include <stdbool.h>
#include "my_rpg.h"
#include "structs.h"

bool display_main_settings(game_t *game)
{
    sfRenderWindow *window = NULL;
    settings_t *settings = NULL;
    button_t **buttons = NULL;

    if (!game || !game->window || !game->scenes || !game->scenes->settings ||
        !game->scenes->settings->buttons)
        return false;
    window = game->window;
    settings = game->scenes->settings;
    buttons = settings->buttons;
    sfRenderWindow_drawSprite(window, settings->background->sprite, NULL);
    return true;
}

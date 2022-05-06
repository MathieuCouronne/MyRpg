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
        default_event_handling(game, game->scenes->pause->buttons);
        if (game->event.type == sfEvtKeyPressed
        && game->event.key.code == sfKeyEscape) {
            game->scenes->prev = game->scenes->current;
            game->scenes->current = MAIN_GAME;
        }
    }
}

bool display_pause(game_t *game)
{
    sfRenderWindow *window = NULL;
    pause_t *pause = NULL;
    button_t **buttons = NULL;

    if (!game || !game->window || !game->scenes || !game->scenes->pause ||
        !game->scenes->pause->buttons)
        return false;
    window = game->window;
    pause = game->scenes->pause;
    buttons = pause->buttons;
    event_handling(game);
    sfRenderWindow_drawSprite(window, pause->background->sprite, NULL);
    for (size_t i = 0; i < 4; i++) {
        sfRenderWindow_drawSprite(window, buttons[i]->asset->sprite, NULL);
        sfRenderWindow_drawText(window, buttons[i]->text, NULL);
    }
    return true;
}

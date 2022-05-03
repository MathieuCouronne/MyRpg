/*
** EPITECH PROJECT, 2021
** handling.c
** File description:
** Game arrow keys events handling
*/

#include <stdbool.h>
#include "my_rpg.h"
#include "structs.h"
#include "macros.h"

static void event_handling(game_t *game)
{
    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
        if (game->event.type == sfEvtKeyPressed
        && game->event.key.code == sfKeyEscape) {
            game->scenes->prev = game->scenes->current;
            game->scenes->current = MAIN_GAME;
        }
        if (game->event.type == sfEvtClosed)
            sfRenderWindow_close(game->window);
        if (handle_buttons_clicks(game, game->scenes->main_menu->buttons))
            return;
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
    sfRenderWindow_setView(window, pause->view);
    sfRenderWindow_drawSprite(window, pause->background->sprite, NULL);
    sfRenderWindow_drawSprite(window, buttons[0]->asset->sprite, NULL);
    sfRenderWindow_drawText(window, buttons[0]->text, NULL);
    sfRenderWindow_drawSprite(window, buttons[1]->asset->sprite, NULL);
    sfRenderWindow_drawText(window, buttons[1]->text, NULL);
    sfRenderWindow_drawSprite(window, buttons[2]->asset->sprite, NULL);
    sfRenderWindow_drawText(window, buttons[2]->text, NULL);
    sfRenderWindow_drawSprite(window, buttons[3]->asset->sprite, NULL);
    sfRenderWindow_drawText(window, buttons[3]->text, NULL);
    return true;
}

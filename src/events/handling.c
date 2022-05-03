/*
** EPITECH PROJECT, 2021
** handling.c
** File description:
** Game events handling
*/

#include "my_rpg.h"

void default_event_handling(game_t *game, button_t **buttons)
{
    if (game->event.type == sfEvtClosed)
        sfRenderWindow_close(game->window);
    handle_buttons_hover(game, buttons);
    if (handle_buttons_clicks(game, buttons))
        return;
}

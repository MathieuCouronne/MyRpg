/*
** EPITECH PROJECT, 2021
** handling.c
** File description:
** Game events handling
*/

#include "my_rpg.h"

void handle_buttons_clicks(game_t *game, button_t **buttons)
{
    if (game->event.type != sfEvtMouseButtonPressed)
        return;
    for (unsigned short i = 0; buttons[i]; i++) {
        if (!is_button_clicked(game, buttons[i]))
            continue;
        buttons[i]->on_click(game);
        break;
    }
}

/*
** EPITECH PROJECT, 2021
** handling.c
** File description:
** Game events handling
*/

#include <stdbool.h>
#include "my_rpg.h"

bool handle_buttons_clicks(game_t *game, button_t **buttons)
{
    if (game->event.type != sfEvtMouseButtonPressed)
        return false;
    for (unsigned short i = 0; buttons[i]; i++) {
        if (!is_button_clicked(game, buttons[i]))
            continue;
        buttons[i]->on_click(game);
        return true;
    }
    return false;
}

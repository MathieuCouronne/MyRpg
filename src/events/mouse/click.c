/*
** EPITECH PROJECT, 2021
** click.c
** File description:
** Game buttons click events handling
*/

#include "my_rpg.h"

bool handle_buttons_clicks(game_t *game, button_t **buttons)
{
    sfVector2i pos = {game->event.mouseButton.x, game->event.mouseButton.y};

    if (game->event.type != sfEvtMouseButtonPressed || !buttons)
        return false;
    for (unsigned short i = 0; buttons[i]; i++) {
        if (!is_pos_in_button(buttons[i], pos)) {
            continue;
        }
        sfSound_play(game->sounds->clic);
        buttons[i]->on_click(game);
        return true;
    }
    return false;
}

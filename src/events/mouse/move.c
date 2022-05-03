/*
** EPITECH PROJECT, 2021
** move.c
** File description:
** Mouse move events handling
*/

#include "my_rpg.h"

bool handle_buttons_hover(game_t *game, button_t **buttons)
{
    sfVector2i pos = {game->event.mouseMove.x, game->event.mouseMove.y};
    bool is_inside = false;
    bool status = false;

    if (game->event.type != sfEvtMouseMoved)
        return false;
    for (unsigned short i = 0; buttons[i]; i++) {
        is_inside = is_pos_in_button(buttons[i], pos);
        if (is_inside && !buttons[i]->hover) {
            buttons[i]->hover = true;
            sfColor shadow = sfColor_fromRGBA(200, 200, 200, 255);
            sfSprite_setColor(buttons[i]->asset->sprite, shadow);
            status = true;
        } else if (!is_inside && buttons[i]->hover) {
            buttons[i]->hover = false;
            sfSprite_setColor(buttons[i]->asset->sprite, sfWhite);
        }
    }
    return status;
}

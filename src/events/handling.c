/*
** EPITECH PROJECT, 2021
** handling.c
** File description:
** Game events handling
*/

#include <stdbool.h>
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

bool handle_buttons_clicks(game_t *game, button_t **buttons)
{
    sfVector2i pos = {game->event.mouseButton.x, game->event.mouseButton.y};

    if (game->event.type != sfEvtMouseButtonPressed)
        return false;
    for (unsigned short i = 0; buttons[i]; i++) {
        if (!is_pos_in_button(buttons[i], pos))
            continue;
        buttons[i]->on_click(game);
        return true;
    }
    return false;
}

/*
** EPITECH PROJECT, 2021
** wheel.c
** File description:
** Game wheel events handling
*/

#include "my_rpg.h"
#include "menu.h"
#include <stdbool.h>

bool is_button_clicked(game_t *game, button_t *button)
{
    sfVector2i pos = {game->event.mouseButton.x, game->event.mouseButton.y};
    sfVector2f button_pos = sfSprite_getPosition(button->asset->sprite);
    sfFloatRect rect = sfSprite_getGlobalBounds(button->asset->sprite);

    if (((float) pos.x >= button_pos.x && (float) pos.y >= button_pos.y) &&
    (((float) pos.x <= button_pos.x + rect.width) &&
    ((float) pos.y <= button_pos.y + rect.height)))
        return true;
    return false;
}

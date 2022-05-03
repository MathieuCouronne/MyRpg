/*
** EPITECH PROJECT, 2021
** is_pos_in_button.c
** File description:
** Is a position inside a button
*/

#include "my_rpg.h"
#include <stdbool.h>

bool is_pos_in_button(button_t *button, sfVector2i pos)
{
    sfVector2f button_pos = sfSprite_getPosition(button->asset->sprite);
    sfFloatRect rect = sfSprite_getGlobalBounds(button->asset->sprite);

    if (((float) pos.x >= button_pos.x && (float) pos.y >= button_pos.y) &&
    (((float) pos.x <= button_pos.x + rect.width) &&
    ((float) pos.y <= button_pos.y + rect.height)))
        return true;
    return false;
}

/*
** EPITECH PROJECT, 2021
** menu.c
** File description:
** menu destroyer
*/

#include <stdlib.h>
#include "my_rpg.h"

void destroy_menu(game_asset_t *menu)
{
    if (!menu)
        return;
    sfSprite_destroy(menu->sprite);
    sfTexture_destroy(menu->texture);
    free(menu);
}

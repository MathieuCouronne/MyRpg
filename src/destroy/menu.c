/*
** EPITECH PROJECT, 2021
** menu.c
** File description:
** Menu destroyer
*/

#include <stdlib.h>
#include "my_rpg.h"

void destroy_menu(game_asset_t *menu)
{
    if (!menu)
        return;
    if (menu->sprite)
        sfSprite_destroy(menu->sprite);
    if (menu->texture)
        sfTexture_destroy(menu->texture);
    free(menu);
}

/*
** EPITECH PROJECT, 2021
** game.c
** File description:
** Game destroyer
*/

#include <stdlib.h>
#include "my_rpg.h"
#include "menu.h"

void destroy_menu(game_asset_t *menu)
{
    if (!menu)
        return;
    sfSprite_destroy(menu->sprite);
    sfTexture_destroy(menu->texture);
    free(menu);
}

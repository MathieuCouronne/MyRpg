/*
** EPITECH PROJECT, 2021
** button.c
** File description:
** button destroyer
*/

#include "my_rpg.h"
#include <stdlib.h>

void destroy_settings(game_asset_t *settings)
{
    if (!settings)
        return;
    sfSprite_destroy(settings->sprite);
    sfTexture_destroy(settings->texture);
    free(settings);
}

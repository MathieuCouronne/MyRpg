/*
** EPITECH PROJECT, 2021
** settings.c
** File description:
** settings destroyer
*/

#include "my_rpg.h"
#include <stdlib.h>

void destroy_settings(game_asset_t *settings)
{
    if (!settings)
        return;
    if (settings->sprite)
        sfSprite_destroy(settings->sprite);
    if (settings->texture)
        sfTexture_destroy(settings->texture);
    free(settings);
}

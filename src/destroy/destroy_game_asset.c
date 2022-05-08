/*
** EPITECH PROJECT, 2021
** destroy_game_asset.c
** File description:
** destroy game asset
*/

#include "my_rpg.h"
#include <stdlib.h>

void destroy_game_asset(game_asset_t *asset)
{
    if (!asset)
        return;
    if (asset->sprite)
        sfSprite_destroy(asset->sprite);
    if (asset->texture)
        sfTexture_destroy(asset->texture);
}

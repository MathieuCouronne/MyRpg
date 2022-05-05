/*
** EPITECH PROJECT, 2021
** game.c
** File description:
** Game destroyer
*/

#include <stdlib.h>
#include "my_rpg.h"

void destroy_game_scene(main_game_t *map)
{
    if (!map)
        return;
    if (map->map->sprite)
        sfSprite_destroy(map->map->sprite);
    if (map->map->texture)
        sfTexture_destroy(map->map->texture);
    destroy_chest(map->chest);
    destroy_albert(map->albert);
    destroy_chief(map->chief);
    free(map);
}

/*
** EPITECH PROJECT, 2021
** game.c
** File description:
** Game destroyer
*/

#include <stdlib.h>
#include "my_rpg.h"
#include "scenes.h"

void destroy_map(main_game_t *map)
{
    if (!map)
        return;
    sfSprite_destroy(map->map->sprite);
    sfTexture_destroy(map->map->texture);
    free(map);
}


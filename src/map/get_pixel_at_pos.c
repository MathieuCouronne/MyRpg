/*
** EPITECH PROJECT, 2022
** get_pixel_at_pos.c
** File description:
** Get pixel at a specified position
*/

#include <SFML/Graphics.h>
#include "my_rpg.h"
#include "macros.h"

static bool is_pixel_outside_map(sfVector2f shift)
{
    return (
        shift.x < 0 ||
        shift.y < 0 ||
        shift.x > MAP_WIDTH ||
        shift.x > MAP_HEIGHT
    );
}

sfColor get_pixel_at_pos(game_t *game, sfVector2f shift)
{
    sfColor color = sfBlack;
    sfVector2u unsigned_pos = {(unsigned int) shift.x, (unsigned int) shift.y};

    printf("x: %u, y: %u\n", unsigned_pos.x, unsigned_pos.y);
    if (!game || !game->collisions || is_pixel_outside_map(shift))
        return color;
    // printf("x: %u, y: %u\n", unsigned_pos.x, unsigned_pos.y);
    printf("pass\n");
    color = sfImage_getPixel(game->collisions, unsigned_pos.x, unsigned_pos.y);
    return color;
}

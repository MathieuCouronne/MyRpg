/*
** EPITECH PROJECT, 2021
** handling.c
** File description:
** Game arrow keys events handling
*/

#include <SFML/Graphics.h>
#include "my_rpg.h"

bool detect_enemies(game_t *game)
{
    sfIntRect *rect = game->player->rect;
    sfVector2f bottom_left = *game->player->position;

    bottom_left.y += (float) rect->height / 2;
    bottom_left.x += (float) rect->width / 2;
    sfColor color = get_pixel_at_pos(game, bottom_left);
    printf("%d %d %d\n", color.r, color.g, color.b);
    if (color_cmp(get_pixel_at_pos(game, bottom_left), game->enemy->color))
        return true;
    return false;
}
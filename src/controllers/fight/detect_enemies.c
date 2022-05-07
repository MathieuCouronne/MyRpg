/*
** EPITECH PROJECT, 2021
** detect_enemies.c
** File description:
** Detect if player is side to side with an enemy
*/

#include <SFML/Graphics.h>
#include "my_rpg.h"
#include "macros.h"

bool detect_enemies(game_t *game)
{
    sfIntRect *rect = game->player->rect;
    sfVector2f bottom_left = *game->player->position;

    bottom_left.y += (float) rect->height / 2;
    bottom_left.x += (float) rect->width / 2;
    for (unsigned int i = 0; i < 3; i++) {
        if (color_cmp(get_pixel_at_pos(game, bottom_left),
        game->enemy[i]->color)) {
            game->enemy_id = i;
            return true;
        }
    }
    return false;
}

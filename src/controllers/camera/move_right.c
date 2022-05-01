/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** Created by mathis
*/

#include <stdbool.h>
#include "structs.h"
#include "macros.h"
#include "my_rpg.h"

static bool move_player_right(game_t *game, sfColor color, float speed)
{
    sfIntRect *rect = game->player->rect;
    sfVector2f top_right = *game->player->position;
    sfVector2f bottom_right = *game->player->position;

    top_right.x += ((float) rect->width * (float) PLAYER_SCALE) + 1;
    bottom_right.x += ((float) rect->width * (float) PLAYER_SCALE) + 1;
    bottom_right.y += (float) rect->height * (float) PLAYER_SCALE;
    if (color_cmp(get_pixel_at_pos(game, top_right), color) ||
        color_cmp(get_pixel_at_pos(game, bottom_right), color))
        return false;
    game->player->position->x += speed;
    return true;
}

void move_right(game_t *game, sfColor color)
{
    float width = sfSprite_getGlobalBounds(game->player->sprite).width;
    float distance = WINDOW_WIDTH / 2 - WINDOW_PADDING;
    float speed = PLAYER_MOVEMENT *
    (sfKeyboard_isKeyPressed(sfKeyLAlt) ? 2 : 1);

    if ((game->player->relative_pos->x + width) < distance) {
        move_player_right(game, color, speed);
        game->player->relative_pos->x += speed * 2;
    } else if (move_player_right(game, color, speed))
        sfView_move(game->view, (sfVector2f) {speed, 0});
}

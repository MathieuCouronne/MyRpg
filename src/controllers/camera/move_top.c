/*
** EPITECH PROJECT, 2022
** move_left.c
** File description:
** Move camera
*/

#include <stdbool.h>
#include "structs.h"
#include "macros.h"
#include "my_rpg.h"

static bool move_player_top(game_t *game, sfColor color, float speed)
{
    sfIntRect *rect = game->player->rect;
    sfVector2f top_left = *game->player->position;
    sfVector2f top_right = *game->player->position;

    top_left.y -= 1;
    top_right.y -= 1;
    top_right.x += (float) rect->width * (float) PLAYER_SCALE;
    if (color_cmp(get_pixel_at_pos(game, top_left), color) ||
        color_cmp(get_pixel_at_pos(game, top_right), color))
        return false;
    game->player->position->y -= speed;
    return true;
}

void move_top(game_t *game, sfColor color)
{
    float distance = WINDOW_HEIGHT / 2 - WINDOW_PADDING;
    float speed = PLAYER_MOVEMENT *
    (sfKeyboard_isKeyPressed(sfKeyLShift) ? 2 : 1);

    if ((game->player->relative_pos->y) > -distance) {
        move_player_top(game, color, speed);
        game->player->relative_pos->y -= speed * 2;
    } else if (move_player_top(game, color, speed))
        sfView_move(game->view, (sfVector2f) {0, -speed});
}

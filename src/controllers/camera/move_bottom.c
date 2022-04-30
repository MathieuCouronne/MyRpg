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

static bool move_player_bottom(game_t *game, sfColor color, float speed)
{
    sfIntRect *rect = game->player->rect;
    sfVector2f bottom_left = *game->player->position;
    sfVector2f bottom_right = *game->player->position;

    bottom_left.x += (float) rect->width * (float) PLAYER_SCALE;
    bottom_left.y += (float) rect->height * (float) PLAYER_SCALE;
    bottom_right.y += (float) rect->height * (float) PLAYER_SCALE;
    if (color_cmp(get_pixel_at_pos(game, bottom_left), color) ||
        color_cmp(get_pixel_at_pos(game, bottom_right), color))
        return false;
    game->player->position->y += speed;
    return true;
}

void move_bottom(game_t *game, sfColor color)
{
    float height = sfSprite_getGlobalBounds(game->player->sprite).height;
    float distance = WINDOW_HEIGHT / 2 - WINDOW_PADDING;
    float speed = PLAYER_MOVEMENT *
    (sfKeyboard_isKeyPressed(sfKeyLAlt) ? 2 : 1);

    if ((game->player->relative_pos->y + height) < distance) {
        move_player_bottom(game, color, speed);
        game->player->relative_pos->y += speed * 2;
    } else if (move_player_bottom(game, color, speed))
        sfView_move(game->view, (sfVector2f) {0, speed});
}

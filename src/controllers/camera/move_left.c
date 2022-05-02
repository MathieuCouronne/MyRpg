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

static void move_rect(game_t *game)
{
    if (game->player->rect->left >= 608 - 77) {
        game->player->rect->left = 14;
    }
    game->player->rect->left += 77;
    sfSprite_setTextureRect(game->player->sprite, *game->player->rect);
}

static void clock_movement(game_t *game)
{
    float time_offset = 0.1;

    if (clock_time(game->player->clock, time_offset)) {
        move_rect(game);
        sfClock_restart(game->player->clock);
    }
}

static bool move_player_left(game_t *game, sfColor color, float speed)
{
    sfIntRect *rect = game->player->rect;
    sfVector2f top_left = *game->player->position;
    sfVector2f bottom_left = *game->player->position;

    top_left.x -= 1;
    bottom_left.x -= 1;
    bottom_left.y += (float) rect->height * (float) PLAYER_SCALE;
    if (color_cmp(get_pixel_at_pos(game, top_left), color) ||
        color_cmp(get_pixel_at_pos(game, bottom_left), color))
        return false;
    if (game->player->rect->top != 93) {
        game->player->rect->top = 93;
        sfSprite_setTextureRect(game->player->sprite, *game->player->rect);
    }
    clock_movement(game);
    game->player->position->x -= speed;
    return true;
}

void move_left(game_t *game, sfColor color)
{
    float distance = WINDOW_WIDTH / 2 - WINDOW_PADDING;
    float speed = PLAYER_MOVEMENT *
    (sfKeyboard_isKeyPressed(sfKeyLShift) ? 2 : 1);

    if ((game->player->relative_pos->x) > -distance &&
    move_player_left(game, color, speed))
        game->player->relative_pos->x -= speed * 2;
    else if (move_player_left(game, color, speed))
        sfView_move(game->view, (sfVector2f) {-speed, 0});
}

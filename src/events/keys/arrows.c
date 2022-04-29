/*
** EPITECH PROJECT, 2021
** handling.c
** File description:
** Game arrow keys events handling
*/

#include <SFML/Graphics.h>
#include "my_rpg.h"
#include "macros.h"

void move_player_left(game_t *game, sfColor color)
{
    sfIntRect *rect = game->player->rect;
    sfVector2f top_left = *game->player->position;
    sfVector2f bottom_left = *game->player->position;
    float speed = PLAYER_MOVEMENT *
    (sfKeyboard_isKeyPressed(sfKeyLAlt) ? 2 : 1);

    top_left.x -= 1;
    bottom_left.x -= 1;
    bottom_left.y += (float) rect->height * (float) PLAYER_SCALE;
    if (color_cmp(get_pixel_at_pos(game, top_left), color) ||
    color_cmp(get_pixel_at_pos(game, bottom_left), color))
        return;
    sfView_move(game->view, (sfVector2f) {-speed, 0});
    game->player->position->x -= speed;
}

void move_player_right(game_t *game, sfColor color)
{
    sfIntRect *rect = game->player->rect;
    sfVector2f top_right = *game->player->position;
    sfVector2f bottom_right = *game->player->position;
    float speed = PLAYER_MOVEMENT *
    (sfKeyboard_isKeyPressed(sfKeyLAlt) ? 2 : 1);

    top_right.x += ((float) rect->width * (float) PLAYER_SCALE) + 1;
    bottom_right.x += ((float) rect->width * (float) PLAYER_SCALE) + 1;
    bottom_right.y += (float) rect->height * (float) PLAYER_SCALE;
    if (color_cmp(get_pixel_at_pos(game, top_right), color) ||
    color_cmp(get_pixel_at_pos(game, bottom_right), color))
        return;
    sfView_move(game->view, (sfVector2f) {speed, 0});
    game->player->position->x += speed;
}

void move_player_top(game_t *game, sfColor color)
{
    sfIntRect *rect = game->player->rect;
    sfVector2f top_left = *game->player->position;
    sfVector2f top_right = *game->player->position;
    float speed = PLAYER_MOVEMENT *
    (sfKeyboard_isKeyPressed(sfKeyLAlt) ? 2 : 1);

    top_left.y -= 1;
    top_right.y -= 1;
    top_right.x += (float) rect->width * (float) PLAYER_SCALE;
    if (color_cmp(get_pixel_at_pos(game, top_left), color) ||
    color_cmp(get_pixel_at_pos(game, top_right), color))
        return;
    sfView_move(game->view, (sfVector2f) {0, -speed});
    game->player->position->y -= speed;
}

void move_player_bottom(game_t *game, sfColor color)
{
    sfIntRect *rect = game->player->rect;
    sfVector2f bottom_left = *game->player->position;
    sfVector2f bottom_right = *game->player->position;
    float speed = PLAYER_MOVEMENT *
    (sfKeyboard_isKeyPressed(sfKeyLAlt) ? 2 : 1);

    bottom_left.x += (float) rect->width * (float) PLAYER_SCALE;
    bottom_left.y += (float) rect->height * (float) PLAYER_SCALE;
    bottom_right.y += (float) rect->height * (float) PLAYER_SCALE;
    if (color_cmp(get_pixel_at_pos(game, bottom_left), color) ||
    color_cmp(get_pixel_at_pos(game, bottom_right), color))
        return;
    sfView_move(game->view, (sfVector2f) {0, speed});
    game->player->position->y += speed;
}

void handle_arrow_keys(game_t *game)
{
    const sfColor collision = sfColor_fromRGB(254, 0, 0);

    if (sfKeyboard_isKeyPressed(sfKeyQ))
        move_player_left(game, collision);
    if (sfKeyboard_isKeyPressed(sfKeyD))
        move_player_right(game, collision);
    if (sfKeyboard_isKeyPressed(sfKeyZ))
        move_player_top(game, collision);
    if (sfKeyboard_isKeyPressed(sfKeyS))
        move_player_bottom(game, collision);
    sfSprite_setPosition(game->player->sprite, *game->player->position);
}

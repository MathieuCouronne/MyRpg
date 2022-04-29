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
    sfVector2f pos = *game->player->position;

    pos.x -= PLAYER_MOVEMENT;
    // pos.y += game->player->rect->height / 2;
    if (color_cmp(get_pixel_at_pos(game, pos), color))
        return;
    sfView_move(game->view, (sfVector2f) {-PLAYER_MOVEMENT, 0});
    game->player->position->x -= PLAYER_MOVEMENT;
}

void move_player_right(game_t *game, sfColor color)
{
    sfVector2f pos = *game->player->position;

    pos.x += PLAYER_MOVEMENT;
    // pos.y += game->player->rect->height / 2;
    if (color_cmp(get_pixel_at_pos(game, pos), color))
        return;
    sfView_move(game->view, (sfVector2f) {PLAYER_MOVEMENT, 0});
    game->player->position->x += PLAYER_MOVEMENT;
}

void move_player_top(game_t *game, sfColor color)
{
    sfVector2f pos = *game->player->position;

    pos.y -= PLAYER_MOVEMENT;
    // pos.y += game->player->rect->height / 2;
    if (color_cmp(get_pixel_at_pos(game, pos), color))
        return;
    sfView_move(game->view, (sfVector2f) {0, -PLAYER_MOVEMENT});
    game->player->position->y -= PLAYER_MOVEMENT;
}

void move_player_bottom(game_t *game, sfColor color)
{
    sfVector2f pos = *game->player->position;

    pos.y += PLAYER_MOVEMENT;
    // pos.y += game->player->rect->height / 2;
    if (color_cmp(get_pixel_at_pos(game, pos), color))
        return;
    sfView_move(game->view, (sfVector2f) {0, PLAYER_MOVEMENT});
    game->player->position->y += PLAYER_MOVEMENT;
}

void handle_arrow_keys(game_t *game)
{
    const sfColor collision = sfColor_fromRGB(254, 0, 0);

    if (sfKeyboard_isKeyPressed(sfKeyLeft))
        move_player_left(game, collision);
    if (sfKeyboard_isKeyPressed(sfKeyRight))
        move_player_right(game, collision);
        // sfView_move(game->view, (sfVector2f) {PLAYER_MOVEMENT, 0});
        // clock_player_right(game->player->clock, game);
        // game->player->position.x += PLAYER_MOVEMENT;
    if (sfKeyboard_isKeyPressed(sfKeyUp))
        move_player_top(game, collision);
        // sfView_move(game->view, (sfVector2f) {0, -PLAYER_MOVEMENT});
        // clock_player_up(game->player->clock, game);
        // game->player->position.y -= PLAYER_MOVEMENT;
    if (sfKeyboard_isKeyPressed(sfKeyDown))
        move_player_bottom(game, collision);
        // sfView_move(game->view, (sfVector2f) {0, PLAYER_MOVEMENT});
        // clock_player_down(game->player->clock, game);
        // game->player->position.y += PLAYER_MOVEMENT;
    sfSprite_setPosition(game->player->sprite, *game->player->position);
}

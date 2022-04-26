/*
** EPITECH PROJECT, 2021
** handling.c
** File description:
** Game arrow keys events handling
*/

#include "my_rpg.h"

void handle_arrow_keys(game_t *game)
{
    if (sfKeyboard_isKeyPressed(sfKeyLeft)) {
        sfView_move(game->view, (sfVector2f) {-5, 0});
        game->player->position.x -= 5;
    }
    if (sfKeyboard_isKeyPressed(sfKeyRight)) {
        sfView_move(game->view, (sfVector2f) {5, 0});
        // clock_player_right(game->player->clock, game);
        game->player->position.x += 5;
    }
    if (sfKeyboard_isKeyPressed(sfKeyUp)) {
        sfView_move(game->view, (sfVector2f) {0, -5});
        // clock_player_up(game->player->clock, game);
        game->player->position.y -= 5;
    }
    if (sfKeyboard_isKeyPressed(sfKeyDown)) {
        sfView_move(game->view, (sfVector2f) {0, 5});
        // clock_player_down(game->player->clock, game);
        game->player->position.y += 5;
    }
    sfSprite_setPosition(game->player->sprite, game->player->position);
}

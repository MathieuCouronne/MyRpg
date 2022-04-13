/*
** EPITECH PROJECT, 2021
** handling.c
** File description:
** Game arrow keys events handling
*/

#include "my_rpg.h"

void handle_arrow_keys(game_t *game, sfEvent *event)
{
    if (event->key.code == sfKeyLeft && game->view) {
        sfView_move(game->view, (sfVector2f) {-20, 0});
        game->player->position.x -= 20;
        sfSprite_setPosition(game->player->sprite, game->player->position);
    } else if (event->key.code == sfKeyRight && game->view) {
        sfView_move(game->view, (sfVector2f) {20, 0});
        clock_player_right(game->player->clock, game);
        game->player->position.x += 20;
        sfSprite_setPosition(game->player->sprite, game->player->position);
    } else if (event->key.code == sfKeyUp && game->view) {
        sfView_move(game->view, (sfVector2f) {0, -20});
        game->player->position.y -= 20;
        sfSprite_setPosition(game->player->sprite, game->player->position);
    } else if (event->key.code == sfKeyDown && game->view) {
        sfView_move(game->view, (sfVector2f) {0, 20});
        clock_player_down(game->player->clock, game);
        game->player->position.y += 20;
        sfSprite_setPosition(game->player->sprite, game->player->position);
    }
}

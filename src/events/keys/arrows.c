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
    } else if (event->key.code == sfKeyRight && game->view) {
        sfView_move(game->view, (sfVector2f) {20, 0});
    } else if (event->key.code == sfKeyUp && game->view) {
        sfView_move(game->view, (sfVector2f) {0, -20});
    } else if (event->key.code == sfKeyDown && game->view)
        sfView_move(game->view, (sfVector2f) {0, 20});
}

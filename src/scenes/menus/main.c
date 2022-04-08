/*
** EPITECH PROJECT, 2021
** handling.c
** File description:
** Game arrow keys events handling
*/

#include "my_rpg.h"

void handle_arrow_keys(game_t *game, sfEvent *event)
{
    if (event->key.code == sfKeyLeft) {
        sfView_move(game->view, (sfVector2f) {-1, 0});
    } else if (event->key.code == sfKeyRight) {
        sfView_move(game->view, (sfVector2f) {1, 0});
    }
}

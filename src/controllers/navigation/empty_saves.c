/*
** EPITECH PROJECT, 2021
** empty_saves.c
** File description:
** Saves scene navigation
*/

#include "my_rpg.h"

void go_to_creation_player1(game_t *game)
{
    game->current = 0;
    go_to_creation(game);
}

void go_to_creation_player2(game_t *game)
{
    game->current = 1;
    go_to_creation(game);
}

void go_to_creation_player3(game_t *game)
{
    game->current = 2;
    go_to_creation(game);
}

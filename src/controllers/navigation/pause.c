/*
** EPITECH PROJECT, 2021
** pause.c
** File description:
** Pause navigation functions
*/

#include "my_rpg.h"

void back_to_game(game_t *game)
{
    game->scenes->prev = game->scenes->current;
    game->scenes->current = MAIN_GAME;
}

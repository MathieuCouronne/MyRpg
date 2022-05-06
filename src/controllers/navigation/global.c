/*
** EPITECH PROJECT, 2021
** global.c
** File description:
** Globals navigation functions
*/

#include "my_rpg.h"

void go_to_menu(game_t *game)
{
    game->scenes->prev = game->scenes->current;
    game->scenes->current = MAIN_MENU;
}

void go_to_prev(game_t *game)
{
    game->scenes->current = game->scenes->prev;
}

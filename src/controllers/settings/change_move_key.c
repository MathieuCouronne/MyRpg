/*
** EPITECH PROJECT, 2021
** saves.c
** File description:
** Saves scene navigation
*/

#include "my_rpg.h"

void change_left(game_t *game)
{
    if (check_bool(game) >= 1)
        return;
    game->scenes->settings->icons[3]->select = true;
    game->scenes->settings->current = 3;
}

void change_right(game_t *game)
{
    if (check_bool(game) >= 1)
        return;
    game->scenes->settings->icons[4]->select = true;
    game->scenes->settings->current = 4;
}

void change_up(game_t *game)
{
    if (check_bool(game) >= 1)
        return;
    game->scenes->settings->icons[5]->select = true;
    game->scenes->settings->current = 5;
}

void change_down(game_t *game)
{
    if (check_bool(game) >= 1)
        return;
    game->scenes->settings->icons[6]->select = true;
    game->scenes->settings->current = 6;
}

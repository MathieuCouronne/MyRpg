/*
** EPITECH PROJECT, 2021
** saves.c
** File description:
** Saves scene navigation
*/

#include "my_rpg.h"

void change_inventory(game_t *game)
{
    if (check_bool(game) >= 1)
        return;
    game->scenes->settings->icons[0]->select = true;
}

void change_interact(game_t *game)
{
    if (check_bool(game) >= 1)
        return;
    game->scenes->settings->icons[1]->select = true;
}

void change_pause(game_t *game)
{
    if (check_bool(game) >= 1)
        return;
    game->scenes->settings->icons[2]->select = true;
}

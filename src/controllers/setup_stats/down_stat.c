/*
** EPITECH PROJECT, 2021
** global.c
** File description:
** Globals navigation functions
*/

#include "my_rpg.h"

void down_strength(game_t *game)
{
    game->scenes->creation_menu->stats
    [game->scenes->creation_menu->class][0]--;
    sfText_setString(game->scenes->creation_menu->stat
    [game->scenes->creation_menu->class][0],
    itoa(game->scenes->creation_menu->stats
    [game->scenes->creation_menu->class][0]));
}

void down_defense(game_t *game)
{
    game->scenes->creation_menu->stats
    [game->scenes->creation_menu->class][1]--;
    sfText_setString(game->scenes->creation_menu->stat
    [game->scenes->creation_menu->class][1],
    itoa(game->scenes->creation_menu->stats
    [game->scenes->creation_menu->class][1]));
}

void down_vitality(game_t *game)
{
    game->scenes->creation_menu->stats
    [game->scenes->creation_menu->class][2]--;
    sfText_setString(game->scenes->creation_menu->stat
    [game->scenes->creation_menu->class][2],
    itoa(game->scenes->creation_menu->stats
    [game->scenes->creation_menu->class][2]));
}

void down_speed(game_t *game)
{
    game->scenes->creation_menu->stats
    [game->scenes->creation_menu->class][3]--;
    sfText_setString(game->scenes->creation_menu->stat
    [game->scenes->creation_menu->class][3],
    itoa(game->scenes->creation_menu->stats
    [game->scenes->creation_menu->class][3]));
}

void down_dexterity(game_t *game)
{
    game->scenes->creation_menu->stats
    [game->scenes->creation_menu->class][4]--;
    sfText_setString(game->scenes->creation_menu->stat
    [game->scenes->creation_menu->class][4],
    itoa(game->scenes->creation_menu->stats
    [game->scenes->creation_menu->class][4]));
}

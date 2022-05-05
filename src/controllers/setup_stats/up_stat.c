/*
** EPITECH PROJECT, 2021
** global.c
** File description:
** Globals navigation functions
*/

#include "my_rpg.h"

void up_strength(game_t *game)
{
    if (game->scenes->creation_menu->unspent == 0)
        return;
    game->scenes->creation_menu->stats
    [game->scenes->creation_menu->class][0] += 1;
    sfText_setString(game->scenes->creation_menu->stat
    [game->scenes->creation_menu->class][0],
    itoa(game->scenes->creation_menu->stats
    [game->scenes->creation_menu->class][0]));
    game->scenes->creation_menu->unspent--;
    sfText_setString(game->scenes->creation_menu->unspent_text,
    itoa(game->scenes->creation_menu->unspent));
}

void up_defense(game_t *game)
{
    if (game->scenes->creation_menu->unspent == 0)
        return;
    game->scenes->creation_menu->stats
    [game->scenes->creation_menu->class][1] += 1;
    sfText_setString(game->scenes->creation_menu->stat
    [game->scenes->creation_menu->class][1],
    itoa(game->scenes->creation_menu->stats
    [game->scenes->creation_menu->class][1]));
    game->scenes->creation_menu->unspent--;
    sfText_setString(game->scenes->creation_menu->unspent_text,
    itoa(game->scenes->creation_menu->unspent));
}

void up_vitality(game_t *game)
{
    if (game->scenes->creation_menu->unspent == 0)
        return;
    game->scenes->creation_menu->stats
    [game->scenes->creation_menu->class][2] += 1;
    sfText_setString(game->scenes->creation_menu->stat
    [game->scenes->creation_menu->class][2],
    itoa(game->scenes->creation_menu->stats
    [game->scenes->creation_menu->class][2]));
    game->scenes->creation_menu->unspent--;
    sfText_setString(game->scenes->creation_menu->unspent_text,
    itoa(game->scenes->creation_menu->unspent));
}

void up_speed(game_t *game)
{
    if (game->scenes->creation_menu->unspent == 0)
        return;
    game->scenes->creation_menu->stats
    [game->scenes->creation_menu->class][3] += 1;
    sfText_setString(game->scenes->creation_menu->stat
    [game->scenes->creation_menu->class][3],
    itoa(game->scenes->creation_menu->stats
    [game->scenes->creation_menu->class][3]));
    game->scenes->creation_menu->unspent--;
    sfText_setString(game->scenes->creation_menu->unspent_text,
    itoa(game->scenes->creation_menu->unspent));
}

void up_dexterity(game_t *game)
{
    if (game->scenes->creation_menu->unspent == 0)
        return;
    game->scenes->creation_menu->stats
    [game->scenes->creation_menu->class][4] += 1;
    sfText_setString(game->scenes->creation_menu->stat
    [game->scenes->creation_menu->class][4],
    itoa(game->scenes->creation_menu->stats
    [game->scenes->creation_menu->class][4]));
    game->scenes->creation_menu->unspent--;
    sfText_setString(game->scenes->creation_menu->unspent_text,
    itoa(game->scenes->creation_menu->unspent));
}

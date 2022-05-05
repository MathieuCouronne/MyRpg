/*
** EPITECH PROJECT, 2021
** global.c
** File description:
** Globals navigation functions
*/

#include "my_rpg.h"

extern int class_base_data[3][5];

void down_strength(game_t *game)
{
    if (game->scenes->creation_menu->stats
    [game->scenes->creation_menu->class][0] - 1 <
    class_base_data[game->scenes->creation_menu->class][0])
        return;
    game->scenes->creation_menu->stats
    [game->scenes->creation_menu->class][0]--;
    sfText_setString(game->scenes->creation_menu->stat
    [game->scenes->creation_menu->class][0],
    itoa(game->scenes->creation_menu->stats
    [game->scenes->creation_menu->class][0]));
    game->scenes->creation_menu->unspent[game->scenes->creation_menu->class]++;
    sfText_setString(game->scenes->creation_menu->unspent_text
    [game->scenes->creation_menu->class],
    itoa(game->scenes->creation_menu->unspent
    [game->scenes->creation_menu->class]));
}

void down_defense(game_t *game)
{
    if (game->scenes->creation_menu->stats
        [game->scenes->creation_menu->class][1] - 1 <
        class_base_data[game->scenes->creation_menu->class][1])
        return;
    game->scenes->creation_menu->stats
    [game->scenes->creation_menu->class][1]--;
    sfText_setString(game->scenes->creation_menu->stat
    [game->scenes->creation_menu->class][1],
    itoa(game->scenes->creation_menu->stats
    [game->scenes->creation_menu->class][1]));
    game->scenes->creation_menu->unspent[game->scenes->creation_menu->class]++;
    sfText_setString(game->scenes->creation_menu->unspent_text
    [game->scenes->creation_menu->class],
    itoa(game->scenes->creation_menu->unspent
    [game->scenes->creation_menu->class]));
}

void down_vitality(game_t *game)
{
    if (game->scenes->creation_menu->stats
        [game->scenes->creation_menu->class][2] - 1 <
        class_base_data[game->scenes->creation_menu->class][2])
        return;
    game->scenes->creation_menu->stats
    [game->scenes->creation_menu->class][2]--;
    sfText_setString(game->scenes->creation_menu->stat
    [game->scenes->creation_menu->class][2],
    itoa(game->scenes->creation_menu->stats
    [game->scenes->creation_menu->class][2]));
    game->scenes->creation_menu->unspent[game->scenes->creation_menu->class]++;
    sfText_setString(game->scenes->creation_menu->unspent_text
    [game->scenes->creation_menu->class],
    itoa(game->scenes->creation_menu->unspent
    [game->scenes->creation_menu->class]));
}

void down_speed(game_t *game)
{
    if (game->scenes->creation_menu->stats
        [game->scenes->creation_menu->class][3] - 1 <
        class_base_data[game->scenes->creation_menu->class][3])
        return;
    game->scenes->creation_menu->stats
    [game->scenes->creation_menu->class][3]--;
    sfText_setString(game->scenes->creation_menu->stat
    [game->scenes->creation_menu->class][3],
    itoa(game->scenes->creation_menu->stats
    [game->scenes->creation_menu->class][3]));
    game->scenes->creation_menu->unspent[game->scenes->creation_menu->class]++;
    sfText_setString(game->scenes->creation_menu->unspent_text
    [game->scenes->creation_menu->class],
    itoa(game->scenes->creation_menu->unspent
    [game->scenes->creation_menu->class]));
}

void down_dexterity(game_t *game)
{
    if (game->scenes->creation_menu->stats
        [game->scenes->creation_menu->class][4] - 1 <
        class_base_data[game->scenes->creation_menu->class][4])
        return;
    game->scenes->creation_menu->stats
    [game->scenes->creation_menu->class][4]--;
    sfText_setString(game->scenes->creation_menu->stat
    [game->scenes->creation_menu->class][4],
    itoa(game->scenes->creation_menu->stats
    [game->scenes->creation_menu->class][4]));
    game->scenes->creation_menu->unspent[game->scenes->creation_menu->class]++;
    sfText_setString(game->scenes->creation_menu->unspent_text
    [game->scenes->creation_menu->class],
    itoa(game->scenes->creation_menu->unspent
    [game->scenes->creation_menu->class]));
}

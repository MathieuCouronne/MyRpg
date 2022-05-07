/*
** EPITECH PROJECT, 2021
** down_stats_game.c
** File description:
** Down stats game
*/

#include "my_rpg.h"

extern int class_base_data[3][5];

void down_strength_game(game_t *game)
{
    if ((int) game->saves[game->current]->stats->strength - 1 <
        class_base_data[game->saves[game->current]->class][0])
        return;
    game->saves[game->current]->stats->strength--;
    sfText_setString(game->scenes->stats->stat[0],
    itoa(game->saves[game->current]->stats->strength));
    game->saves[game->current]->unspent++;
    sfText_setString(game->scenes->stats->unspent_text,
    itoa(game->saves[game->current]->unspent));
}

void down_defense_game(game_t *game)
{
    if ((int) game->saves[game->current]->stats->defense - 1 <
        class_base_data[game->saves[game->current]->class][1])
        return;
    game->saves[game->current]->stats->defense--;
    sfText_setString(game->scenes->stats->stat[1],
    itoa(game->saves[game->current]->stats->defense));
    game->saves[game->current]->unspent++;
    sfText_setString(game->scenes->stats->unspent_text,
    itoa(game->saves[game->current]->unspent));
}

void down_vitality_game(game_t *game)
{
    if ((int) game->saves[game->current]->stats->vitality - 1 <
        class_base_data[game->saves[game->current]->class][2])
        return;
    game->saves[game->current]->stats->vitality--;
    sfText_setString(game->scenes->stats->stat[2],
    itoa(game->saves[game->current]->stats->vitality));
    game->saves[game->current]->unspent++;
    sfText_setString(game->scenes->stats->unspent_text,
    itoa(game->saves[game->current]->unspent));
}

void down_speed_game(game_t *game)
{
    if ((int) game->saves[game->current]->stats->speed - 1 <
        class_base_data[game->saves[game->current]->class][3])
        return;
    game->saves[game->current]->stats->speed--;
    sfText_setString(game->scenes->stats->stat[3],
    itoa(game->saves[game->current]->stats->speed));
    game->saves[game->current]->unspent++;
    sfText_setString(game->scenes->stats->unspent_text,
    itoa(game->saves[game->current]->unspent));
}

void down_dexterity_game(game_t *game)
{
    if ((int) game->saves[game->current]->stats->dexterity - 1 <
        class_base_data[game->saves[game->current]->class][4])
        return;
    game->saves[game->current]->stats->dexterity--;
    sfText_setString(game->scenes->stats->stat[4],
    itoa(game->saves[game->current]->stats->dexterity));
    game->saves[game->current]->unspent++;
    sfText_setString(game->scenes->stats->unspent_text,
    itoa(game->saves[game->current]->unspent));
}

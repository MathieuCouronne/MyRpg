/*
** EPITECH PROJECT, 2021
** global.c
** File description:
** Globals navigation functions
*/

#include "my_rpg.h"

extern int class_base_data[3][5];

void up_strength_game(game_t *game)
{
    if (game->saves[game->current]->unspent == 0)
        return;
    game->saves[game->current]->stats->strength++;
    sfText_setString(game->scenes->stats->stat[0],
    itoa(game->saves[game->current]->stats->strength));
    game->saves[game->current]->unspent--;
    sfText_setString(game->scenes->stats->unspent_text,
    itoa(game->saves[game->current]->unspent));
}

void up_defense_game(game_t *game)
{
    if (game->saves[game->current]->unspent == 0)
        return;
    game->saves[game->current]->stats->defense++;
    sfText_setString(game->scenes->stats->stat[1],
    itoa(game->saves[game->current]->stats->defense));
    game->saves[game->current]->unspent--;
    sfText_setString(game->scenes->stats->unspent_text,
    itoa(game->saves[game->current]->unspent));
}

void up_vitality_game(game_t *game)
{
    if (game->saves[game->current]->unspent == 0)
        return;
    game->saves[game->current]->stats->vitality++;
    sfText_setString(game->scenes->stats->stat[2],
    itoa(game->saves[game->current]->stats->vitality));
    game->saves[game->current]->unspent--;
    sfText_setString(game->scenes->stats->unspent_text,
    itoa(game->saves[game->current]->unspent));
}

void up_speed_game(game_t *game)
{
    if (game->saves[game->current]->unspent == 0)
        return;
    game->saves[game->current]->stats->speed++;
    sfText_setString(game->scenes->stats->stat[3],
    itoa(game->saves[game->current]->stats->speed));
    game->saves[game->current]->unspent--;
    sfText_setString(game->scenes->stats->unspent_text,
    itoa(game->saves[game->current]->unspent));
}

void up_dexterity_game(game_t *game)
{
    if (game->saves[game->current]->unspent == 0)
        return;
    game->saves[game->current]->stats->dexterity++;
    sfText_setString(game->scenes->stats->stat[4],
    itoa(game->saves[game->current]->stats->dexterity));
    game->saves[game->current]->unspent--;
    sfText_setString(game->scenes->stats->unspent_text,
    itoa(game->saves[game->current]->unspent));
}

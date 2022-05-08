/*
** EPITECH PROJECT, 2021
** escape_fight.c
** File description:
** escape from fight
*/

#include <stdlib.h>
#include "structs.h"
#include "my_rpg.h"

void escape_fight(game_t *game)
{
    game->saves[game->current]->hp =
        game->saves[game->current]->stats->vitality;
    game->scenes->fight->enemy[game->enemy_id]->hp =
        game->scenes->fight->enemy[game->enemy_id]->max_hp;
    game->scenes->current = MAIN_GAME;
}

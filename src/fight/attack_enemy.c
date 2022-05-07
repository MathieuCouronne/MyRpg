/*
** EPITECH PROJECT, 2021
** create_map.c
** File description:
** attacks enemy during fight
*/

#include <stdbool.h>
#include <stdlib.h>
#include "my_rpg.h"
#include "structs.h"

void attack_enemy(game_t *game)
{
//    unsigned int dmg = player->stats->strength + attack->dmg;
    unsigned int dmg = game->saves[game->current]->stats->strength;

    game->scenes->fight->enemy[game->enemy_id]->hp -= dmg;
    create_text_enemy(game->scenes->fight->enemy[game->enemy_id], game->scenes->fight);
    attack_player(game->saves[game->current], game->scenes->fight->enemy[game->enemy_id]);
    create_text_player(game->saves[game->current], game->scenes->fight);
}

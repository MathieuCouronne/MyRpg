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

static check_player_hp(game_t *game)
{
    if (game->saves[game->current]->hp <= 0) {
        game->saves[game->current]->hp =
            game->saves[game->current]->stats->vitality;
        game->scenes->fight->enemy[game->enemy_id]->hp =
            game->scenes->fight->enemy[game->enemy_id]->max_hp;
        game->scenes->current = MAIN_GAME;
    }
}

void attack_enemy(game_t *game)
{
    unsigned int dmg = game->saves[game->current]->stats->strength;

    if (dmg > game->scenes->fight->enemy[game->enemy_id]->hp) {
        game->scenes->fight->enemy[game->enemy_id]->hp =
            game->scenes->fight->enemy[game->enemy_id]->max_hp;
    } else
        game->scenes->fight->enemy[game->enemy_id]->hp -= dmg;
    create_text_enemy(game->scenes->fight->enemy[game->enemy_id],
        game->scenes->fight);
    if (game->scenes->fight->enemy[game->enemy_id]->hp <= 0) {
        game->saves[game->current]->hp =
            game->saves[game->current]->stats->vitality;
        game->scenes->current = MAIN_GAME;
        return;
    }
    attack_player(game->saves[game->current],
        game->scenes->fight->enemy[game->enemy_id]);
    create_text_player(game->saves[game->current], game->scenes->fight);
    check_player_hp(game);
}

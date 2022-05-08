/*
** EPITECH PROJECT, 2021
** attack_enemy.c
** File description:
** Attacks enemy during fight
*/

#include "my_rpg.h"
#include "structs.h"

static void check_player_hp(game_t *game)
{
    if (game->saves[game->current]->hp <= 0) {
        game->saves[game->current]->hp =
            game->saves[game->current]->stats->vitality;
        game->scenes->fight->enemy[game->enemy_id]->hp =
            game->scenes->fight->enemy[game->enemy_id]->max_hp;
        game->scenes->current = MAIN_GAME;
    }
}

static bool check_enemy_hp(game_t *game)
{
    if (game->scenes->fight->enemy[game->enemy_id]->hp <= 0) {
        game->saves[game->current]->hp =
            game->saves[game->current]->stats->vitality;
        game->scenes->fight->enemy[game->enemy_id]->hp =
            game->scenes->fight->enemy[game->enemy_id]->max_hp;
        if (add_experience(game->saves[game->current], 40)) {
            game->scenes->game_scene->level_up = true;
            game->scenes->game_scene->level_up_clock = sfClock_create();
        }
        game->scenes->current = MAIN_GAME;
        return true;
    }
    return false;
}

void attack_enemy(game_t *game)
{
    unsigned int dmg = get_dmg(game->saves[game->current]->stats->strength);

    game->scenes->fight->enemy[game->enemy_id]->hp -= dmg;
    create_text_enemy(game->scenes->fight->enemy[game->enemy_id],
        game->scenes->fight);
    if (check_enemy_hp(game))
        return;
    attack_player(game->saves[game->current],
        game->scenes->fight->enemy[game->enemy_id]);
    create_text_player(game->saves[game->current], game->scenes->fight);
    check_player_hp(game);
}

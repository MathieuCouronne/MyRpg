/*
** EPITECH PROJECT, 2021
** gamble_fight.c
** File description:
** decides if enemy's or player's life is divided by 2
*/

#include <stdlib.h>
#include <SFML/Window.h>
#include <stdbool.h>
#include "structs.h"
#include "my_rpg.h"

static bool is_player_divided(void)
{
    void *ptr = malloc(1);
    unsigned int seed = 0;
    unsigned int res = 0;

    if (!ptr)
        return 1;
    seed = *((unsigned int *)&ptr);
    srand(seed);
    free(ptr);
    res = (rand() % 100);
    if (res < 50)
        return true;
    return false;
}

void gamble_fight(game_t *game)
{
    if (is_player_divided()) {
        game->saves[game->current]->hp /= 2;
        create_text_player(game->saves[game->current], game->scenes->fight);
    } else {
        game->scenes->fight->enemy[game->enemy_id]->hp /= 2;
        create_text_enemy(game->scenes->fight->enemy[game->enemy_id],
        game->scenes->fight);
    }
}

/*
** EPITECH PROJECT, 2021
** display_win_defeat.c
** File description:
** display if we win or defeat
*/

#include <stdbool.h>
#include "my_rpg.h"
#include "structs.h"
#include <stdlib.h>

void display_victory(game_t *game)
{
    sfRenderWindow_drawSprite(game->window,
    game->scenes->fight->win_sprite->sprite, NULL);
    if (clock_time(game->scenes->fight->win_clock, 2)) {
        game->scenes->fight->victory = false;
        game->scenes->current = MAIN_GAME;
        sfClock_destroy(game->scenes->fight->win_clock);
    }
}

void display_defeat(game_t *game)
{
    sfRenderWindow_drawSprite(game->window,
    game->scenes->fight->defeat_prite->sprite, NULL);
    if (clock_time(game->scenes->fight->defeat_clock, 2)) {
        game->scenes->fight->defeat = false;
        game->scenes->current = MAIN_GAME;
        sfClock_destroy(game->scenes->fight->defeat_clock);
    }
}

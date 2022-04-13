/*
** EPITECH PROJECT, 2021
** create_map.c
** File description:
** create_map main game
*/

#include "my_rpg.h"
#include "structs.h"
#include "game.h"
#include <SFML/System/Time.h>
#include <SFML/System/Types.h>
#include <SFML/Graphics.h>

void move_up(game_t *game)
{
    if (game->player->rect->left == 0)
        return;
    if (game->player->rect->left != 0) {
        game->player->rect->left -= 74;
        sfSprite_setTextureRect(game->player->sprite, *game->player->rect);
        sfRenderWindow_drawSprite(game->window, game->player->sprite, NULL);
    }
}

void clock_player_up(sfClock *clock, game_t *game)
{
    float time_offset = 0.1;

        if (clock_time(clock, time_offset)) {
            move_up(game);
            sfClock_restart(clock);
    }
}

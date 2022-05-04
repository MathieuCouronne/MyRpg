/*
** EPITECH PROJECT, 2021
** saves.c
** File description:
** Saves scene navigation
*/

#include <SFML/Graphics.h>
#include "my_rpg.h"

static void change_player(game_t *game, sfTexture *texture)
{
    sfSprite_setTexture(game->player->sprite, texture, false);
    back_to_game(game);
}

void go_to_game_player1(game_t *game)
{
    change_player(game, game->scenes->saves->character[0]->texture);
}

void go_to_game_player2(game_t *game)
{
    change_player(game, game->scenes->saves->character[1]->texture);
}

void go_to_game_player3(game_t *game)
{
    change_player(game, game->scenes->saves->character[2]->texture);
}

void go_to_creation(game_t *game)
{
    game->scenes->prev = game->scenes->current;
    game->scenes->current = CREATION;
}

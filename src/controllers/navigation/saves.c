/*
** EPITECH PROJECT, 2021
** saves.c
** File description:
** Saves scene navigation
*/

#include <SFML/Graphics.h>
#include "my_rpg.h"

static void change_player(game_t *game, unsigned int i)
{
    character_t *character = game->saves[i];
    sfTexture *texture = game->scenes->saves->character[i]->texture;

    game->current = i;
    sfSprite_setTexture(game->player->sprite, texture, false);
    game->scenes->stats = init_stats(game);
    back_to_game(game);
    sfView_setCenter(game->view, character->camera);
    game->player->position->x = character->player.x;
    game->player->position->y = character->player.y;
    game->player->relative_pos->x = 0;
    game->player->relative_pos->y = 0;
    sfSprite_setPosition(game->player->sprite, *game->player->position);
}

void go_to_game_player1(game_t *game)
{
    change_player(game, 0);
}

void go_to_game_player2(game_t *game)
{
    change_player(game, 1);
}

void go_to_game_player3(game_t *game)
{
    change_player(game, 2);
}

void go_to_creation(game_t *game)
{
    game->scenes->prev = game->scenes->current;
    game->scenes->current = CREATION;
}

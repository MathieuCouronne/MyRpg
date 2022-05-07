/*
** EPITECH PROJECT, 2021
** saves.c
** File description:
** Saves scene navigation
*/

#include <SFML/Graphics.h>
#include "my_rpg.h"
#include "macros.h"

extern const char *class_textures[];

void put_stats(game_t *game)
{
    game->saves[game->current]->stats->strength =
    game->scenes->creation_menu->stats
    [game->scenes->creation_menu->class][0];
    game->saves[game->current]->stats->defense =
    game->scenes->creation_menu->stats
    [game->scenes->creation_menu->class][1];
    game->saves[game->current]->stats->vitality =
    game->scenes->creation_menu->stats
    [game->scenes->creation_menu->class][2];
    game->saves[game->current]->stats->speed =
    game->scenes->creation_menu->stats
    [game->scenes->creation_menu->class][3];
    game->saves[game->current]->stats->dexterity =
    game->scenes->creation_menu->stats
    [game->scenes->creation_menu->class][4];
    game->saves[game->current]->class = game->scenes->creation_menu->class;
}

void create_game(game_t *game)
{
    sfSprite_setScale(game->characters
    [game->scenes->creation_menu->class]->sprite, (sfVector2f) {1.f, 1.f});
    game->player->texture = sfTexture_createFromFile(class_textures
    [game->scenes->creation_menu->class], NULL);
    sfSprite_setTexture(game->player->sprite, game->player->texture, sfFalse);
    game->player->position->x = (float) 2270;
    game->player->position->y = (float) 2030;
    game->player->relative_pos->x = 0;
    game->player->relative_pos->y = 0;
    game->saves[game->current] = create_character();
    put_stats(game);
    game->saves[game->current]->unspent =
    game->scenes->creation_menu->unspent[game->scenes->creation_menu->class];
    game->scenes->stats = init_stats(game);
    sfView_setCenter(game->view, (sfVector2f) {2270, 2030});
    game->scenes->current = MAIN_GAME;
}

/*
** EPITECH PROJECT, 2021
** saves.c
** File description:
** Saves scene navigation
*/

#include <SFML/Graphics.h>
#include "my_rpg.h"

extern const char *class_textures[];

void create_game(game_t *game)
{
    sfSprite_setScale(game->characters
    [game->scenes->creation_menu->class]->sprite, (sfVector2f) {1.f, 1.f});
    game->player->texture = sfTexture_createFromFile(class_textures
    [game->scenes->creation_menu->class], NULL);
    sfSprite_setTexture(game->player->sprite, game->player->texture, sfFalse);
    game->stats->strength = game->scenes->creation_menu->stats
    [game->scenes->creation_menu->class][0];
    game->stats->defense = game->scenes->creation_menu->stats
    [game->scenes->creation_menu->class][1];
    game->stats->vitality = game->scenes->creation_menu->stats
    [game->scenes->creation_menu->class][2];
    game->stats->speed = game->scenes->creation_menu->stats
    [game->scenes->creation_menu->class][3];
    game->stats->dexterity = game->scenes->creation_menu->stats
    [game->scenes->creation_menu->class][4];
    game->scenes->prev = game->scenes->current;
    game->scenes->current = MAIN_GAME;
}

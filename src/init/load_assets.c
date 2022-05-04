/*
** EPITECH PROJECT, 2021
** game.c
** File description:
** Game initializer
*/

#include <stdlib.h>
#include "my_rpg.h"
#include "macros.h"

extern const char *class_textures[];

game_asset_t **init_characters()
{
    game_asset_t **characters = malloc(sizeof(game_asset_t *) * 4);

    for (size_t i = 0; i < 3; i++) {
        characters[i] = malloc(sizeof(game_asset_t));
        characters[i]->sprite = sfSprite_create();
        characters[i]->rect = rect_player();
        characters[i]->texture = sfTexture_createFromFile(class_textures[i], characters[i]->rect);
        sfSprite_setTexture(characters[i]->sprite, characters[i]->texture, sfTrue);
        sfSprite_setTextureRect(characters[i]->sprite, *characters[i]->rect);
    }
    characters[3] = NULL;
    return characters;
}

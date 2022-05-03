/*
** EPITECH PROJECT, 2021
** init_menu_button.c
** File description:
** init menu button
*/

#include <stdlib.h>
#include <SFML/Window.h>
#include "structs.h"
#include "my_rpg.h"
#include "macros.h"

extern const char *class_textures[];

size_t count_saves(character_t **saves)
{
    size_t n = 0;

    for (size_t i = 0; i < 3; i++) {
        if (!saves[i])
            continue;
        n++;
    }
    return n;
}

game_asset_t **init_character(character_t **saves)
{
    game_asset_t **character = malloc(sizeof(game_asset_t *) *
    (count_saves(saves) + 1));
    sfFloatRect rect;

    for (size_t i = 0; i < 3; i++) {
        if (!saves[i])
            continue;
        character[i] = malloc(sizeof(game_asset_t));
        character[i]->rect = rect_player();
        character[i]->sprite = sfSprite_create();
        character[i]->texture = sfTexture_createFromFile
        (class_textures[saves[i]->class], NULL);
        sfSprite_setTexture(character[i]->sprite, character[i]->texture, sfTrue);
        sfSprite_setTextureRect(character[i]->sprite, *character[i]->rect);
        sfSprite_setScale(character[i]->sprite, (sfVector2f) {5.f, 5.f});
        rect = sfSprite_getGlobalBounds(character[i]->sprite);
        character[i]->pos.y = WINDOW_HEIGHT / 2 - rect.height + 100;
    }
    character[count_saves(saves)] = NULL;
    return character;
}

void set_pos_character(game_asset_t **character)
{
    sfFloatRect rect;

    if (character[0] != NULL) {
        rect = sfSprite_getGlobalBounds(character[0]->sprite);
        sfSprite_setPosition(character[0]->sprite, (sfVector2f)
        {WINDOW_WIDTH/ 5 - rect.height / 2 + 30, character[0]->pos.y});
    }
    if (character[1] != NULL) {
        rect = sfSprite_getGlobalBounds(character[1]->sprite);
        sfSprite_setPosition(character[1]->sprite, (sfVector2f)
        {WINDOW_WIDTH/ 2 - rect.height / 2 + 30, character[1]->pos.y});
    }
    if (character[1] != NULL && character[2] != NULL) {
        rect = sfSprite_getGlobalBounds(character[2]->sprite);
        sfSprite_setPosition(character[2]->sprite, (sfVector2f)
        {WINDOW_WIDTH/ 1.25 - rect.height / 2 + 30, character[2]->pos.y});
    }
}

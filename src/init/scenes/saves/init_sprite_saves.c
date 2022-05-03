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

static void position_character_asset(game_asset_t *character, float shift)
{
    sfFloatRect rect = {0};
    sfVector2f pos = {0, 0};

    sfSprite_setScale(character->sprite, (sfVector2f) {5.f, 5.f});
    sfSprite_setTexture(character->sprite, character->texture, sfTrue);
    sfSprite_setTextureRect(character->sprite, *character->rect);
    rect = sfSprite_getGlobalBounds(character->sprite);
    pos.x = WINDOW_WIDTH / shift - rect.height / 2 + 30;
    pos.y = (float) WINDOW_HEIGHT / 2 - rect.height + 120;
    sfSprite_setPosition(character->sprite, pos);
}

game_asset_t **init_character(character_t **saves)
{
    game_asset_t **character = malloc(sizeof(game_asset_t *) * 4);
    float shifts[3] = {5, 2, 1.25f};
    char *path = NULL;

    for (size_t i = 0; i < 3; i++) {
        if (!saves[i]) {
            character[i] = NULL;
            continue;
        }
        path = (char *) class_textures[saves[i]->class];
        character[i] = malloc(sizeof(game_asset_t));
        character[i]->rect = rect_player();
        character[i]->sprite = sfSprite_create();
        character[i]->texture = sfTexture_createFromFile(path, NULL);
        position_character_asset(character[i], shifts[i]);
    }
    character[3] = NULL;
    return character;
}

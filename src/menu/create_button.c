/*
** EPITECH PROJECT, 2021
** game.c
** File description:
** Game initializer
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include "menu.h"
#include "structs.h"
#include "macros.h"

sfVector2f center_text(float x, float y, sfText *text, sfVector2f pos_sprite)
{
    sfVector2f pos;
    sfFloatRect rect = sfText_getGlobalBounds(text);

    pos.x = (x / 2) + pos_sprite.x - (rect.width / 2);
    pos.y = pos_sprite.y + (y / 2) - 40;
    return pos;
}

button_t *create_button(char *str, sfVector2f pos_sprite, void (*fn) (game_t *game))
{
    button_t *button = malloc(sizeof(button_t));
    sfVector2f pos = {pos_sprite.x, pos_sprite.y};

    button->asset = malloc(sizeof(game_asset_t));
    button->font = sfFont_createFromFile("./font/LifeCraft_Font.ttf");
    button->text = sfText_create();
    button->asset->sprite = sfSprite_create();
    button->asset->texture = sfTexture_createFromFile(BUTTON_SPRITE_PATH, NULL);
    sfSprite_setTexture(button->asset->sprite, button->asset->texture, sfTrue);
    sfSprite_setPosition(button->asset->sprite, button->asset->pos);
    sfText_setFont(button->text, button->font);
    sfText_setString(button->text, str);
    sfText_setCharacterSize(button->text, 60);
    sfText_setColor(button->text, sfBlack);
    pos = center_text(350, 140, button->text, pos_sprite);
    sfText_setPosition(button->text, pos);
    return button;
}

/*
** EPITECH PROJECT, 2021
** create_button.c
** File description:
** Create buttons for menu
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
    pos.y = pos_sprite.y + (y / 2) - (rect.height / 2 + 10);
    return pos;
}

void init_text_butt(button_t *button, char *str)
{
    sfText_setFont(button->text, button->font);
    sfText_setString(button->text, str);
    sfText_setCharacterSize(button->text, 40);
    sfText_setColor(button->text, sfBlack);
}

static void set_button_infos(button_t *button, sfVector2f pos_sprite,
    char *str, sfVector2f scale)
{
    sfVector2f pos = {pos_sprite.x, pos_sprite.y};
    sfFloatRect rect_button;

    sfSprite_setScale(button->asset->sprite, scale);
    sfSprite_setTexture(button->asset->sprite, button->asset->texture, sfTrue);
    sfSprite_setPosition(button->asset->sprite, pos);
    init_text_butt(button, str);
    rect_button = sfSprite_getGlobalBounds(button->asset->sprite);
    pos = center_text(rect_button.width, rect_button.height,
        button->text, pos_sprite);
    sfText_setPosition(button->text, pos);
}

button_t *create_button(char *str, sfVector2f pos_sprite,
void (*on_click) (game_t *game), sfVector2f scale)
{
    button_t *button = malloc(sizeof(button_t));

    if (!button)
        return NULL;
    button->asset = malloc(sizeof(game_asset_t));
    button->font = sfFont_createFromFile(ARIAL_FONT_PATH);
    button->on_click = on_click;
    button->hover = false;
    button->text = sfText_create();
    if (!button->asset)
        return NULL;
    button->asset->sprite = sfSprite_create();
    button->asset->texture = sfTexture_createFromFile(BUTTON_PATH, NULL);
    if (!button->font || !button->text ||
        !button->asset->sprite || !button->asset->texture)
        return NULL;
    set_button_infos(button, pos_sprite, str, scale);
    return button;
}

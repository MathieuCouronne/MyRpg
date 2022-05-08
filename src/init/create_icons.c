/*
** EPITECH PROJECT, 2021
** create_icons.c
** File description:
** Create icons and save card
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdlib.h>
#include "menu.h"
#include "structs.h"
#include "my_rpg.h"
#include "macros.h"

sfText *create_pseudo_txt(game_t *game, unsigned int i, button_t *butt)
{
    sfText *text = sfText_create();

    sfText_setString(text, game->saves[i]->name);
    sfText_setCharacterSize(text, 20);
    sfText_setColor(text, sfWhite);
    sfText_setPosition(text, (sfVector2f) {butt->asset->pos.x,
        butt->asset->pos.y});
    sfText_setFont(text,butt->font);
    return text;
}

button_t *create_icon(sfVector2f pos_sprite, char *path,
void (*on_click) (game_t *game))
{
    button_t *button = malloc(sizeof(button_t));

    if (!button)
        return NULL;
    button->asset = malloc(sizeof(game_asset_t));
    button->text = sfText_create();
    if (!button->asset || !button->text)
        return NULL;
    button->asset->sprite = sfSprite_create();
    button->asset->texture = sfTexture_createFromFile(path, NULL);
    if (!button->asset->sprite || !button->asset->texture)
        return NULL;
    button->on_click = on_click;
    button->hover = false;
    button->select = false;
    sfSprite_setTexture(button->asset->sprite, button->asset->texture, sfTrue);
    sfSprite_setPosition(button->asset->sprite, pos_sprite);
    return button;
}

button_t *create_save_card(sfVector2f pos_sprite, char *path,
void (*on_click) (game_t *game))
{
    button_t *button = malloc(sizeof(button_t));
    sfVector2f pos = {pos_sprite.x, pos_sprite.y};

    if (!button)
        return NULL;
    button->asset = malloc(sizeof(game_asset_t));
    button->text = sfText_create();
    button->font = sfFont_createFromFile(ARIAL_FONT_PATH);
    if (!button->asset)
        return NULL;
    button->asset->sprite = sfSprite_create();
    button->asset->texture = sfTexture_createFromFile(path, NULL);
    if (!button->asset->sprite || !button->asset->texture)
        return NULL;
    button->asset->pos = pos;
    button->on_click = on_click;
    button->hover = false;
    sfSprite_setTexture(button->asset->sprite, button->asset->texture, sfTrue);
    sfSprite_setPosition(button->asset->sprite, pos_sprite);
    return button;
}

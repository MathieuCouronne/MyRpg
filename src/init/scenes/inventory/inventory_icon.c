/*
** EPITECH PROJECT, 2021
** inventory_icon.c
** File description:
** init_icon_inventory
*/

#include <SFML/Audio.h>
#include <stdlib.h>
#include "structs.h"
#include "menu.h"
#include "my_rpg.h"
#include "macros.h"

extern const char *items_textures[];

static sfIntRect *rect_chest(void)
{
    sfIntRect *rect = malloc(sizeof(sfIntRect));

    if (!rect)
        return NULL;
    rect->top = 0;
    rect->left = 0;
    rect->width = 56;
    rect->height = 56;
    return rect;
}

game_asset_t **init_inventory_items(void)
{
    game_asset_t **inventory = malloc(sizeof(game_asset_t *) * 4);

    if (!inventory)
        return NULL;
    for (size_t i = 0; i < 3; i++) {
        inventory[i] = malloc(sizeof(game_asset_t));
        inventory[i]->sprite = sfSprite_create();
        inventory[i]->rect = rect_chest();
        inventory[i]->texture = sfTexture_createFromFile(items_textures[i],
            NULL);
        if (!inventory[i]->sprite || !inventory[i]->rect ||
            !inventory[i]->texture)
            return NULL;
        sfSprite_setTexture(inventory[i]->sprite, inventory[i]->texture,
            sfTrue);
        sfSprite_setTextureRect(inventory[i]->sprite, *inventory[i]->rect);
    }
    inventory[3] = NULL;
    return inventory;
}

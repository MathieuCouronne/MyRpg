/*
** EPITECH PROJECT, 2021
** inventory.c
** File description:
** init_inventory
*/

#include <SFML/Audio.h>
#include <stdlib.h>
#include "structs.h"
#include "menu.h"
#include "my_rpg.h"
#include "macros.h"

game_asset_t *init_inventory_background(void)
{
    game_asset_t *background = malloc(sizeof(game_asset_t));

    if (!background)
        return NULL;
    background->sprite = sfSprite_create();
    background->texture = sfTexture_createFromFile(INVENTORY_PATH, NULL);
    sfSprite_setTexture(background->sprite, background->texture, sfTrue);
    return background;
}

inventory_sprite_t *init_inventory(void)
{
    inventory_sprite_t *scene = malloc(sizeof(inventory_sprite_t));

    if (!scene)
        return NULL;
    scene->background = init_inventory_background();
    scene->pos.x = 650;
    scene->pos.y = 330;
    scene->buttons = NULL;
    sfSprite_setPosition(scene->background->sprite, scene->pos);
    return scene;
}

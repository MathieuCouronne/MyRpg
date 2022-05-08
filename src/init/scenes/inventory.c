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

inventory_sprite_t *init_inventory(void)
{
    inventory_sprite_t *scene = malloc(sizeof(inventory_sprite_t));

    if (!scene)
        return NULL;
    scene->background = init_inventory_background();
    if (!scene->background)
        return NULL;
    scene->pos.x = 650;
    scene->pos.y = 330;
    scene->buttons = NULL;
    scene->loot = init_inventory_sprite();
    sfSprite_setPosition(scene->background->sprite, scene->pos);
    return scene;
}

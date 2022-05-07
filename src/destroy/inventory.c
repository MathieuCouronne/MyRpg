/*
** EPITECH PROJECT, 2021
** inventory.c
** File description:
** Inventory destroyer
*/

#include <stdlib.h>
#include "my_rpg.h"
#include "menu.h"
#include <SFML/Audio.h>

void destroy_inventory(inventory_sprite_t *inventory)
{
    if (!inventory)
        return;
    sfSprite_destroy(inventory->background->sprite);
    sfTexture_destroy(inventory->background->texture);
    free(inventory);
}

/*
** EPITECH PROJECT, 2021
** my_rpg.h
** File description:
** my_rpg header file
*/

#include <SFML/Audio.h>
#include <stdlib.h>
#include "structs.h"
#include "menu.h"
#include "my_rpg.h"
#include "inventory.h"

static slot_t **fill_inventory(void)
{
    slot_t ***content = malloc(sizeof(slot_t *) * (INVENTORY_HEIGHT + 1));

    content[INVENTORY_HEIGHT] = NULL;
    for (unsigned int i = 0; i < INVENTORY_HEIGHT; i++) {
        content[i] = malloc(sizeof(slot_t) * (INVENTORY_WIDTH + 1));
        content[i][INVENTORY_WIDTH] = NULL;
    }
}

inventory_t *create_inventory(void)
{
    inventory_t *inventory = malloc(sizeof(inventory_t));

    inventory->height = INVENTORY_HEIGHT;
    inventory->width = INVENTORY_WIDTH;
    inventory->content = fill_inventory();
    return inventory;
}
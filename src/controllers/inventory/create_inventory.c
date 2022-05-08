/*
** EPITECH PROJECT, 2021
** create_inventory.c
** File description:
** Create an inventory
*/

#include "structs.h"
#include "my_rpg.h"
#include "inventory.h"

static slot_t **fill_slot(slot_t **content, unsigned int width, unsigned int y)
{
    for (unsigned int x = 0; x < width; x++) {
        content[x] = malloc(sizeof(slot_t));
        if (!content[x])
            return NULL;
        content[x]->id = EMPTY;
        content[x]->pos.x = x;
        content[x]->pos.y = y;
        content[x]->quantity = 0;
    }
    return content;
}

static slot_t ***fill_inventory(unsigned int width, unsigned int height)
{
    slot_t ***content = malloc(sizeof(slot_t **) * (height + 1));

    if (!content)
        return NULL;
    content[height] = NULL;
    for (unsigned int y = 0; y < height; y++) {
        content[y] = malloc(sizeof(slot_t *) * (width + 1));
        if (!content[y])
            return NULL;
        content[y][width] = NULL;
        content[y] = fill_slot(content[y], width, y);
        if (!content[y])
            return NULL;
    }
    return content;
}

inventory_t *create_inventory(unsigned int width, unsigned int height)
{
    inventory_t *inventory = malloc(sizeof(inventory_t));

    if (!inventory)
        return NULL;
    inventory->height = height;
    inventory->width = width;
    inventory->content = fill_inventory(width, height);
    if (!inventory->content)
        return NULL;
    return inventory;
}

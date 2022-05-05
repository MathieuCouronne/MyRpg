/*
** EPITECH PROJECT, 2021
** my_rpg.h
** File description:
** my_rpg header file
*/

#include <stdio.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include "structs.h"
#include "menu.h"
#include "my_rpg.h"
#include "inventory.h"

static slot_t **fill_slot(slot_t **content, unsigned int width, unsigned int y)
{
    for (unsigned int x = 0; x < width; x++) {
        content[x] = malloc(sizeof(slot_t));
        if (!content[x])
            return NULL;
        content[x]->id = 0;
        content[x]->pos.x = x;
        content[x]->pos.y = y;
        content[x]->quantity = 0;
    }
    return content;
}

static slot_t ***fill_inventory(unsigned int height, unsigned int width)
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

inventory_t *create_inventory(unsigned int height, unsigned int width)
{
    inventory_t *inventory = malloc(sizeof(inventory_t));

    if (!inventory)
        return NULL;
    inventory->height = height;
    inventory->width = width;
    inventory->content = fill_inventory(height, width);
    if (!inventory->content)
        return NULL;
    return inventory;
}

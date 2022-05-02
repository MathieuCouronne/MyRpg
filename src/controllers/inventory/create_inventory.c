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

static slot_t ***fill_inventory(unsigned int height, unsigned int width)
{
    slot_t ***content = malloc(sizeof(slot_t **) * (height + 1));

    content[height] = NULL;
    for (unsigned int y = 0; y < height; y++) {
        content[y] = malloc(sizeof(slot_t *) * (width + 1));
        content[y][width] = NULL;
        for (unsigned int x = 0; x < width; x++) {
            content[y][x] = malloc(sizeof(slot_t));
            content[y][x]->id = 0;
            content[y][x]->pos.x = x;
            content[y][x]->pos.y = y;
            content[y][x]->quantity = 0;
        }
    }
    return content;
}

inventory_t *create_inventory(unsigned int height, unsigned int width)
{
    inventory_t *inventory = malloc(sizeof(inventory_t));

    inventory->height = height;
    inventory->width = width;
    inventory->content = fill_inventory(height, width);
    return inventory;
}

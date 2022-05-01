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
    for (unsigned int i = 0; i < height; i++) {
        content[i] = malloc(sizeof(slot_t *) * (width + 1));
        content[i][width] = NULL;
        for (unsigned int j = 0; j < width; j++) {
            content[i][j] = malloc(sizeof(slot_t));
            content[i][j]->name = "empty";
            content[i][j]->pos.x = i;
            content[i][j]->pos.y = j;
            content[i][j]->quantity = 0;
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

/*
** EPITECH PROJECT, 2022
** save_inventory.c
** File description:
** Save character inventory into the config file
*/

#include "my_rpg.h"
#include "my.h"

static void save_slot(FILE *file, slot_t *slot)
{
    char *id = NULL;
    char *quantity = NULL;
    char *x = NULL;
    char *y = NULL;

    if (slot->id == -1)
        return;
    id = itoa(slot->id);
    quantity = itoa(slot->quantity);
    x = itoa(slot->pos.x);
    y = itoa(slot->pos.y);
    fwrite(id, my_strlen(id), 1, file);
    fwrite(" ", 1, 1, file);
    fwrite(quantity, my_strlen(quantity), 1, file);
    fwrite(" ", 1, 1, file);
    fwrite(x, my_strlen(x), 1, file);
    fwrite(" ", 1, 1, file);
    fwrite(y, my_strlen(y), 1, file);
    fwrite("\n", 1, 1, file);
}

void save_characters_inventory(FILE *file, character_t *character)
{
    inventory_t *inventory = character->inventory;

    if (!inventory)
        return;
    for (unsigned int y = 0; y < inventory->height; y++) {
        for (unsigned int x = 0; x < inventory->width; x++) {
            save_slot(file, inventory->content[y][x]);
        }
    }
}

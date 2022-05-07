/*
** EPITECH PROJECT, 2021
** is_slot_in_inventory.c
** File description:
** Check if the inventory contains the given slot
*/

#include <stdbool.h>
#include "my_rpg.h"

static bool is_slot_in_line(slot_t **line, slot_t *slot)
{
    for (unsigned int i = 0; line[i]; i++) {
        if (line[i]->id == slot->id && line[i]->quantity == slot->quantity)
            return true;
    }
    return false;
}

bool is_slot_in_inventory(inventory_t *inventory, slot_t *slot)
{
    for (unsigned int i = 0; inventory->content[i]; i++) {
        if (is_slot_in_line(inventory->content[i], slot))
            return true;
    }
    return false;
}

bool is_quest_valid(inventory_t *inventory, slot_t **slot)
{
    for (unsigned int i = 0; slot[i]; i++) {
        if (!is_slot_in_inventory(inventory, slot[i]))
            return false;
    }
    return true;
}

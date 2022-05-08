/*
** EPITECH PROJECT, 2021
** remove_from_inventory.c
** File description:
** Remove items from inventory
*/

#include "structs.h"
#include "menu.h"
#include "my_rpg.h"
#include "inventory.h"

static void remove_slot(slot_t **content, unsigned int id, unsigned int x,
    unsigned int quantity)
{
    unsigned int i = 0;

    for (; content[i]->id != (int) id; i++);
    if (quantity > content[i]->quantity)
        return;
    content[i]->quantity -= quantity;
    if (content[i]->quantity == 0)
        content[i]->id = -1;
    content[i]->pos.x = x;
    content[i]->pos.y = i;
}

static bool is_slot_here(slot_t **content, unsigned int id)
{
    for (unsigned int i = 0; content[i]; i++) {
        if (content[i]->id == (int) id)
            return true;
    }
    return false;
}

inventory_t *remove_from_inventory(inventory_t *inventory, unsigned int id,
unsigned int quantity)
{
    for (unsigned int i = 0; inventory->content[i]; i++) {
        if (is_slot_here(inventory->content[i], id))
            remove_slot(inventory->content[i], id, i, quantity);
    }
    return inventory;
}

/*
** EPITECH PROJECT, 2021
** add_to_inventory.h
** File description:
** Function to add items to inventory
*/

#include "structs.h"
#include "menu.h"
#include "my_rpg.h"
#include "inventory.h"

static void add_to_empty_slot(slot_t **content, unsigned int id,
unsigned int quantity, unsigned int x)
{
    unsigned int i = 0;

    for (; content[i]->id != EMPTY && i < INVENTORY_WIDTH; i++);
    content[i]->id = (int) id;
    content[i]->quantity = quantity;
    content[i]->pos.x = x;
    content[i]->pos.y = i;
}

static bool line_is_full(slot_t **content)
{
    for (unsigned int i = 0; content[i]; i++) {
        if (content[i]->id == EMPTY)
            return false;
    }
    return true;
}

static bool item_found(slot_t **content, unsigned int id)
{
    for (unsigned int i = 0; content[i]; i++) {
        if (content[i]->id == (int) id)
            return true;
    }
    return false;
}

static void add_quantity(slot_t **content, unsigned int id,
unsigned int quantity)
{
    unsigned int i = 0;

    for (; content[i]->id != (int) id; i++);
    content[i]->quantity += quantity;
}

inventory_t *add_to_inventory(inventory_t *inventory, unsigned int id,
unsigned int quantity)
{
    for (unsigned int i = 0; inventory->content[i]; i++) {
        if (item_found(inventory->content[i], id)) {
            add_quantity(inventory->content[i], id, quantity);
            return inventory;
        }
    }
    for (unsigned int i = 0; inventory->content[i]; i++) {
        if (!line_is_full(inventory->content[i])) {
            add_to_empty_slot(inventory->content[i], id, quantity, i);
            return inventory;
        }
    }
    return inventory;
}

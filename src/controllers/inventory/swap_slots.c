/*
** EPITECH PROJECT, 2021
** swap_slots.h
** File description:
** Swap inventory
*/

#include "structs.h"

inventory_t *swap_slots(inventory_t *inventory, sfVector2u pos1,
sfVector2u pos2)
{
    slot_t *tmp = inventory->content[pos1.x][pos1.y];

    inventory->content[pos1.x][pos1.y] = inventory->content[pos2.x][pos2.y];
    inventory->content[pos2.x][pos2.y] = tmp;
    free(tmp);
    return inventory;
}

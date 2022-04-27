/*
** EPITECH PROJECT, 2021
** my_rpg.h
** File description:
** my_rpg header file
*/

#include <stdio.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include "my.h"
#include "structs.h"
#include "menu.h"
#include "my_rpg.h"
#include "inventory.h"

static void remove_slot(slot_t **content, char const *name, unsigned int x)
{
    unsigned int i = 0;

    for (; my_strcmp(content[i]->name, name) != 0; i++);
    content[i]->name = "empty";
    content[i]->quantity = 0;
    content[i]->pos.x = x;
    content[i]->pos.y = i;
}

static bool is_slot_here(slot_t **content, char const *name)
{
    for (unsigned int i = 0; content[i]; i++) {
        if (content[i]->name == name)
            return true;
    }
    return false;
}

inventory_t *remove_from_inventory(inventory_t *inventory, char const *name)
{
    for (unsigned int i = 0; inventory->content[i]; i++) {
        if (is_slot_here(inventory->content[i], name))
            remove_slot(inventory->content[i], name, i);
    }
    return inventory;
}

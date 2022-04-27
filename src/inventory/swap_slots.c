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

inventory_t *swap_slots(inventory_t *inventory, sfVector2u pos1,
    sfVector2u pos2)
{
    slot_t *tmp = malloc(sizeof(slot_t *));

    tmp = inventory->content[pos1.x][pos1.y];
    inventory->content[pos1.x][pos1.y] = inventory->content[pos2.x][pos2.y];
    inventory->content[pos2.x][pos2.y] = tmp;
    return inventory;
}
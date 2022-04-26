/*
** EPITECH PROJECT, 2021
** structs.h
** File description:
** my_rpg structs header file
*/

#include <SFML/Graphics.h>

#define INVENTORY_HEIGHT 4
#define INVENTORY_WIDTH 9

#ifndef INVENTORY_H_
    #define INVENTORY_H_

typedef struct slot_s {
    char *name;
    sfVector2f pos;
    unsigned int quantity;
} slot_t;

typedef struct inventory_s {
    unsigned int height;
    unsigned int width;
    slot_t ***content;
} inventory_t;

#endif

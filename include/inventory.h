/*
** EPITECH PROJECT, 2021
** structs.h
** File description:
** my_rpg structs header file
*/

#include <SFML/Graphics.h>

#ifndef INVENTORY_H_
    #define INVENTORY_H_

    #define INVENTORY_WIDTH 9
    #define INVENTORY_HEIGHT 4

typedef struct slot_s {
    int id;
    sfVector2u pos;
    unsigned int quantity;
} slot_t;

typedef struct inventory_s {
    unsigned int height;
    unsigned int width;
    slot_t ***content;
} inventory_t;

#endif

/*
** EPITECH PROJECT, 2021
** structs.h
** File description:
** my_rpg structs header file
*/

#include <SFML/Graphics.h>

#ifndef STRUCTS_H_
    #define STRUCTS_H_

typedef struct scenes_s {

} scenes_t;

typedef struct game_s {
    sfRenderWindow *window;
    scenes_t *scenes;
} game_t;

#endif

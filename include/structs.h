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
    sfView *view;
    scenes_t *scenes;
} game_t;

typedef struct event_controller_s {
    sfEventType type;
    void (*fn) (game_t *game, sfEvent *event);
} event_controller_t;

#endif

/*
** EPITECH PROJECT, 2021
** structs.h
** File description:
** my_rpg structs header file
*/

#include <SFML/Graphics.h>

#ifndef STRUCTS_H_
    #define STRUCTS_H_

typedef struct game_s {
    sfRenderWindow *window;
    sfView *view;
    struct scenes_s *scenes;
} game_t;

typedef struct scenes_s {
    void (*main_menu) (game_t *game);
    // TODO: add buttons
} scenes_t;

typedef struct event_controller_s {
    sfEventType type;
    void (*fn) (game_t *game, sfEvent *event);
} event_controller_t;

#endif

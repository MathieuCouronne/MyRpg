/*
** EPITECH PROJECT, 2021
** structs.h
** File description:
** my_rpg structs header file
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>

#ifndef STRUCTS_H_
    #define STRUCTS_H_

typedef struct scenes_s {

} scenes_t;

typedef struct game_s {
    sfRenderWindow *window;
    sfView *view;
    scenes_t *scenes;
} game_t;

typedef struct game_asset_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfRectangleShape *rect;
    sfVector2f pos;
    float scaling;
} game_asset_t;

typedef struct event_controller_s {
    sfEventType type;
    void (*fn) (game_t *game, sfEvent *event);
} event_controller_t;

#endif

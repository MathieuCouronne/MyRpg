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

typedef struct game_s {
    sfRenderWindow *window;
    sfView *view;
    struct scenes_s *scenes;
} game_t;

typedef struct scenes_s {
    void (*main_menu) (game_t *game);
    // TODO: add buttons
} scenes_t;

typedef struct main_menu_scenes_s {
    void (*main_menu) (game_t *game);
} main_menu_scenes_t;

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

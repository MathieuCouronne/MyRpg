/*
** EPITECH PROJECT, 2021
** structs.h
** File description:
** my_rpg structs header file
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include "menu.h"
#include "idk.h"

#ifndef STRUCTS_H_
    #define STRUCTS_H_

typedef struct main_game_s {
    game_asset_t *map;
} main_game_t;

typedef struct main_menu_scenes_s {
    game_asset_t *background;
    menu_buttons_t *buttons;
} main_menu_scenes_t;

typedef struct scenes_s {
    main_menu_scenes_t *main_menu;
    main_game_t *game_scene;
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

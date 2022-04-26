/*
** EPITECH PROJECT, 2021
** menu.h
** File description:
** my_rpg menu header file
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include "idk.h"
#include "enum.h"
#include <stdbool.h>

#ifndef RPG_MENU_H
    #define RPG_MENU_H

typedef struct button_s {
    game_asset_t *asset;
    sfText *text;
    button_state state;
    sfFont *font;
} button_t;

typedef struct menu_buttons_s {
    button_t *play;
    button_t *settings;
    button_t *title;
    button_t *quit;
} menu_buttons_t;

typedef struct main_menu_scenes_s {
    game_asset_t *background;
    menu_buttons_t *buttons;
} main_menu_scenes_t;

#endif //RPG_MENU_H

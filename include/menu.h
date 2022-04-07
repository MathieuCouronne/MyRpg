/*
** EPITECH PROJECT, 2021
** menu.h
** File description:
** my_rpg menu header file
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include "structs.h"
#include "enum.h"

#ifndef RPG_MENU_H
    #define RPG_MENU_H

typedef struct button_s {
    game_asset_t *asset;
    sfText *text;
    button_state state;
    sfFont *font;
} button_t;

typedef struct buttons_s {
    button_t *play;
}buttons_t;

game_asset_t *init_menu_background(void);
buttons_t *init_buttons(void);

#endif //RPG_MENU_H

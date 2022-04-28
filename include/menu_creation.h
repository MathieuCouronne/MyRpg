/*
** EPITECH PROJECT, 2021
** macros.h
** File description:
** my_rpg macros header file
*/

#include "game.h"
#include "idk.h"
#include "enum.h"
#include "menu.h"

#ifndef RPG_MENU_CREATION_H
    #define RPG_MENU_CREATION_H

typedef struct menu_creation_s {
    button_t *confirm;
} menu_creation_t;

typedef struct main_creation_scenes_s {
    game_asset_t *background;
    menu_creation_t *buttons;
} main_creation_scenes_t;

#endif //RPG_MENU_CREATION_H

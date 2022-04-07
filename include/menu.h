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
    sfText text;
    button_state state;
} button_t;

#endif //RPG_MENU_H

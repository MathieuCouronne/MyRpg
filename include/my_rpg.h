/*
** EPITECH PROJECT, 2021
** my_rpg.h
** File description:
** my_rpg header file
*/

#include "structs.h"
#include "menu.h"

#ifndef MY_RPG_H_
    #define MY_RPG_H_

// Initialization
game_t *init_game(void);

// Destroy
void destroy_game(game_t *game);
void destroy_menu(game_asset_t *menu);
void destroy_button(button_t *button);
void destroy_buttons(buttons_t *button);

// Events
void handle_events(game_t *game, sfEvent *event);
void handle_arrow_keys(game_t *game, sfEvent *event);
void handle_mouse_wheel(game_t *game, sfEvent *event);

#endif

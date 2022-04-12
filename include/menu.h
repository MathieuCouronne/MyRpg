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

game_asset_t *init_menu_background(void);
menu_buttons_t *init_buttons(void);
button_t *create_button(char *str, sfVector2f pos_sprite);
sfVector2f center_text(float x, float y, sfText *text, sfVector2f pos_sprite);
bool click_play_menu(button_t *button, sfEvent event);
void handle_menu_events(menu_buttons_t *buttons, sfEvent event);
button_t *title_menu(char *str);

#endif //RPG_MENU_H

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
game_asset_t *init_hp_bar(void);

// Destroy
void destroy_game(game_t *game);
void destroy_menu(game_asset_t *menu);
void menu_destroy_buttons(menu_buttons_t *button);
void destroy_player(player_t *player);
void destroy_ennemy(enemy_t *ennemy);
void destroy_fight(fight_t *fight);

// Events
void handle_events(game_t *game, sfEvent *event);
void handle_arrow_keys(game_t *game, sfEvent *event);
void handle_mouse_wheel(game_t *game, sfEvent *event);

//sounds
sound_t *menu_music();
void destroy_sound(sound_t *music);

#endif

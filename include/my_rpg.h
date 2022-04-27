/*
** EPITECH PROJECT, 2021
** my_rpg.h
** File description:
** my_rpg header file
*/

#include "structs.h"
#include "menu.h"
#include "inventory.h"

#ifndef MY_RPG_H_
    #define MY_RPG_H_

// Initialization
game_t *init_game(void);
game_asset_t *init_hp_bar(void);
game_asset_t *init_menu_background(void);
menu_buttons_t *init_buttons(void);
fight_t *init_fight(void);
enemy_t *init_ogre(void);
player_t *character_sprite(void);
button_t *create_button(char *str, sfVector2f pos_sprite);
int clock_time(sfClock *clock, float time_offset);
button_t *title_menu(char *str);
main_menu_scenes_t *init_main_menu(void);
main_game_t *init_main_game(game_t *game);
text_t *init_text(char *str);

// Destroy
void destroy_game(game_t *game);
void destroy_menu(game_asset_t *menu);
void menu_destroy_buttons(menu_buttons_t *button);
void destroy_player(player_t *player);
void destroy_enemy(enemy_t *enemy);
void destroy_fight(fight_t *fight);
void destroy_all(game_t *game);
void destroy_map(main_game_t *map);

// Events
void handle_arrow_keys(game_t *game);
void handle_events(game_t *game, sfEvent *event);
void handle_mouse_wheel(game_t *game, sfEvent *event);
void handle_menu_events(menu_buttons_t *buttons, sfEvent event);
bool click_play_menu(button_t *button, sfEvent event);

//sounds
sound_t *menu_music();
void destroy_sound(sound_t *music);

//display
bool display_main_menu(game_t *game);
bool display_fight(game_t *game);
bool display_main_game(game_t *game);

//movement
void clock_player_down(sfClock *clock, game_t *game);
void clock_player_up(sfClock *clock, game_t *game);
void clock_player_right(sfClock *clock, game_t *game);

//inventory
inventory_t *create_inventory(void);
inventory_t *add_to_inventory(inventory_t *inventory, char const *name,
    unsigned int quantity);
inventory_t *remove_from_inventory(inventory_t *inventory, char const *name);
inventory_t *swap_slots(inventory_t *inventory, sfVector2u pos1,
    sfVector2u pos2);

//fight
char *string_info(fight_t *fight);
char *string_info_enemy(fight_t *fight);

#endif

/*
** EPITECH PROJECT, 2021
** my_rpg.h
** File description:
** my_rpg header file
*/

#include "structs.h"
#include "menu.h"
#include "inventory.h"
#include "character.h"

#ifndef MY_RPG_H_
    #define MY_RPG_H_

void my_printf(char *str, ...);

// Initialization
game_t *init_game(void);
game_asset_t *init_hp_bar(void);
game_asset_t *init_menu_background(void);
button_t **init_buttons(void);
fight_t *init_fight(void);
enemy_t *init_ogre(void);
player_t *init_player(void);
chest_t *chest_sprite(void);
button_t *create_button(char *str, sfVector2f pos_sprite,
void (*on_click) (game_t *game), sfVector2f scale);
int clock_time(sfClock *clock, float time_offset);
button_t *title_menu(char *str);
main_menu_scenes_t *init_main_menu(void);
main_game_t *init_main_game(game_t *game);
text_t *init_text(char *str);
bool download_assets(void);
char **read_file(char const *filename);
bool write_file(char const *filename, config_t *config);
config_t *parse_config(void);
settings_t *init_settings(void);
button_t *create_icon(sfVector2f pos_sprite, char *path,
void (*on_click) (game_t *game));
int chest(game_t *game);
pause_t *init_pause(game_t *game);
scene_saves_t *init_saves(game_t *game);
button_t *create_save_card(sfVector2f pos_sprite, char *path,
void (*on_click) (game_t *game));
npc_t *init_albert(void);
npc_t *init_chief(void);
config_t *init_config(void);
game_asset_t **init_character(character_t **saves);
button_t **init_slots(game_t *game);
sfIntRect *rect_player(void);
main_creation_scenes_t *init_creation(void);
button_t **init_buttons_creation();
inventory_sprite_t *init_inventory(void);
bool display_inventory(game_t *game);

// Destroy
void destroy_game(game_t *game);
void destroy_menu(game_asset_t *menu);
void menu_destroy_buttons(button_t **button);
void destroy_player(player_t *player);
void destroy_fight(fight_t *fight);
void destroy_all(game_t *game);
void destroy_map(main_game_t *map);
void destroy_chest(chest_t *chest);
void destroy_settings(game_asset_t *settings);
void settings_destroy_icons(button_t **buttons);
void settings_destroy_buttons(button_t **buttons);
void destroy_inventory(inventory_sprite_t *inventory);

// Events
void default_event_handling(game_t *game, button_t **buttons);
void handle_arrow_keys(game_t *game);
void handle_events(game_t *game, sfEvent *event);
void handle_mouse_wheel(game_t *game, sfEvent *event);
bool handle_buttons_clicks(game_t *game, button_t **buttons);
bool handle_buttons_hover(game_t *game, button_t **buttons);
bool is_button_clicked(game_t *game, button_t *button);

// Sounds
sounds_t *menu_music(void);
void destroy_sound(sounds_t *music);

// Display
void scene_manager(game_t *game);
bool display_main_menu(game_t *game);
bool display_fight(game_t *game);
bool display_main_game(game_t *game);
bool display_settings(game_t *game);
bool display_pause(game_t *game);
bool display_saves(game_t *game);
bool display_creation(game_t *game);

// Inventory
inventory_t *create_inventory(unsigned int height, unsigned int width);
inventory_t *add_to_inventory(inventory_t *inventory, unsigned int id,
unsigned int quantity);
inventory_t *remove_from_inventory(inventory_t *inventory, unsigned int id,
unsigned int quantity);
inventory_t *swap_slots(inventory_t *inventory, sfVector2u pos1,
    sfVector2u pos2);

// Fight
char *string_info(fight_t *fight);
char *string_info_enemy(fight_t *fight);
button_t **init_attack_buttons(void);

// Character
character_t *create_character(void);
void add_experience(character_t *character, unsigned int exp);

// Music
void play_music(sfMusic *sounds);

// Map
sfColor get_pixel_at_pos(game_t *game, sfVector2f shift);
void move_left(game_t *game, sfColor color);
void move_right(game_t *game, sfColor color);
void move_top(game_t *game, sfColor color);
void move_bottom(game_t *game, sfColor color);

// Utils
bool color_cmp(sfColor color1, sfColor color2);
unsigned int get_2d_array_length(char **array);
bool clear_str(char *str, char c);
char *itoa(unsigned int value);
bool is_pos_in_button(button_t *button, sfVector2i pos);

// Parsing
void update_character(data_parsing_match_t matches[],
char **array);
void get_player_data(character_t *character, FILE *file, char **line);
void get_player_stats(character_t *character, FILE *file, char **line);
void get_player_inventory(character_t *character, FILE *file, char **line);
void get_config_data(config_t *config, FILE *file, char **line);
config_t *get_config(char const *filename);
character_t *get_character_save(char const *filename);

// Storage
bool write_config(config_t *config);
void write_value(FILE *file, data_parsing_match_t match);
void save_infos(FILE *file, config_t *config);
void save_keys(FILE *file, config_t *config);

// Navigations
void go_to_creation(game_t *game);
void go_to_menu(game_t *game);
void go_to_settings(game_t *game);
void go_to_saves(game_t *game);
void go_to_game_player1(game_t *game);
void go_to_game_player2(game_t *game);
void go_to_game_player3(game_t *game);
void back_to_game(game_t *game);
void quit_game(game_t *game);

#endif

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
bool load_game(thread_params_t *params);
game_asset_t *init_hp_bar(void);
game_asset_t *init_menu_background(void);
game_asset_t *init_enemy_bar(void);
game_asset_t *init_player_bar(void);
button_t **init_attack_buttons(void);
button_t **init_buttons(void);
fight_t *init_fight(void);
enemy_t *init_ogre(void);
player_t *init_player(void);
chest_t *init_chest(void);
button_t *create_button(char *str, sfVector2f pos_sprite,
void (*on_click) (game_t *game), sfVector2f scale);
int clock_time(sfClock *clock, float time_offset);
button_t *title_menu(char *str);
main_menu_scenes_t *init_main_menu(void);
main_game_t *init_main_game(game_t *game);
text_t *init_text(char *str);
bool download_assets(int *loaded);
char **read_file(char const *filename);
bool write_file(char const *filename, config_t *config);
config_t *parse_config(void);
settings_t *init_settings(game_t *game);
button_t *create_icon(sfVector2f pos_sprite, char *path,
void (*on_click) (game_t *game));
int open_chest(game_t *game);
pause_t *init_pause(game_t *game);
scene_saves_t *init_saves(game_t *game);
button_t *create_save_card(sfVector2f pos_sprite, char *path,
void (*on_click) (game_t *game));
npc_t *init_albert(void);
npc_t *init_chief(void);
config_t *init_config(void);
game_asset_t **init_character(character_t **saves);
inventory_sprite_t *init_inventory(void);
bool display_inventory(game_t *game);
button_t **init_slots(game_t *game);
sfIntRect *rect_player(void);
main_creation_scenes_t *init_creation(void);
button_t **init_buttons_creation(void);
game_asset_t **init_characters(void);
sfText **init_text_creation(sfFont *font);
loader_t *init_loader_window(void);
sfText ***create_stat_text(sfFont *font, main_creation_scenes_t *creation);
stats_t *init_war_stats(void);
sfText **init_unspent(main_creation_scenes_t *creation, sfFont *font);
sfText **init_text_life(fight_t *text_fight);
quests_t *init_quests(void);
sfText **init_text_life_characters(fight_t *text_fight);
sfText **init_text_life_enemy(fight_t *text_enemy);
quest_t *create_first_quest(void);
quest_t *create_second_quest(void);
sfText **create_stat_text_scene(sfFont *font,
stats_scene_t *saves);
sfText *init_text_class_scene(sfFont *font, game_t *game);
button_t **init_buttons_stats(void);
stats_scene_t *init_stats(game_t *game);
sfText **init_keybinds_text(game_t *game, sfFont *font);
button_t **init_icons_settings(void);
unsigned int check_bool(game_t *game);

// Destroy
void destroy_game(game_t *game);
void destroy_menu(game_asset_t *menu);
void menu_destroy_buttons(button_t **button);
void destroy_player(player_t *player);
void destroy_fight(fight_t *fight);
void destroy_all(game_t *game);
void destroy_game_scene(main_game_t *map);
void destroy_chest(chest_t *chest);
void destroy_settings(game_asset_t *settings);
void settings_destroy_icons(button_t **buttons);
void settings_destroy_buttons(button_t **buttons);
void destroy_inventory(inventory_sprite_t *inventory);
void destroy_npcs(npc_t **npcs);

// Events
void default_event_handling(game_t *game, button_t **buttons);
void handle_arrow_keys(game_t *game);
void handle_events(game_t *game, sfEvent *event);
void handle_mouse_wheel(game_t *game, sfEvent *event);
bool handle_buttons_clicks(game_t *game, button_t **buttons);
bool handle_buttons_hover(game_t *game, button_t **buttons);
bool is_button_clicked(game_t *game, button_t *button);
void handle_game_change_scenes(game_t *game);
bool handle_quests_keys(game_t *game);

// Sounds
sounds_t *menu_music(config_t *config);
void destroy_sound(sounds_t *music);

// Display
void scene_manager(game_t *game);
bool display_loader(loader_t *loader, int total);
bool display_main_menu(game_t *game);
bool display_fight(game_t *game);
bool display_main_game(game_t *game);
bool display_settings(game_t *game);
bool display_pause(game_t *game);
bool display_saves(game_t *game);
bool display_creation(game_t *game);
bool display_stats(game_t *game);

// Inventory
inventory_t *create_inventory(unsigned int height, unsigned int width);
bool is_slot_in_inventory(inventory_t *inventory, slot_t *slot);
bool is_quest_valid(inventory_t *inventory, slot_t **slot);
inventory_t *add_to_inventory(inventory_t *inventory, unsigned int id,
unsigned int quantity);
inventory_t *remove_from_inventory(inventory_t *inventory, unsigned int id,
unsigned int quantity);
inventory_t *swap_slots(inventory_t *inventory, sfVector2u pos1,
sfVector2u pos2);

// Controllers
void transform_dialog_txt(game_t *game, sfText *sprite);
void transform_dialog(game_t *game);
void finish_quest(game_t *game);

// Fight
char *string_info(fight_t *fight);
char *string_info_enemy(fight_t *fight);
void attack_player(character_t *player, enemy_t *enemy);
void attack_enemy(game_t *game);
enemy_t **create_enemies(void);
player_t **create_characters(void);
enemy_t *create_ogre(void);
bool detect_enemies(game_t *game);
sfText *init_text_player_hp(fight_t *text_fight);
sfText *init_text_enemy_hp(fight_t *text_enemy);
bool create_text_player(character_t *player, fight_t *fight);
bool create_text_enemy(enemy_t *enemy, fight_t *fight);

// Character
character_t *create_character(void);
void add_experience(character_t *character, unsigned int exp);

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
void get_player_positions(game_t *game, character_t *character, FILE *file,
char **line);
void get_config_data(config_t *config, FILE *file, char **line);
config_t *get_config(char const *filename);
character_t *get_character_save(game_t *game, char const *filename);

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
void go_to_creation_player1(game_t *game);
void go_to_creation_player2(game_t *game);
void go_to_creation_player3(game_t *game);
void back_to_game(game_t *game);
void quit_game(game_t *game);
void create_game(game_t *game);
void go_to_prev(game_t *game);

// Setup_stats
void up_strength(game_t *game);
void up_defense(game_t *game);
void up_vitality(game_t *game);
void up_speed(game_t *game);
void up_dexterity(game_t *game);
void down_strength(game_t *game);
void down_defense(game_t *game);
void down_vitality(game_t *game);
void down_speed(game_t *game);
void down_dexterity(game_t *game);
void up_strength_game(game_t *game);
void up_defense_game(game_t *game);
void up_vitality_game(game_t *game);
void up_speed_game(game_t *game);
void up_dexterity_game(game_t *game);
void down_strength_game(game_t *game);
void down_defense_game(game_t *game);
void down_vitality_game(game_t *game);
void down_speed_game(game_t *game);
void down_dexterity_game(game_t *game);

// Change_settings
void change_left(game_t *game);
void change_right(game_t *game);
void change_up(game_t *game);
void change_down(game_t *game);
void change_inventory(game_t *game);
void change_interact(game_t *game);
void change_pause(game_t *game);

#endif

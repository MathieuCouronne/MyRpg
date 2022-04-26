/*
** EPITECH PROJECT, 2021
** structs.h
** File description:
** my_rpg structs header file
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include "menu.h"
#include "idk.h"
#include "game.h"

#ifndef STRUCTS_H_
    #define STRUCTS_H_

typedef struct fight_s {
    game_asset_t *background_fight;
    game_asset_t *text_bar;
    game_asset_t *hp_bar;
    player_t *player;
    enemy_t *ennemy;
} fight_t;

typedef struct main_game_s {
    game_asset_t *map;
} main_game_t;

typedef struct main_menu_scenes_s {
    game_asset_t *background;
    menu_buttons_t *buttons;
} main_menu_scenes_t;

typedef struct scenes_s {
    main_menu_scenes_t *main_menu;
    main_game_t *game_scene;
    fight_t *fight;
} scenes_t;

typedef struct sound_s {
    sfMusic *music;
} sound_t;

typedef struct game_s {
    sfRenderWindow *window;
    sfView *view;
    scenes_t *scenes;
    sound_t *sound;
    player_t *player;
    enemy_t *ennemy;
} game_t;

typedef struct event_controller_s {
    sfEventType type;
    void (*fn) (game_t *game, sfEvent *event);
} event_controller_t;

bool display_main_game(game_t *game);
void clock_player_down(sfClock *clock, game_t *game);
void clock_player_up(sfClock *clock, game_t *game);
void destroy_map(main_game_t *map);
void destroy_all(game_t *game);
void clock_player_right(sfClock *clock, game_t *game);

#endif

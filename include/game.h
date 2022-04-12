/*
** EPITECH PROJECT, 2021
** game.h
** File description:
** my_rpg game.h
*/

#include "idk.h"

#ifndef RPG_GAME_H
    #define RPG_GAME_H

typedef struct game_scene_s {
    game_asset_t *map;
    sfView *view;
} game_scene_t;

bool display_main_game(game_t *game);
void destroy_map(main_game_t *map);

#endif //RPG_GAME_H

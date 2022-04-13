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

typedef struct player_s {
    sfSprite *sprite;
    sfIntRect *rect;
    sfVector2f position;
    sfTexture *texture;
    sfClock *clock;
} player_t;

player_t *character_sprite(void);
int clock_time(sfClock *clock, float time_offset);

#endif //RPG_GAME_H

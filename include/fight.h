/*
** EPITECH PROJECT, 2021
** enum.h
** File description:
** my_rpg enum
*/

#include "idk.h"
#include "game.h"

#ifndef RPG_FIGHT_H
    #define RPG_FIGHT_H

typedef struct text_s {
    sfText *text;
    sfFont *font;
} text_t;

typedef struct enemy_s {
    sfSprite *sprite;
    sfIntRect *rect;
    sfVector2f position;
    sfTexture *texture;
    char *name;
    unsigned int dps;
    unsigned int hp;
} enemy_t;

typedef struct fight_s {
    game_asset_t *background_fight;
    game_asset_t *text_bar;
    game_asset_t *hp_bar;
    player_t *player;
    enemy_t *enemy;
} fight_t;

#endif //RPG_FIGHT_H

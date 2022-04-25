/*
** EPITECH PROJECT, 2021
** enum.h
** File description:
** my_rpg enum
*/

#include "game.h"
#include "structs.h"

#ifndef RPG_FIGHT_H
    #define RPG_FIGHT_H

fight_t *init_fight(void);
bool display_fight(game_t *game);
sfIntRect *rect_player(void);

#endif //RPG_FIGHT_H

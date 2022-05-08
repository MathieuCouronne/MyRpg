/*
** EPITECH PROJECT, 2021
** init_buttons.c
** File description:
** init buttons for fight
*/

#include <stdlib.h>
#include "structs.h"
#include "my_rpg.h"

void escape_fight(game_t *game)
{
    game->scenes->current = MAIN_GAME;
}
/*
** EPITECH PROJECT, 2021
** create_map.c
** File description:
** create_map main game
*/

#include <stdbool.h>
#include "my_rpg.h"
#include "structs.h"
#include "game.h"
#include <stdlib.h>

void move_right(player_t *player)
{
    player->rect->width += 55;
}
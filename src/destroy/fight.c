/*
** EPITECH PROJECT, 2021
** game.c
** File description:
** Game destroyer
*/

#include <stdlib.h>
#include "my_rpg.h"
#include "scenes.h"
#include "fight.h"

void destroy_fight(fight_t *fight)
{
    if (!fight)
        return;
    sfSprite_destroy(fight->background_fight->sprite);
    free(fight);
}
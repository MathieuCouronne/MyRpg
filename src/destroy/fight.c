/*
** EPITECH PROJECT, 2021
** game.c
** File description:
** Game destroyer
*/

#include <stdlib.h>
#include "my_rpg.h"

void destroy_fight(fight_t *fight)
{
    if (!fight)
        return;
    sfSprite_destroy(fight->background_fight->sprite);
    sfSprite_destroy(fight->player->sprite);
    for (unsigned int i = 0; i < 3; i++)
        sfSprite_destroy(fight->enemy[i]->sprite);
    sfSprite_destroy(fight->player_bar->sprite);
    sfSprite_destroy(fight->text_bar->sprite);
    free(fight);
}

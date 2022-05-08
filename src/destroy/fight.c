/*
** EPITECH PROJECT, 2021
** fight.c
** File description:
** Fight destroyer
*/

#include <stdlib.h>
#include "my_rpg.h"

void destroy_fight(fight_t *fight)
{
    if (!fight)
        return;
    if (fight->player->sprite)
        sfSprite_destroy(fight->player->sprite);
    for (unsigned int i = 0; i < 3; i++) {
        if (fight->enemy[i]->sprite)
            sfSprite_destroy(fight->enemy[i]->sprite);
        if (fight->enemy[i]->texture)
            sfTexture_destroy(fight->enemy[i]->texture);
    }
    if (fight->font)
        sfFont_destroy(fight->font);
    destroy_game_asset(fight->enemy_bar);
    destroy_game_asset(fight->player_bar);
    destroy_game_asset(fight->win_sprite);
    destroy_game_asset(fight->text_bar);
    destroy_game_asset(fight->background_fight);
    destroy_game_asset(fight->defeat_prite);
    free(fight);
}

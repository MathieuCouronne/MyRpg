/*
** EPITECH PROJECT, 2021
** fight_text.c
** File description:
** Init text hp for player and enemy fight
*/

#include <SFML/Window.h>
#include <stdlib.h>
#include "structs.h"
#include "my_rpg.h"
#include "macros.h"

sfText *init_text_player_hp(fight_t *text_fight)
{
    sfText *text_life = sfText_create();

    if (!text_life)
        return NULL;
    sfText_setFont(text_life, text_fight->font);
    sfText_setCharacterSize(text_life, 25);
    sfText_setColor(text_life, sfWhite);
    sfText_setPosition(text_life, (sfVector2f) {210, 90});
    return text_life;
}

sfText *init_text_enemy_hp(fight_t *text_enemy)
{
    sfText *text_life = sfText_create();

    if (!text_life)
        return NULL;
    sfText_setFont(text_life, text_enemy->font);
    sfText_setCharacterSize(text_life, 25);
    sfText_setColor(text_life, sfWhite);
    sfText_setPosition(text_life, (sfVector2f) {1560, 90});
    return text_life;
}

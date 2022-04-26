/*
** EPITECH PROJECT, 2021
** ennemy.c
** File description:
** ennemy destroyer
*/

#include <stdlib.h>
#include "my_rpg.h"
#include "menu.h"
#include <SFML/Audio.h>
#include "game.h"

void destroy_ennemy(enemy_t *ennemy)
{
    if (!ennemy)
        return;
    sfSprite_destroy(ennemy->sprite);
    sfTexture_destroy(ennemy->texture);
    free(ennemy);
}
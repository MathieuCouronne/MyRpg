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

void destroy_enemy(enemy_t *enemy)
{
    if (!enemy)
        return;
    sfSprite_destroy(enemy->sprite);
    sfTexture_destroy(enemy->texture);
    free(enemy);
}
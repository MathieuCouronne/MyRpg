/*
** EPITECH PROJECT, 2021
** enemy.c
** File description:
** enemy destroyer
*/

#include <stdlib.h>
#include "my_rpg.h"
#include "menu.h"
#include <SFML/Audio.h>

void destroy_enemy(enemy_t *enemy)
{
    if (!enemy)
        return;
    sfSprite_destroy(enemy->sprite);
    sfTexture_destroy(enemy->texture);
    free(enemy);
}
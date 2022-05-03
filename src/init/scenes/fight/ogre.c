/*
** EPITECH PROJECT, 2021
** player.c
** File description:
** init_player
*/

#include <SFML/Audio.h>
#include <stdlib.h>
#include "structs.h"
#include "menu.h"
#include "my_rpg.h"
#include "macros.h"

static sfIntRect rect_ogre(void)
{
    sfIntRect rect = {
        295, 8, 62, 54
    };

    return rect;
}

enemy_t *init_ogre(void)
{
    enemy_t *enemy = malloc(sizeof(player_t));

    enemy->sprite = sfSprite_create();
    enemy->rect = rect_ogre();
    enemy->texture = sfTexture_createFromFile(ENEMY_PATH, NULL);
    sfSprite_setTexture(enemy->sprite, enemy->texture, sfTrue);
    sfSprite_setScale(enemy->sprite, (sfVector2f) {10, 10});
    sfSprite_setPosition(enemy->sprite, (sfVector2f) {1125, 50});
    sfSprite_setTextureRect(enemy->sprite, enemy->rect);
    return enemy;
}

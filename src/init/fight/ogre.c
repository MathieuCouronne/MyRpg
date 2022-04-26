/*
** EPITECH PROJECT, 2021
** player.c
** File description:
** init_player
*/

#include "structs.h"
#include "menu.h"
#include <SFML/Audio.h>
#include "my_rpg.h"
#include "game.h"
#include <stdlib.h>

static sfIntRect *rect_player(void)
{
    sfIntRect *rect = malloc(sizeof(sfIntRect));

    rect->top = 8;
    rect->left = 295;
    rect->width = 62;
    rect->height = 54;
    return rect;
}

enemy_t *init_ogre(void)
{
    enemy_t *enemy = malloc(sizeof(player_t));

    enemy->sprite = sfSprite_create();
    enemy->rect = rect_player();
    enemy->texture = sfTexture_createFromFile(
            "./assets/images/enemy.png", NULL);
    sfSprite_setTexture(enemy->sprite, enemy->texture, sfTrue);
    sfSprite_setScale(enemy->sprite, (sfVector2f) {10, 10});
    sfSprite_setPosition(enemy->sprite, (sfVector2f) {1125, 50});
    //sfSprite_setPosition(enemy->sprite, enemy->position);
    sfSprite_setTextureRect(enemy->sprite, *enemy->rect);
    return enemy;
}

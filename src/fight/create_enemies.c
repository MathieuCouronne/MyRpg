/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** creates an enemy
*/

#include "structs.h"
#include "my_rpg.h"
#include "inventory.h"
#include "macros.h"


enemy_t *create_ogre(void)
{
    enemy_t *troll = malloc(sizeof(enemy_t));

    if (!troll)
        return NULL;
    troll->sprite = sfSprite_create();
    troll->rect = (sfIntRect) {239, 37, 39, 44};
    troll->position = (sfVector2f) {0, 0};
    troll->texture = sfTexture_createFromFile(OGRE_PATH, NULL);
    sfSprite_setTexture(troll->sprite, troll->texture, sfTrue);
    sfSprite_setTextureRect(troll->sprite, troll->rect);
    sfSprite_setPosition(troll->sprite, troll->position);
    troll->name = "Ogre";
    troll->dps = 10;
    troll->hp = 150;
    troll->max_hp = 150;
}


enemy_t *create_troll(void)
{
    enemy_t *troll = malloc(sizeof(enemy_t));

    if (!troll)
        return NULL;
    troll->sprite = sfSprite_create();
    troll->rect = (sfIntRect) {200, 10, 39, 42};
    troll->position = (sfVector2f) {0, 0};
    troll->texture = sfTexture_createFromFile(TROLL_PATH, NULL);
    sfSprite_setTexture(troll->sprite, troll->texture, sfTrue);
    sfSprite_setTextureRect(troll->sprite, troll->rect);
    sfSprite_setPosition(troll->sprite, troll->position);
    troll->name = "Troll";
    troll->dps = 15;
    troll->hp = 100;
    troll->max_hp = 100;
}

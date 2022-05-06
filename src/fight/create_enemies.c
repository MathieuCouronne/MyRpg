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

enemy_t *create_dragon(void)
{
    enemy_t *dragon = malloc(sizeof(enemy_t));

    if (!dragon)
        return NULL;
    dragon->sprite = sfSprite_create();
    dragon->rect = (sfIntRect) {279, 8, 74, 73};
    dragon->position = (sfVector2f) {0, 0};
    dragon->texture = sfTexture_createFromFile(DRAGON_PATH, NULL);
    sfSprite_setTexture(dragon->sprite, dragon->texture, sfTrue);
    sfSprite_setTextureRect(dragon->sprite, dragon->rect);
    sfSprite_setPosition(dragon->sprite, dragon->position);
    dragon->name = "Dragon";
    dragon->dps = 25;
    dragon->hp = 500;
    dragon->max_hp = 500;
    return dragon;
}

enemy_t *create_ogre(void)
{
    enemy_t *ogre = malloc(sizeof(enemy_t));

    if (!ogre)
        return NULL;
    ogre->sprite = sfSprite_create();
    ogre->texture = sfTexture_createFromFile(REVERSED_OGRE_PATH, NULL);
    if (!ogre->sprite || !ogre->texture)
        return NULL;
    sfSprite_setTexture(ogre->sprite, ogre->texture, sfTrue);
    sfSprite_setScale(ogre->sprite, (sfVector2f) {10, 10});
    sfSprite_setPosition(ogre->sprite, (sfVector2f) {1350, 240});
    ogre->name = "Ogre";
    ogre->dps = 10;
    ogre->hp = 150;
    ogre->max_hp = 150;
    return ogre;
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
    return troll;
}

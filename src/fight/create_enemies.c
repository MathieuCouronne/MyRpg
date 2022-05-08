/*
** EPITECH PROJECT, 2021
** creeate_enemies.c
** File description:
** Creates an enemy
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
    dragon->position = (sfVector2f) {1125, 180};
    dragon->texture = sfTexture_createFromFile(REVERSED_DRAGON_PATH, NULL);
    dragon->color = sfColor_fromRGB(255, 255, 0);
    sfSprite_setTexture(dragon->sprite, dragon->texture, sfTrue);
    sfSprite_setScale(dragon->sprite, (sfVector2f) {8, 8});
    sfSprite_setPosition(dragon->sprite, dragon->position);
    dragon->name = "Dragon";
    dragon->dps = 40;
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
    ogre->color = sfColor_fromRGB(255, 0, 254);
    if (!ogre->sprite || !ogre->texture)
        return NULL;
    sfSprite_setTexture(ogre->sprite, ogre->texture, sfTrue);
    sfSprite_setScale(ogre->sprite, (sfVector2f) {10, 10});
    sfSprite_setPosition(ogre->sprite, (sfVector2f) {1350, 240});
    ogre->name = "Ogre";
    ogre->dps = 25;
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
    troll->position = (sfVector2f) {1250, 290};
    troll->texture = sfTexture_createFromFile(REVERSED_TROLL_PATH, NULL);
    troll->color = sfColor_fromRGB(0, 255, 255);
    sfSprite_setTexture(troll->sprite, troll->texture, sfTrue);
    sfSprite_setScale(troll->sprite, (sfVector2f) {10, 10});
    sfSprite_setPosition(troll->sprite, troll->position);
    troll->name = "Troll";
    troll->dps = 25;
    troll->hp = 100;
    troll->max_hp = 100;
    return troll;
}

enemy_t **create_enemies(void)
{
    enemy_t **enemies = malloc(sizeof(enemy_t *) * 4);

    if (!enemies)
        return NULL;
    enemies[0] = create_troll();
    enemies[1] = create_ogre();
    enemies[2] = create_dragon();
    enemies[3] = NULL;
    for (unsigned int i = 0; i < 3; i++) {
        if (!enemies[i])
            return NULL;
    }
    return enemies;
}

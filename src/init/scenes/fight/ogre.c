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

enemy_t *init_ogre(void)
{
    enemy_t *enemy = malloc(sizeof(player_t));

    if (!enemy)
        return NULL;
    enemy->sprite = sfSprite_create();
    enemy->texture = sfTexture_createFromFile(REVERSED_OGRE_PATH, NULL);
    if (!enemy->sprite || !enemy->texture)
        return NULL;
    sfSprite_setTexture(enemy->sprite, enemy->texture, sfTrue);
    sfSprite_setScale(enemy->sprite, (sfVector2f) {10, 10});
    sfSprite_setPosition(enemy->sprite, (sfVector2f) {1350, 240});
    return enemy;
}

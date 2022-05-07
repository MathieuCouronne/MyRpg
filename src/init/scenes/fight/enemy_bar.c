/*
** EPITECH PROJECT, 2021
** enemy_bar.c
** File description:
** Create enemy bar
*/

#include "structs.h"
#include <SFML/Audio.h>
#include <stdlib.h>
#include "menu.h"
#include "my_rpg.h"
#include "macros.h"

game_asset_t *init_enemy_bar(void)
{
    game_asset_t *hp = malloc(sizeof(game_asset_t));

    if (!hp)
        return NULL;
    hp->sprite = sfSprite_create();
    hp->texture = sfTexture_createFromFile(FIGHT_ENEMY_BAR_PATH, NULL);
    if (!hp->sprite || !hp->texture)
        return NULL;
    sfSprite_setPosition(hp->sprite, (sfVector2f) {1450, 50});
    sfSprite_setScale(hp->sprite, (sfVector2f) {0.75, 0.75});
    sfSprite_setTexture(hp->sprite, hp->texture, sfTrue);
    return hp;
}

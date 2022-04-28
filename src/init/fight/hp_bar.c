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
#include <stdlib.h>

game_asset_t *init_hp_bar(void)
{
    game_asset_t *hp = malloc(sizeof(game_asset_t));

    if (!hp)
        return NULL;
    hp->sprite = sfSprite_create();
    hp->texture = sfTexture_createFromFile
            ("./assets/images/hp.png", NULL);
    sfSprite_setPosition(hp->sprite, (sfVector2f) {0, 100});
    sfSprite_setScale(hp->sprite, (sfVector2f) {4, 4});
    sfSprite_setTexture(hp->sprite, hp->texture, sfTrue);
    return hp;
}

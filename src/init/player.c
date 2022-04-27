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
#include "macros.h"
#include <stdlib.h>

sfIntRect *rect_player(void)
{
    sfIntRect *rect = malloc(sizeof(sfIntRect));

    rect->top = 0;
    rect->left = 0;
    rect->width = 74;
    rect->height = 50;
    return rect;
}

player_t *init_player(void)
{
    player_t *player = malloc(sizeof(player_t));
    sfVector2f player_scale = {PLAYER_SCALE, PLAYER_SCALE};

    player->clock = sfClock_create();
    player->sprite = sfSprite_create();
    player->rect = rect_player();
    player->texture = sfTexture_createFromFile(PLAYER_SPRITE_PATH, NULL);
    if (!player->sprite || !player->rect || !player->texture)
        return NULL;
    player->position.x = 2220;
    player->position.y = 2200;
    sfSprite_setTexture(player->sprite, player->texture, sfTrue);
    sfSprite_setScale(player->sprite, player_scale);
    sfSprite_setPosition(player->sprite, player->position);
    sfSprite_setTextureRect(player->sprite, *player->rect);
    return player;
}

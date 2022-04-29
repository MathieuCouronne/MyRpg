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
#include "macros.h"
#include <stdlib.h>

sfIntRect *rect_player(void)
{
    sfIntRect *rect = malloc(sizeof(sfIntRect));

    rect->top = 16;
    rect->left = 14;
    rect->width = 43;
    rect->height = 61;
    return rect;
}

player_t *init_player(void)
{
    player_t *player = malloc(sizeof(player_t));
    sfVector2f player_scale = {PLAYER_SCALE, PLAYER_SCALE};

    player->clock = sfClock_create();
    player->sprite = sfSprite_create();
    player->rect = rect_player();
    player->texture = sfTexture_createFromFile(DOGWARRIOR_PATH, NULL);
    player->position = malloc(sizeof(sfVector2f));
    if (!player->sprite || !player->rect || !player->texture ||
    !player->position)
        return NULL;
    player->position->x = (float) MAP_WIDTH / 2;
    player->position->y = (float) MAP_HEIGHT / 2;
    sfSprite_setTexture(player->sprite, player->texture, sfTrue);
    sfSprite_setScale(player->sprite, player_scale);
    sfSprite_setPosition(player->sprite, *player->position);
    sfSprite_setTextureRect(player->sprite, *player->rect);
    return player;
}

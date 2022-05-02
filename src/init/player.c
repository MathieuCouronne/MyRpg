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

sfIntRect *rect_player(void)
{
    sfIntRect *rect = malloc(sizeof(sfIntRect));

    rect->top = 16;
    rect->left = 14;
    rect->width = 43;
    rect->height = 61;
    return rect;
}

static void transform_player(player_t *player)
{
    sfVector2f player_scale = {PLAYER_SCALE, PLAYER_SCALE};

    sfSprite_setTexture(player->sprite, player->texture, sfTrue);
    sfSprite_setScale(player->sprite, player_scale);
    sfSprite_setPosition(player->sprite, *player->position);
    sfSprite_setTextureRect(player->sprite, *player->rect);
}

player_t *init_player(void)
{
    player_t *player = malloc(sizeof(player_t));

    player->clock = sfClock_create();
    player->sprite = sfSprite_create();
    player->rect = rect_player();
    player->texture = sfTexture_createFromFile(DOGWARRIOR_PATH, NULL);
    player->position = malloc(sizeof(sfVector2f));
    player->relative_pos = malloc(sizeof(sfVector2f));
    if (!player->sprite || !player->rect || !player->texture ||
    !player->position || !player->relative_pos)
        return NULL;
    player->position->x = (float) MAP_WIDTH / 2;
    player->position->y = (float) MAP_HEIGHT / 2;
    player->relative_pos->x = 0;
    player->relative_pos->y = 0;
    player->clock = sfClock_create();
    transform_player(player);
    return player;
}

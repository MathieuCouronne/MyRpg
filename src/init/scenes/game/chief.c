/*
** EPITECH PROJECT, 2021
** chief.c
** File description:
** init_chief
*/

#include <SFML/Audio.h>
#include <stdlib.h>
#include "structs.h"
#include "menu.h"
#include "my_rpg.h"
#include "macros.h"

sfIntRect *rect_chief(void)
{
    sfIntRect *rect = malloc(sizeof(sfIntRect));

    if (!rect)
        return NULL;
    rect->top = 9;
    rect->left = 22;
    rect->width = 38;
    rect->height = 66;
    return rect;
}

static void transform_chief(npc_t *chief)
{
    sfVector2f chief_scale = {PLAYER_SCALE, PLAYER_SCALE};

    sfSprite_setTexture(chief->sprite, chief->texture, sfTrue);
    sfSprite_setScale(chief->sprite, chief_scale);
    sfSprite_setPosition(chief->sprite, chief->position);
    sfSprite_setTextureRect(chief->sprite, *chief->rect);
}

npc_t *init_chief(void)
{
    npc_t *chief = malloc(sizeof(npc_t));

    if (!chief)
        return NULL;
    chief->sprite = sfSprite_create();
    chief->rect = rect_chief();
    chief->texture = sfTexture_createFromFile(CHIEF_PATH, NULL);
    if (!chief->sprite || !chief->rect || !chief->texture)
        return NULL;
    chief->position.x = 2600;
    chief->position.y = 1150;
    transform_chief(chief);
    return chief;
}

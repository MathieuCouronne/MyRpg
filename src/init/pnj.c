/*
** EPITECH PROJECT, 2021
** pnj.c
** File description:
** init_pnj
*/

#include <SFML/Audio.h>
#include <stdlib.h>
#include "structs.h"
#include "menu.h"
#include "my_rpg.h"
#include "macros.h"

sfIntRect *rect_pnj(void)
{
    sfIntRect *rect = malloc(sizeof(sfIntRect));

    rect->top = 16;
    rect->left = 14;
    rect->width = 43;
    rect->height = 61;
    return rect;
}

static void transform_pnj(pnj_t *pnj)
{
    sfVector2f pnj_scale = {PLAYER_SCALE, PLAYER_SCALE};

    sfSprite_setTexture(pnj->sprite, pnj->texture, sfTrue);
    sfSprite_setScale(pnj->sprite, pnj_scale);
    sfSprite_setPosition(pnj->sprite, pnj->position);
    sfSprite_setTextureRect(pnj->sprite, *pnj->rect);
}

pnj_t *init_pnj(void)
{
    pnj_t *pnj = malloc(sizeof(pnj_t));

    pnj->sprite = sfSprite_create();
    pnj->rect = rect_pnj();
    pnj->texture = sfTexture_createFromFile(ALBERT_PATH, NULL);
    pnj->relative_pos = malloc(sizeof(sfVector2f));
    if (!pnj->sprite || !pnj->rect || !pnj->texture ||
    !pnj->relative_pos)
        return NULL;
    pnj->position.x = 1730;
    pnj->position.y = 1600;
    transform_pnj(pnj);
    return pnj;
}
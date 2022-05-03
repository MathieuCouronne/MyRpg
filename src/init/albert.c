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

sfIntRect *rect_albert(void)
{
    sfIntRect *rect = malloc(sizeof(sfIntRect));

    rect->top = TOP_PADDING;
    rect->left = LEFT_PADDING;
    rect->width = ALBERT_WIDTH;
    rect->height = ALBERT_HEIGHT;
    return rect;
}

static void transform_albert(npc_t *albert)
{
    sfVector2f albert_scale = {PLAYER_SCALE, PLAYER_SCALE};

    sfSprite_setTexture(albert->sprite, albert->texture, sfTrue);
    sfSprite_setScale(albert->sprite, albert_scale);
    sfSprite_setPosition(albert->sprite, albert->position);
    sfSprite_setTextureRect(albert->sprite, *albert->rect);
}

npc_t *init_albert(void)
{
    npc_t *albert = malloc(sizeof(npc_t));
    albert->sprite = sfSprite_create();
    albert->rect = rect_albert();
    albert->texture = sfTexture_createFromFile(ALBERT_PATH, NULL);
    albert->relative_pos = malloc(sizeof(sfVector2f));
    if (!albert->sprite || !albert->rect || !albert->texture ||
    !albert->relative_pos)
        return NULL;
    albert->position.x = 1740;
    albert->position.y = 1600;
    transform_albert(albert);
    return albert;
}

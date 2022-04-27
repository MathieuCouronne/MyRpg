/*
** EPITECH PROJECT, 2021
** chest.c
** File description:
** init_chest
*/

#include "structs.h"
#include "menu.h"
#include <SFML/Audio.h>
#include "my_rpg.h"
#include "game.h"
#include <stdlib.h>

sfIntRect *rect_chest(void)
{
    sfIntRect *rect = malloc(sizeof(sfIntRect));

    rect->top = 0;
    rect->left = 0;
    rect->width = 47;
    rect->height = 40;
    return rect;
}

chest_t *chest_sprite(void)
{
    chest_t *chest = malloc(sizeof(chest_t));

    chest->sprite = sfSprite_create();
    chest->rect = rect_chest();
    chest->texture = sfTexture_createFromFile(
        "./assets/images/Chest.png", NULL);
    sfSprite_setTexture(chest->sprite, chest->texture, sfTrue);
    chest->position.x = 2300;
    chest->position.y = 2400;
    sfSprite_setScale(chest->sprite, (sfVector2f) {2, 2});
    sfSprite_setPosition(chest->sprite, chest->position);
    sfSprite_setTextureRect(chest->sprite, *chest->rect);
    chest->clock = sfClock_create();
    return chest;
}

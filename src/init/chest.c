/*
** EPITECH PROJECT, 2021
** chest.c
** File description:
** init_chest
*/

#include <SFML/Audio.h>
#include <stdlib.h>
#include "structs.h"
#include "menu.h"
#include "my_rpg.h"
#include "macros.h"

static sfIntRect *rect_chest(void)
{
    sfIntRect *rect = malloc(sizeof(sfIntRect));

    if (!rect)
        return NULL;
    rect->top = 0;
    rect->left = 0;
    rect->width = 47;
    rect->height = 46;
    return rect;
}

chest_t *init_chest(void)
{
    chest_t *chest = malloc(sizeof(chest_t));
    sfVector2f scale = {1.1f, 1.1f};

    if (!chest)
        return NULL;
    chest->clock = sfClock_create();
    chest->sprite = sfSprite_create();
    chest->rect = rect_chest();
    chest->texture = sfTexture_createFromFile(CHEST_PATH, NULL);
    if (!chest->clock || !chest->sprite || !chest->rect || !chest->texture)
        return NULL;
    sfSprite_setTexture(chest->sprite, chest->texture, sfTrue);
    chest->position.x = 1500;
    chest->position.y = 1500;
    sfSprite_setScale(chest->sprite, scale);
    sfSprite_setPosition(chest->sprite, chest->position);
    sfSprite_setTextureRect(chest->sprite, *chest->rect);
    return chest;
}

static void move_rect(sfIntRect *rect)
{
    rect->top += 46;
    if (rect->top == 184)
        rect->top = 0;
}

int open_chest(game_t *game)
{
    chest_t *chest = game->scenes->game_scene->chest;
    sfTime time = sfClock_getElapsedTime(chest->clock);
    sfInt32 milliseconds = sfTime_asMilliseconds(time);
    static bool is_open = false;

    sfMusic_play(game->sounds->chest);
    while (is_open != true) {
        if (milliseconds > 400 && !is_open) {
            move_rect(chest->rect);
            sfSprite_setTextureRect(chest->sprite, *chest->rect);
            sfClock_restart(chest->clock);
        }
        if (milliseconds > 400 && !is_open && chest->rect->top == 138)
            is_open = true;
    }
    return 0;
}

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

sfIntRect *rect_chest(void)
{
    sfIntRect *rect = malloc(sizeof(sfIntRect));

    rect->top = 0;
    rect->left = 0;
    rect->width = 47;
    rect->height = 46;
    return rect;
}

chest_t *chest_sprite(void)
{
    chest_t *chest = malloc(sizeof(chest_t));

    chest->clock = sfClock_create();
    chest->sprite = sfSprite_create();
    chest->rect = rect_chest();
    chest->texture = sfTexture_createFromFile(CHEST_PATH, NULL);
    sfSprite_setTexture(chest->sprite, chest->texture, sfTrue);
    chest->position.x = 1500;
    chest->position.y = 1500;
    sfSprite_setScale(chest->sprite, (sfVector2f) {1.1, 1.1});
    sfSprite_setPosition(chest->sprite, chest->position);
    sfSprite_setTextureRect(chest->sprite, *chest->rect);
    return chest;
}

bool move_rect(sfIntRect *rect, int offset, int max_value)
{
    if (offset <= max_value)
        rect->top += offset;
    if (rect->top == max_value)
        rect->top = 0;
}

int chest(game_t *game)
{
    sfTime time = sfClock_getElapsedTime(game->chest->clock);
    sfInt32 milliseconds = sfTime_asMilliseconds(time);

    if (milliseconds > 700) {
        move_rect(game->chest->rect, 46, 184);
        sfSprite_setTextureRect(game->chest->sprite, *game->chest->rect);
        sfClock_restart(game->chest->clock);
    }
    sfRenderWindow_drawSprite(game->window, game->chest->sprite, NULL);
    return 0;
}

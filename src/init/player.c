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

player_t *character_sprite(void)
{
    player_t *player = malloc(sizeof(player_t));

    player->sprite = sfSprite_create();
    player->rect = rect_player();
    player->texture = sfTexture_createFromFile(
        "./assets/images/character.png", NULL);
    sfSprite_setTexture(player->sprite, player->texture, sfTrue);
    player->position.x = 2220;
    player->position.y = 2200;
    sfSprite_setScale(player->sprite, (sfVector2f) {2, 2});
    sfSprite_setPosition(player->sprite, player->position);
    sfSprite_setTextureRect(player->sprite, *player->rect);
    player->clock = sfClock_create();
    return player;
}

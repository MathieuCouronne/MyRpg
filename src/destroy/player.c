/*
** EPITECH PROJECT, 2021
** menu.c
** File description:
** menu destroyer
*/

#include <stdlib.h>
#include "my_rpg.h"
#include "menu.h"
#include <SFML/Audio.h>
#include "game.h"

void destroy_player(player_t *player)
{
    if (!player)
        return;
    sfSprite_destroy(player->sprite);
    sfTexture_destroy(player->texture);
    free(player);
}
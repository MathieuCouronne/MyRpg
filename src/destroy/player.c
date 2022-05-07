/*
** EPITECH PROJECT, 2021
** player.c
** File description:
** Player destroyer
*/

#include <stdlib.h>
#include "my_rpg.h"
#include "menu.h"
#include <SFML/Audio.h>

void destroy_player(player_t *player)
{
    if (!player)
        return;
    sfSprite_destroy(player->sprite);
    sfTexture_destroy(player->texture);
    free(player);
}

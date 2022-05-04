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

void destroy_albert(npc_t *albert)
{
    if (!albert)
        return;
    sfSprite_destroy(albert->sprite);
    sfTexture_destroy(albert->texture);
    free(albert);
}

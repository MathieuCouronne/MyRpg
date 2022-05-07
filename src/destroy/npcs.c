/*
** EPITECH PROJECT, 2021
** npcs.c
** File description:
** Destroy NPCS
*/

#include <stdlib.h>
#include "my_rpg.h"

void destroy_npcs(npc_t **npcs)
{
    if (!npcs)
        return;
    for (unsigned int i = 0; npcs[i]; i++) {
        if (npcs[i]->sprite)
            sfSprite_destroy(npcs[i]->sprite);
        if (npcs[i]->texture)
            sfTexture_destroy(npcs[i]->texture);
    }
    free(npcs);
}

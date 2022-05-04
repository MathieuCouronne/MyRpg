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

void destroy_chief(npc_t *chief)
{
    if (!chief)
        return;
    sfSprite_destroy(chief->sprite);
    sfTexture_destroy(chief->texture);
    free(chief);
}

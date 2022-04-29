/*
** EPITECH PROJECT, 2021
** chest.c
** File description:
** chest destroyer
*/

#include <stdlib.h>
#include "my_rpg.h"
#include "menu.h"
#include <SFML/Audio.h>

void destroy_chest(chest_t *chest)
{
    if (!chest)
        return;
    sfSprite_destroy(chest->sprite);
    sfTexture_destroy(chest->texture);
    free(chest);
}

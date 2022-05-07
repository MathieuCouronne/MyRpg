/*
** EPITECH PROJECT, 2021
** menu.c
** File description:
** menu destroyer
*/

#include <SFML/Audio.h>
#include <stdlib.h>
#include "my_rpg.h"

void destroy_sound(sounds_t *sounds)
{
    if (!sounds->menu || !sounds->chest || !sounds->clic)
        return;
    sfMusic_destroy(sounds->menu);
    sfMusic_destroy(sounds->chest);
    sfSound_destroy(sounds->clic);
    sfSoundBuffer_destroy(sounds->buffer);
    free(sounds);
}

/*
** EPITECH PROJECT, 2021
** music.c
** File description:
** Musics destroyer
*/

#include <SFML/Audio.h>
#include <stdlib.h>
#include "my_rpg.h"

void destroy_sound(sounds_t *sounds)
{
    if (!sounds->menu || !sounds->clic)
        return;
    if (sounds->menu)
        sfMusic_destroy(sounds->menu);
    if (sounds->clic)
        sfSound_destroy(sounds->clic);
    if (sounds->buffer)
        sfSoundBuffer_destroy(sounds->buffer);
    free(sounds);
}

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

void destroy_sound(sounds_t *sounds)
{
    sfMusic_destroy(sounds->main_theme);
    free(sounds);
}

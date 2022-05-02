/*
** EPITECH PROJECT, 2021
** game.c
** File description:
** Game initializer
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdlib.h>
#include "menu.h"
#include "structs.h"
#include "my_rpg.h"
#include "macros.h"

int clock_time(sfClock *clock, float time_offset)
{
    float seconds;
    sfTime time = sfClock_getElapsedTime(clock);

    seconds = time.microseconds / 1000000.0;
    if (seconds >= time_offset) {
        return 1;
    }
    return 0;
}

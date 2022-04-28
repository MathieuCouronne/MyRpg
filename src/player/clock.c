/*
** EPITECH PROJECT, 2021
** create_map.c
** File description:
** create_map main game
*/

#include "my_rpg.h"
#include "structs.h"
#include <SFML/System/Time.h>
#include <SFML/System/Types.h>
#include <SFML/Graphics.h>

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

/*
** EPITECH PROJECT, 2021
** clock.c
** File description:
** Clock initializer
*/

#include <SFML/Window.h>
#include <stdbool.h>

bool clock_time(sfClock *clock, float time_offset)
{
    sfTime time = {0};
    float seconds = 0;

    if (!clock)
        return false;
    time = sfClock_getElapsedTime(clock);
    seconds = sfTime_asSeconds(time);
    if (seconds >= time_offset)
        return true;
    return false;
}

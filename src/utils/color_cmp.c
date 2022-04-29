/*
** EPITECH PROJECT, 2022
** color_cmp.c
** File description:
** Compare colors
*/

#include <SFML/Graphics.h>
#include <stdbool.h>

bool color_cmp(sfColor color1, sfColor color2)
{
    if (
        color1.r == color2.r &&
        color1.g == color2.g &&
        color1.b == color2.b
    )
        return true;
    return false;
}

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

    printf("1 -> r: %d, g: %d, b: %d\n", color1.r, color1.g, color1.b);
    printf("2 -> r: %d, g: %d, b: %d\n\n", color2.r, color2.g, color2.b);
    if (
        color1.r == color2.r &&
        color1.g == color2.g &&
        color1.b == color2.b
    )
        return true;
    return false;
}

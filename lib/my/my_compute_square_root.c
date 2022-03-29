/*
** EPITECH PROJECT, 2021
** my_compute_square_root
** File description:
** Return the sqrt of a number
*/

#include <stdio.h>

int my_compute_square_root(int nb)
{
    float sqrt = (float)nb / (float)2;
    float tmp = 0;

    if (nb < 0)
        return 0;

    while (tmp != sqrt) {
        tmp = sqrt;
        sqrt = (nb / tmp + tmp) / 2;
    }
    if (sqrt <= -2147483648 || sqrt >= 2147483647 || sqrt == (long)sqrt)
        return sqrt;
    else
        return 0;
}

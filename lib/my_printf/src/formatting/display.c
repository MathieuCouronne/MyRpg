/*
** EPITECH PROJECT, 2021
** align_left
** File description:
** align values to left
*/

#include <stdarg.h>
#include "my_printf.h"

void my_putnbr(int nb);

static void display_neg(int *nbr, int *nb)
{
    my_putcharacter('-');
    (*nbr) *= -1;
    (*nb) -= 1;
}

int display(va_list av, char const *str, int *nb, align_pos_t pos)
{
    char c = str[0];
    int nbr = va_arg(av, int);

    if ((c == '-' || c == '0') && nbr < 0)
        display_neg(&nbr, nb);
    if (c == '-')
        my_putnbr(nbr);
    for (int l = 0; l < *nb - intlen(nbr); l++)
        my_putcharacter(ALIGNMENTS[pos.j].character);
    if (c == '0' || c == ' ') {
        if (c == ' ' && nbr < 0)
            display_neg(&nbr, nb);
        my_putnbr(nbr);
    }
    (*pos.i) += pos.k + 1;
    return 1;
}

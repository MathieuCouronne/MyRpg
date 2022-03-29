/*
** EPITECH PROJECT, 2021
** putnbr
** File description:
** Print a number
*/

#include <stdarg.h>
#include "my_printf.h"

void my_putnbr(int nb);

void putnbr(va_list args, char conversion, char flag)
{
    int nbr = va_arg(args, int);

    (void) conversion;
    (void) flag;
    if (conversion == '+' && nbr > 0)
        my_putcharacter('+');
    my_putnbr(nbr);
}

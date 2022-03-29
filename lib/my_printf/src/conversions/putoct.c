/*
** EPITECH PROJECT, 2021
** putoct
** File description:
** Print a number in octal base
*/

#include <stdarg.h>

int my_putnbr_base(int nbr, char const *base);
void my_putcharacter(char c);

void putoct(va_list args, char conversion, char flag)
{
    int nbr = va_arg(args, int);

    (void) flag;
    if (nbr != 0 && conversion == '#')
        my_putcharacter('0');
    my_putnbr_base(nbr, "01234567");
}

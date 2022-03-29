/*
** EPITECH PROJECT, 2021
** putbin
** File description:
** Print a number in binary
*/

#include <stdarg.h>

int my_putnbr_base(int nbr, char const *base);
void my_putcharacter(char c);

void putbin(va_list args, char conversion, char flag)
{
    int nbr = va_arg(args, int);

    (void) conversion;
    (void) flag;
    my_putnbr_base(nbr, "01");
}

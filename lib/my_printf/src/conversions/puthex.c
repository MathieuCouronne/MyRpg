/*
** EPITECH PROJECT, 2021
** puthex
** File description:
** Print a number in hexadecimal
*/

#include <stdarg.h>

int my_putnbr_base(int nbr, char const *base);
void my_putcharacter(char c);

static int is_lower(char c)
{
    return (c >= 'a' && 'z' >= c);
}

static void display_zero(int nbr, char conversion, char flag)
{
    if (nbr != 0 && conversion == '#') {
        my_putcharacter('0');
        if (is_lower(flag))
            my_putcharacter('x');
        else
            my_putcharacter('X');
    }
}

void puthex(va_list args, char conversion, char flag)
{
    int nbr = va_arg(args, int);
    char *base = "0123456789ABCDEF";

    display_zero(nbr, conversion, flag);
    if (is_lower(flag))
        base = "0123456789abcdef";
    my_putnbr_base(nbr, base);
}

/*
** EPITECH PROJECT, 2021
** putptr
** File description:
** Print a pointer
*/

#include <stdarg.h>

void my_putnbr_base(long nbr, char const *base);
void my_putstr(char const *str);

void putptr(va_list args, char conversion, char flag)
{
    long nbr = va_arg(args, long);
    (void) conversion;
    (void) flag;

    my_putstr("0x");
    my_putnbr_base(nbr, "0123456789abcdef");
}

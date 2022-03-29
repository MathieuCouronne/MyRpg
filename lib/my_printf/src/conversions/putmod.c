/*
** EPITECH PROJECT, 2021
** putmod
** File description:
** Print a modulo character
*/

#include <stdarg.h>

void my_putcharacter(char c);

void putmod(va_list args, char conversion, char flag)
{
    (void) args;
    (void) conversion;
    (void) flag;
    my_putcharacter('%');
}

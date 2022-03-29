/*
** EPITECH PROJECT, 2021
** putcharacter
** File description:
** Print a character
*/

#include <stdarg.h>

void my_putcharacter(char c);

void putcharacter(va_list args, char conversion, char flag)
{
    char c = va_arg(args, int);

    (void) conversion;
    (void) flag;
    my_putcharacter(c);
}

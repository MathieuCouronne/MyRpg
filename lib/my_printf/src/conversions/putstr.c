/*
** EPITECH PROJECT, 2021
** putstr
** File description:
** Print a string
*/

#include <stdarg.h>
#include <unistd.h>

int my_strlen(char const *str);

void putstr(va_list args, char conversion, char flag)
{
    char *str = va_arg(args, char *);

    (void) conversion;
    (void) flag;
    write(1, str, my_strlen(str));
}

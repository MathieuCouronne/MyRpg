/*
** EPITECH PROJECT, 2021
** my_putstr
** File description:
** Display character of string
*/

#include <unistd.h>

int my_strlen(char const *str);

int my_putstr(char const *str)
{
    write(1, str, my_strlen(str));
    return 0;
}

/*
** EPITECH PROJECT, 2022
** write.c
** File description:
** Write config into a file
*/

#include <stdlib.h>
#include "my.h"

char *itoa(unsigned int value)
{
    char *result = malloc(sizeof(char) * 33);
    unsigned int rest = 0;
    int i = 0;

    while (value > 0) {
        rest = value % 10;
        if (rest >= 10)
            result[i++] = 65 + (rest - 10);
        else
            result[i++] = 48 + rest;
        value /= 10;
    }
    if (i == 0)
        result[i++] = '0';
    result[i] = '\0';
    return my_revstr(result);
}

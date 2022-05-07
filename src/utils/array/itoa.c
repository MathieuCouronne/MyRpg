/*
** EPITECH PROJECT, 2022
** itoa.c
** File description:
** int to char
*/

#include <stdlib.h>
#include "my.h"

char *itoa(unsigned int value)
{
    char *result = malloc(sizeof(char) * 33);
    int tmp = (int) value;
    unsigned int rest = 0;
    int i = 0;

    while (tmp > 0) {
        rest = tmp % 10;
        if (rest >= 10)
            result[i++] = 65 + (rest - 10);
        else
            result[i++] = 48 + rest;
        tmp /= 10;
    }
    if (i == 0)
        result[i++] = '0';
    result[i] = '\0';
    return my_revstr(result);
}

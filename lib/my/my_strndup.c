/*
** EPITECH PROJECT, 2021
** my_strndup
** File description:
** Create the strndup function
*/

#include <stdlib.h>

int my_strlen(char const *str);
char *my_strncpy(char *dest, char const *src, int size);

char *my_strndup(char const *src, unsigned int size)
{
    char *new = malloc(sizeof(char) * (size + 1));

    my_strncpy(new, src, (int) size);
    new[size] = '\0';
    return new;
}

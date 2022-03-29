/*
** EPITECH PROJECT, 2021
** my_strdup
** File description:
** Recreate the strdup function
*/

#include <stdlib.h>

int my_strlen(char const *str);
char *my_strcpy(char *dest, char const *src);

char *my_strdup(char const *src)
{
    int needed = my_strlen(src) + 1;
    char *new = malloc(needed);

    my_strcpy(new, src);
    return new;
}

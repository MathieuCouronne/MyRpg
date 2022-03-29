/*
** EPITECH PROJECT, 2021
** my_strncpy
** File description:
** Copy n char of string
*/

int my_strlen(char const *str);

char *my_strncpy(char *dest, char const *src , int n)
{
    int i;

    for (i = 0; src[i] != '\0' && i < n; i++)
        dest[i] = src[i];
    for (int j = i; j < n; j++)
        dest[j] = '\0';
    return dest;
}

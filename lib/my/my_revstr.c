/*
** EPITECH PROJECT, 2021
** my_revstr
** File description:
** Reverse a string
*/

int my_strlen(char const *str);

char *my_revstr(char *str)
{
    int length = my_strlen(str);
    int start;
    int tmp;

    for (start = 0; start < length / 2; start++) {
        tmp = str[start];
        str[start] = str[length - 1 - start];
        str[length - 1 - start] = tmp;
    }
    return str;
}

/*
** EPITECH PROJECT, 2021
** my_strupcase
** File description:
** Uppercase letters
*/

int my_strlen(char const *str);

char *my_strlowcase(char *str)
{
    int length = my_strlen(str);
    int i;

    for (i = 0; i < length; i++) {
        if (str[i] >= 65 && str[i] <= 90)
            str[i] += 32;
    }
    return str;
}

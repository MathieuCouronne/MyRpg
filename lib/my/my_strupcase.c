/*
** EPITECH PROJECT, 2021
** my_strupcase
** File description:
** Uppercase letters
*/

int my_strlen(char const *str);

char *my_strupcase(char *str)
{
    int i;

    for (i = 0; i < my_strlen(str); i++) {
        if (str[i] >= 97 && str[i] <= 122)
            str[i] -= 32;
    }
    return str;
}

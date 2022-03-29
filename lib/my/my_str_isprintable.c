/*
** EPITECH PROJECT, 2021
** my_str_isprintable
** File description:
** Return 1 if string contain only printable character
*/

int my_str_isprintable(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (!(str[i] >= 32 && 127 >= str[i]))
            return 0;
    }
    return 1;
}

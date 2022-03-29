/*
** EPITECH PROJECT, 2021
** my_str_isupper
** File description:
** Return 1 if string is only uppercase letters
*/

int my_str_isupper(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (!(str[i] >= 'A' && 'Z' >= str[i]))
            return 0;
    }
    return 1;
}

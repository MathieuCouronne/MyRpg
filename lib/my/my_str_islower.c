/*
** EPITECH PROJECT, 2021
** my_str_islower
** File description:
** Return 1 if string is only lowercase letters
*/

int my_str_islower(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (!(str[i] >= 'a' && 'z' >= str[i]))
            return 0;
    }
    return 1;
}

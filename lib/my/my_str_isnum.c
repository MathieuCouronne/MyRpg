/*
** EPITECH PROJECT, 2021
** my_str_isnum
** File description:
** Return 1 if string contains only digits, else return 0
*/

int my_str_isnum(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (!(str[i] >= '0' && '9' >= str[i]))
            return 0;
    }
    return 1;
}

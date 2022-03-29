/*
** EPITECH PROJECT, 2021
** my_str_isalpha
** File description:
** Return 1 if string contains only alphabetical characters, else return 1
*/

int my_str_isalpha(char const *str)
{
    char const *s = str;

    for (int i = 0; s[i] != '\0'; i++) {
        if (!(s[i] >= 'a' && 'z' >= s[i]) && !(s[i] >= 'A' && 'Z' >= s[i]))
            return 0;
    }
    return 1;
}

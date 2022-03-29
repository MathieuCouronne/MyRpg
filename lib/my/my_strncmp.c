/*
** EPITECH PROJECT, 2021
** my_strncmp
** File description:
** Compare two strings
*/

int my_strlen(char const *str);

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;

    while (s1[i] == s2[i] && s1[i] && s2[i] && i <= n)
        i++;
    if (s1[i] == '\0' && s2[i] == '\0')
        return 0;
    return (s2[i] - s1[i]);
}

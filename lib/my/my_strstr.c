/*
** EPITECH PROJECT, 2021
** my_strstr
** File description:
** Look for a pattern to find in a string
*/

int my_strlen(char const *str);

static char *look_for_pattern(char *str, char const *to_find, int *i, int *j)
{
    int length = my_strlen(to_find);

    while (str[(*i) + (*j)] == to_find[(*j)]) {
        if (!(my_strlen(str) - *i < length) && *j == length - 1) {
            return str + *i;
        }
        (*j)++;
    }
    *j = 0;
    (*i)++;
    return 0;
}

char *my_strstr(char *str, char const *to_find)
{
    int i = 0;
    int j = 0;

    while (str[i] != '\0') {
        char *res = look_for_pattern(str, to_find, &i, &j);
        if (res != 0)
            return res;
    }
    return 0;
}

/*
** EPITECH PROJECT, 2021
** my_str_to_word_array
** File description:
** Split a string into words
*/

#include <stdlib.h>

int my_strlen(char const *str);
int is_anum(char const str);
char *my_strdup(char const *src);

static int get_words_amount(char const *str)
{
    int count = 0;
    int is_next_num = 0;
    int is_next_end = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        is_next_num = (is_anum(str[i]) && !is_anum(str[i + 1]));
        is_next_end = (is_anum(str[i]) && str[i + 1] == '\0');
        if (is_next_num || is_next_end)
            count++;
    }
    return count;
}

static char **add_to_array(char const *str, int cnt, char **arr, int range[2])
{
    int from = range[0];
    int to = range[1];
    int j = 0;
    int length = my_strlen(str);
    char *word = malloc(sizeof(char) * (to - from + 1));

    for (int i = 0; i < length; i++) {
        if (i >= from && i < to) {
            word[j] = str[i];
            j++;
        }
    }
    word[j] = '\0';
    arr[cnt] = my_strdup(word);
    free(word);
    return arr;
}

static char **get_array(char const *str, int *count)
{
    char **arr = malloc(sizeof(char *) * (get_words_amount(str) + 1));
    int from = 0;
    int range[2] = {0};
    int is_next_num = 0;
    int is_next_end = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        is_next_num = (is_anum(str[i]) && !is_anum(str[i + 1]));
        is_next_end = (is_anum(str[i]) && str[i + 1] == '\0');
        if ((!is_anum(str[i]) && !is_anum(str[i + 1])) || !is_anum(str[i])) {
            from = i + 1;
        } else if (is_next_num || is_next_end) {
            range[0] = from;
            range[1] = i + 1;
            arr = add_to_array(str, *count, arr, range);
            *count = *count + 1;
            from = i;
        }
    }
    return arr;
}

char **my_str_to_word_array(char const *str)
{
    char **arr = NULL;
    int count = 0;

    if (!str) {
        arr = malloc(sizeof(char *) * 1);
        arr[0] = NULL;
        return arr;
    }
    arr = get_array(str, &count);
    arr[count] = NULL;
    return arr;
}

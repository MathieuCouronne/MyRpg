/*
** EPITECH PROJECT, 2022
** my_string_to_array
** File description:
** Split a string into words
*/

#include <stdbool.h>
#include <stdlib.h>
#include "my.h"

static bool is_separator(char c, char const *separators)
{
    for (unsigned int i = 0; separators[i] != '\0'; i++) {
        if (c == separators[i])
            return true;
    }
    return false;
}

static char *get_words(char const *str, char const *separators)
{
    char *new = NULL;
    unsigned int end = 0;

    for (; !is_separator(str[end], separators) && str[end] != '\0'; end++);
    new = my_strndup(str, end);
    return new;
}

static unsigned int get_word_count(char const *str, unsigned int pos,
char const *separators)
{
    unsigned int count = 0;

    for (; !is_separator(str[pos], separators) && str[pos] != '\0'; pos++)
        count++;
    if (count > 0)
        return 1;
    return 0;
}

static unsigned int count_words(char const *str, char const *separators)
{
    unsigned int count = 0;
    unsigned int i = 0;

    while (str[i] != '\0') {
        for (; is_separator(str[i], separators) && str[i] != '\0'; i++);
        count += get_word_count(str, i, separators);
        for (; !is_separator(str[i], separators) && str[i] != '\0'; i++);
    }
    return count;
}

char **my_str_to_word_array(char const *str, char const *separators)
{
    unsigned int amount = count_words(str, separators);
    unsigned int pos = 0;
    unsigned int array_pos = 0;
    char **array = malloc(sizeof(char *) * (amount + 1));

    if (amount == 0 || !array) {
        if (array)
            free(array);
        return NULL;
    }
    for (unsigned int i = 0; str[i] != '\0';) {
        for (; is_separator(str[i], separators) && str[i] != '\0'; i++, pos++);
        array[array_pos++] = get_words(str + pos, separators);
        for (; !is_separator(str[i], separators) && str[i] != '\0'; i++, pos++);
    }
    array[amount] = NULL;
    return array;
}

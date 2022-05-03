/*
** EPITECH PROJECT, 2022
** clear_str
** File description:
** clears a string if there is any comment
*/

#include <stdbool.h>

bool clear_str(char *str, char c)
{
    for (unsigned int i = 0; str[i] != '\0'; i++) {
        if (str[i] == c) {
            str[i] = '\0';
            return true;
        }
    }
    return false;
}

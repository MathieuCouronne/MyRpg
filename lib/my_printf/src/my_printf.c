/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** my_printf Main File
*/

#include "my_printf.h"
#include <stdarg.h>

char get_character(char c)
{
    for (int i = 0; CHARACTERS[i] != 0; i++) {
        if (c == CHARACTERS[i])
            return CHARACTERS[i];
    }
    return 0;
}

static int manage_flag(va_list args, char const *str, align_pos_t pos)
{
    char conversion = 0;
    char characters = get_character(str[*(pos.i)]);

    for (int flag = 0; CONVERSIONS[pos.j].flag[flag] != 0; flag++) {
        conversion = characters ? str[*(pos.i) + 1] : str[*(pos.i)];
        if (get_alignment(args, str + *(pos.i), pos.i))
            return 0;
        else if (conversion == CONVERSIONS[pos.j].flag[flag]) {
            CONVERSIONS[pos.j].fn(args, characters, conversion);
            *(pos.i) += characters ? 1 : 0;
            return 1;
        }
    }
    return -1;
}

static int display_flag(char const *str, int *i, va_list args)
{
    int res = 0;
    align_pos_t pos = {i, 0, 0};

    if (str[*i] != '%')
        return 0;
    (*i)++;
    for (int j = 0; CONVERSIONS[j].flag[0] != 0; j++) {
        pos.j = j;
        res = manage_flag(args, str, pos);
        if (res != -1)
            return res;
    }
    my_putcharacter('%');
    return 0;
}

void my_printf(char *str, ...)
{
    va_list args;

    va_start(args, str);
    for (int i = 0; str[i] != '\0'; i++) {
        if (!display_flag(str, &i, args))
            my_putcharacter(str[i]);
    }
    va_end(args);
}

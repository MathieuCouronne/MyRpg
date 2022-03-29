/*
** EPITECH PROJECT, 2021
** align_left
** File description:
** align values to left
*/

#include <stdarg.h>
#include "my_printf.h"

void my_putnbr(int nb);

static int is_alignment_allowed_helper(char c, int i)
{
    for (int j = 0; ALIGNMENTS[i].allowed[j] != 0; j++) {
        if (c == ALIGNMENTS[i].allowed[j])
            return 1;
    }
    return 0;
}

static int is_alignment_allowed(char c)
{
    for (int i = 0; ALIGNMENTS[i].flag != 0; i++) {
        if (is_alignment_allowed_helper(c, i))
            return 1;
    }
    return 0;
}

static int get_flag(va_list args, char const *str, int *nb, align_pos_t pos)
{
    if (str[pos.k] >= '0' && str[pos.k] <= '9') {
        *nb *= 10;
        *nb += (str[pos.k] - 48);
    } else if (is_alignment_allowed(str[pos.k]))
        return display(args, str, nb, pos);
    return 0;
}

static int align(va_list args, char const *str, int *nb, align_pos_t pos)
{
    char c = str[0];
    int flag = 0;

    if (c != ALIGNMENTS[pos.j].flag)
        return 0;
    for (int k = 1; str[k] != '\0'; k++) {
        pos.k = k;
        flag = get_flag(args, str, nb, pos);
        if (flag)
            return flag;
    }
    return 0;
}

int get_alignment(va_list args, char const *str, int *i)
{
    int nb = 0;
    int res = 0;
    align_pos_t pos = {i, 0, 0};

    for (int j = 0; ALIGNMENTS[j].flag != 0; j++) {
        pos.j = j;
        res = align(args, str, &nb, pos);
        if (res)
            return res;
    }
    return 0;
}

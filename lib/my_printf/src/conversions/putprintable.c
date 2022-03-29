/*
** EPITECH PROJECT, 2021
** putprintable
** File description:
** Show a string with escaped non-printable characters
*/

#include <stdarg.h>

void my_putcharacter(char c);
void my_putstr(char const *str);
void my_putnbr(int nb);
int my_putnbr_base(int nbr, char const *base);
int my_strlen(char const *str);

static void my_getnbr_base(int nbr, char const *base, int *res)
{
    int length = my_strlen(base);
    int rest = 0;

    rest = nbr % length;
    nbr /= length;
    if (nbr < 0) {
        nbr *= -1;
        (*res) *= -1;
    }
    if (nbr > 0)
        my_getnbr_base(nbr, base, res);
    (*res) *= 10;
    (*res) += base[rest] - 48;
}

static int is_char_printable(char c)
{
    return (c >= 32);
}

static void is_not_printable(char c)
{
    int res = 0;
    my_getnbr_base(c, "01234567", &res);

    my_putcharacter(92);
    if (res < 10)
        my_putstr("00");
    else if (res < 100)
        my_putcharacter('0');
    my_putnbr_base(c, "01234567");
}

void putprintable(va_list args, char conversion, char flag)
{
    char *str = va_arg(args, char *);

    (void) conversion;
    (void) flag;
    for (int i = 0; str[i]; i++) {
        if (is_char_printable(str[i]))
            my_putcharacter(str[i]);
        else
            is_not_printable(str[i]);
    }
}

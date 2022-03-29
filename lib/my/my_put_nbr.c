/*
** EPITECH PROJECT, 2021
** my_put_nbr
** File description:
** Print a number
*/

void my_putchar(char c);

static long reverse(long number)
{
    long reversed = 0;

    while (number > 0) {
        reversed = reversed * 10 + number % 10;
        number = number / 10;
    }
    return reversed;
}

static int int_length(int nb)
{
    int length = 0;
    while (nb >= 10) {
        length++;
        nb /= 10;
    }
    return length + 1;
}

static void display_value(long long_int, int nb)
{
    int display_amount = 0;
    unsigned int ascii_code;
    int value;
    int to_add;
    long unreversed_long_int = long_int;

    long_int = reverse(long_int);
    while (long_int) {
        value = long_int % 10;
        ascii_code = value + 48;
        my_putchar(ascii_code);
        long_int = long_int / 10;
        display_amount++;
    }
    to_add = int_length(unreversed_long_int) - display_amount;
    for (int i = 0; to_add != i && to_add > 0; i++) {
        my_putchar(48);
    }
}

int my_put_nbr(int nb)
{
    long long_int = nb;

    if (long_int < 0) {
        my_putchar(45);
        long_int = long_int * -1;
    }
    if (long_int == 0) {
        my_putchar(48);
    } else {
        display_value(long_int, nb);
    }
    return 0;
}

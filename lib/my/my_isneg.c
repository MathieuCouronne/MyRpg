/*
** EPITECH PROJECT, 2021
** my_isneg
** File description:
** Print N if number is negative, however, print P
*/

void my_putchar(char c);

int my_isneg(int n)
{
    if (n < 0)
        my_putchar('N');
    else if (n >= 0)
        my_putchar('P');
    my_putchar('\n');
    return 0;
}

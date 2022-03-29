/*
** EPITECH PROJECT, 2021
** my_putnbr_base
** File description:
** Convert a decimal number into given base
*/

void my_putcharacter(char c);
int my_strlen(char const *str);

void my_putnbr_base(long nbr, char const *base)
{
    long length = my_strlen(base);
    long rest = 0;

    rest = nbr % length;
    nbr /= length;
    if (nbr < 0) {
        nbr *= -1;
        my_putcharacter('-');
    }
    if (nbr > 0)
        my_putnbr_base(nbr, base);
    my_putcharacter(base[rest]);
}

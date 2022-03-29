/*
** EPITECH PROJECT, 2021
** my_putnbr
** File description:
** Print a number
*/

void my_putcharacter(char c);

void my_putnbr(int nb)
{
    long res = 0;
    long clean = nb;

    if (clean < 0) {
        clean *= -1;
        my_putcharacter('-');
    }
    if (clean >= 0) {
        if (clean >= 10) {
            res = clean % 10;
            clean = (clean - res) / 10;
            my_putnbr((int) clean);
            my_putcharacter(48 + res);
        } else
            my_putcharacter(48 + nb % 10);
    }
}

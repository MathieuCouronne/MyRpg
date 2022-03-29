/*
** EPITECH PROJECT, 2021
** my_is_prime
** File description:
** Return 1 if number is prime, else return 0
*/

int my_is_prime(int nb)
{
    int i = 2;

    if (nb < i)
        return 0;
    while (i < nb) {
        if (nb % i == 0)
            return 0;
        i++;
    }
    return 1;
}

/*
** EPITECH PROJECT, 2021
** my_find_prime_sub
** File description:
** Return the nearest prime number from a given number
*/

int my_is_prime(int nb);

int my_find_prime_sup(int nb)
{
    int i = nb;

    while (1) {
        if (my_is_prime(i))
            return i;
        i++;
    }
}

/*
** EPITECH PROJECT, 2021
** my_compute_power_rec
** File description:
** Return first argument raised to the power p
*/

int my_compute_power_rec(int nb, int p);

static int get_power_value(int res, int nb)
{
    long long_res = res;
    const long max = 2147483647;

    if (res == 0)
        return 0;
    if (long_res * nb > max)
        return 0;
    else
        return (nb * res);
}

static int get_compute_value(int nb, int p)
{
    if (p < 0)
        return 0;
    return get_power_value(my_compute_power_rec(nb, p - 1), nb);
}

int my_compute_power_rec(int nb, int p)
{
    if (p == 0)
        return 1;
    else if (p < 0 || p != 0)
        return get_compute_value(nb, p);
    return 1;
}

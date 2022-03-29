/*
** EPITECH PROJECT, 2021
** intlen
** File description:
** Get integer lenght
*/

int intlen(int value)
{
    int negative = value < 0 ? 1 : 0;
    int length = 0;

    if (value == 0)
        return 1;
    if (negative)
        value *= -1;
    while (value) {
        length++;
        value /= 10;
    }
    return (negative ? length + 1 : length);
}

/*
** EPITECH PROJECT, 2021
** my_swap
** File description:
** Swap the content of 2 integers
*/

char my_putchar(char c);

void my_swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

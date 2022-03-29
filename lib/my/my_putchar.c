/*
** EPITECH PROJECT, 2021
** my_putchar
** File description:
** Function to display only 1 character
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

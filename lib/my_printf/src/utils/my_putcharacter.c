/*
** EPITECH PROJECT, 2021
** my_putcharacter
** File description:
** Function to display only 1 character
*/

#include <unistd.h>

void my_putcharacter(char c)
{
    write(1, &c, 1);
}

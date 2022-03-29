/*
** EPITECH PROJECT, 2021
** flags
** File description:
** Allowed flags for my_printf
*/

#include "my_printf.h"

const char CHARACTERS[] = {'#', '+', 0};
const alignments_t ALIGNMENTS[] = {
    {'0', '0', {'d', 'i', 'o', 'u', 0}, 1},
    {' ', ' ', {'d', 'i', 'o', 'u', 0}, 0},
    {'-', ' ', {'d', 'i', 'o', 'u', 0}, 2},
    {0, 0, {0}, 2}
};
const conversions_t CONVERSIONS[] = {
    {{'s', 0}, &putstr},
    {{'c', 0}, &putcharacter},
    {{'d', 'i', 'u', 0}, &putnbr},
    {{'x', 'X', 0}, &puthex},
    {{'o', 0}, &putoct},
    {{'b', 0}, &putbin},
    {{'p', 0}, &putptr},
    {{'S', 0}, &putprintable},
    {{'%', 0}, &putmod},
    {{0}, 0}
};

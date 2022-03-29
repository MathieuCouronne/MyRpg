/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** my_printf header file
*/

#pragma once
#include <stdarg.h>

void putcharacter(va_list args, char conversion, char flag);
void putstr(va_list args, char conversion, char flag);
void putnbr(va_list args, char conversion, char flag);
void puthex(va_list args, char conversion, char flag);
void putoct(va_list args, char conversion, char flag);
void putbin(va_list args, char conversion, char flag);
void putptr(va_list args, char conversion, char flag);
void putmod(va_list args, char conversion, char flag);
void putprintable(va_list args, char conversion, char flag);
void my_putcharacter(char c);
int my_putnbr_base(int nbr, char const *base);
int my_strlen(char const *str);
int intlen(int value);
int get_alignment(va_list args, char const *str, int *i);

typedef struct conversions {
    char flag[4];
    void (*fn)(va_list, char, char);
} conversions_t;

typedef struct alignments {
    char flag;
    char character;
    char allowed[5];
    int priority;
} alignments_t;

typedef struct align_pos {
    int *i;
    int j;
    int k;
} align_pos_t;

extern const char CHARACTERS[];
extern const alignments_t ALIGNMENTS[];
extern const conversions_t CONVERSIONS[];
int display(va_list av, char const *str, int *nb, align_pos_t pos);

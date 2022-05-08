/*
** EPITECH PROJECT, 2021
** attack_enemy.c
** File description:
** Generates damage according to stats
*/

#include "my_rpg.h"
#include "structs.h"

unsigned int get_dmg(unsigned int str)
{
    void *ptr = malloc(1);
    unsigned int seed = 0;
    unsigned int res = 0;

    if (!ptr)
        return 1;
    seed = *((unsigned int *)&ptr);
    srand(seed);
    free(ptr);
    res = (rand() % str);
    return res;
}
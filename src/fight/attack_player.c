/*
** EPITECH PROJECT, 2021
** create_map.c
** File description:
** attacks enemy during fight
*/

#include <stdbool.h>
#include <stdlib.h>
#include "my_rpg.h"
#include "structs.h"

static bool dodge(character_t *character)
{
    void *ptr = malloc(sizeof(1));
    unsigned int seed = 0;
    unsigned int res = 0;

    if (!ptr)
        return;
    seed = *((unsigned int *)&ptr);
    srand(seed);
    free(ptr);
    res = (rand() % 100) + 1;
    my_printf("res = %d\n", res);
    if (res <= character->stats->dexterity)
        return true;
    return false;
}

void attack_player(character_t *player, enemy_t *enemy, attack_t *attack)
{

    unsigned int dmg = enemy->dps - player->stats->defense;
    player->hp -= dmg;
}
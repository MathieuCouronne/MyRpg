/*
** EPITECH PROJECT, 2021
** attack_player.c
** File description:
** Attacks player during fight
*/

#include <stdbool.h>
#include <stdlib.h>
#include "my_rpg.h"
#include "structs.h"

static bool dodge(character_t *character)
{
    void *ptr = malloc(1);
    unsigned int seed = 0;
    unsigned int res = 0;

    if (!ptr)
        return false;
    seed = *((unsigned int *)&ptr);
    srand(seed);
    free(ptr);
    res = (rand() % 100) + 1;
    if (res <= character->stats->dexterity)
        return true;
    return false;
}

void attack_player(character_t *player, enemy_t *enemy)
{
    int def = get_dmg(player->stats->defense);
    int dmg = (get_dmg(enemy->dps) - def);

    if (dodge(player))
        return;
    if (dmg < 0)
        dmg = 0;
    player->hp -= dmg;
}
